给定一个字符串 s，将 s 分割成一些子串，使每个子串都是回文串。

返回符合要求的最少分割次数。

示例:

输入:?"aab"
输出: 1
解释: 进行一次分割就可将?s 分割成 ["aa","b"] 这样两个回文子串。

class Solution {
public:
    int len = 0;
    int minCut(string s) {
        len = s.size();
        if(len < 2) return 0;

        vector<int> dp(len,0);
        for(int i = 0; i < len; i++)
            dp[i] = i;

        for(int i = 0; i < len; i++)
        {
            merge(s,i,i,dp);
            merge(s,i,i+1,dp);
        }
  
        return dp[len-1];
    }

    inline void merge(string& s,int le,int ri,vector<int>& dp)
    {
        while(le >= 0 && ri < len && s[le] == s[ri])
        {
            dp[ri] = min(dp[ri],((le == 0) ? 0 : (dp[le-1] + 1)));
            ri++;
            le--;
        }
    }
};
