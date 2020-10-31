class Solution {
public:
    const int mod = 1e9 + 7;
    int countPalindromicSubsequences(string s) {
        int n = s.size();
        int dp[n+1][n+1];
        memset(dp,0x00,sizeof dp);
        for(int i = 1; i <= n; i++) dp[i][i] = 1;   // i-i组成的回文串为1个

        for(int len = 2; len <= n; len ++)  // 区间长度
            for(int i = 1; i <= n; i ++) {  // 子区间起点
                int j = i + len - 1;
                if(j > n) break;
                if(s[i-1] != s[j-1]) {
                    dp[i][j] = (dp[i + 1][j] + dp[i][j - 1]) % mod ;
                    dp[i][j] = (dp[i][j] + (mod - dp[i + 1][j - 1]) % mod) % mod ;
                    continue;
                }

                // s[i-1] == s[j-1]
                int le = i + 1, ri = j - 1;
                while(le < j && s[le - 1] != s[i - 1]) le++;
                while(ri > i && s[ri - 1] != s[i - 1]) ri--;

                // +2 是因为 s[i-1]， s[i-1]s[j-1] 也就是比中间区间多了2个回文
                if(ri < le) dp[i][j] = (dp[i+1][j-1]*2 + 2) % mod;          // i-j 没有和 s[i-1]相同的字母，aba
                else if(le == ri) dp[i][j] = (dp[i+1][j-1] * 2 + 1) % mod;  // 只有一个相同字母  aaa
                else dp[i][j] = (dp[i + 1][j - 1] * 2 % mod + (mod - dp[le + 1][ri - 1])) % mod ;  // 至少2个
            }

        return dp[1][n];
    }
};

给定一个字符串 S，找出 S 中不同的非空回文子序列个数，并返回该数字与 10^9 + 7 的模。

通过从 S 中删除 0 个或多个字符来获得子序列。

如果一个字符序列与它反转后的字符序列一致，那么它是回文字符序列。

如果对于某个??i，A_i != B_i，那么?A_1, A_2, ... 和?B_1, B_2, ... 这两个字符序列是不同的。

?

示例 1：

输入：
S = 'bccb'
输出：6
解释：
6 个不同的非空回文子字符序列分别为：'b', 'c', 'bb', 'cc', 'bcb', 'bccb'。
注意：'bcb' 虽然出现两次但仅计数一次。
示例 2：

输入：
S = 'abcdabcdabcdabcdabcdabcdabcdabcddcbadcbadcbadcbadcbadcbadcbadcba'
输出：104860361
解释：
共有 3104860382 个不同的非空回文子序列，对 10^9 + 7 取模为 104860361。
?

提示：

字符串?S?的长度将在[1, 1000]范围内。
每个字符?S[i]?将会是集合?{'a', 'b', 'c', 'd'}?中的某一个。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/count-different-palindromic-subsequences
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
