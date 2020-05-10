//给你一棵有?n?个节点的无向树，节点编号为?0?到?n-1?，它们中有一些节点有苹果。通过树上的一条边，需要花费 1 秒钟。你从?节点 0?出发，请你返回最少需要多少秒，可以收集到所有苹果，并回到节点 0 。

//无向树的边由?edges?给出，其中?edges[i] = [fromi, toi]?，表示有一条边连接?from?和?toi 。除此以外，还有一个布尔数组?hasApple ，其中?hasApple[i] = true?代表节点?i?有一个苹果，否则，节点?i?没有苹果。

//?




class Solution {
public:
    struct edge
    {
        int to;
        int next;
    };
    
    edge e[200005];
    int head[200005];
    int f[200005];
    int ans = 0;
    
    void add(int from,int to,int len)
    {
        e[len].to = to;
        e[len].next = head[from];
        head[from] = len;
    }
    
    void dfs(vector<int>& visit,int x)
    {
        //遍历以当前点为起点，可以达到的所有边
        for(int i = head[x]; i; i = e[i].next)
            if(e[i].to != f[x])
            {
                f[e[i].to] = x;
                dfs(visit,e[i].to);
                visit[x] += visit[e[i].to];
            }
        
        //记录可以到达的点
        if(visit[x]) ans++;
    }
    
    int minTime1(int n, vector<vector<int>>& edges, vector<bool>& hasApple) {
        int len = 0;
        for(auto& eoch : edges)
        {
            add(eoch[1],eoch[0],len++);
            add(eoch[0],eoch[1],len++);
        }
            
        vector<int> visit(200005);
        for(int i = 0; i < n; i++)
            visit[i]= hasApple[i];
        
        dfs(visit,0);
        
        return max(ans,1)*2 - 2;
    }
	
	//后序遍历 
    int minTime(int n, vector<vector<int>>& edges, vector<bool>& hasApple) {
        vector<vector<int> > map(n);

        for(auto& e : edges)
        {
            map[e[0]].push_back(e[1]);
            map[e[1]].push_back(e[0]);
        }

        vector<bool> visit(n);
        PostOrder(map,0,hasApple,visit);
        return max(ans,0) * 2;
    }

    bool PostOrder(vector<vector<int> >& map,int index,vector<bool>& hasApple,vector<bool>& visit)
    {
        visit[index] = true;
        bool flag = hasApple[index];

        for(auto son : map[index])
        {
            if(visit[son]) continue;

            if(PostOrder(map,son,hasApple,visit))
            {
                flag = true;
                ans++;
            }
        }

        return flag;
    }
  
    
};
