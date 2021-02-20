#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;

const int N = 21, M = 1 << 21;

int n;
int w[N][N];
int f[M][N];    // f[i][j] 从0->j, 经过的点为i的最短路径长度

int main() {
    cin >> n;
    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
            cin >> w[i][j];
    memset(f,0x3f,sizeof f);
    f[1][0] = 0;
    
    for(int i = 1; i < 1 << n; i++)
        if(i & 1)
        for(int j = 1; j < n; j++) 
            if(i >> j &  1)
                for(int k = 0; k < n; k++)
                    if(i >> k & 1)
                        f[i][j] = min(f[i][j],f[i - (1 << j)][k] + w[k][j]);
    
    cout << f[(1 << n) - 1][n - 1] << endl;
    return 0;
}


给定一张 n 个点的带权无向图，点从 0~n-1 标号，求起点 0 到终点 n-1 的最短Hamilton路径。 Hamilton路径的定义是从 0 到 n-1 不重不漏地经过每个点恰好一次。

输入格式
第一行输入整数n。

接下来n行每行n个整数，其中第i行第j个整数表示点i到j的距离（记为a[i,j]）。

对于任意的x,y,z，数据保证 a[x,x]=0，a[x,y]=a[y,x] 并且 a[x,y]+a[y,z]>=a[x,z]。

输出格式
输出一个整数，表示最短Hamilton路径的长度。

数据范围
1≤n≤20
0≤a[i,j]≤107
输入样例：
5
0 2 4 5 1
2 0 6 5 3
4 6 0 8 3
5 5 8 0 5
1 3 3 5 0
输出样例：
18
