#ifndef MYPCAP_H
#define MYPCAP_H

#include <init.h>
#include <pcap.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <winsock2.h>
#include <Windows.h>
#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

#define SIZE 1024

extern pcap_if_t*               allNetwork;     // 网卡信息
extern int                      size;           // 网卡数量
extern char                     errbuf[SIZE];   // 错误信息
extern pcap_t*                  sniff;          // 嗅探
extern struct pcap_pkthdr*      packHeader;     // 数据包头
extern const u_char*            packData;       // 数据报
extern const int                packSum;        // 最多循环抓取数据包的次数

// 以太网帧头部信息
struct ether_parse {
    string _decs;       // 目标MAC 地址
    string _src;        // 源  MAC 地址
    string _type;       // 上层协议类型
    string _str;        // 16进制字符串信息
};
extern ether_parse* eth_protocal;  // 以太网协议

// ip 协议
struct ip_parse {
    string      _version;           // 版本
    string      _handerLen;         // 首部长度
    string      _diffserv;          // 区分服务
    string      _totalLen;          // 总长度
    string      _identification;    // 标识
    string      _flag_offset;       // 标志 3 + 片偏移 13
    string      _timeLive;          // 生存时间
    string      _protocol;          // 协议
    string      _checkSum;          // 首部校验和
    string      _src;               // 源地址
    string      _desc;              // 目的地址
    string      _str[4];            // 16进制字符串信息数组
};
extern ip_parse* ip_protocal;       // ip 协议

// udp 协议  传输层
struct udp_parse {
    string      _sport;             // 源端口
    string      _dport;             // 目的端口
    string      _len;               // 数据长度
    string      _checksum;          // 校验和
    string      _str[2];            // 16进制字符串信息数组
};
extern udp_parse* udp_protocal;     // udp 协议

// tcp 协议  传输层
struct tcp_parse {
    string      _sport;             // 源端口
    string      _dport;             // 目的端口
    string      _seqNum;            // 序列号
    string      _ackNum;            // 确认号
    string      _off_res_flag;      // 数据偏移 4  保留位 6  标志位 6
    string      _winSize;           // 窗口大小
    string      _checkSum;          // 校验和
    string      _urgentPoint;       // 紧急指针
    string      _str[5];            // 16进制字符串信息数组
};
extern tcp_parse* tcp_protocal;     // tcp 协议

// 获取网卡信息
bool infoNetwork();

// 利用嗅探获取数据包  cnt 网络嗅探编号
bool setSniffing(int cnt);

// 获取数据包
bool getDataPacket();

// 解析数据链路层
bool ParseDateLine();

// 解析网络层
bool ParseNetWork();

// 解析传输层 0 随机解析  1 解析TCP  2 解析UDP  3 解析ICMP
bool ParseTransport(const int flag);

// 解析TCP协议
bool ParseTCP();

// 解析UDP协议
bool ParseUDP();

// 解析ICMP协议
bool ParseICMP();

// 释放网卡信息
bool closeNetwork();

#endif // MYPCAP_H
