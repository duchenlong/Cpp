总共有 n?个人和 40 种不同的帽子，帽子编号从 1 到 40 。

给你一个整数列表的列表?hats?，其中?hats[i]?是第 i?个人所有喜欢帽子的列表。

请你给每个人安排一顶他喜欢的帽子，确保每个人戴的帽子跟别人都不一样，并返回方案数。

由于答案可能很大，请返回它对?10^9 + 7?取余后的结果。

?

示例 1：

输入：hats = [[3,4],[4,5],[5]]
输出：1
解释：给定条件下只有一种方法选择帽子。
第一个人选择帽子 3，第二个人选择帽子 4，最后一个人选择帽子 5。
示例 2：

输入：hats = [[3,5,1],[3,5]]
输出：4
解释：总共有 4 种安排帽子的方法：
(3,5)，(5,3)，(1,3) 和 (1,5)
示例 3：

输入：hats = [[1,2,3,4],[1,2,3,4],[1,2,3,4],[1,2,3,4]]
输出：24
解释：每个人都可以从编号为 1 到 4 的帽子中选。
(1,2,3,4) 4 个帽子的排列方案数为 24 。
示例 4：

输入：hats = [[1,2,3],[2,3,5,6],[1,3,7,9],[1,8,9],[2,5,7]]
输出：111


class Solution {
public:
    const int mod = 1000000007;
    int numberWays1(vector<vector<int>>& hats) {
        int len = hats.size();//一共有len个人
        int maxhats = 0;
        //找一个帽子的最大编号
        for(auto& row : hats)
            for(auto& col : row)
                maxhats = max(maxhats,col);
        
        vector<vector<int> > tmp(maxhats + 1);
        //把人对应帽子变成帽子对应人
        for(int i = 0; i < len; i++)
            for(auto& col : hats[i])
                tmp[col].push_back(i);
        
        //dp[i][j] 前i个帽子，所有人的状态为j 的方案数
        //一共有10个人，每个人的状态就可以用 一个只有一个1的十位的二进制来表示  2的十次方  = 1024
        //全1 1111111111  表示都带着帽子
        //全0 0000000000  表示没有人戴帽子
        vector<vector<int> > dp(maxhats + 1, vector<int>(1<<len));
        dp[0][0] = 1;

        for(int i = 1; i <= maxhats; i++)
            for(int j = 0; j < (1<<len); j++)//0 -->  1<<len  表示了从没有一个人有帽子到全部人都带了帽子的状态
            {
                dp[i][j] = dp[i-1][j];//还没有使用这个帽子，顺延上一次的状态

                for(auto& k : tmp[i])//遍历第i个帽子可以带的人
                    if(j & (1<<k)) //这个人正好带着这个帽子
                        dp[i][j] = (dp[i-1][j ^ (1<<k)] + dp[i][j]) % mod;
                        //累加上前一个帽子时这个人不带帽子的符合的情况，使用异或来一步到位
            }
        
        return dp[maxhats][(1<<len) - 1];
    }

    int numberWays(vector<vector<int>>& hats) {
        int len = hats.size();//一共有len个人
        int maxhats = 0;
        //找一个帽子的最大编号
        for(auto& row : hats)
            for(auto& col : row)
                maxhats = max(maxhats,col);
        
        vector<vector<int> > tmp(maxhats + 1);
        //把人对应帽子变成帽子对应人
        for(int i = 0; i < len; i++)
            for(auto& col : hats[i])
                tmp[col].push_back(i);
        
        //dp[i] 表示当前状态为i的所有方案数
        vector<int> dp(1<<len);
        dp[0] = 1;

        for(int i = 1; i <= maxhats; i++)
            for(int j = (1<<len)-1; ~j; j--)//压缩为一维需要从后向前遍历，以确保每一次使用的数据都是上一次的数据
            {
                for(auto& k : tmp[i])//遍历第i个帽子可以带的人
                    if(j & (1<<k)) 
                        dp[j] = (dp[j - (1<<k)] + dp[j]) % mod;
            }
        
        return dp[(1<<len) - 1];
    }
};
