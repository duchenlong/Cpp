class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        int n = prices.size();
        //if(k == 0 || n < 2) return 0;

        if(k >= n / 2) return Fun(prices,n);

        int f[n][k+1][2];
        memset(f,0x00,sizeof f);
        for(int j = k; j > 0; j--) {
            f[0][j][0] = 0;
            f[0][j][1] = -prices[0];
        }
        
        for(int i = 1; i < n; i++)
            for(int j = k; j > 0; j--) {
                f[i][j][0] = max(f[i - 1][j][0], f[i-1][j][1] + prices[i]);
                f[i][j][1] = max(f[i - 1][j][1], f[i-1][j-1][0] - prices[i]);
            }

        return f[n-1][k][0];
    }

    int Fun(vector<int>& prices,int n) {
        int res = 0;
        for(int i = 1; i < n; i++) {
            if(prices[i] > prices[i - 1]) {
                res += prices[i] - prices[i - 1];
            }
        }

        return res;
    }
};
给定一个整数数组?prices ，它的第 i 个元素?prices[i] 是一支给定的股票在第 i 天的价格。

设计一个算法来计算你所能获取的最大利润。你最多可以完成 k 笔交易。

注意：你不能同时参与多笔交易（你必须在再次购买前出售掉之前的股票）。

?

示例 1：

输入：k = 2, prices = [2,4,1]
输出：2
解释：在第 1 天 (股票价格 = 2) 的时候买入，在第 2 天 (股票价格 = 4) 的时候卖出，这笔交易所能获得利润 = 4-2 = 2 。
示例 2：

输入：k = 2, prices = [3,2,6,5,0,3]
输出：7
解释：在第 2 天 (股票价格 = 2) 的时候买入，在第 3 天 (股票价格 = 6) 的时候卖出, 这笔交易所能获得利润 = 6-2 = 4 。
     随后，在第 5 天 (股票价格 = 0) 的时候买入，在第 6 天 (股票价格 = 3) 的时候卖出, 这笔交易所能获得利润 = 3-0 = 3 。
?

提示：

0 <= k <= 109
0 <= prices.length <= 1000
0 <= prices[i] <= 1000

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/best-time-to-buy-and-sell-stock-iv
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
