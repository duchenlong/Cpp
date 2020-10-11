class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int n = nums.size();
        int sum = 0;
        int maxN = INT_MIN;
        for(int i = 0; i < nums.size(); i++) {
            sum += nums[i];
            maxN = max(nums[i],maxN);
        }

        int ans = sum / 2;
        if((sum & 1) == 1 || maxN > ans) return false;
        
        
        vector<bool> dp(ans+1,false);
        // 初始化
        dp[0] = true;
        for(int i = 0; i < n; i++) 
            for(int j = ans; j >= nums[i]; j--){
                dp[j] = dp[j] || dp[j - nums[i]];
            }
                
        return dp[ans];
    }
};

给定一个只包含正整数的非空数组。是否可以将这个数组分割成两个子集，使得两个子集的元素和相等。

注意:

每个数组中的元素不会超过 100
数组的大小不会超过 200
示例 1:

输入: [1, 5, 11, 5]

输出: true

解释: 数组可以分割成 [1, 5, 5] 和 [11].
?

示例?2:

输入: [1, 2, 3, 5]

输出: false

解释: 数组不能分割成两个元素和相等的子集.

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/partition-equal-subset-sum
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
