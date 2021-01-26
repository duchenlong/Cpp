#include <iostream>
#include <algorithm>
using namespace std;

typedef long long LL;
const int N = 50, M = 1e4 + 10;

LL f[N], t[M];
int n,m;

int main() {
    cin >> n >> m;
    for(int i = 0; i < n; i++) cin >> f[i];
    t[0] = 1;
    for(int i = 0; i < n; i++) {
        for(int j = f[i]; j <= m; j++)
            t[j] += t[j - f[i]];
    }
    
    cout << t[m] << endl;
    return 0;
}

给定 V 种货币（单位：元），每种货币使用的次数不限。

不同种类的货币，面值可能是相同的。

现在，要你用这 V 种货币凑出 N 元钱，请问共有多少种不同的凑法。

输入格式
第一行包含两个整数 V 和 N。

接下来的若干行，将一共输出 V 个整数，每个整数表示一种货币的面值。

输出格式
输出一个整数，表示所求总方案数。

数据范围
1≤V≤25,
1≤N≤10000
答案保证在long long范围内。

输入样例：
3 10
1 2 5
输出样例：
10
