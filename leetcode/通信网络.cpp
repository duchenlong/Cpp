#include <cstring>
#include <iostream>
using namespace std;

const int N = 1010, M = 10010;
int h[N], e[M], ne[M], id;
bool st[N][N];
int n, m;

void add(int u,int v) {
    e[id] = v, ne[id] = h[u], h[u] = id++;
}

void dfs(int u,int fa) {
    if(st[fa][u]) return ;
    st[fa][u] = true;
    
    for(int i = h[u]; ~i; i = ne[i]) {
        int v = e[i];
        dfs(v,fa);
    }
}

int main() {
    cin >> n >> m;
    memset(h,-1,sizeof h);
    for(int i = 0; i < m; i++) {
        int u,v;
        cin >> u >> v;
        add(u,v);
    }
    
    for(int i = 1; i <= n; i++) {
        dfs(i,i);
    }
        
    
    int res = 0;
    for(int i = 1; i <= n; i++) {
        int cnt = 0;
        for(int j = 1; j <= n; j++)
            if(st[i][j] || st[j][i]) cnt ++;
            else break;
        
        if(cnt == n) res ++;
    }
    
    cout << res << endl;
    return 0;
}

某国的军队由 N 个部门组成，为了提高安全性，部门之间建立了 M 条通路，每条通路只能单向传递信息，即一条从部门 a 到部门 b 的通路只能由 a 向 b 传递信息。

信息可以通过中转的方式进行传递，即如果 a 能将信息传递到 b，b 又能将信息传递到 c，则 a 能将信息传递到 c。

一条信息可能通过多次中转最终到达目的地。

由于保密工作做得很好，并不是所有部门之间都互相知道彼此的存在。

只有当两个部门之间可以直接或间接传递信息时，他们才彼此知道对方的存在。

部门之间不会把自己知道哪些部门告诉其他部门。

p1.png

上图中给了一个 4 个部门的例子，图中的单向边表示通路。

部门 1 可以将消息发送给所有部门，部门 4 可以接收所有部门的消息，所以部门 1 和部门 4 知道所有其他部门的存在。

部门 2 和部门 3 之间没有任何方式可以发送消息，所以部门 2 和部门 3 互相不知道彼此的存在。

现在请问，有多少个部门知道所有 N 个部门的存在。

或者说，有多少个部门所知道的部门数量（包括自己）正好是 N。

输入格式
输入的第一行包含两个整数 N,M，分别表示部门的数量和单向通路的数量。所有部门从 1 到 N 标号。

接下来 M 行，每行两个整数 a,b，表示部门 a 到部门 b 有一条单向通路。

输出格式
输出一行，包含一个整数，表示答案。

数据范围
对于 30% 的评测用例，1≤N≤10，1≤M≤20；
对于 60% 的评测用例，1≤N≤100，1≤M≤1000；
对于 100% 的评测用例，1≤N≤1000，1≤M≤10000。

输入样例：
4 4
1 2
1 3
2 4
3 4
输出样例：
2
样例解释
部门 1 和部门 4 知道所有其他部门的存在。
