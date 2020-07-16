有 n 个城市通过 m 个航班连接。每个航班都从城市 u 开始，以价格 w 抵达 v。

现在给定所有的城市和航班，以及出发城市 src 和目的地 dst，你的任务是找到从 src 到 dst 最多经过 k?站中转的最便宜的价格。 如果没有这样的路线，则输出 -1。

?

示例 1：

输入: 
n = 3, edges = [[0,1,100],[1,2,100],[0,2,500]]
src = 0, dst = 2, k = 1
输出: 200
解释: 
城市航班图如下


从城市 0 到城市 2 在 1 站中转以内的最便宜价格是 200，如图中红色所示。
示例 2：

输入: 
n = 3, edges = [[0,1,100],[1,2,100],[0,2,500]]
src = 0, dst = 2, k = 0
输出: 500
解释: 
城市航班图如下


从城市 0 到城市 2 在 0 站中转以内的最便宜价格是 500，如图中蓝色所示。
?

提示：

n 范围是 [1, 100]，城市标签从 0 到 n - 1.
航班数量范围是 [0, n * (n - 1) / 2].
每个航班的格式 (src, dst, price).
每个航班的价格范围是 [1, 10000].
k 范围是 [0, n - 1].
航班没有重复，且不存在环路

class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        unordered_map<int,vector<pair<int,int> > > map;
        for(auto& eoch : flights)
            map[eoch[0]].push_back({eoch[1],eoch[2]});
        
        queue<pair<int,int> > que;
        que.push({src,0});
        int m = k;
        int ans = INT_MAX;
        vector<int> visit(n,INT_MAX);
        visit[src] = 0;

        while(m-- >= 0 && !que.empty())
        {
            int size = que.size();
            
            for(int i = 0; i < size; i++)
            {
                auto f = que.front();
                que.pop();

                for(auto& eoch : map[f.first])
                {
                    int next = eoch.first;
                    int money = f.second + eoch.second;
                    if(visit[next] < money) continue;

                    visit[next] = money;
                    if(next == dst)
                        ans = min(ans,money);
                    else
                        que.push({next,money});
                }
            }
        }

        return ans == INT_MAX ? -1 : ans;
    }
};
