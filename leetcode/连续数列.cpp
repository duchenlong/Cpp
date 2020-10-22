class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int ans = INT_MIN;
        int le = -1;
        int sum = 0;

        for(int i = 0; i < nums.size(); i++) {
            sum += nums[i];
            
            while(le < i && sum < nums[i]) sum -= nums[++le];
            ans = max(ans,sum);
        }

        return ans;
    }
};

给定一个整数数组，找出总和最大的连续数列，并返回总和。

示例：

输入： [-2,1,-3,4,-1,2,1,-5,4]
输出： 6
解释： 连续子数组 [4,-1,2,1] 的和最大，为 6。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/contiguous-sequence-lcci
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
