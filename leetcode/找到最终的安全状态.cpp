class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> vis(n,0);   // 0 未被访问 1 成环  2 dfs中被访问
        vector<int> res;

        for(int i = 0; i < n; i++) {
            if(!DFS(i,vis,graph)) vis[i] = 1;
            else res.push_back(i);
        }

        return res;
    }

    bool DFS(int u,vector<int>& vis,vector<vector<int>>& graph) {
        if(vis[u]) return vis[u] == 2;

        vis[u] = 1;
        for(auto& e : graph[u]) {
            if(vis[e] == 2) continue;
            if(vis[e] == 1 || !DFS(e,vis,graph)) return false;
        }

        vis[u] = 2;
        return true;
    }
};

class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<set<int> > mp(n);        // 反向记录
        vector<int> cnt(n);             // 出度
        queue<int> que;
        for(int i = 0; i < n; i++) {
            cnt[i] = graph[i].size();
            if(cnt[i] == 0) {
                que.push(i);
                continue;
            }
            for(auto& e : graph[i])
                mp[e].insert(i);
        }

        vector<int> res;
        while(!que.empty()) {
            int f = que.front();
            que.pop();

            res.push_back(f);
            for(auto& e : mp[f]) {
                cnt[e] --;
                if(cnt[e] == 0) que.push(e);
            }
        }

        sort(res.begin(),res.end());
        return res;
    }
};


在有向图中, 我们从某个节点和每个转向处开始, 沿着图的有向边走。 如果我们到达的节点是终点 (即它没有连出的有向边), 我们停止。

现在, 如果我们最后能走到终点，那么我们的起始节点是最终安全的。 更具体地说, 存在一个自然数 K,? 无论选择从哪里开始行走, 我们走了不到 K 步后必能停止在一个终点。

哪些节点最终是安全的？ 结果返回一个有序的数组。

该有向图有 N 个节点，标签为 0, 1, ..., N-1, 其中 N 是?graph?的节点数.? 图以以下的形式给出: graph[i] 是节点 j 的一个列表，满足 (i, j) 是图的一条有向边。

示例：
输入：graph = [[1,2],[2,3],[5],[0],[5],[],[]]
输出：[2,4,5,6]
这里是上图的示意图。



提示：

graph 节点数不超过 10000.
图的边数不会超过 32000.
每个 graph[i] 被排序为不同的整数列表， 在区间 [0, graph.length - 1]?中选取。
通过次数6,670提交次数14,079

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/find-eventual-safe-states
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
