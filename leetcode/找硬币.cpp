#include <iostream>
#include <algorithm>
using namespace std;

const int N = 1e5 + 10;
int f[N],n,m;

int main() {
    cin >> n >> m;
    for(int i =0 ; i < n;i++)
        cin >> f[i];
    sort(f,f+n);
    int le = 0, ri = n - 1;
    while(le + 1 < ri) {
        int num = f[le] + f[ri];
        if(num ==m) break;
        else if(num < m) le++;
        else ri--;
    }
    
    if(f[le] + f[ri] == m) cout << f[le] << " " << f[ri] << endl;
    else puts("No Solution");
}

伊娃喜欢从整个宇宙中收集硬币。

有一天，她去了一家宇宙购物中心购物，结账时可以使用各种硬币付款。

但是，有一个特殊的付款要求：每张帐单，她只能使用恰好两个硬币来准确的支付消费金额。

给定她拥有的所有硬币的面额，请你帮她确定对于给定的金额，她是否可以找到两个硬币来支付。

输入格式
第一行包含两个整数 N 和 M，分别表示硬币数量以及需要支付的金额。

第二行包含 N 个整数，表示每个硬币的面额。

输出格式
输出一行，包含两个整数 V1,V2，表示所选的两个硬币的面额，使得 V1≤V2 并且 V1+V2=M。

如果答案不唯一，则输出 V1 最小的解。

如果无解，则输出 No Solution。

数据范围
1≤N≤105,
1≤M≤1000
输入样例1：
8 15
1 2 8 7 2 4 11 15
输出样例1：
4 11
输入样例2：
7 14
1 8 7 2 4 11 15
输出样例2：
No Solution
难度：简单
时/空限制：1s / 64MB
总通过数：817
总尝试数：1622
来源：PAT甲级真题1048
算法标签
