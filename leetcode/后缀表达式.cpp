#include <iostream>
#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstring>

using namespace std;
typedef long long ll;

const int N = 1e5 + 10;
ll f[2 * N];
int n,m,k;
ll ans;

int main() {
    cin >> n >> m;
    k = n + m + 1;
    for(int i = 0; i < k; i++) scanf("%lld",&f[i]);
    sort(f,f+k);

    if(!m) {
        int ri = k - 1;
        while(n >= 0) {
            ans += f[ri--];
            n--;
        }
    } else {
        ans = f[k - 1] - f[0];
        for(int i = 1; i < k - 1; i++) ans += abs(f[i]);
    }
    
    cout << ans;
    return 0;
}


给定 N 个加号、M 个减号以及 N+M+1 个整数 A1,A2,???,AN+M+1，小明想知道在所有由这 N 个加号、M 个减号以及 N+M+1 个整数凑出的合法的后缀表达式中，结果最大的是哪一个？

请你输出这个最大的结果。

例如使用 123+?，则 “23+1?” 这个后缀表达式结果是 4，是最大的。

输入格式
第一行包含两个整数 N 和 M。

第二行包含 N+M+1 个整数 A1,A2,???,AN+M+1。

输出格式
输出一个整数，代表答案。

数据范围
0≤N,M≤105,
?109≤Ai≤109
输入样例：
1 1
1 2 3
输出样例：
4
