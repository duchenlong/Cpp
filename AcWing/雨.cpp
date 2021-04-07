#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;

const int N = 55;
int f[N][N],st[N][N],d[N][N];
int dir[4][2] = {1,0,-1,0,0,1,0,-1}; 
int T;
int n,m;
int res;

struct node {
    int x,y,d;
    bool operator<(const node& t) const {
        return d > t.d;
    }
};

int main() {
    cin >> T;
    
    int cnt = 1;
    while( T -- ){
        cin >> n >> m;
        res = 0;
        for(int i = 0; i < n; i ++)
            for(int j = 0; j < m; j ++)
                cin >> f[i][j];
        
        memset(d,0x3f,sizeof d);
        memset(st,0x00,sizeof st);
        
        priority_queue<node> pq;
        for(int i = 0; i < n; i++) {
            pq.push({i,0,f[i][0]});
            d[i][0] = f[i][0];
            pq.push({i,m - 1,f[i][m - 1]});
            d[i][m - 1] = f[i][m - 1];
        }
        for(int j = 1; j < m - 1; j++) {
            pq.push({0,j,f[0][j]});
            d[0][j] = f[0][j];
            pq.push({n - 1,j,f[n - 1][j]});
            d[n - 1][j] = f[n - 1][j];
        }
        
        
        while(pq.size()) {
            node t = pq.top();
            pq.pop();
            
            if(st[t.x][t.y])
                continue;
            st[t.x][t.y] = 1;
            res += t.d - f[t.x][t.y];
            
            for(int i = 0; i < 4; i++) {
                int x = dir[i][0] + t.x, y = dir[i][1] + t.y;
                if(x < 0 || x >= n || y < 0 || y >= m || st[x][y])
                    continue;
                
                if(d[x][y] > max(t.d,f[x][y])) {
                    d[x][y] = max(t.d,f[x][y]);
                    pq.push({x,y,d[x][y]});
                }
            }
        }
       
        
        printf("Case #%d: %d\n",cnt ++, res);
    }
    
    return 0;
}


海里有一个小岛。

岛可以描述为一个具有 R 行 C 列的矩阵，其中包含的数字 H[i][j] 表示每个单元格的高度。

以下是一个 3×3 岛屿的示例：

3 5 5
5 4 5
5 5 5
有时，大雨会在这个岛上的每个单元格上均匀地降落。

你可以假设降水量可以是无限大。

在这样的大雨之后，岛上的一些区域（由沿着边缘连接的一个或多个单元格形成）可能会存在积水。

一片区域可以存在积水的前提是与该区域内单元格沿着边缘连接的区域外的单元格的高度均高于区域内单元格。（周围的海洋被视为高度为 0 的无限单元格。）

否则，水将始终流入其他区域并最终出海。

你可以假设海的高度永远不会改变。

在大雨过后，我们将使用 W[i][j] 来表示岛屿上每个单元格的高度。

以下是对大雨过后的示例岛屿的高度的分析。

最中央的初始高度为 4 的单元格被初始高度为 5 的单元格包围着，因此在该单元格将产生积水，在积水高度到达 5 以后，没有更多区域被高度更高的单元格包围，因此将不再继续积水。

请注意，水不会直接在两个共享顶点的单元格之间流动;水必须沿着共同的边缘流动。（所以中央单元格的积水不会从左上角处流走）

以下是雨后示例岛屿的高度：

3 5 5
5 5 5
5 5 5
给定岛的高度矩阵，你能计算出大雨后的每个单元格的增加高度（W[i][j]?H[i][j]）的总和吗？

输入格式
第一行包含整数 T，表示共有 T 组测试数据。

每组数据第一行包含两个整数 R 和 C。

接下来 R 行每行包含 C 个整数 H[i][j]，表示矩阵内单元格的高度。

输出格式
每组数据输出一个结果，每个结果占一行。

结果表示为 Case #x: y，其中 x 是组别编号（从 1 开始），y 是增加高度的总和。

数据范围
1≤T≤100,
1≤H[i][j]≤1000,
1≤R,C≤50
输入样例：
3
3 3
3 5 5
5 4 5
5 5 5
4 4
5 5 5 1
5 1 1 5
5 1 5 5
5 2 5 8
4 3
2 2 2
2 1 2
2 1 2
2 1 2
输出样例：
Case #1: 1
Case #2: 3
Case #3: 0
样例解释
样例#1已经在题目中说明。

在样例#2中，雨后岛屿看起来像这样：

5 5 5 1
5 2 2 5
5 2 5 5
5 2 5 8
样例#3在雨后保持不变。
