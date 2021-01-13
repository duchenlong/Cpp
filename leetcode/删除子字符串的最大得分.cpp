class Solution {
public:
    int maximumGain(string s, int x, int y) {      
        int n = s.size();
        int res = 0;
        if(x < y) {
            swap(x,y);
            for(auto& e : s) {
                if(e == 'a') e = 'b';
                else if(e == 'b') e = 'a';
            }
        }
        stack<int> a,b;
        
        for(int i = 0; i< n; i++) {
            if(s[i] != 'a' && s[i] != 'b') {
                while(b.size() && a.size()) {
                    int tb = b.top();b.pop();
                    int ta = a.top();a.pop();
                    if(ta > tb) res += y;
                    else res += x;
                }
                a = stack<int> ();
                b = stack<int> ();
                continue;
            }
            
            if(s[i] == 'a') a.push(i);
            else b.push(i);
            
            while(b.size() && a.size() && b.top() > a.top() ) {
                a.pop();
                b.pop();
                res += x;
            }
        }
        
        while(b.size() && a.size()) {
            int tb = b.top();b.pop();
            int ta = a.top();a.pop();
            if(ta > tb) res += y;
            else res += x;
        }
        return res;
    }
};

给你一个字符串?s?和两个整数?x 和?y?。你可以执行下面两种操作任意次。

删除子字符串?"ab"?并得到?x?分。
比方说，从?"cabxbae"?删除 ab?，得到?"cxbae"?。
删除子字符串"ba"?并得到?y?分。
比方说，从?"cabxbae"?删除 ba?，得到?"cabxe"?。
请返回对 s?字符串执行上面操作若干次能得到的最大得分。

?

示例 1：

输入：s = "cdbcbbaaabab", x = 4, y = 5
输出：19
解释：
- 删除 "cdbcbbaaabab" 中加粗的 "ba" ，得到 s = "cdbcbbaaab" ，加 5 分。
- 删除 "cdbcbbaaab" 中加粗的 "ab" ，得到 s = "cdbcbbaa" ，加 4 分。
- 删除 "cdbcbbaa" 中加粗的 "ba" ，得到 s = "cdbcba" ，加 5 分。
- 删除 "cdbcba" 中加粗的 "ba" ，得到 s = "cdbc" ，加 5 分。
总得分为 5 + 4 + 5 + 5 = 19 。
示例 2：

输入：s = "aabbaaxybbaabb", x = 5, y = 4
输出：20
?

提示：

1 <= s.length <= 105
1 <= x, y <= 104
s?只包含小写英文字母。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/maximum-score-from-removing-substrings
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
