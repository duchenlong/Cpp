你有一张某海域 N×N 像素的照片，”.”表示海洋、”#”表示陆地，如下所示：

.......
.##....
.##....
....##.
..####.
...###.
.......
其中”上下左右”四个方向上连在一起的一片陆地组成一座岛屿，例如上图就有 2 座岛屿。

由于全球变暖导致了海面上升，科学家预测未来几十年，岛屿边缘一个像素的范围会被海水淹没。

具体来说如果一块陆地像素与海洋相邻(上下左右四个相邻像素中有海洋)，它就会被淹没。

例如上图中的海域未来会变成如下样子：

.......
.......
.......
.......
....#..
.......
.......
请你计算：依照科学家的预测，照片中有多少岛屿会被完全淹没。

输入格式
第一行包含一个整数N。

以下 N 行 N 列，包含一个由字符”#”和”.”构成的 N×N 字符矩阵，代表一张海域照片，”#”表示陆地，”.”表示海洋。

照片保证第 1 行、第 1 列、第 N 行、第 N 列的像素都是海洋。

输出格式
一个整数表示答案。

数据范围
1≤N≤1000
输入样例1：
7
.......
.##....
.##....
....##.
..####.
...###.
.......
输出样例1：
1
输入样例2：
9
.........
.##.##...
.#####...
.##.##...
.........
.##.#....
.#.###...
.#..#....
.........
输出样例2：
1


#include <iostream>
#include <queue>
#include <cstdio>
#include <cstring>

using namespace std;

struct node {
    int x,y;
    node(int a,int b) {
        x = a;
        y = b;
    }
};

const int N = 1010;
char f[N][N];
int vis[N][N];
int n = 0;
int dir[4][2] = {-1,0,1,0,0,1,0,-1};

bool BFS(int x,int y) {
    //cout << x <<" " << y <<" "<< f[x][y] << endl;
    queue<node> que;
    que.push(node(x,y));
    vis[x][y] = 1;
    
    bool ret = false;
    
    while(!que.empty()) {
        node qf = que.front();
        que.pop();
        
        int cnt = 0;        // 周围有几个陆地
        for(int i = 0; i < 4; i++) {
            int tx = qf.x + dir[i][0];
            int ty = qf.y + dir[i][1];
            if(tx < 0 || tx >= n || ty < 0 || ty >= n || f[tx][ty] == '.') 
                continue;       // 海洋
            // 陆地
            cnt ++;
            if(vis[tx][ty] == 1) continue;
            que.push(node(tx,ty));
            vis[tx][ty] = 1;
        }
        // cout << cnt << " ";
        if(cnt == 4) ret = true;        // 存在有陆地不会淹没
    }
    
    return ret;
}

int main() {
    cin >> n;
    memset(f,0x00,sizeof f);
    getchar();
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) scanf("%c",&f[i][j]);
        getchar();
    }
    
    memset(vis,0x00,sizeof vis);
    
    int ans = 0;
    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++) {
            if(f[i][j] == '.' || vis[i][j] == 1) continue;
            
            if(!BFS(i,j)) ans++;
        }
    
    cout << ans;
    return 0;
}
