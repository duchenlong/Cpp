class Solution {
public:
    int n;
    unordered_map<int,set<int> > mp;
    vector<int> res;
    vector<int> nums;
    
    vector<int> getCoprimes(vector<int>& _nums, vector<vector<int>>& edges) {
        n = _nums.size();
        nums = _nums;
        for(auto& e : edges) {
            mp[e[0]].insert(e[1]);
            mp[e[1]].insert(e[0]);
        }
        
        res.resize(n, -1);
        
        dfs(0,-1,vector<int> (51,-1));
        
        return res;
    }
    
    int gcd(int a,int b) {
        if(a < b) return gcd(b,a);
        if(b == 0) return a;
        return gcd(b,a % b);
    }
    
    void dfs(int v,int u,vector<int> f) {
        int cur = nums[v];
        res[v] = f[cur];
        
        for(int i = 1; i <= 50; i++)
            if(gcd(cur,i) == 1) {
                f[i] = v;
            }

        for(auto& e : mp[v]) {
            if(e == u) continue;
            dfs(e,v,f);
        }
        
    }
};


const int N = 1e5 + 10, M = 2 * N;
int h[N],e[M],ne[M],id;
int depth[N];

class Solution {
public:
    vector<int> nums,res,pos;
    vector<vector<int> > g; // 互质数的关系

    void add(int u,int v) {
        e[id] = v, ne[id] = h[u], h[u] = id ++;
    }

    int gcd(int a,int b) {
        //if(a < b) return gcd(b,a);
        if(b == 0) return a;
        return gcd(b,a % b);
    }

    vector<int> getCoprimes(vector<int>& _nums, vector<vector<int>>& edges) {
        nums = _nums;
        int n = _nums.size();
        memset(h,-1,sizeof h);
        id = 0;

        for(auto& e : edges) {
            int a = e[0], b = e[1];
            add(a,b), add(b,a);
        }

        g.resize(55);
        for(int i = 1; i <= 50; i++)
            for(int j = 1; j <= 50; j++)
                if(gcd(i,j) == 1)
                    g[i].push_back(j);
        
        res.resize(n,-1);
        pos.resize(55, -1);
        depth[0] = 0;

        dfs(0,-1);

        return res;
    }

    void dfs(int v,int fa) {
        int x = nums[v];
        for(auto& e : g[x])
            if(pos[e] != -1) 
                if(res[v] == -1 || depth[pos[e]] > depth[res[v]])
                    res[v] = pos[e];

        int pre = pos[x];
        pos[x] = v;
        for(int i = h[v]; ~i; i = ne[i]) {
            int j = e[i];
            if(j == fa) continue;
            depth[j] = depth[v] + 1;

            dfs(j,v);
        }
        pos[x] = pre;
    }
};


给你一个 n?个节点的树（也就是一个无环连通无向图），节点编号从 0?到 n - 1?，且恰好有 n - 1?条边，每个节点有一个值。树的 根节点?为 0 号点。

给你一个整数数组?nums?和一个二维数组?edges?来表示这棵树。nums[i]?表示第?i?个点的值，edges[j] = [uj, vj]?表示节点?uj?和节点?vj?在树中有一条边。

当?gcd(x, y) == 1?，我们称两个数?x 和?y?是 互质的?，其中?gcd(x, y)?是 x?和 y?的 最大公约数?。

从节点?i?到 根?最短路径上的点都是节点 i?的祖先节点。一个节点 不是 它自己的祖先节点。

请你返回一个大小为 n?的数组 ans?，其中?ans[i]是离节点?i?最近的祖先节点且满足?nums[i] 和?nums[ans[i]]?是 互质的?，如果不存在这样的祖先节点，ans[i]?为 -1?。

?

示例 1：



输入：nums = [2,3,3,2], edges = [[0,1],[1,2],[1,3]]
输出：[-1,0,0,1]
解释：上图中，每个节点的值在括号中表示。
- 节点 0 没有互质祖先。
- 节点 1 只有一个祖先节点 0 。它们的值是互质的（gcd(2,3) == 1）。
- 节点 2 有两个祖先节点，分别是节点 1 和节点 0 。节点 1 的值与它的值不是互质的（gcd(3,3) == 3）但节点 0 的值是互质的(gcd(2,3) == 1)，所以节点 0 是最近的符合要求的祖先节点。
- 节点 3 有两个祖先节点，分别是节点 1 和节点 0 。它与节点 1 互质（gcd(3,2) == 1），所以节点 1 是离它最近的符合要求的祖先节点。
示例 2：



输入：nums = [5,6,10,2,3,6,15], edges = [[0,1],[0,2],[1,3],[1,4],[2,5],[2,6]]
输出：[-1,0,-1,0,0,0,-1]
?

提示：

nums.length == n
1 <= nums[i] <= 50
1 <= n <= 105
edges.length == n - 1
edges[j].length == 2
0 <= uj, vj < n
uj != vj

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/tree-of-coprimes
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
