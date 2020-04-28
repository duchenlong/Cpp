//给定一个整数数组 nums?，找到一个具有最大和的连续子数组（子数组最少包含一个元素），返回其最大和。

//示例:

//输入: [-2,1,-3,4,-1,2,1,-5,4],
//输出: 6
//解释:?连续子数组?[4,-1,2,1] 的和最大，为?6。



class Solution {
public:
    //遍历O(n)
    int maxSubArray1(vector<int>& nums) {
        int sum = 0;
        int ans = INT_MIN;

        for(auto& eoch : nums) {
            if(sum > 0) sum += eoch;
            else sum = eoch;

            ans = max(sum,ans);
        }

        return ans;
    }
    //动态规划
    int maxSubArray2(vector<int>& nums) {
        int len = nums.size();
        vector<int> dp(len,0);

        dp[0] = nums[0];
        int ans = dp[0];

        for(int i = 1; i < len; i++) {
            dp[i] = max(dp[i-1] + nums[i], nums[i]);
            ans = max(dp[i], ans);
        }
        return ans;
    }
    //分治 O(Nlogn)
    int maxSubArray(vector<int>& nums) {
        int len = nums.size();
        if(len == 0) return 0;
        return merger(nums,0,len-1);
    }
    //计算左右区间连接起来后的新区间，最长子序列的大小
    int AddMerger(vector<int>& nums,int left, int mid, int right) {
        //左边区间应该以mid中间点为起点
        int sum = 0;
        int leftSum = INT_MIN;
        for(int i = mid; i >= left; i--){
            sum += nums[i];
            leftSum = max(leftSum,sum);
        }

        sum = 0;
        int rightSum = INT_MIN;
        //y右边区间以mid+1为起点
        for(int i = mid+1; i <= right; i++) {
            sum += nums[i];
            rightSum = max(rightSum,sum);
        }
        return leftSum + rightSum;
    }

    int merger(vector<int>& nums, int left, int right){
        if(left == right) return nums[left];

        int mid = left + (right - left) / 2;
        return max3(merger(nums,left,mid),
                    merger(nums,mid+1,right),
                    AddMerger(nums,left,mid,right));
    }

    int max3(int a,int b,int c){
        return max(a,max(b,c));
    }
};
