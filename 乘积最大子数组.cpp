//给你一个整数数组 nums?，请你找出数组中乘积最大的连续子数组（该子数组中至少包含一个数字），并返回该子数组所对应的乘积。

//?

//示例 1:

//输入: [2,3,-2,4]
//输出: 6
//解释:?子数组 [2,3] 有最大乘积 6。
//示例 2:

//输入: [-2,0,-1]
//输出: 0
//解释:?结果不能为 2, 因为 [-2,-1] 不是子数组。


class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int len = nums.size();
        if(len < 1) return 0;
        
        int Nmax = nums[0];
        int Nmin = nums[0];
        int ans = nums[0];

        for(int i = 1; i < len; i++)
        {
            int n = nums[i];
            int tmp = Nmax;

            //防止出现两个负数的情况
            Nmax = max(max(n*Nmax,n),Nmin*n);
            //如果前面只有一个负数，那么情况Nmin的最小值到i这里一定时连续的
            //而他最大数的范围一定是从上一个负数后面转移过来的
            Nmin = min(min(n*tmp,n),Nmin*n);

            ans = max(Nmax,ans);
        }

        return ans;
    }
};
