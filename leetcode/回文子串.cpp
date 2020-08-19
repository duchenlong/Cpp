给定一个字符串，你的任务是计算这个字符串中有多少个回文子串。

具有不同开始位置或结束位置的子串，即使是由相同的字符组成，也会被视作不同的子串。

?

示例 1：

输入："abc"
输出：3
解释：三个回文子串: "a", "b", "c"
示例 2：

输入："aaa"
输出：6
解释：6个回文子串: "a", "a", "a", "aa", "aa", "aaa"
?

提示：

输入的字符串长度不会超过 1000 。

class Solution {
public:
    int countSubstrings(string s) {
        int n = s.size();
        int ans = 0;

        for(int i = 0; i < n; i++)
        {
            ans += check(s,n,i,i);
            ans += check(s,n,i,i+1);
        }
            
        return ans;
    }

    int check(string& s,int n,int le,int ri)
    {
        int ret = 0;
        while(le >= 0 && ri <= n-1 && s[le] == s[ri])
        {
            ret++;
            le--;
            ri++;
        }

        return ret;
    }
};
