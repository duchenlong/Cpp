//给定不同面额的硬币 coins 和一个总金额 amount。编写一个函数来计算可以凑成总金额所需的最少的硬币个数。如果没有任何一种硬币组合能组成总金额，返回?-1。

//?

//示例?1:

//输入: coins = [1, 2, 5], amount = 11
//输出: 3 
//解释: 11 = 5 + 5 + 1
//示例 2:

//输入: coins = [2], amount = 3
//输出: -1
//?

//说明:
//你可以认为每种硬币的数量是无限的。



class Solution {
public:
    int coinChange1(vector<int>& coins, int amount) {
        vector<int> ans(amount+1,amount+1);
        ans[0] = 0;
        for(int i = 1; i <= amount; i++)
        {
            for(auto& eoch : coins)
            {
                if(eoch > i) continue;
                ans[i] = min(ans[i],ans[i-eoch] + 1);
            }
        }
        return ans[amount]==amount+1 ? -1 : ans[amount];
    }
    //深搜
    int coinChange(vector<int>& coins, int amount) 
    {
        sort(coins.begin(),coins.end());
        int ans = INT_MAX;
        dfs(coins,amount,0,ans,coins.size()-1);
        return ans == INT_MAX ? -1 : ans;
    } 
    //amount 需要的价值  value当前价值
    void dfs(vector<int>& coins, int amount,int value,int& ans,int index)
    {
        if(index < 0 || value + amount / coins[index] >= ans)
            return;
        if(amount % coins[index] == 0)
        {
            ans = min(ans,value + amount / coins[index]);
            return ;
        }

        for(int i = amount / coins[index]; ~i; i--)
            dfs(coins,amount-i*coins[index],value+i,ans,index-1);
    }
};
