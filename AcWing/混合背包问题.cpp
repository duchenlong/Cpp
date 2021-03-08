#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

const int N = 1010;
int f[N];
int n,m;

struct goods{
    int v,w,s;
};

int main() {
    cin >> n >> m;
    vector<goods> vec;
    for(int i = 0; i < n; i++) {
        int v,w,s;
        cin >> v >> w >> s;
        
        if(s <= 0) vec.push_back({v,w,s});
        else  {
            int t = 1;
            while(t <= s) {
                vec.push_back({v * t,w * t, -1});
                s -= t;
                t <<= 1;
            }
            if(s) vec.push_back({v * t,w * t, -1});
        }
    }
    
    for(auto& e : vec) {
        int v = e.v, w = e.w, s = e.s;
        if(s == -1) {
            for(int i = m; i >= v; i--)
                f[i] = max(f[i],f[i - v] + w);
        } else {
            for(int i = v; i <= m; i++)
                f[i] = max(f[i],f[i - v] + w);
        }
    }
    
    cout << f[m] << endl;
    return 0;
}


有 N 种物品和一个容量是 V 的背包。

物品一共有三类：

第一类物品只能用1次（01背包）；
第二类物品可以用无限次（完全背包）；
第三类物品最多只能用 si 次（多重背包）；
每种体积是 vi，价值是 wi。

求解将哪些物品装入背包，可使物品体积总和不超过背包容量，且价值总和最大。
输出最大价值。

输入格式
第一行两个整数，N，V，用空格隔开，分别表示物品种数和背包容积。

接下来有 N 行，每行三个整数 vi,wi,si，用空格隔开，分别表示第 i 种物品的体积、价值和数量。

si=?1 表示第 i 种物品只能用1次；
si=0 表示第 i 种物品可以用无限次；
si>0 表示第 i 种物品可以使用 si 次；
输出格式
输出一个整数，表示最大价值。

数据范围
0<N,V≤1000
0<vi,wi≤1000
?1≤si≤1000
输入样例
4 5
1 2 -1
2 4 1
3 4 0
4 5 2
输出样例：
8
