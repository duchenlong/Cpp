class Solution {
public:
    int countNumbersWithUniqueDigits(int n) {
        if(n == 0) return 1;
        else if(n == 10) return 10;

        int dp[n + 1];        // dp[i] 表示第 i 位有多少不同的数字x的个数
        memset(dp,0x00,sizeof dp);
        dp[0] = 1;
        dp[1] = 10;
        // n == 0  0        ans = 1;
        // n == 1  1~9      ans = 9 + dp[0]
        // n == 2  十位 1~9  对应的个位有 0~9 - 1 种情况  ans = 9 * 9 + dp[1]
        // n == 3  百位 1~9  对应的十位有 0~9 - 1 种情况  个位有0~9 - 2 种情况  ans = 9 * 9 * 8 + dp[2]

        // dp[i] = dp[i-1] + (单单前一种状态中，不同的数字个数) * 当前位的情况
        for(int i = 2; i <= n; i++) dp[i] = dp[i - 1] + (dp[i - 1] - dp[i - 2]) * (10 - i + 1);

        return dp[n];
    }
};

给定一个非负整数 n，计算各位数字都不同的数字 x 的个数，其中 0 ≤ x < 10n?。

示例:

输入: 2
输出: 91 
解释: 答案应为除去 11,22,33,44,55,66,77,88,99 外，在 [0,100) 区间内的所有数字。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/count-numbers-with-unique-digits
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
