#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;

const int N = 10010;
int f[N];
int n,m;

int main() {
    cin >> n >> m;
    f[0] = 1;
    for(int j = 0; j < n; j++) {
        int x;
        cin >> x;
        for(int i = m; i >= x; i--) 
            f[i] += f[i - x];
    }
    
    cout << f[m] << endl;
    return 0;
}


给定N个正整数A1,A2,…,AN，从中选出若干个数，使它们的和为M，求有多少种选择方案。

输入格式
第一行包含两个整数N和M。

第二行包含N个整数，表示A1,A2,…,AN。

输出格式
包含一个整数，表示可选方案数。

数据范围
1≤N≤100,
1≤M≤10000,
1≤Ai≤1000
输入样例：
4 4
1 1 2 2
输出样例：
3
