#include <iostream>
#include <unordered_map>

using namespace std;

int main() {
    int n;
    cin >> n;
    
    unordered_map<int,int> mp;
    for(int i = 0; i < n; i++) {
        int x;
        cin >> x;
        mp[x] ++;
    }
    
    int res = 0, cnt = -1;
    for(auto [k,v] : mp) {
        if(cnt == -1 || v > cnt) {
            res = k;
            cnt = v;
        } else if(v == cnt && k < res) {
            res = k;
        }
    }
    
    cout << res << endl;
    return 0;
}


给定 n 个正整数，找出它们中出现次数最多的数。

如果这样的数有多个，请输出其中最小的一个。

输入格式
输入的第一行只有一个正整数 n，表示数字的个数。

输入的第二行有 n 个整数 s1,s2,…,sn。

相邻的数用空格分隔。

输出格式
输出这 n 个次数中出现次数最多的数。

如果这样的数有多个，输出其中最小的一个。

数据范围
1≤n≤1000,
1≤si≤10000
输入样例：
6
10 1 10 20 30 20
输出样例：
10
