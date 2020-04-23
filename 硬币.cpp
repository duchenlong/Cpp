//硬币。给定数量不限的硬币，币值为25分、10分、5分和1分，编写代码计算n分有几种表示法。(结果可能会很大，你需要将结果模上1000000007)

//示例1:

// 输入: n = 5
// 输出：2
// 解释: 有两种方式可以凑成总金额:
//5=5
//5=1+1+1+1+1
//示例2:

// 输入: n = 10
// 输出：4
// 解释: 有四种方式可以凑成总金额:
//10=10
//10=5+5
//10=5+1+1+1+1+1
//10=1+1+1+1+1+1+1+1+1+1

class Solution {
public:
    int waysToChange(int n) {
        vector<int> dp(n+1,0);
        dp[0] = 1;
        for(int i = 0; i < 4; i++){//币值
            int yuan = value[i];
            for(int j = yuan; j <= n; j++){
                dp[j] = (dp[j] + dp[j - yuan]) % mod;
            }
        }
        return dp[n];
    }
private:
    static const int mod = 1000000007;
    const int value[4] = {1,5,10,25};
};
