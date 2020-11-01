class Solution {
public:
    int countSubstrings(string s, string t) {
        int n = s.size();
        int m = t.size();
        
        int ans = 0;
        for(int i = 0; i < n; i++)
            for(int j = 0; j < m; j++) {
                int cnt = 0;
                for(int k = 0; i + k < n && j + k < m; k++) {
                    cnt += (s[i+k] != t[j+k]);
                    if(cnt > 1) break;
                    if(cnt == 1) ans++;
                }
            } 

        // for(int len = 1; len <= n; len++) {
        //     for(int i = 0; i <= n - len; i++) {
        //         string s1 = s.substr(i,len);
                
        //         for(int j = 0; j <= m - len; j++) {
        //             string s2 = t.substr(j,len);
                    
        //             sort(s1.begin(),s1.begin());
        //             sort(s2.begin(),s2.begin());
        //             int is = 0;
        //             for(int k = 0;  k < len; k++) if(s1[k] != s2[k]) is++; else if(is == 2) break;
                    
        //             if(is == 1) ans++;
        //         }
        //     }
        // }
        
        return ans;
    }
};


给你两个字符串?s 和?t?，请你找出 s?中的非空子串的数目，这些子串满足替换 一个不同字符?以后，是 t?串的子串。换言之，请你找到 s?和 t?串中 恰好?只有一个字符不同的子字符串对的数目。

比方说，?"computer" 和?"computation" 加粗部分只有一个字符不同：?'e'/'a'?，所以这一对子字符串会给答案加 1 。

请你返回满足上述条件的不同子字符串对数目。

一个 子字符串?是一个字符串中连续的字符。

?

示例 1：

输入：s = "aba", t = "baba"
输出：6
解释：以下为只相差 1 个字符的 s 和 t 串的子字符串对：
("aba", "baba")
("aba", "baba")
("aba", "baba")
("aba", "baba")
("aba", "baba")
("aba", "baba")
加粗部分分别表示 s 和 t 串选出来的子字符串。
示例 2：
输入：s = "ab", t = "bb"
输出：3
解释：以下为只相差 1 个字符的 s 和 t 串的子字符串对：
("ab", "bb")
("ab", "bb")
("ab", "bb")
加粗部分分别表示 s 和 t 串选出来的子字符串。
示例 3：
输入：s = "a", t = "a"
输出：0
示例 4：

输入：s = "abe", t = "bbc"
输出：10
?

提示：

1 <= s.length, t.length <= 100
s 和?t?都只包含小写英文字母。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/count-substrings-that-differ-by-one-character
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
