#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

const int N = 2e4 + 10, M = 2e5 + 10;
int h[N],e[M],ne[M],w[M],idx;
int color[N];
int n,m;

void add(int u,int v,int k) {
    e[idx] = v,w[idx] = k, ne[idx] = h[u],h[u] = idx++;
}

bool dfs(int id,int c,int k) {
    color[id] = c;
    for(int i = h[id]; ~i; i = ne[i]) {
        if(w[i] <= k) continue;
        int v = e[i];
        if(color[v]) {
            if(color[v] == color[id]) return false;
        } else if(!dfs(v,3-c,k)) return false;
    }
    return true;
}

bool check(int k) {
    memset(color,0x00,sizeof color);
    for(int i = 1; i <= n; i++)
        if(!color[i]) if(!dfs(i,1,k)) return false;
    return true;
}

int main() {
    cin >> n >> m;
    memset(h,-1,sizeof h);
    for(int i = 1; i <= m; i++) {
        int a,b,c;
        cin >> a >> b >> c;
        add(a,b,c);
        add(b,a,c);
    }
    
    int le = 0, ri = 1e9;
    while(le < ri) {
        int mid = le + ri >> 1;
        if(check(mid)) ri = mid;
        else le = mid + 1;
    }
    
    cout << le << endl;
    return 0;
}



S 城现有两座监狱，一共关押着 N 名罪犯，编号分别为1~N。

他们之间的关系自然也极不和谐。

很多罪犯之间甚至积怨已久，如果客观条件具备则随时可能爆发冲突。

我们用“怨气值”（一个正整数值）来表示某两名罪犯之间的仇恨程度，怨气值越大，则这两名罪犯之间的积怨越多。

如果两名怨气值为 c 的罪犯被关押在同一监狱，他们俩之间会发生摩擦，并造成影响力为 c 的冲突事件。

每年年末，警察局会将本年内监狱中的所有冲突事件按影响力从大到小排成一个列表，然后上报到 S 城 Z 市长那里。

公务繁忙的 Z 市长只会去看列表中的第一个事件的影响力，如果影响很坏，他就会考虑撤换警察局长。

在详细考察了 N 名罪犯间的矛盾关系后，警察局长觉得压力巨大。

他准备将罪犯们在两座监狱内重新分配，以求产生的冲突事件影响力都较小，从而保住自己的乌纱帽。

假设只要处于同一监狱内的某两个罪犯间有仇恨，那么他们一定会在每年的某个时候发生摩擦。那么，应如何分配罪犯，才能使 Z 市长看到的那个冲突事件的影响力最小？这个最小值是多少？

输入格式
第一行为两个正整数 N 和 M，分别表示罪犯的数目以及存在仇恨的罪犯对数。

接下来的 M 行每行为三个正整数aj，bj，cj，表示aj号和bj号罪犯之间存在仇恨，其怨气值为cj。

数据保证1≤aj<bj<N,0<cj≤109 且每对罪犯组合只出现一次。

输出格式
输出共1行，为 Z 市长看到的那个冲突事件的影响力。

如果本年内监狱中未发生任何冲突事件，请输出0。

数据范围
N≤20000,M≤100000
输入样例：
4 6
1 4 2534
2 3 3512
1 2 28351
1 3 6618
2 4 1805
3 4 12884
输出样例：
3512
难度：中等
时/空限制：1s / 64MB
总通过数：1331
总尝试数：2341
来源：《算法竞赛进阶指南》, NOIP2010提高组
算法标签



#include <iostream>
#include <algorithm>

using namespace std;

const int N = 20010, M = 1e5 + 10;
int n,m;
int f[M];
struct node{
    int u,v,w;
    bool operator<(const node& t) const {
        return w > t.w;
    }
}e[M];

int find(int x) {
    if(x != f[x]) f[x] = find(f[x]);
    return f[x];
}

bool merge(int x,int y) {
    int tx = find(x), ty = find(y);
    if(tx == ty) return false;
    f[tx] = find(y + n);
    f[ty] = find(x + n);
    return true;
}

int main() {
    cin >> n >> m;
    for(int i = 0; i < m; i++)
        cin >> e[i].u >> e[i].v >> e[i].w;
    sort(e,e+m);
    for(long long i = 0; i <= (n << 1); i++) f[i] = i;
    
    int res = 0;
    for(int i = 0; i < m; i++) {
        int u = e[i].u, v = e[i].v, w = e[i].w;
        if(!merge(u,v)) {
            res = w;
            break;
        }
    }
    cout << res << endl;
    return 0;
}

