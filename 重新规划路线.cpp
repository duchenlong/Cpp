//n 座城市，从 0 到 n-1 编号，其间共有 n-1 条路线。因此，要想在两座不同城市之间旅行只有唯一一条路线可供选择（路线网形成一颗树）。去年，交通运输部决定重新规划路线，以改变交通拥堵的状况。

//路线用 connections 表示，其中 connections[i] = [a, b] 表示从城市 a 到 b 的一条有向路线。

//今年，城市 0 将会举办一场大型比赛，很多游客都想前往城市 0 。

//请你帮助重新规划路线方向，使每个城市都可以访问城市 0 。返回需要变更方向的最小路线数。

//题目数据 保证 每个城市在重新规划路线方向后都能到达城市 0 。

//?

class Solution {
public:
    int minReorder(int n, vector<vector<int>>& c) {
        unordered_map<int,set<int> > map;
        unordered_map<int,set<int> > unmap;
        for(auto& eoch : c)
        {
            map[eoch[0]].insert(eoch[1]);//from --》 to
            unmap[eoch[1]].insert(eoch[0]);//to --》 from
        }
        
        queue<int> que;
        que.push(0);
        vector<int> visit(n,0);//判断哪条路选择了
        visit[0]=1;

        int ans = 0;
        
        while(!que.empty())
        {
            int size = que.size();
            
            for(int i = 0; i < size; i++)
            {
                int f = que.front();
                que.pop();
                
                //不用修改的路
                for(auto& eoch : unmap[f])
                {
                    if(visit[eoch]) continue;
                    que.push(eoch);
                    visit[eoch]=1;
                }
                
                //需要修改
                for(auto& eoch : map[f])
                {
                    if(visit[eoch]) continue;
                    que.push(eoch);
                    visit[eoch]=1;
                    ans++;
                }
                
            }
            
        }
        return ans;
    }
};
