//假设你正在爬楼梯。需要 n 阶你才能到达楼顶。

//每次你可以爬 1 或 2 个台阶。你有多少种不同的方法可以爬到楼顶呢？

//注意：给定 n 是一个正整数。

class Solution {
public:
    //递归
    int climbStairs1(int n) {
        if(n < 3)
            return n;
        return climbStairs(n-1) + climbStairs(n-2);
    }
    //动态规划
    int climbStairs(int n) {
        if(n < 3)
            return n;
        int* dp = (int*)malloc(sizeof(int) * n);
        dp[0] = 1;
        dp[1] = 2;
        for(int i = 2; i < n; i++)
        {
            dp[i] = dp[i-1] + dp[i-2];
        }
        int num = dp[n-1];
        free(dp);
        return num;
    }
};
