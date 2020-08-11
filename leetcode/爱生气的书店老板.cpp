今天，书店老板有一家店打算试营业?customers.length?分钟。每分钟都有一些顾客（customers[i]）会进入书店，所有这些顾客都会在那一分钟结束后离开。

在某些时候，书店老板会生气。 如果书店老板在第 i 分钟生气，那么 grumpy[i] = 1，否则 grumpy[i] = 0。 当书店老板生气时，那一分钟的顾客就会不满意，不生气则他们是满意的。

书店老板知道一个秘密技巧，能抑制自己的情绪，可以让自己连续?X 分钟不生气，但却只能使用一次。

请你返回这一天营业下来，最多有多少客户能够感到满意的数量。
?

示例：

输入：customers = [1,0,1,2,1,1,7,5], grumpy = [0,1,0,1,0,1,0,1], X = 3
输出：16
解释：
书店老板在最后 3 分钟保持冷静。
感到满意的最大客户数量 = 1 + 1 + 1 + 1 + 7 + 5 = 16.
?

提示：

1 <= X <=?customers.length ==?grumpy.length <= 20000
0 <=?customers[i] <= 1000
0 <=?grumpy[i] <= 1



class Solution {
public:
    int maxSatisfied(vector<int>& customers, vector<int>& grumpy, int X) {
        int ans = 0;
        int le = 0;
        int x_sum = 0;
        int t_sum = 0;
        for(int i = 0; i < grumpy.size(); i++)
        {
            ans += (grumpy[i]==0) ? customers[i] : 0;
            t_sum += grumpy[i] * customers[i];
            if(i - le + 1 == X)
            {
                x_sum = max(x_sum,t_sum);
                t_sum -= (grumpy[le] == 1) ? customers[le] : 0;
                le++;
            }
        }

        return ans + x_sum;
    }
};
