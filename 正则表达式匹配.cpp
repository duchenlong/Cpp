给你一个字符串?s?和一个字符规律?p，请你来实现一个支持 '.'?和?'*'?的正则表达式匹配。

'.' 匹配任意单个字符
'*' 匹配零个或多个前面的那一个元素
所谓匹配，是要涵盖?整个?字符串?s的，而不是部分字符串。

说明:

s?可能为空，且只包含从?a-z?的小写字母。
p?可能为空，且只包含从?a-z?的小写字母，以及字符?.?和?*。
示例 1:

输入:
s = "aa"
p = "a"
输出: false
解释: "a" 无法匹配 "aa" 整个字符串。
示例 2:

输入:
s = "aa"
p = "a*"
输出: true
解释:?因为 '*' 代表可以匹配零个或多个前面的那一个元素, 在这里前面的元素就是 'a'。因此，字符串 "aa" 可被视为 'a' 重复了一次。
示例?3:

输入:
s = "ab"
p = ".*"
输出: true
解释:?".*" 表示可匹配零个或多个（'*'）任意字符（'.'）。
示例 4:

输入:
s = "aab"
p = "c*a*b"
输出: true
解释:?因为 '*' 表示零个或多个，这里 'c' 为 0 个, 'a' 被重复一次。因此可以匹配字符串 "aab"。
示例 5:

输入:
s = "mississippi"
p = "mis*is*p*."
输出: false

class Solution {
public:
    bool isMatch(string s, string p) {
        int n = s.size();
        int m = p.size();

        auto check = [&](int i,int j)
        {
            if(p[j] == '.')
                return true;
            return s[i] == p[j];
        };

        //dp[i][j] == s的前i个字符 和 p 的前j个字符是匹配的
        vector<vector<int> > dp(n + 1,vector<int> (m + 1,0));
        dp[0][0] = 1;
        //初始化第一列
        for(int j = 1; j <= m; j++)
            if(p[j-1] == '*')   dp[0][j] = dp[0][j-2];

        for(int i = 1; i <= n; i++)
            for(int j = 1; j <= m; j++)
            {
                if(p[j-1] == '*')
                {
                    dp[i][j] = dp[i][j-2];//使用0次 * 匹配
                    //使用*匹配，*前面是 . 或者 和 s[i-1]相等
                    if(check(i-1,j-2))
                        dp[i][j] |= dp[i-1][j]; 
                }
                else if(check(i-1,j-1))
                    dp[i][j] = dp[i-1][j-1];
            }

        return dp[n][m];
    }
};
