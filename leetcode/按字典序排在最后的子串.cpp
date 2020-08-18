给你一个字符串?s，找出它的所有子串并按字典序排列，返回排在最后的那个子串。

?

示例 1：

输入："abab"
输出："bab"
解释：我们可以找出 7 个子串 ["a", "ab", "aba", "abab", "b", "ba", "bab"]。按字典序排在最后的子串是 "bab"。
示例?2：

输入："leetcode"
输出："tcode"
?

提示：

1 <= s.length <= 4 * 10^5
s 仅含有小写英文字符。


class Solution {
public:
    string lastSubstring(string s) {
        int p = 0;
        for(int i = 1; i < s.size(); i++)
        {
            if(s[i-1] >= s[i])  continue;
            if(strcmp(&s[p],&s[i]) < 0) p = i;
        }
        return s.substr(p);
    }
};
