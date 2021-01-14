#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>

using namespace std;

const int N = 110, M = 1010;
int t,r,c,n;
int res[M],vis[N][N];
string f[N];

void dfs(int x,int y) {
    static int dx[] = {-1,0,1,0} , dy[] = {0,1,0,-1};
    if(vis[x][y]) return ;
    vis[x][y]  = 1;
    
    for(int i = 0; i< 4; i++) {
        int a = x+dx[i], b = y + dy[i];
        if(a < 0 || b < 0 || a >= r || b >= c || vis[a][b] || f[a][b] == '0') continue;
        dfs(a,b);
    }
}

int slove() {
    memset(vis,0x00,sizeof vis);
    int ret = 0;
    
    for(int i = 0; i < r; i++)
        for(int j = 0; j < c; j++) {
            if(vis[i][j] || f[i][j] == '0') continue;
            dfs(i,j);
            ret ++;
        }
    return ret;
}



int main () {
    cin >> t;
    int cnt = 0;
    while(t--) {
        cnt ++;
        cin >> r >> c;
        for(int i = 0; i < r ;i ++)
           cin >> f[i];
        
        cin >> n;
        int end = 0;
        while(n --) {
            char ch;
            cin >> ch;
            if(ch == 'Q') res[end++] = slove();
            else {
                int a,b,c;
                cin >> a >> b >> c;
                f[a][b] = c + '0';
            }
        }
        
        printf("Case #%d:\n",cnt);
        for(int i = 0; i < end; i++)
            cout << res[i] << endl;
    }
    
    return 0;
}


我们有一个R行C列的矩形网格，其中每个方格内的数字都是0或1。

我们将在网格上执行N个操作，每个操作都是以下之一：

操作M：将网格的一个单元格中的数字更改为0或1。
操作Q：确定1的不同连通区域的数量。 1的连通区域是指矩阵内全部为1的连通的单元格的子集，在子集区域内通过沿着共享边缘在单元格之间行进，可以从该区域中的任何单元格到达该区域中的任何其他单元格。
输入格式
第一行包含整数T，表示共有T组测试数据。

每组数据第一行包含两个整数R和C，表示矩形网格的行数和列数。

接下来R行，每行包含一个长度为C的由1和0构成的字符串，表示矩阵网格的初始状态。

接下来一行，包含整数N，表示操作数量。

接下来N行，每行包含一个操作指令，操作指令共两种，如下所示：

“M x y z”，表示M指令，具体含义为将第x行第y列的方格内的值变为z。
“Q”，表示Q指令，表示进行一次询问。
输出格式
对于每组测试数据，第一行输出“Case #x:”，其中x为组别编号（从1开始）。

接下来Q行，每行输出一个询问的结果。

数据范围
1≤T≤10,
1≤R,C≤100,
0≤x<R,
0≤y<C,
0≤z≤1,
1≤N≤1000
输入样例：
1
4 4
0101
0010
0100
1111
7
Q
M 0 2 1
Q
M 2 2 0
Q
M 2 1 0
Q
输出样例：
Case #1:
4
2
2
2
