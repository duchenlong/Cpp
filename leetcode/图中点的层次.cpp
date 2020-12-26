给定一个n个点m条边的有向图，图中可能存在重边和自环。

所有边的长度都是1，点的编号为1~n。

请你求出1号点到n号点的最短距离，如果从1号点无法走到n号点，输出-1。

输入格式
第一行包含两个整数n和m。

接下来m行，每行包含两个整数a和b，表示存在一条从a走到b的长度为1的边。

输出格式
输出一个整数，表示1号点到n号点的最短距离。

数据范围
1≤n,m≤105
输入样例：
4 5
1 2
2 3
3 4
1 3
1 4
输出样例：
1


#include <iostream>
#include <cstring>
#include <queue>

using namespace std;

const int N = 1e5 + 10;
int h[N], e[N], ne[N], idx;
int n,m;
bool vis[N];

void add(int u,int v) {
    e[idx] = v, ne[idx] = h[u], h[u] = idx++;
}

int bfs() {
    queue<int> que;
    que.push(1);
    vis[1] = true;
    
    int res = 0;
    
    while(!que.empty()) {
        int size = que.size();
        res++;
        
        while(size --) {
            int f = que.front();
            que.pop();
            
            for(int i = h[f]; ~i; i = ne[i]) {
                int v = e[i];
                if(vis[v])
                    continue;
                    
                que.push(v);
                vis[v] = true;
                
                if(v == n) return res;
            }
        }
    }
    
    return -1;
}

int main() {
    cin >> n >> m;
    memset(h,-1,sizeof h);
    for(int i = 0; i <= m; i ++) {
        int a,b;
        cin >> a >> b;
        add(a,b);
    }
    
    cout << bfs() << endl;
    return 0;
}
