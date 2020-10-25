class Solution {
public:
    int maxSumDivThree(vector<int>& nums) {
        int n = nums.size();
        int dp[n+1][3];
        memset(dp,0x00,sizeof dp);
        dp[0][0] = 0;
        dp[0][1] = dp[0][2] = INT_MIN;

        for(int i = 1; i <= n; i++)
            if(nums[i - 1] % 3 == 0) {
                dp[i][0] = max(dp[i - 1][0], dp[i - 1][0] + nums[i-1]);
                dp[i][1] = max(dp[i - 1][1], dp[i - 1][1] + nums[i-1]);
                dp[i][2] = max(dp[i - 1][2], dp[i - 1][2] + nums[i-1]);
            } else if(nums[i - 1] % 3 == 1) {
                dp[i][0] = max(dp[i - 1][0], dp[i - 1][2] + nums[i-1]);
                dp[i][1] = max(dp[i - 1][1], dp[i - 1][0] + nums[i-1]);
                dp[i][2] = max(dp[i - 1][2], dp[i - 1][1] + nums[i-1]);
            } else if(nums[i - 1] % 3 == 2) {
                dp[i][0] = max(dp[i - 1][0], dp[i - 1][1] + nums[i-1]);
                dp[i][1] = max(dp[i - 1][1], dp[i - 1][2] + nums[i-1]);
                dp[i][2] = max(dp[i - 1][2], dp[i - 1][0] + nums[i-1]);
            }
        
        return dp[n][0];
    }
};

给你一个整数数组?nums，请你找出并返回能被三整除的元素最大和。

?

示例 1：

输入：nums = [3,6,5,1,8]
输出：18
解释：选出数字 3, 6, 1 和 8，它们的和是 18（可被 3 整除的最大和）。
示例 2：

输入：nums = [4]
输出：0
解释：4 不能被 3 整除，所以无法选出数字，返回 0。
示例 3：

输入：nums = [1,2,3,4,4]
输出：12
解释：选出数字 1, 3, 4 以及 4，它们的和是 12（可被 3 整除的最大和）。
?

提示：

1 <= nums.length <= 4 * 10^4
1 <= nums[i] <= 10^4

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/greatest-sum-divisible-by-three
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
