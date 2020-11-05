给定 N 个整数 A1,A2,…AN。

请你从中选出 K 个数，使其乘积最大。

请你求出最大的乘积，由于乘积可能超出整型范围，你只需输出乘积除以 1000000009 的余数。

注意，如果 X<0， 我们定义 X 除以 1000000009 的余数是负(?X)除以 1000000009 的余数，即：0?((0?x)%1000000009)
输入格式
第一行包含两个整数 N 和 K。

以下 N 行每行一个整数 Ai。

输出格式
输出一个整数，表示答案。

数据范围
1≤K≤N≤105,
?105≤Ai≤105
输入样例1：
5 3
-100000
-10000
2
100000
10000
输出样例1：
999100009
输入样例2：
5 3
-100000
-100000
-2
-100000
-100000
输出样例2：
-999999829

#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

using ll = long long;
const int mod = 1e9 + 9;
const int N = 1e5 + 10;
ll f[N];
int n,k;

ll ans = 1;

int main() {
    cin >> n >> k;
    for(int i = 0; i < n; i++) scanf("%lld",&f[i]);
    sort(f,f+n);
    
    if(f[n-1] < 0) {    // 全为负数
        if(k & 1) {     // 选奇数个，n : n - k 所有负数从大到小相乘
            int cnt = k;
            int i = n - 1;
            while(cnt --) {
                ans = (ans * f[i]) % mod;
                i--;
            }
        } else {        // 选偶数个，0 : k  从小到大相乘
            for(int i = 0; i < k; i++) ans = (ans * f[i]) % mod;
        }
    } else {                // 全为正数 或者 有正有负
        int le = 0, ri = n - 1;
        int cnt = k;
        if(cnt & 1) {       // 奇数个，筛选最大的一个数
            ans = f[ri--];
            cnt --;
        }
        
        // 取左右最大的两个数的乘积
        while(cnt > 1) {
            ll numle = f[le] * f[le + 1];
            ll numri = f[ri] * f[ri - 1];
            if(numle > numri) {
                ans = (ans * (numle % mod)) % mod;
                le += 2;
            } else {
                ans = (ans * (numri % mod)) % mod;
                ri -= 2;
            }
            cnt -= 2;
        } 
    }
    
    cout << ans;
    return 0;
}

