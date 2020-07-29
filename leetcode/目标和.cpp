给定一个非负整数数组，a1, a2, ..., an, 和一个目标数，S。现在你有两个符号?+?和?-。对于数组中的任意一个整数，你都可以从?+?或?-中选择一个符号添加在前面。

返回可以使最终数组和为目标数 S 的所有添加符号的方法数。

?

示例：

输入：nums: [1, 1, 1, 1, 1], S: 3
输出：5
解释：

-1+1+1+1+1 = 3
+1-1+1+1+1 = 3
+1+1-1+1+1 = 3
+1+1+1-1+1 = 3
+1+1+1+1-1 = 3

一共有5种方法让最终目标和为3。
?

提示：

数组非空，且长度不会超过 20 。
初始的数组的和不会超过 1000 。
保证返回的最终结果能被 32 位整数存下。

class Solution {
public:
    //dfs
    int findTargetSumWays1(vector<int>& nums, int s) {
        int n = nums.size();
        int sum = 0;
        for(auto& num : nums)
            sum += num;
        if(sum < s) return 0;

        int ans = 0;
        dfs(nums,s,0,n,ans);

        return ans;
    }

    void dfs(vector<int>& nums,int cur,int idx,int n,int& ans)
    {
        if(idx == n)
        {
            if(cur == 0)    ans++;
            return;
        }

        dfs(nums,cur+nums[idx],idx+1,n,ans);
        dfs(nums,cur-nums[idx],idx+1,n,ans);
    }

    //dp
    //sum(+) - sum(-) = target
    //sum(+) = target + sum(-)
    //sum(+) + sum(+) = target + sum(-) + sum(+)
    //2 * sum(+) = target + sum(num)
    int findTargetSumWays(vector<int>& nums, int s)
    {
        int sum = 0;
        for(auto& num : nums)
            sum += num;
        //target + sum(num)必须为偶数  
        if(sum < s || (sum + s) % 2 == 1)
            return 0;
        
        int n = (sum + s) / 2;
        vector<int> dp(n + 1,0);
        dp[0] = 1;
        
        for(auto& num : nums)
            for(int i = n; i >= num; i--)
                dp[i] += dp[i - num];
        return dp[n];
    }
};
