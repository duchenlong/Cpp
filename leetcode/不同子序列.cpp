给定两个字符串S和T，返回S子序列等于T的不同子序列个数有多少个？
字符串的子序列是由原来的字符串删除一些字符（也可以不删除）在不改变相对位置的情况下的剩余字符（例如，"ACE"is a subsequence of"ABCDE"但是"AEC"不是）
例如：
S ="rabbbit", T ="rabbit"

class Solution {
public:
    /**
     * 
     * @param S string字符串 
     * @param T string字符串 
     * @return int整型
     */
    int numDistinct(string S, string T) {
        // write code here
        int n = S.size();
        int m = T.size();
        
        int dp[n+1][m+1];
        memset(dp,0x00,sizeof(dp));
        for(int i = 0; i <= n; i++)
            dp[i][0] = 1;
        
        for(int i = 1; i <= n; i++)
            for(int j = 1; j <= m; j++)
                if(S[i-1] == T[j-1])
                    dp[i][j] = dp[i-1][j] + dp[i-1][j-1];
                else
                    dp[i][j] = dp[i-1][j];
        
        return dp[n][m];
    }
};
