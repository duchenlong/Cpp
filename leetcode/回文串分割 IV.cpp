const int N = 2010;
int f[N][N];

class Solution {
public:
    bool checkPartitioning(string s) {
        int n = s.size();
        memset(f,0x00,sizeof f);

        for(int i = n - 1; i >= 0; i--)
            for(int j = i; j < n; j++) {
                if(j == i) f[i][j] = 1;
                else if(j - i == 1 && s[i] == s[j]) f[i][j] = 1;
                else if(f[i+1][j-1] && s[i] == s[j]) f[i][j] = 1;
            }
        
        for(int i = 0; i < n; i++)
            for(int j = i + 1; j < n - 1; j++)
                if(f[0][i] && f[i+1][j] && f[j+1][n-1]) return true;
        return false;
    }
};

给你一个字符串?s?，如果可以将它分割成三个?非空?回文子字符串，那么返回?true?，否则返回?false?。

当一个字符串正着读和反着读是一模一样的，就称其为 回文字符串 。

?

示例 1：

输入：s = "abcbdd"
输出：true
解释："abcbdd" = "a" + "bcb" + "dd"，三个子字符串都是回文的。
示例 2：

输入：s = "bcbddxy"
输出：false
解释：s 没办法被分割成 3 个回文子字符串。
?

提示：

3 <= s.length <= 2000
s?????? 只包含小写英文字母。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/palindrome-partitioning-iv
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
