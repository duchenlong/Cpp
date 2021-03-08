class Solution {
public:

    int minCut(string s) {
        int n = s.size();
        vector<vector<bool> > f(n + 1, vector<bool> (n + 1, false));
        for(int len = 1; len <= n; len ++)
            for(int i = 1; i + len - 1 <= n; i ++) {
                int j = i + len - 1;
                if(len == 1) 
                    f[i][j] = true;
                else if(s[i - 1] == s[j - 1]) {
                    if(i + 1 == j)
                        f[i][j] = true;
                    else f[i][j] = f[i + 1][j - 1];
                }
            }
        
        vector<int> res(n + 1,0);
        for(int i = 1; i <= n; i++) {
            if(f[1][i])
                res[i] = 0;
            else {
                res[i] = i;
                for(int j = 1; j < i; j++)
                    if(f[j + 1][i]) res[i] = min(res[i],res[j] + 1);
            }
        }
        
        return res[n];
    }
};


给你一个字符串 s，请你将 s 分割成一些子串，使每个子串都是回文。

返回符合要求的 最少分割次数 。

?

示例 1：

输入：s = "aab"
输出：1
解释：只需一次分割就可将?s 分割成 ["aa","b"] 这样两个回文子串。
示例 2：

输入：s = "a"
输出：0
示例 3：

输入：s = "ab"
输出：1
?

提示：

1 <= s.length <= 2000
s 仅由小写英文字母组成

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/palindrome-partitioning-ii
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
