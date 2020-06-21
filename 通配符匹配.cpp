给定一个字符串?(s) 和一个字符模式?(p) ，实现一个支持?'?'?和?'*'?的通配符匹配。

'?' 可以匹配任何单个字符。
'*' 可以匹配任意字符串（包括空字符串）。
两个字符串完全匹配才算匹配成功。

说明:

s?可能为空，且只包含从?a-z?的小写字母。
p?可能为空，且只包含从?a-z?的小写字母，以及字符???和?*。
示例?1:

输入:
s = "aa"
p = "a"
输出: false
解释: "a" 无法匹配 "aa" 整个字符串。
示例?2:

输入:
s = "aa"
p = "*"
输出: true
解释:?'*' 可以匹配任意字符串。
示例?3:

输入:
s = "cb"
p = "?a"
输出: false
解释:?'?' 可以匹配 'c', 但第二个 'a' 无法匹配 'b'。
示例?4:

输入:
s = "adceb"
p = "*a*b"
输出: true
解释:?第一个 '*' 可以匹配空字符串, 第二个 '*' 可以匹配字符串 "dce".
示例?5:

输入:
s = "acdcb"
p = "a*c?b"
输出: false


//动态规划 
bool isMatch(char * s, char * p){
    int lens = strlen(s);
    int lenp = strlen(p);

    int i = 0;
    int j = 0;
    int** dp = (int**)malloc(sizeof(int*) * (lens + 1));
    for(i = 0; i <= lens; i++)
    {
        dp[i] = (int*)calloc((lenp + 1),sizeof(int));
    }

    dp[0][0] = true;
    for(i = 0; i < lenp; i++)
    {
        if(p[i] == '*')
        {
            dp[0][i+1] = true;
        }
        else
        {
            break;
        }
    }

    for(i = 1; i <= lens; i++)
    {
        for(j = 1; j <= lenp; j++)
        {
            if(p[j-1] == s[i-1] || p[j-1] == '?')
            {
                dp[i][j] = dp[i-1][j-1];
            }
            else if(p[j-1] == '*')
            {
                dp[i][j] = dp[i-1][j] || dp[i][j-1];
            }
            else
            {
                dp[i][j] = false;
            }
        }
    }

    return dp[lens][lenp];
}


class Solution {
public:
    //回溯
    bool isMatch(string s, string p) {
        int n = s.size();
        int m = p.size();

        int idp = 0;
        int star = -1;//上一个 *字符的位置
        int k = 0;//上一个 * 字符匹配s的位置
        int ids = 0;

        while(ids < n)
        {
            if(s[ids] == p[idp] || p[idp] == '?')
            {
                idp++;
                ids++;
                continue;
            }

            if(p[idp] == '*')
            {
                star = idp++;
                k = ids;
                continue;
            }

            //回溯到上一个 * 的位置
            if(star != -1)
            {
                ids = ++k;
                idp = star + 1;
                continue;
            }
            return false;
        }

        //防止 p字符串后面全是*的情况
        while(idp < m && p[idp] == '*')
            idp++;
        return idp == m;
    }
};
