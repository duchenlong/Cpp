#include <iostream>
#include <cstring>

using namespace std;

const int N = 1e5 + 10, M = 2 * N;
int h[N], e[M], ne[M], idx;
bool vis[N];
int n,a,b;
int ans = N;

void add(int from,int to) {
    e[idx] = to, ne[idx] = h[from], h[from] = idx, idx++;
}

int dfs(int u) {
    vis[u] = true;
    
    int res = 0, sum = 1;   // res 最大连通子图的节点数，sum 当前树(根为u)中节点的数量
    for(int i = h[u]; i != -1 ; i = ne[i]) {
        int v = e[i];
        if(vis[v])
            continue;
        
        int s = dfs(v);
        res = max(res,s);
        sum += s;
    }
    
    res = max(res, n - sum);
    ans = min(ans,res);
    
    return sum;
}

int main() {
    cin >> n;
    memset(h,-1,sizeof h);
    
    for(int i = 1; i < n; i ++) {
        cin >> a >> b;
        add(a,b),add(b,a);
    }
    
    dfs(1);
    
    cout << ans << endl;
    
    return 0;
}


给定一颗树，树中包含n个结点（编号1~n）和n-1条无向边。

请你找到树的重心，并输出将重心删除后，剩余各个连通块中点数的最大值。

重心定义：重心是指树中的一个结点，如果将这个点删除后，剩余各个连通块中点数的最大值最小，那么这个节点被称为树的重心。

输入格式
第一行包含整数n，表示树的结点数。

接下来n-1行，每行包含两个整数a和b，表示点a和点b之间存在一条边。

输出格式
输出一个整数m，表示将重心删除后，剩余各个连通块中点数的最大值。

数据范围
1≤n≤105
输入样例
9
1 2
1 7
1 4
2 8
2 5
4 3
3 9
4 6
输出样例：
4
