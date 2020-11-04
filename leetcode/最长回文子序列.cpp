class Solution {
public:
    int longestPalindromeSubseq(string s) {
        int n = s.size();
        int f[n+1][n+1];
        memset(f,0x00,sizeof f);

        for(int i = 0; i <= n; i++) f[i][i] = 1;

        for(int i = n - 1; i > 0; i--)
            for(int j = i + 1; j <= n; j++) {
                if(s[i-1] == s[j-1]) f[i][j] = f[i+1][j-1] + 2;
                else f[i][j] = max(f[i+1][j],f[i][j-1]);
            }
        return f[1][n];
    }
};


给定一个字符串 s ，找到其中最长的回文子序列，并返回该序列的长度。可以假设 s 的最大长度为 1000 。

?

示例 1:
输入:

"bbbab"
输出:

4
一个可能的最长回文子序列为 "bbbb"。

示例 2:
输入:

"cbbd"
输出:

2
一个可能的最长回文子序列为 "bb"。

?

提示：

1 <= s.length <= 1000
s 只包含小写英文字母

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/longest-palindromic-subsequence
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
