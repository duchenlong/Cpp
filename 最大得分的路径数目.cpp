给你一个正方形字符数组?board?，你从数组最右下方的字符?'S'?出发。

你的目标是到达数组最左上角的字符?'E' ，数组剩余的部分为数字字符?1, 2, ..., 9?或者障碍 'X'。在每一步移动中，你可以向上、向左或者左上方移动，可以移动的前提是到达的格子没有障碍。

一条路径的 「得分」 定义为：路径上所有数字的和。

请你返回一个列表，包含两个整数：第一个整数是 「得分」 的最大值，第二个整数是得到最大得分的方案数，请把结果对?10^9 + 7 取余。

如果没有任何路径可以到达终点，请返回?[0, 0] 。

?

示例 1：

输入：board = ["E23","2X2","12S"]
输出：[7,1]
示例 2：

输入：board = ["E12","1X1","21S"]
输出：[4,2]
示例 3：

输入：board = ["E11","XXX","11S"]
输出：[0,0]


class Solution {
public:
    const int mod = 1000000007;
    vector<int> pathsWithMaxScore(vector<string>& board) {
        int row = board.size();
        int col = board[0].size();

        vector<vector<int> > dp(row, vector<int> (col,0));
        vector<vector<int> > dp2(row, vector<int> (col,0));
        
        dp2[row-1][col-1] = 1;
        //初始化最后一行
        for(int i = col-1; i > 0; i--)
            if(board[row-1][i-1] != 'X')
            {
                dp[row-1][i-1] = (board[row-1][i-1] - '0' + dp[row-1][i]) % mod;
                dp2[row-1][i-1] = 1;

            }
            else break;

        //最后一列
        for(int i = row-1; i > 0; i--)
            if(board[i-1][col-1] != 'X')
            {
                dp[i-1][col-1] = (board[i-1][col-1] - '0' + dp[i][col-1]) % mod;
                dp2[i-1][col-1] = 1;
            }
            else break;

        for(int i = row-2; i >= 0; i--)
            for(int j = col-2; j >= 0; j--)
            {
                if(board[i][j] == 'X')  continue;
                int a = dp[i+1][j];
                int b = dp[i][j+1];
                int c = dp[i+1][j+1];
                int maxNum = max(max(a,b),c);
               
                int d = dp2[i+1][j];
                int e = dp2[i][j+1];
                int f = dp2[i+1][j+1];

                //防止出现不通的路
                if(maxNum == 0 && d == 0 && e == 0 && f == 0)
                {
                    dp[i][j] = 0;
                    dp2[i][j] = 0;
                    continue;
                }

                //得分，dp
                dp[i][j] = (maxNum % mod + ((board[i][j] == 'E') ?  0 : (board[i][j] - '0'))) % mod; 

                //分数最高的路径
                if(a==max(max(a,b),c))
                    dp2[i][j] += dp2[i+1][j]%mod;
                if(b==max(max(a,b),c))
                    dp2[i][j] += dp2[i][j+1]%mod;
                if(c==max(max(a,b),c))
                    dp2[i][j] += dp2[i+1][j+1]%mod;
            }
        
        return {dp[0][0],dp2[0][0] % mod};
    }
};
