//给你一个由?'1'（陆地）和 '0'（水）组成的的二维网格，请你计算网格中岛屿的数量。

//岛屿总是被水包围，并且每座岛屿只能由水平方向和/或竖直方向上相邻的陆地连接形成。

//此外，你可以假设该网格的四条边均被水包围。

//示例 1:

//输入:
//11110
//11010
//11000
//00000
//输出:?1
//示例?2:

//输入:
//11000
//11000
//00100
//00011
//输出: 3
//解释: 每座岛屿只能由水平和/或竖直方向上相邻的陆地连接而成。


class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int ans = 0;
        int row = grid.size();
        if(row == 0)
            return 0;
        int col = grid[0].size();
        vector<vector<int> > visit(row, vector<int> (col,0));

        for(int i = 0; i < row; i++)
        {
            for(int j = 0; j < col; j++)
            {
                if(grid[i][j] == '0' || visit[i][j])
                    continue;

                visit[i][j] = 1;
                dfs(grid,visit,row,col,i,j);
                ans++;
            }
        }

        return ans;
    }

    void dfs(vector<vector<char>>& grid,vector<vector<int>>& visit, int row, int col,int r, int c)
    {
        static int dir[8][2] = {1,0,0,1,-1,0,0,-1};

        for(int i = 0; i < 4; i++)
        {
            int x = r + dir[i][0];
            int y = c + dir[i][1];
            if(x < 0 || x >= row || y < 0 || y >= col)
                continue;
            if(grid[x][y] == '0' ||  visit[x][y])
                continue;
            visit[x][y] = 1;
            dfs(grid,visit,row,col,x,y);
        }
    }
};
