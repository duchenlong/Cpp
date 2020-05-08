
//在一个由 0 和 1 组成的二维矩阵内，找到只包含 1 的最大正方形，并返回其面积。

//示例:

//输入: 

//1 0 1 0 0
//1 0 1 1 1
//1 1 1 1 1
//1 0 0 1 0

//输出: 4


class Solution {
public:
    //暴力遍历
    int maximalSquare1(vector<vector<char>>& matrix) {
        int ans = 0;
        int row = matrix.size();
        if(row <= 0) return 0;
        int col = matrix[0].size();
        for(int i = 0; i < row; i++)
            for(int j = 0; j < col; j++)
            {
                if(matrix[i][j] == '0')
                    continue;
                int area = slove(matrix,i,j,row,col);
                ans = max(area,ans);
            }
        
        return ans;
    }
    int slove(vector<vector<char> >& matrix,int x,int y,int row,int col)
    {
        int area = 1;
        int tx = x;
        int ty = y;
        while(tx+1 < row && ty + 1 < col)
        {
            tx++;
            ty++;
            int tmp = 0;
            //判断向下的
            for(int i = x; i <= tx; i++)
            {
                if(matrix[i][ty] == '0')
                    return area;
                tmp++;
            }

            //判断向左
            for(int j = y; j < ty; j++)
            {
                if(matrix[tx][j] == '0')
                    return area;
                tmp++;
            }
            area += tmp;
        }
        return area;
    }

    //动态规划
    int maximalSquare(vector<vector<char>>& matrix)
    {
        int ans = 0;
        int row = matrix.size();
        if(row <= 0) return 0;
        int col = matrix[0].size();

        //dp[i][j]   表示以matrix[i][j]为右下角元素的最大边长
        vector<vector<int>> dp(row,vector<int> (col,0));
        // for(int i = 0; i < col; i++)
        //     if(matrix[0][i] == '1')
        //     {
        //         dp[0][i] = 1;
        //         ans = 1;
        //     }
            
        // for(int j = 0; j < row; j++)
        //     if(matrix[j][0] == '1')
        //     {
        //         dp[j][0] = 1;
        //         ans = 1;
        //     }

        for(int i = 0; i < row; i++)
            for(int j = 0; j < col; j++)
                if(matrix[i][j] == '1')
                {
                    if(i==0 || j==0)
                        dp[i][j] = 1; 
                    else
                        dp[i][j] = Threemin(dp[i-1][j],dp[i-1][j-1],dp[i][j-1]) + 1;
                    
                    ans = max(dp[i][j],ans);
                }
        return ans * ans;
    }
    //三数取小
    int Threemin(int a,int b,int c)
    {
        return min(min(a,b),c);
    }
};
