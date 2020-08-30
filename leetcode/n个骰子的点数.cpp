把n个骰子扔在地上，所有骰子朝上一面的点数之和为s。输入n，打印出s的所有可能的值出现的概率。

?

你需要用一个浮点数数组返回答案，其中第 i 个元素代表这 n 个骰子所能掷出的点数集合中第 i 小的那个的概率。

?

示例 1:

输入: 1
输出: [0.16667,0.16667,0.16667,0.16667,0.16667,0.16667]
示例?2:

输入: 2
输出: [0.02778,0.05556,0.08333,0.11111,0.13889,0.16667,0.13889,0.11111,0.08333,0.05556,0.02778]
?

限制：

1 <= n <= 11。

class Solution {
public:
    vector<double> twoSum1(int n) {
        int dp[n+1][6*n+1];
        memset(dp,0x00,sizeof(dp));

        for(int i = 1; i <= 6; i++)
            dp[1][i] = 1;
        
        for(int i = 1; i <= n; i++)
            for(int j = i; j <= 6*n; j++)
                for(int k = 1; k <= 6; k++)
                    dp[i][j] += (j >= k) ? dp[i-1][j-k] : 0;
        
        int size = pow(6,n);
        vector<double> ans;
        for(int i = n; i <= 6*n; i++)
            ans.push_back((double)dp[n][i]/size);
        
        return ans;
    }


    vector<double> twoSum(int n) {
        int dp[6*n+1];
        memset(dp,0x00,sizeof(dp));

        for(int i = 1; i <= 6; i++)
            dp[i] = 1;
        
        for(int i = 2; i <= n; i++)
            for(int j = 6 * n; j > 0; j--){
                int tmp = 0;
                for(int k = 1; k <= 6; k++)
                    tmp += (j >= k) ? dp[j-k] : 0;
                dp[j] = tmp;
            }
                
        int size = pow(6,n);
        vector<double> ans;
        for(int i = n; i <= 6*n; i++)
            ans.push_back((double)dp[i]/size);
        
        return ans;
    }    
};
