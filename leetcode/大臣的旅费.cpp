#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

typedef long long LL;
const int N = 1e5 * 3;
int h[N],e[N],w[N],ne[N],id;
int dic[N];
int n;

void add(int u,int v,int t) {
    e[id] = v, w[id] = t, ne[id] = h[u], h[u] = id++; 
}

void dfs(int u,int father,int val) {
    dic[u] = val;
    for(int i = h[u]; ~i; i = ne[i]) {
        int v = e[i];
        if(v == father) continue;
        dfs(v,u,val + w[i]);
    }
}

int main() {
    cin >> n;
    memset(h,-1,sizeof h);
    for(int i = 0; i < n; i++) {
        int u,v,t;
        cin >> u >> v >> t;
        add(u,v,t);
        add(v,u,t);
    }
    
    int u = 0;
    // 第一次dfs 统计所有节点到根节点的路径
    dfs(1,-1,0);
    for(int i = 1; i <= n; i++)
        if(dic[u] < dic[i]) u = i;
    memset(dic,0x00,sizeof dic);
    
    // 第二次 dfs 统计所有节点到u的距离
    dfs(u,-1,0);
    for(int i = 1; i <= n; i++)
        if(dic[u] < dic[i]) u = i;
    LL res = dic[u];
    
    res = res * 10 + (res * (res + 1)) / 2;
    cout << res << endl;
    return 0;
}

很久以前，T王国空前繁荣。

为了更好地管理国家，王国修建了大量的快速路，用于连接首都和王国内的各大城市。

为节省经费，T国的大臣们经过思考，制定了一套优秀的修建方案，使得任何一个大城市都能从首都直接或者通过其他大城市间接到达。

同时，如果不重复经过大城市，从首都到达每个大城市的方案都是唯一的。

J是T国重要大臣，他巡查于各大城市之间，体察民情。

所以，从一个城市马不停蹄地到另一个城市成了J最常做的事情。

他有一个钱袋，用于存放往来城市间的路费。

聪明的J发现，如果不在某个城市停下来修整，在连续行进过程中，他所花的路费与他已走过的距离有关，在走第x千米到第x+1千米这一千米中（x是整数），他花费的路费是x+10这么多。也就是说走1千米花费11，走2千米要花费23。

J大臣想知道：他从某一个城市出发，中间不休息，到达另一个城市，所有可能花费的路费中最多是多少呢？

输入格式
输入的第一行包含一个整数 n，表示包括首都在内的T王国的城市数。

城市从 1 开始依次编号，1 号城市为首都。

接下来 n?1 行，描述T国的高速路（T国的高速路一定是 n?1 条）。

每行三个整数 Pi,Qi,Di，表示城市 Pi 和城市 Qi 之间有一条双向高速路，长度为 Di 千米。

输出格式
输出一个整数，表示大臣J最多花费的路费是多少。

数据范围
1≤n≤105,
1≤Pi,Qi≤n,
1≤Di≤1000
输入样例：
5 
1  2  2 
1  3  1 
2  4  5 
2  5  4 
输出样例：
135
