#ifndef CONTROL_H
#define CONTROL_H

#include <mypcap.h>

extern int cnt;     // 当前抓包次数

// 获取网卡信息
bool Get();

// 解析数据包  0 随机解析  1 解析TCP  2 解析UDP  3 解析ICMP
bool Parse(const int flag);

// 获得 传输层协议类型
string GetTranPro();

// 释放网卡信息
bool close();
#endif // CONTROL_H
