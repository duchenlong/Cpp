#include "control.h"

#define MAXCNT 1

// 获取网卡信息
bool Get() {
    return infoNetwork();
}

// 解析协议     0 随机解析  1 解析TCP  2 解析UDP  3 解析ICMP
bool Parse(const int flag) {
    int cnt = 0;                // 当前抓取数据包的次数
    bool ret = false;           // 判断是否为可以解析的包
    while ( cnt ++ < MAXCNT) {
// cout << cnt << endl;
        ret = getDataPacket();              // 获取数据包
        if(!ret) continue;

// cout << "dataline" << endl;
        ret = ParseDateLine();              // 解析数据链路层，以太网帧头
        if(!ret) continue;

        ret = ParseNetWork();               // 解析网络层
        if(!ret) continue;

//cout << "tran" << endl;
        ret = ParseTransport(flag);         // 解析传输层
        if(!ret) continue;
//cout << "tranend" << endl;
        return true;
    }

    return false;
}

// 获得 传输层协议类型
string GetTranPro(){
    string ans("other");
    switch (atoi((::ip_protocal)->_protocol.c_str())) {
    case 1: ans = "ICMP";break;
    case 6: ans = "TCP";break;
    case 17: ans = "UDP";break;
    }

// cout << ans << endl;
    return ans;
}

// 释放网卡信息
bool close() {
    return closeNetwork();
}
