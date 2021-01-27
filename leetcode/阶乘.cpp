#include <iostream>
#include <unordered_map>
using namespace std;

unordered_map<int,int> mp;
typedef long long LL;

int kui(int a,int b,int p) {
    int res = 1;
    while(b) {
        if(b&1) res = (LL)res * a % p;
        a = (LL)a * a % p;
        b >>= 1;
    }
    return res;
}

int main() {
    int n;
    cin >> n;
    for(int i = 2; i <= n; i++) {
        int t = 2;
        int m = i;
        for(int j = 2; j <= m / j; j++) {
            while(m % j == 0) {
                mp[j] ++;
                m /= j;
            }
        }
        if(m > 1) mp[m] ++;
    }
    
    int res = 1;
    mp[2] -= mp[5];
    for(auto& e : mp) {
        if(e.first == 5) continue;
        res = (res * kui(e.first,e.second,10)) % 10;
    }
    cout << res << endl;
    return 0;
}

N  的阶乘（记作 N!）是指从 1 到 N（包括 1 和 N）的所有整数的乘积。

阶乘运算的结果往往都非常的大。

现在，给定数字 N，请你求出 N! 的最右边的非零数字是多少。

例如 5!=1×2×3×4×5=120，所以 5! 的最右边的非零数字是 2。

输入格式
共一行，包含一个整数 N。

输出格式
输出一个整数，表示 N! 的最右边的非零数字。

数据范围
1≤N≤1000
输入样例：
7
输出样例：
4
