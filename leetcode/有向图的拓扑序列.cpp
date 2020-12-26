给定一个n个点m条边的有向图，点的编号是1到n，图中可能存在重边和自环。

请输出任意一个该有向图的拓扑序列，如果拓扑序列不存在，则输出-1。

若一个由图中所有点构成的序列A满足：对于图中的每条边(x, y)，x在A中都出现在y之前，则称A是该图的一个拓扑序列。

输入格式
第一行包含两个整数n和m

接下来m行，每行包含两个整数x和y，表示存在一条从点x到点y的有向边(x, y)。

输出格式
共一行，如果存在拓扑序列，则输出任意一个合法的拓扑序列即可。

否则输出-1。

数据范围
1≤n,m≤105
输入样例：
3 3
1 2
2 3
1 3
输出样例：
1 2 3

#include <iostream>
#include <cstring>

using namespace std;

const int N = 1e5 + 10;
int h[N], e[N], ne[N], idx;
int n,m;
int f[N];
int qq[N],hh,tt;

void add(int u,int v) {
    e[idx] = v, ne[idx] = h[u], h[u] = idx++;
}

void bfs() {
    for(int i = 1; i <= n; i++) {
        if(f[i] == 0) {
            qq[tt++] = i;
        }
    }
    
    while(hh < tt) {
        int size = tt - hh;

        while(size --) {
            int t = qq[hh++];
            
            for(int i = h[t]; ~i; i = ne[i]) {
                int v = e[i];
                f[v]--;
                if(f[v] == 0) qq[tt++] = v;
            }
        }
    }
    
     // 环
    if(tt != n) {
        cout << "-1" << endl;
        return ;
    }
    
    for(int i = 0; i < n; i++)
        cout << qq[i] << " ";
}

int main() {
    cin >> n >> m;
    memset(h,-1,sizeof h);
    for(int i = 0; i < m; i++) {
        int a,b;
        cin >> a >> b;
        add(a,b);
        f[b]++;
    }
    
    bfs();
    return 0;
}
