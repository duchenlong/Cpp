#include <iostream>

using std::cin;
using std::cout;
using std::endl;

typedef long long LL;
const int N = 1e5 + 10;
LL hash[N],n,k;
LL res,sum;

int main() {
    cin >> n >> k;
    hash[0] = 1;
    
    // [i,j] (sum[j] - sum[i - 1]) % k = 0
    //        sum[j] % k - sum[i - 1] % k = 0
    //          sum[j] % k = sum[i-1] % k
    for(int i = 0; i < n; i++) {
        int w;
        cin >> w;
        sum = (sum + w) % k;
        res += hash[sum];
        hash[sum] ++;
    }
    cout << res << endl;
    return 0;
}

给定一个长度为 N 的数列，A1,A2,…AN，如果其中一段连续的子序列 Ai,Ai+1,…Aj 之和是 K 的倍数，我们就称这个区间 [i,j] 是 K 倍区间。

你能求出数列中总共有多少个 K 倍区间吗？

输入格式
第一行包含两个整数 N 和 K。

以下 N 行每行包含一个整数 Ai。

输出格式
输出一个整数，代表 K 倍区间的数目。

数据范围
1≤N,K≤100000,
1≤Ai≤100000
输入样例：
5 2
1
2
3
4
5
输出样例：
6
