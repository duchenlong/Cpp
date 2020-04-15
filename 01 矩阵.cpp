//给定一个由 0 和 1 组成的矩阵，找出每个元素到最近的 0 的距离。

//两个相邻元素间的距离为 1 。

//示例 1:
//输入:

//0 0 0
//0 1 0
//0 0 0
//输出:

//0 0 0
//0 1 0
//0 0 0
//示例 2:
//输入:

//0 0 0
//0 1 0
//1 1 1
//输出:

//0 0 0
//0 1 0
//1 2 1
//注意:
//给定矩阵的元素个数不超过 10000。
//给定矩阵中至少有一个元素是 0。
//矩阵中的元素只在四个方向上相邻: 上、下、左、右。


class Solution {
public:
    //BFS
    vector<vector<int>> updateMatrix1(vector<vector<int>>& matrix) {
        int row = matrix.size();
        int col = matrix[0].size();
        vector<vector<int> > ans(row, vector<int> (col,-1));
        int count = row * col;//未统计的格子数

        queue<node> que;
        //先把所有距离为0的格子入队
        for(int i = 0; i < row; i++)
            for(int j = 0; j < col; j++)
                if(matrix[i][j] == 0)
                {
                    count--;
                    que.push(GetNode(i,j));
                    ans[i][j] = 0;
                }
                    
        int path = 1;
        while(count && !que.empty())
        {
            //找当前path步的格子
            int size = que.size();
            for(int i = 0; i < size; i++)
            {
                node n = que.front();
                que.pop();

                static int dir[4][2] = {1,0,-1,0,0,1,0,-1};
                for(int j = 0; j < 4; j++)
                {
                    int tx = n._row + dir[j][0];
                    int ty = n._col + dir[j][1];

                    //判断是否越界
                    if(tx < 0 || tx >= row || ty < 0 || ty >= col)
                        continue;
                    //判断当前位置是否访问过
                    if(ans[tx][ty] != -1)
                        continue;
                    ans[tx][ty] = path;
                    que.push(GetNode(tx,ty));
                    count--;
                }
            }
            path++;
        }
        return ans;

    }

    typedef struct node{
        int _row;
        int _col;
    }node;

    node GetNode(int row,int col)
    {
        node n;
        n._col = col;
        n._row = row;
        return n;
    }
    //动态规划
    vector<vector<int>> updateMatrix(vector<vector<int>>& matrix) {
        int row = matrix.size();
        int col = matrix[0].size();
        vector<vector<int> > dp(row, vector<int>(col,0));

        //判断左，上两个方向
        for(int i = 0; i < row; i++)
            for(int j = 0; j < col; j++)
            {
                if(matrix[i][j])//先把1都初始化为最大值
                    dp[i][j] = 0x0000ffff;
                //判断左，上
                if(dp[i][j])
                {
                    if(i > 0)
                        dp[i][j] = min(dp[i][j],dp[i-1][j]+1);//左方
                    if(j > 0)
                        dp[i][j] = min(dp[i][j],dp[i][j-1]+1);//上方
                }
            }
        
        //判断右，下
        for(int i = row - 1; i >= 0; i--)
            for(int j = col - 1; j >= 0; j--)
            {
                if(dp[i][j])
                {
                    if(i+1 < row)
                        dp[i][j] = min(dp[i][j], dp[i+1][j]+1);
                    if(j+1 < col)
                        dp[i][j] = min(dp[i][j],dp[i][j+1]+1);
                }
            }
        return dp;
    }
};
