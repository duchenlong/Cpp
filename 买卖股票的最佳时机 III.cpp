//给定一个数组，它的第 i 个元素是一支给定的股票在第 i 天的价格。

//设计一个算法来计算你所能获取的最大利润。你最多可以完成?两笔?交易。

//注意:?你不能同时参与多笔交易（你必须在再次购买前出售掉之前的股票）。

//示例?1:

//输入: [3,3,5,0,0,3,1,4]
//输出: 6
//解释: 在第 4 天（股票价格 = 0）的时候买入，在第 6 天（股票价格 = 3）的时候卖出，这笔交易所能获得利润 = 3-0 = 3 。
//?    随后，在第 7 天（股票价格 = 1）的时候买入，在第 8 天 （股票价格 = 4）的时候卖出，这笔交易所能获得利润 = 4-1 = 3 。
//示例 2:

//输入: [1,2,3,4,5]
//输出: 4
//解释: 在第 1 天（股票价格 = 1）的时候买入，在第 5 天 （股票价格 = 5）的时候卖出, 这笔交易所能获得利润 = 5-1 = 4 。 ? 
//?    注意你不能在第 1 天和第 2 天接连购买股票，之后再将它们卖出。 ? 
//?    因为这样属于同时参与了多笔交易，你必须在再次购买前出售掉之前的股票。
//示例 3:

//输入: [7,6,4,3,1] 
//输出: 0 
//解释: 在这个情况下, 没有交易完成, 所以最大利润为 0。


class Solution {
public:
    int maxProfit1(vector<int>& prices) {
        int len = prices.size();
        if(len < 2) return 0;
        int k = 2;
        int dp[len][k+1][2];
        memset(dp,0,sizeof(dp));

        for(int i = 0; i < len; i++)
                for(int j = k; j > 0; j--)
                    if(i == 0)
                    {
                        //0 表示不买，手里没有股票  1  表示买当前股票
                        dp[i][j][0] = 0;
                        dp[i][j][1] = 0 - prices[i];
                    }
                    else
                    {
                        //当前手里没有股票  前一天就没有      前一天给卖了
                        dp[i][j][0] = max(dp[i-1][j][0],dp[i-1][j][1] + prices[i]);
                        //当前手里有股票，，股票是前一天的       股票是今天买的
                        dp[i][j][1] = max(dp[i-1][j][1],dp[i-1][j-1][0] - prices[i]);
                    }
        return dp[len-1][k][0];
    }

    int maxProfit(vector<int>& prices)
    {
        int len = prices.size();
        if(len < 2) return 0;
        int oneBuy = INT_MIN;//第一次买入的最大收益
        int oneSell = 0;    //第一次卖出的最大收益

        int twoBuy = INT_MIN;//第二次买入的最大收益
        int twoSell = 0;    //第二次卖出的最大收益

        for(int i = 0; i < len; i++)
        {
            int yuan = prices[i];
            oneBuy = max(oneBuy,0-yuan);
            oneSell = max(oneSell,oneBuy+yuan);

            twoBuy = max(twoBuy,oneSell - yuan);
            twoSell = max(twoSell,twoBuy+yuan);
        }
        return twoSell;
    }
};
