class Solution {
public:
    int wiggleMaxLength1(vector<int>& nums) {
        int n = nums.size();
        if(n == 0)  return 0;
        int dp[n][2];
        memset(dp,0x00,sizeof(dp));
        dp[0][0] = 1;   //后两个元素为递减的最大长度
        dp[0][1] = 1;   //后两个元素为递增的最大长度
        int ans = 1;

        for(int i = 1; i < n; i++){
            dp[i][0] = 1;
            dp[i][1] = 1;

            for(int j = 0; j < i; j++){
                if(nums[i] > nums[j]) {
                    dp[i][1] = max(dp[j][0]+1, dp[i][1]);
                } else if (nums[i] < nums[j]) {
                    dp[i][0] = max(dp[j][1]+1, dp[i][0]);
                }

                ans = max(dp[i][0],dp[i][1]);
            }
        }

        return ans;
    }

    int wiggleMaxLength(vector<int>& nums) {
        int n = nums.size();
        if(n < 2) {
            return n;
        }

        int up = 1;
        int down = 1;
        for(int i = 1; i < n; i++){
            if(nums[i] > nums[i-1]) {
                up = down + 1;
            }

            if(nums[i] < nums[i-1]) {
                down = up + 1;
            }
        }

        return max(up,down);
    }
};
