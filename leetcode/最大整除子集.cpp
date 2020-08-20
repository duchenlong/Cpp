给出一个由无重复的正整数组成的集合，找出其中最大的整除子集，子集中任意一对 (Si，Sj) 都要满足：Si % Sj = 0 或 Sj % Si = 0。

如果有多个目标子集，返回其中任何一个均可。

?

示例 1:

输入: [1,2,3]
输出: [1,2] (当然, [1,3] 也正确)
示例 2:

输入: [1,2,4,8]
输出: [1,2,4,8]

class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        int n = nums.size();
        if(n < 2)   return nums;
        sort(nums.begin(),nums.end());

        vector<int> dp(n,1);
        for(int i = 1; i < n; i++)
            for(int j = 0; j < i; j++)
                if(nums[i] % nums[j] == 0) dp[i] = max(dp[i],dp[j]+1);
        
        int idx = 0;
        for(int i = 1; i < n; i++)
            if(dp[i] > dp[idx]) idx = i;
        
        int len = dp[idx];
        vector<int> ans(len,0);
        for(int i = idx; i >= 0; i--)
            if(nums[idx] % nums[i] == 0 && dp[i] == len)
            {
                len--;
                ans[len] = nums[i];
                idx = i;
            }
        return ans;
    }
};
