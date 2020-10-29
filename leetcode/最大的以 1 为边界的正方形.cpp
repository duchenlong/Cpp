class Solution {
public:
    int largest1BorderedSquare(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        int dp[n+1][m+1][2]; // dp[i][j][0] 表示 i,j 向左可以延伸的1的数量，dp[i][j][1] 则表示向上延伸的1的数量
        memset(dp,0x00,sizeof dp);

        int ans = 0;
        for(int i = 1; i <= n; i++)
            for(int j = 1; j <= m; j++) {
                if(grid[i-1][j-1] == 0) continue;

                dp[i][j][0] = dp[i][j-1][0] + 1;    // 向左有多少连续的1
                dp[i][j][1] = dp[i-1][j][1] + 1;    // 向上有多少连续的1
                int len = min(dp[i][j][1],dp[i][j][0]);     // 最小边长

                for(int k = len; k > 0; k--) {
                    if(dp[i][j-k+1][1] < k || dp[i-k+1][j][0] < k) continue;
                    ans = max(ans,k * k);
                }
            }
        
        return ans;
    }
};

给你一个由若干 0 和 1 组成的二维网格?grid，请你找出边界全部由 1 组成的最大 正方形 子网格，并返回该子网格中的元素数量。如果不存在，则返回 0。

?

示例 1：

输入：grid = [[1,1,1],[1,0,1],[1,1,1]]
输出：9
示例 2：

输入：grid = [[1,1,0,0]]
输出：1
?

提示：

1 <= grid.length <= 100
1 <= grid[0].length <= 100
grid[i][j] 为?0?或?1

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/largest-1-bordered-square
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
