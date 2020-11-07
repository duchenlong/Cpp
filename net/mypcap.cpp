#include <mypcap.h>

pcap_if_t*          allNetwork      =  nullptr;     // 网卡信息
int                 size            = 0;            // 网卡数量
char                errbuf[SIZE];                   // 错误信息
pcap_t*             sniff           = nullptr;      // 嗅探
struct pcap_pkthdr* packHeader      = nullptr;      // 数据包头
const u_char*       packData        = nullptr;      // 数据报
const int           packSum         = 1;            // 最多循环抓取数据包的次数

ether_parse*    eth_protocal = nullptr;         // 以太网协议
ip_parse*       ip_protocal  = nullptr;         // ip 协议
udp_parse*      udp_protocal = nullptr;         // udp 协议
tcp_parse*      tcp_protocal = nullptr;         // tcp 协议

// 获取网卡信息
bool infoNetwork() {
    if(::allNetwork) closeNetwork();
    ::allNetwork = nullptr;
    memset(errbuf,0x00,sizeof errbuf);
    int ret = pcap_findalldevs_ex(PCAP_SRC_IF_STRING,NULL,&(::allNetwork),::errbuf);
    if(ret == -1) {
         // qDebug() << QString::fromUtf8("Get info Network error ") << QString::fromUtf8(::errbuf);
         return false;
    }

    pcap_if_t* cur = ::allNetwork;
    ::size = 0;
    while(cur) {
        //qDebug() << ::size << " " << QString::fromUtf8(cur->name) << " " << QString::fromUtf8(cur->description);
        cur = cur->next;
        ::size++;
    }

    return true;
}

// 建立嗅探获取数据包  cnt 网络嗅探编号
bool setSniffing(int cnt){
    if(cnt < 0) return false;

    // 得到指定嗅探
    pcap_if_t* adapters = ::allNetwork;

    for(int i = 0; i < cnt && adapters; i++) {
        adapters = adapters->next;
    }
    if(adapters == nullptr) return false;

//cout << adapters->description << endl;
    // 当前抓包使用的嗅探为 pcap_if_t* curAdapter
    pcap_if_t* curAdapter = adapters;
#define  MAXDATAFRAMES 1518

    // 为捕获/发送数据打开一个普通的源
    // PCAP_OPENFLAG_PROMISCUOUS 网卡设置为混合模式
    // 1000 1000毫秒如果读不到数据就超时返回
    ::sniff = pcap_open(curAdapter->name,MAXDATAFRAMES,PCAP_OPENFLAG_PROMISCUOUS,1000,NULL,::errbuf);
    if(pcap_datalink(::sniff) != DLT_EN10MB) return false;      // 必须是以太网协议
    return ::sniff != nullptr;
}

// 获取数据包
bool getDataPacket() {
    ::packData = nullptr;
    ::packData = nullptr;
    int num = 0;
    while( num++ < packSum) {
        int ret = pcap_next_ex(sniff, &(::packHeader), &(::packData));
        if(ret != 1) continue;  // 捕获失败，循环继续

        // 捕获成功
        return true;
    }

    return false;
}

char buf[SIZE / 2];

// itoa 封装，转为指定进制的sting 类型
template <class T>
string dataToString(T data,int radix) {
    memset(buf,0x00,sizeof buf);
    itoa(data,buf,radix);
    return buf;
}

// 解析数据链路层
bool ParseDateLine() {
    // 以太网数据帧头格式
    struct ether_hander {
        u_char  _ether_dhost[6];    // 目标地址
        u_char  _ether_shost[6];    // 源地址
        u_short _ether_type;        // 以太网类型
    };
    ether_hander* handl = (ether_hander*)packData;      // 得到以太网帧头
    ::eth_protocal = new ether_parse();                 // 转为显示的格式

#define NTOHS(A) ((((A)&0xFF00)>>8) | (((A)&0x00FF)<<8))
    handl->_ether_type = NTOHS(handl->_ether_type);  // 网络字节序转为主机字节序

    // 以太网协议类型
    (::eth_protocal)->_type = "0x" + dataToString(handl->_ether_type,16);
    if((::eth_protocal)->_type != "0x800") return false;    // 网络层不是ip协议

    // 目标地址 MAC
    memset(buf,0x00,sizeof buf);
#define A(I) handl->_ether_dhost[I]
    sprintf(buf," %02X:%02X:%02X:%02X:%02X:%02X ",A(0),A(1),A(2),A(3),A(4),A(5));
    (::eth_protocal)->_decs = buf;

    // 源地址 MAC
    memset(buf,0x00,sizeof buf);
#define B(I) handl->_ether_shost[I]
    sprintf(buf," %02X:%02X:%02X:%02X:%02X:%02X ",B(0),B(1),B(2),B(3),B(4),B(5));
    (::eth_protocal)->_src = buf;

    // 原数据
    (::eth_protocal)->_str += "0x";
    for(int i = 0; i < 6; i++) {
        string t = dataToString(handl->_ether_dhost[i],16);
        (::eth_protocal)->_str += string("0",2-t.size()) + t + " ";
    }
    for(int i = 0; i < 6; i++) {
        string t = dataToString(handl->_ether_shost[i],16);
        (::eth_protocal)->_str += string("0",2-t.size()) + t + " ";
    }
    string t = dataToString(handl->_ether_type,16);
    (::eth_protocal)->_str += string("0",4-t.size()) + t;
    return true;
}

// 点分十进制
string iptos(long in)
{
    u_char *p;
    p = (u_char *)&in;
    memset(buf,0x00,sizeof buf);
    sprintf(buf, "%d.%d.%d.%d", p[0], p[1], p[2], p[3]);
    return buf;
}

// 解析网络层
bool ParseNetWork() {
    struct ip_hander {
        u_char      _version_handerLen;     // 版本 4  首部长度 4
        u_char      _diffserv;              // 服务类型
        u_short     _totalLen;              // 总长度
        u_short     _identification;        // 标识
        u_short     _flag_offset;           // 标志 3 + 片偏移 13
        u_char      _timeLive;              // 生存时间
        u_char      _protocol;              // 协议
        u_short     _checkSum;              // 首部校验和
        long        _src;                   // 源地址
        long        _desc;                  // 目的地址
    };

    ip_hander* handl = (ip_hander*)(::packData + 14);
    ::ip_protocal    = new ip_parse();

    // ip 版本 ipv4  ipv6
    if((handl->_version_handerLen & (0x40)) == 0x40) (::ip_protocal)->_version = "ipv4";
    else if((handl->_version_handerLen & (0x60)) == 0x60) (::ip_protocal)->_version = "ipv6";
    else return false;

    char len = handl->_version_handerLen & 0x0f;
    if(len < 0x05) return false;    //少于固定长度
    (::ip_protocal)->_handerLen = "0x" + dataToString(len,16);                              // 首部长度
    (::ip_protocal)->_diffserv =  "0x" + dataToString(handl->_diffserv,16);                 // 服务类型
    (::ip_protocal)->_totalLen =  "0x" + dataToString(handl->_totalLen,16);                 // 总长度
    (::ip_protocal)->_identification =  "0x" + dataToString(handl->_identification,16);     // 标识

    char flag = (handl->_flag_offset) >> 13;
    string fRet = dataToString(flag,2);
    fRet = string(3-fRet.size(),'0') + fRet; // 补前置0
    char offset = handl->_flag_offset & 0x1fff;
    string oRet = dataToString(offset,16);
    oRet = string(4 - oRet.size(),'0') + oRet;
    (::ip_protocal)->_flag_offset = fRet + "  " + "0x" +oRet;                   // 标志 3 片偏移 13
    (::ip_protocal)->_timeLive = "0x" + dataToString(handl->_timeLive,16);      // 生存时间
    (::ip_protocal)->_protocol = dataToString(handl->_protocol,10);             // 协议
    (::ip_protocal)->_checkSum = "0x" + dataToString(handl->_checkSum,16);      // 首部校验和
    (::ip_protocal)->_src   = iptos(handl->_src);                               // 源地址
    (::ip_protocal)->_desc  = iptos(handl->_desc);                              // 目标地址

#define FUN(S,N) string(N - S.size(),'0') + S
    (::ip_protocal)->_str[0] = "0x" + FUN(dataToString(handl->_version_handerLen,16),2) + " " + FUN(dataToString(handl->_diffserv,16),2) + " " + FUN(dataToString(handl->_totalLen,16),4);
    (::ip_protocal)->_str[1] = "0x" + FUN(dataToString(handl->_identification,16),4) + " " + FUN(dataToString(handl->_flag_offset,16),4);
    (::ip_protocal)->_str[2] = "0x" + FUN(dataToString(handl->_timeLive,16),2) + " " + FUN(dataToString(handl->_protocol,16),2) + " " + FUN(dataToString(handl->_checkSum,16),4);
    return true;
}

// 解析传输层 0 随机解析  1 解析TCP  2 解析UDP
bool ParseTransport(const int flag){
    bool ret = false;
    switch (atoi((::ip_protocal)->_protocol.c_str())) {
    case 1:     if(flag!=0 && flag != 3) return false;ret = ParseICMP();break;
    case 6:     if(flag!=0 && flag != 1) return false;ret = ParseTCP();break;
    case 17:    if(flag!=0 && flag != 2) return false;ret = ParseUDP();break;
    default:    break;
    }
    return ret;
}

// 解析TCP协议
bool ParseTCP() {
    struct TCP_hander {
        ushort      _sport;         // 源端口
        ushort      _dport;         // 目的端口
        uint        _seqNum;        // 序列号
        uint        _ackNum;        // 确认号
        ushort      _off_res_flag;  // 数据偏移 4  保留位 6  标志位 6
        ushort      _winSize;       // 窗口大小
        ushort      _checkSum;      // 校验和
        ushort      _urgentPoint;   // 紧急指针
    };

    TCP_hander* handl   = (TCP_hander*)(::packData + 14 + 20);  // 以太网帧头14 ip头部 20
    ::tcp_protocal      = new tcp_parse();

    (::tcp_protocal)->_sport        = "0x" + dataToString(handl->_sport,16) + "(" + to_string(handl->_sport) + ") ";         // 源端口
    (::tcp_protocal)->_dport        = "0x" + dataToString(handl->_dport,16) + "(" + to_string(handl->_dport) + ") ";         // 目的端口
    (::tcp_protocal)->_seqNum       = "0x" + dataToString(handl->_seqNum,16) + "(" + to_string(handl->_seqNum) + ") ";       // 序列号
    (::tcp_protocal)->_ackNum       = "0x" + dataToString(handl->_ackNum,16) + "(" + to_string(handl->_ackNum) + ") ";       // 确认号

    string offset   = dataToString((handl->_off_res_flag & 0xf000) >> 12,2);
    (::tcp_protocal)->_off_res_flag = string(4 - offset.size(),'0') + offset;               // 4 数据偏移

    string reserve  = dataToString((handl->_off_res_flag & 0x0fC0) >> 6,2);
    (::tcp_protocal)->_off_res_flag += " " + string(6 - reserve.size(),'0') + reserve;      // 6 位保留位

    string flag     = dataToString((handl->_off_res_flag & 0x003f),2);
    (::tcp_protocal)->_off_res_flag += " " + string(6 - flag.size(),'0') + flag;            // 6 位标志

    (::tcp_protocal)->_winSize  = "0x" + dataToString(handl->_winSize,16);         // 窗口大小
    (::tcp_protocal)->_checkSum = "0x" + dataToString(handl->_checkSum,16);        // 校验和
    (::tcp_protocal)->_urgentPoint = "0x" + dataToString(handl->_urgentPoint,16);  // 紧急指针

#define FUN(S,N) string(N - S.size(),'0') + S
    (::tcp_protocal)->_str[0] = "0x" + FUN(dataToString(handl->_sport,16),4) + " " + FUN(dataToString(handl->_dport,16),4);
    (::tcp_protocal)->_str[1] = "0x" + FUN(dataToString(handl->_seqNum,16),8);
    (::tcp_protocal)->_str[2] = "0x" + FUN(dataToString(handl->_ackNum,16),8);
    (::tcp_protocal)->_str[3] = "0x" + FUN(dataToString(handl->_off_res_flag,16),4) + " " + FUN(dataToString(handl->_winSize,16),4);
    (::tcp_protocal)->_str[4] = "0x" + FUN(dataToString(handl->_checkSum,16),4) + " " + FUN(dataToString(handl->_urgentPoint,16),4);
    return true;
}

// 解析UDP协议
bool ParseUDP() {
    struct UDP_handler {
        ushort      _sport;     // 源端口
        ushort      _dport;     // 目的端口
        ushort      _len;       // 数据长度
        ushort      _checksum;  // 校验和
    };

    UDP_handler* handl = (UDP_handler*)(::packData + 14 + 20);      // 以太网帧头14 ip头部 20
    ::udp_protocal = new udp_parse();

    (::udp_protocal)->_sport        = "0x" + dataToString(handl->_sport,16) + "(" + to_string(handl->_sport) + ")";       // 源端口
    (::udp_protocal)->_dport        = "0x" +dataToString(handl->_dport,16) + "(" + to_string(handl->_dport) + ")";       // 目的端口
    (::udp_protocal)->_len          = "0x" +dataToString(handl->_len,16);         // 数据包长度
    (::udp_protocal)->_checksum     = "0x" +dataToString(handl->_checksum,16);    // udp校验和

#define FUN(S,N) string(N - S.size(),'0') + S
    (::udp_protocal)->_str[0] = "0x" + FUN(dataToString(handl->_sport,16),4) + " " + FUN(dataToString(handl->_dport,16),4);
    (::udp_protocal)->_str[1] = "0x" + FUN(dataToString(handl->_len,16),4) + " " + FUN(dataToString(handl->_checksum,16),4);
    return true;
}

// ICMP 协议
bool ParseICMP() {
    struct icmp_handler{
        u_char      _type;              // icmp 类型
        u_char      _code;              // 代码
        u_short     _checkSum;          // 校验和
        u_short     _identification;    // 标识
        u_short     _seq;               // 序列号
        uint        _initTime;          // 发起时间戳
        u_short     _recvTime;          // 接收时间戳
        u_short     _sendTime;          // 传输时间戳
    };

    return true;
}

// 释放网卡信息
bool closeNetwork() {
    pcap_freealldevs(allNetwork);
    return true;
}
