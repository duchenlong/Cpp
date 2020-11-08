class Solution {
public:
    const int mod = 1e9 + 7;
    int distinctSubseqII(string s) {
        int n = s.size();
        int f[n+1],last[26];
        memset(f,0x00,sizeof f);
        memset(last,0x00,sizeof last);
        
        f[0] = 0;
        f[1] = 1; last[s[0] - 'a'] = 1;
        for(int i = 2; i <= n; i++) {
            char idx = s[i - 1] - 'a';
            f[i] = (f[i - 1] * 2 + 1) % mod;

            if(last[idx] != 0) {        // last[idx]为计算上一个相同字符出现的位置，-1 为前一个位置
                f[i] = (f[i] - f[last[idx] - 1] - 1 + mod) % mod;
            }
            last[idx] = i; 
        }

        return f[n];
    }
};


给定一个字符串?S，计算?S?的不同非空子序列的个数。

因为结果可能很大，所以返回答案模 10^9 + 7.

?

示例 1：

输入："abc"
输出：7
解释：7 个不同的子序列分别是 "a", "b", "c", "ab", "ac", "bc", 以及 "abc"。
示例 2：

输入："aba"
输出：6
解释：6 个不同的子序列分别是 "a", "b", "ab", "ba", "aa" 以及 "aba"。
示例 3：

输入："aaa"
输出：3
解释：3 个不同的子序列分别是 "a", "aa" 以及 "aaa"。
?

?

提示：

S?只包含小写字母。
1 <= S.length <= 2000

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/distinct-subsequences-ii
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
