class Solution {
public:
    static const int N = 310;
    int dp[N][N]; // dp[i][j] 表示以 i,j 为右下角，可以构成的最大正方形的边长

    int countSquares(vector<vector<int>>& matrix) {
        memset(dp,0x00,sizeof dp);
        int ans = 0;
        int n = matrix.size();
        int m = matrix[0].size();

        for(int i = 0; i < n; i++)
            for(int j = 0; j < m; j++)
                if(matrix[i][j] == 1) {
                    dp[i+1][j+1] = Min(dp[i][j],dp[i+1][j],dp[i][j+1]) + 1;
                    ans += dp[i+1][j+1];
                }
        return ans;
    }

    inline int Min(int a,int b,int c) {
        return min(a,min(b,c));
    }
};

给你一个?m * n?的矩阵，矩阵中的元素不是 0 就是 1，请你统计并返回其中完全由 1 组成的 正方形 子矩阵的个数。

?

示例 1：

输入：matrix =
[
? [0,1,1,1],
? [1,1,1,1],
? [0,1,1,1]
]
输出：15
解释： 
边长为 1 的正方形有 10 个。
边长为 2 的正方形有 4 个。
边长为 3 的正方形有 1 个。
正方形的总数 = 10 + 4 + 1 = 15.
示例 2：

输入：matrix = 
[
  [1,0,1],
  [1,1,0],
  [1,1,0]
]
输出：7
解释：
边长为 1 的正方形有 6 个。 
边长为 2 的正方形有 1 个。
正方形的总数 = 6 + 1 = 7.
?

提示：

1 <= arr.length?<= 300
1 <= arr[0].length?<= 300
0 <= arr[i][j] <= 1

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/count-square-submatrices-with-all-ones
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
