给你一个二维字符网格数组?grid?，大小为?m x n?，你需要检查?grid?中是否存在 相同值 形成的环。

一个环是一条开始和结束于同一个格子的长度 大于等于 4?的路径。对于一个给定的格子，你可以移动到它上、下、左、右四个方向相邻的格子之一，可以移动的前提是这两个格子有 相同的值?。

同时，你也不能回到上一次移动时所在的格子。比方说，环??(1, 1) -> (1, 2) -> (1, 1)?是不合法的，因为从 (1, 2)?移动到 (1, 1) 回到了上一次移动时的格子。

如果 grid?中有相同值形成的环，请你返回 true?，否则返回 false?。

?

示例 1：



输入：grid = [["a","a","a","a"],["a","b","b","a"],["a","b","b","a"],["a","a","a","a"]]
输出：true
解释：如下图所示，有 2 个用不同颜色标出来的环：

示例 2：



输入：grid = [["c","c","c","a"],["c","d","c","c"],["c","c","e","c"],["f","c","c","c"]]
输出：true
解释：如下图所示，只有高亮所示的一个合法环：

示例 3：



输入：grid = [["a","b","b"],["b","z","b"],["b","b","a"]]
输出：false
?

提示：

m == grid.length
n == grid[i].length
1 <= m <= 500
1 <= n <= 500
grid?只包含小写英文字母。



class Solution {
public:
    using key = pair<int,int>;
    struct node{
        int _x;
        int _y;
        key _pre;
        node(int x,int y,int px,int py)
            :_x(x),_y(y)
        {
            _pre = make_pair(px,py);
        }
    };
    int n,m;
    bool containsCycle(vector<vector<char>>& grid) {
        n = grid.size();
        m = grid[0].size();

        vector<vector<bool> > vis(n,vector<bool> (m,false));

        for(int i = 0; i < n; i++)
            for(int j = 0; j < m; j++){
                if(vis[i][j] == true)   continue;

                int ret = BFS(grid,vis,i,j);
                
                if(ret == true) return true;
            }
        return false;
    }

    bool BFS(vector<vector<char>>& grid,vector<vector<bool> >& vis,int x,int y){
        static int dir[4][2] = {1,0,-1,0,0,1,0,-1};
        queue<node> que;
        que.push(node(x,y,-1,-1));
        char ch = grid[x][y];

        while(!que.empty()){
            auto f = que.front();
            que.pop();

            for(int i = 0; i < 4; i++){
                int tx = f._x + dir[i][0];
                int ty = f._y + dir[i][1];

                if(tx < 0 || tx >= n || ty < 0 || ty >= m || 
                        (tx == f._pre.first && ty == f._pre.second) || grid[tx][ty] != ch)
                        continue;
                
                if(vis[tx][ty] == true) return true;

                vis[tx][ty] = true;
                que.push(node(tx,ty,f._x,f._y));
            }
        }
        //没有成环
        return false;
    } 
};
