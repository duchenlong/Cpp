#include <iostream>
#include <algorithm>

using namespace std;

const int N = 15;
int f[N][N][N][N];
int g[N][N];
int n;

int main() {
    cin >> n;
    int a,b,c;
    while(cin >> a >> b >> c, a) {
        g[a][b] = c;
    }
    
    for(int i = 1; i <= n; i ++)
        for(int j = 1; j <= n; j ++)
            for(int k = 1; k <= n; k ++)
                for(int l = 1; l <= n; l ++) {
                    int t1 = max(f[i-1][j][k-1][l],f[i][j-1][k][l-1]);
                    int t2 = max(f[i][j-1][k-1][l],f[i-1][j][k][l-1]);
                    f[i][j][k][l] = max(t1,t2) + g[i][j];
                    if(i != k && j != l)
                        f[i][j][k][l] += g[k][l];
                }
    cout << f[n][n][n][n] << endl;
    return 0;
}


设有 N×N 的方格图，我们在其中的某些方格中填入正整数，而其它的方格中则放入数字0。如下图所示：

2.gif

某人从图中的左上角 A 出发，可以向下行走，也可以向右行走，直到到达右下角的 B 点。

在走过的路上，他可以取走方格中的数（取走后的方格中将变为数字0）。

此人从 A 点到 B 点共走了两次，试找出两条这样的路径，使得取得的数字和为最大。

输入格式
第一行为一个整数N，表示 N×N 的方格图。

接下来的每行有三个整数，第一个为行号数，第二个为列号数，第三个为在该行、该列上所放的数。

行和列编号从 1 开始。

一行“0 0 0”表示结束。

输出格式
输出一个整数，表示两条路径上取得的最大的和。

数据范围
N≤10
输入样例：
8
2 3 13
2 6 6
3 5 7
4 4 14
5 2 21
5 6 4
6 3 15
7 2 14
0 0 0
输出样例：
67
