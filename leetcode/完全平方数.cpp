class Solution {
public:
    int numSquares(int n) {
        vector<int> f;      // 完全平方数
        for(int i = 1; i * i <= n; i++) f.push_back(i*i);

        // 背包问题 dp[n] 表示数字为n 时的最小个数
        // 完全背包，每个物品可以无限用
        int dp[n+1];
        memset(dp,0x3f,sizeof dp);
        dp[0] = 0;
        for(int i = 0; i < f.size(); i++) {
            for(int j = f[i]; j <= n; j++)
                dp[j] = min(dp[j],dp[j - f[i]] + 1);
        }

        return dp[n];
    }
};


给定正整数?n，找到若干个完全平方数（比如?1, 4, 9, 16, ...）使得它们的和等于 n。你需要让组成和的完全平方数的个数最少。

示例?1:

输入: n = 12
输出: 3 
解释: 12 = 4 + 4 + 4.
示例 2:

输入: n = 13
输出: 2
解释: 13 = 4 + 9.

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/perfect-squares
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
