如下图所示的螺旋折线经过平面上所有整点恰好一次。

p1.png

对于整点 (X,Y)，我们定义它到原点的距离 dis(X,Y) 是从原点到 (X,Y) 的螺旋折线段的长度。

例如 dis(0,1)=3,dis(?2,?1)=9

给出整点坐标 (X,Y)，你能计算出 dis(X,Y) 吗？

输入格式
包含两个整数 X,Y。

输出格式
输出一个整数，表示 dis(X,Y)。

数据范围
?109≤X,Y≤109
输入样例：
0 1
输出样例：
3
难度：中等
时/空限制：1s / 64MB
总通过数：436
总尝试数：1293
来源：第九届蓝桥杯省赛C++B组
算法标签


#include <iostream>
#include <cmath>

using namespace std;
using ll = long long;

ll x,y;
ll ans;

ll Sn(ll n) {
    if(n == 0) return 0;
    return 2 * n + (n * (n - 1));
}

int main() {
    cin >> x >> y;
    ll n = max(abs(x),abs(y));
    ans = 4 * Sn(n-1);
    ll len = 2  + (n - 1) * 2;
    //cout << ans << " " << len << " " << n << endl; 

    if(y > 0 && abs(x) <= y) {                  // 上
        ans += len + len/2 + x;
    } else if(x > 0 && x >= abs(y)) {           // 右
        ans += len * 2 + len/2 - y;
    } else if(y <= 0 && abs(y) + 1 >= abs(x)) { // 下
        ans += len * 3 + -x-y;
    } else {
        ans += y - x;                           // 左
    }
    
    cout << ans;
    return 0;
}
