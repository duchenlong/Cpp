//设想有个机器人坐在一个网格的左上角，网格 r 行 c 列。机器人只能向下或向右移动，但不能走到一些被禁止的网格（有障碍物）。设计一种算法，寻找机器人从左上角移动到右下角的路径。



//网格中的障碍物和空位置分别用 1 和 0 来表示。

//返回一条可行的路径，路径由经过的网格的行号和列号组成。左上角为 0 行 0 列。

//示例?1:

//输入:
//[
//? [0,0,0],
//? [0,1,0],
//? [0,0,0]
//]
//输出: [[0,0],[0,1],[0,2],[1,2],[2,2]]
//解释: 
//输入中标粗的位置即为输出表示的路径，即
//0行0列（左上角） -> 0行1列 -> 0行2列 -> 1行2列 -> 2行2列（右下角）


class Solution {
public:
	//动态规划 
    vector<vector<int>> pathWithObstacles(vector<vector<int>>& obstacleGrid) {
        vector<vector<int>> ans;

        int row = obstacleGrid.size();
        int col = obstacleGrid[0].size();
        if(!row || !col) return ans;
        //起点和终点不能是障碍
        if(obstacleGrid[0][0] || obstacleGrid[row-1][col-1]) return ans;

        int dp[row + 1][col + 1];
        dp[0][0] = 1;
        //初始化行
        for(int i = 1; i < col; i++)
            if(obstacleGrid[0][i]) dp[0][i] = 0;//如果当前位置是障碍，0表示不通
            else dp[0][i] = dp[0][i-1];//不是障碍的话需要顺延上1列
        //初始化第一列
        for(int i = 1; i < row; i++)
            if(obstacleGrid[i][0]) dp[i][0] = 0; //如果当前位置是障碍，0表示不通
            else dp[i][0] = dp[i-1][0];//不是障碍的话需要顺延上1行
        
        //动态规划
        for(int i = 1; i < row; i++)
            for(int j = 1; j < col; j++)
                if(obstacleGrid[i][j]) dp[i][j] = 0;//当前位置是障碍
                else dp[i][j] = max(dp[i-1][j], dp[i][j-1]);

        if(dp[row-1][col-1] == 0) return ans;//无法到达最后一个位置

        //从后向前回溯路径
        int r = row - 1;
        int c = col - 1;
        
        while(r!=0 || c!=0){
            ans.push_back({r,c});
            int left = 0;
            if(c > 0) left = dp[r][c-1];//找到当前位置左边的状态
            int up = 0;
            if(r > 0) up = dp[r-1][c];//找到当前位置右边的状态
            //left,up   1,0  0,1 1,1
            if(left >= up) c--;
            else r--;
        }
        ans.push_back({0,0});
        reverse(ans.begin(),ans.end());
        return ans;
    }


    //dfs  超时。。。。。。
    int row, col;
    int flag = false;
    int dir[2][2] = {0,1,1,0};
    vector<vector<int>> ans;
    vector<vector<int>> pathWithObstacles1(vector<vector<int>>& obstacleGrid) {
        row = obstacleGrid.size();
        col = obstacleGrid[0].size();
        vector<vector<int>> visit(row, vector<int> (col,0));
        dfs(obstacleGrid,visit,0,0,1);
        return ans;
    }

    void dfs(vector<vector<int>>& obstacleGrid, vector<vector<int>>& visit,int x, int y, int index){
         if(obstacleGrid[x][y])
            return;
        if(x == row-1 && y == col-1)
        {
            ans.push_back({x,y});
            flag = true;
            return ;
        }

        for(int i = 0; i < 2; i++){
            int tx = x + dir[i][0];
            int ty = y + dir[i][1];

            if(tx >= row || ty >= col)
                continue;
            if(visit[tx][ty] || obstacleGrid[tx][ty])
                continue;
            
            ans.push_back({x,y});
            dfs(obstacleGrid,visit,tx,ty,index+1);
            if(flag) return;
            ans.pop_back();
        }
    }
};
