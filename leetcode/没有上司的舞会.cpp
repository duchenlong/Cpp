#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;

const int N = 6010;
int happy[N];
int h[N],e[N],ne[N],id;
int f[N][2];
bool is_father[N];
int n;

void add(int u,int v) {
    e[id] = v, ne[id] = h[u], h[u] = id++;
}

void dfs(int u) {
    f[u][1] = happy[u];
    
    for(int i = h[u]; ~i; i = ne[i]) {
        int v = e[i];
        dfs(v);
        
        f[u][0] += max(f[v][0],f[v][1]);
        f[u][1] += f[v][0];
    }
}

int main() {
    cin >> n;
    for(int i = 1; i <= n; i++)
        cin >> happy[i];
    
    memset(h,-1,sizeof h);
    
    for(int i = 1; i < n; i++) {
        int a,b;
        cin >> a >> b;
        add(b,a);
        is_father[a] = true;
    }
    
    int root = 1;
    while(is_father[root]) root++;
    
    dfs(root);
    
    cout << max(f[root][0],f[root][1]) << endl;
    return 0;
}


Ural大学有N名职员，编号为1~N。

他们的关系就像一棵以校长为根的树，父节点就是子节点的直接上司。

每个职员有一个快乐指数，用整数 Hi 给出，其中 1≤i≤N。

现在要召开一场周年庆宴会，不过，没有职员愿意和直接上司一起参会。

在满足这个条件的前提下，主办方希望邀请一部分职员参会，使得所有参会职员的快乐指数总和最大，求这个最大值。

输入格式
第一行一个整数N。

接下来N行，第 i 行表示 i 号职员的快乐指数Hi。

接下来N-1行，每行输入一对整数L, K,表示K是L的直接上司。

输出格式
输出最大的快乐指数。

数据范围
1≤N≤6000,
?128≤Hi≤127
输入样例：
7
1
1
1
1
1
1
1
1 3
2 3
6 4
7 4
4 5
3 5
输出样例：
5
