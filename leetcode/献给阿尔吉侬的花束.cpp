#include <iostream>
#include <cstring>
#include <queue>
using namespace std;

typedef pair<int,int> PII;
const int N = 210;
char f[N][N];
int dist[N][N];
int n,m;

int BFS(PII start) {
    memset(dist,0x00,sizeof dist);
    queue<PII> que;
    que.push(start);
    dist[start.first][start.second] = 1;
    
    int dir[4][2] = {1,0,0,1,-1,0,0,-1};
    while(que.size()) {
        int cnt = que.size();
        while(cnt --) {
            auto fr = que.front();
            que.pop();
            
            for(int i = 0; i < 4; i++) {
                int x = fr.first + dir[i][0], y = fr.second + dir[i][1];
                if(x < 0 || y < 0 || x >= n || y >= m || f[fr.first][fr.second] == '#' || dist[x][y]) continue;
                dist[x][y] = dist[fr.first][fr.second] + 1;
                if(f[x][y] == 'E') {
                    return dist[x][y] - 1;
                }
                
                que.push({x,y});
            }
        }
    }
    
    return -1;
}

int main() {
    int T;
    cin >> T;
    while(T --) {
        cin >> n >> m;
        for(int i = 0; i < n; i++) cin >> f[i];
        for(int i = 0; i < n; i++)
            for(int j = 0; j < m; j++) {
                if(f[i][j] == 'S') {
                    int res = BFS({i,j});
                    
                    if(res == -1) puts("oop!");
                    else cout << res << endl;
                }
            }
    }
    
    return 0;
} 


阿尔吉侬是一只聪明又慵懒的小白鼠，它最擅长的就是走各种各样的迷宫。

今天它要挑战一个非常大的迷宫，研究员们为了鼓励阿尔吉侬尽快到达终点，就在终点放了一块阿尔吉侬最喜欢的奶酪。

现在研究员们想知道，如果阿尔吉侬足够聪明，它最少需要多少时间就能吃到奶酪。

迷宫用一个 R×C 的字符矩阵来表示。

字符 S 表示阿尔吉侬所在的位置，字符 E 表示奶酪所在的位置，字符 # 表示墙壁，字符 . 表示可以通行。

阿尔吉侬在 1 个单位时间内可以从当前的位置走到它上下左右四个方向上的任意一个位置，但不能走出地图边界。

输入格式
第一行是一个正整数 T，表示一共有 T 组数据。

每一组数据的第一行包含了两个用空格分开的正整数 R 和 C，表示地图是一个 R×C 的矩阵。

接下来的 R 行描述了地图的具体内容，每一行包含了 C 个字符。字符含义如题目描述中所述。保证有且仅有一个 S 和 E。

输出格式
对于每一组数据，输出阿尔吉侬吃到奶酪的最少单位时间。

若阿尔吉侬无法吃到奶酪，则输出“oop!”（只输出引号里面的内容，不输出引号）。

每组数据的输出结果占一行。

数据范围
1<T≤10,
2≤R,C≤200
输入样例：
3
3 4
.S..
###.
..E.
3 4
.S..
.E..
....
3 4
.S..
####
..E.
输出样例：
5
1
oop!
