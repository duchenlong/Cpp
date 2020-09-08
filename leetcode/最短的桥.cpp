在给定的二维二进制数组?A?中，存在两座岛。（岛是由四面相连的 1 形成的一个最大组。）

现在，我们可以将?0?变为?1，以使两座岛连接起来，变成一座岛。

返回必须翻转的?0 的最小数目。（可以保证答案至少是 1。）

?

示例 1：

输入：[[0,1],[1,0]]
输出：1
示例 2：

输入：[[0,1,0],[0,0,0],[0,0,1]]
输出：2
示例 3：

输入：[[1,1,1,1,1],[1,0,0,0,1],[1,0,1,0,1],[1,0,0,0,1],[1,1,1,1,1]]
输出：1
?

提示：

1 <= A.length =?A[0].length <= 100
A[i][j] == 0 或?A[i][j] == 1


class Solution {
public:
    int n,m;
    vector<vector<bool> > vis;
    using key = pair<int,int>;
    int dir[4][2] = {1,0,-1,0,0,1,0,-1};

    int shortestBridge(vector<vector<int>>& A) {
        n = A.size();
        m = A[0].size();
        vis = vector<vector<bool> > (n,vector<bool> (m,false));

        queue<key> que;
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(A[i][j] == 1) {
                    dfs(que,A,i,j); //  dfs标记一个岛屿
                    return bfs(que,A);  //bfs求最近距离
                }
            }
        }
        return -1;
    }

    void dfs(queue<key>& que,vector<vector<int> >& A,int x,int y) {
        que.push(make_pair(x,y));
        vis[x][y] = true;
        
        for(int i = 0; i < 4; i++) {
            int tx = dir[i][0] + x;
            int ty = dir[i][1] + y;
            if(tx < 0 || tx >= n || ty < 0 || ty >= m || vis[tx][ty] || A[tx][ty] == 0) continue;

            dfs(que,A,tx,ty);
        }
    }

    int bfs(queue<key>& que,vector<vector<int> >& A) {
        int ret = 0;
        while(que.empty() == false) {
            int size = que.size();

            while(size--) {
                auto f = que.front();
                que.pop();

                for(int i = 0; i < 4; i++) {
                    int tx = dir[i][0] + f.first;
                    int ty = dir[i][1] + f.second;
                    if(tx < 0 || tx >= n || ty < 0 || ty >= m || vis[tx][ty]) continue;

                    if(A[tx][ty] == 1) return ret;
                    vis[tx][ty] = true;
                    que.push(make_pair(tx,ty));
                }
            }
            ret++;
        }

        return ret;
    }
};
