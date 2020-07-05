给你一个只包含 0 和 1 的?rows * columns?矩阵?mat?，请你返回有多少个?子矩形?的元素全部都是 1 。

?

示例 1：

输入：mat = [[1,0,1],
?           [1,1,0],
?           [1,1,0]]
输出：13
解释：
有 6?个 1x1 的矩形。
有 2 个 1x2 的矩形。
有 3 个 2x1 的矩形。
有 1 个 2x2 的矩形。
有 1 个 3x1 的矩形。
矩形数目总共 = 6 + 2 + 3 + 1 + 1 = 13?。
示例 2：

输入：mat = [[0,1,1,0],
?           [0,1,1,1],
?           [1,1,1,0]]
输出：24
解释：
有 8 个 1x1 的子矩形。
有 5 个 1x2 的子矩形。
有 2 个 1x3 的子矩形。
有 4 个 2x1 的子矩形。
有 2 个 2x2 的子矩形。
有 2 个 3x1 的子矩形。
有 1 个 3x2 的子矩形。
矩形数目总共 = 8 + 5 + 2 + 4 + 2 + 2 + 1 = 24 。
示例 3：

输入：mat = [[1,1,1,1,1,1]]
输出：21
示例 4：

输入：mat = [[1,0,1],[0,1,0],[1,0,1]]
输出：5
?

提示：

1 <= rows?<= 150
1 <= columns?<= 150
0 <= mat[i][j] <= 1


class Solution {
public:
    int numSubmat(vector<vector<int>>& mat) {
        int n = mat.size();
        int m = mat[0].size();
        vector<vector<int> > dp(n+1,vector<int>(m+1,0));

        for(int i = 1; i <= n; i++)
            for(int j = 1; j <= m; j++)
                dp[i][j] = (mat[i-1][j-1] == 0) ? 0 : 1 + dp[i][j-1];
        
        int ans = 0;
        for(int i = 1; i <= n; i++)
            for(int j = 1;j <= m; j++)
            {
                int minCol = INT_MAX;//以 i,j为右下角的矩形的水平宽度
                for(int k = i; k > 0; k--)//矩形的高度
                {
                    minCol = min(minCol,dp[k][j]);
                    ans += minCol;
                    if(minCol == 0)  break;
                }
            }
        return ans;
    }
};
