对于一个具有树特征的无向图，我们可选择任何一个节点作为根。图因此可以成为树，在所有可能的树中，具有最小高度的树被称为最小高度树。给出这样的一个图，写出一个函数找到所有的最小高度树并返回他们的根节点。

格式

该图包含?n?个节点，标记为?0?到?n - 1。给定数字?n?和一个无向边?edges?列表（每一个边都是一对标签）。

你可以假设没有重复的边会出现在?edges?中。由于所有的边都是无向边， [0, 1]和?[1, 0]?是相同的，因此不会同时出现在?edges?里。

示例 1:

输入: n = 4, edges = [[1, 0], [1, 2], [1, 3]]

        0
        |
        1
       / \
      2   3 

输出: [1]
示例 2:

输入: n = 6, edges = [[0, 3], [1, 3], [2, 3], [4, 3], [5, 4]]

     0  1  2
      \ | /
        3
        |
        4
        |
        5 

输出: [3, 4]
说明:

?根据树的定义，树是一个无向图，其中任何两个顶点只通过一条路径连接。 换句话说，一个任何没有简单环路的连通图都是一棵树。
树的高度是指根节点和叶子节点之间最长向下路径上边的数量。


class Solution {
public:
    //超时
    vector<int> findMinHeightTrees1(int n, vector<vector<int>>& edges) {
        if(n == 0)  return {};
        if(edges.size() == 0)
        {
            vector<int> tmp;
            for(int i = 0; i < n; i++)
                tmp.push_back(i);
            return tmp;
        }
        int minH = INT_MAX;
        unordered_map<int,vector<int> > ans;
        unordered_map<int,set<int> > map;

        for(auto& eoch : edges)
        {
            map[eoch[1]].insert(eoch[0]);
            map[eoch[0]].insert(eoch[1]);
        }
        
        for(int i = 0; i < n; i++)
        {
            unordered_map<int,int> visit;
            int tmp = dfs(map,visit,i);
            ans[tmp].push_back(i);
            minH = min(minH,tmp);
        }
        
        return ans[minH];
    }

    int dfs(unordered_map<int,set<int> >& map,unordered_map<int,int>& visit, int u)
    {
        int ret = INT_MIN;
        for(auto& v : map[u])
        {
            if(visit.find(v) != visit.end() || visit[v] == 1)
                continue;
            visit[u] = 1;
            ret = max(ret,1 + dfs(map,visit,v));
            visit[u] = 0;
        }
        return ret==INT_MIN ? 0 : ret;
    }

	//拓扑排序 
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        if(n == 0)  return {};
        if(edges.size() == 0)
        {
            vector<int> tmp;
            for(int i = 0; i < n; i++)
                tmp.push_back(i);
            return tmp;
        }

        unordered_map<int,unordered_set<int> > map;
        for(auto& edge : edges)
        {
            map[edge[0]].insert(edge[1]);
            map[edge[1]].insert(edge[0]);
        }

        queue<int> que;
        for(int i = 0; i < n; i++)
            if(map[i].size() == 1)
                que.push(i);
        
        while(n > 2)
        {
            int size = que.size();
            n -= size;
            while(size--)
            {
                int f = que.front();
                que.pop();
                for(auto& v : map[f])
                {
                    map[v].erase(f);
                    if(map[v].size() == 1) que.push(v);
                }
            }
        }

        vector<int> ans;
        while(!que.empty())
        {
            ans.push_back(que.front());
            que.pop();
        }
        return ans;
    }
};
