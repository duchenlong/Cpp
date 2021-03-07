const int N = 2 * 1e4 + 10, M = N * 4;
int h[N], ne[M], e[M], w[M],id;
int dist[N],st[N];

class Solution {
public:
    typedef pair<int,int> PII;
    typedef long long LL;
    const int MOD = 1e9 + 7;
    vector<int> cnt;
    vector<bool> vis;
    
    void add(int u,int v,int t) {
        e[id] = v, w[id] = t, ne[id] = h[u], h[u] = id ++;
    }
    
    int countRestrictedPaths(int n, vector<vector<int>>& edges) {
        memset(h,-1,sizeof h);
        id = 0;
        cnt.resize(n + 1,-1);
        vis.resize(n + 1,false);
        
        for (auto& e : edges) {
            int u = e[0], v = e[1], t = e[2];
            add(u,v,t);
            add(v,u,t);
        }
        dijkstra(n);
        
//         for(int i = 1; i <= n; i++)
//             cout << dist[i] << " ";
//         cout << endl;
        
        return dfs(1,n) % MOD;
    }
    
int dijkstra(int n) {
    memset(dist, 0x3f, sizeof dist);
    memset(st,0x00,sizeof st);
    dist[n] = 0;
    
    priority_queue<PII, vector<PII>, greater<PII> > pq;     // 小根堆
    pq.push({0,n});
    
    while(!pq.empty()) {
        PII t = pq.top();
        pq.pop();
        
        int distance = t.first, ver = t.second;
        if(st[ver]) continue;  // 排除当前节点已经找到最短路的情况
        st[ver] = true;
        
        for(int i = h[ver]; i != -1 ; i = ne[i]) {
            int v = e[i];
            if(dist[v] > distance + w[i]) {
                dist[v] = distance + w[i];
                pq.push({dist[v],v});
            }
        }
    }
    
    if(dist[1] == 0x3f3f3f3f) return -1;
    return dist[1];
}
    
    LL dfs(int u,int end) { 
        if(u == end) return 1;
        if(cnt[u] != -1) {
            return cnt[u];
        }
        
        vis[u] = true;
        
        LL res = 0;
        for(int i = h[u]; ~i; i = ne[i]) {
            int v = e[i], t = w[i];
            //cout << dist[u] << " " << dist[v] << " " << u << " " << v <<endl;
            
            if(vis[v] || dist[u] <= dist[v]) continue;
            //if(v == end) cout << dist[u] << " " << dist[v] << " " << u << " " << v <<  " " << vis[v] << endl;
            res = (res + dfs(v,end)) % MOD;
        }
        
        vis[u] = false;
        cnt[u] = res;
        
        return cnt[u];
    }
    
    
};


现有一个加权无向连通图。给你一个正整数 n ，表示图中有 n 个节点，并按从 1 到 n 给节点编号；另给你一个数组 edges ，其中每个 edges[i] = [ui, vi, weighti] 表示存在一条位于节点 ui 和 vi 之间的边，这条边的权重为 weighti 。

从节点 start 出发到节点 end 的路径是一个形如 [z0, z1, z2, ..., zk] 的节点序列，满足 z0 = start 、zk = end 且在所有符合 0 <= i <= k-1 的节点 zi 和 zi+1 之间存在一条边。

路径的距离定义为这条路径上所有边的权重总和。用 distanceToLastNode(x) 表示节点 n 和 x 之间路径的最短距离。受限路径 为满足 distanceToLastNode(zi) > distanceToLastNode(zi+1) 的一条路径，其中 0 <= i <= k-1 。

返回从节点 1 出发到节点 n 的 受限路径数 。由于数字可能很大，请返回对 109 + 7 取余 的结果。

?

示例 1：


输入：n = 5, edges = [[1,2,3],[1,3,3],[2,3,1],[1,4,2],[5,2,2],[3,5,1],[5,4,10]]
输出：3
解释：每个圆包含黑色的节点编号和蓝色的 distanceToLastNode 值。三条受限路径分别是：
1) 1 --> 2 --> 5
2) 1 --> 2 --> 3 --> 5
3) 1 --> 3 --> 5
示例 2：


输入：n = 7, edges = [[1,3,1],[4,1,2],[7,3,4],[2,5,3],[5,6,1],[6,7,2],[7,5,3],[2,6,4]]
输出：1
解释：每个圆包含黑色的节点编号和蓝色的 distanceToLastNode 值。唯一一条受限路径是：1 --> 3 --> 7 。
?

提示：

1 <= n <= 2 * 104
n - 1 <= edges.length <= 4 * 104
edges[i].length == 3
1 <= ui, vi <= n
ui != vi
1 <= weighti <= 105
任意两个节点之间至多存在一条边
任意两个节点之间至少存在一条路径

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/number-of-restricted-paths-from-first-to-last-node
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
