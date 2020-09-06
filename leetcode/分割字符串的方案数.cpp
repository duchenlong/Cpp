给你一个二进制串?s? （一个只包含 0 和 1 的字符串），我们可以将 s?分割成 3 个 非空?字符串 s1, s2, s3 （s1 + s2 + s3 = s）。

请你返回分割?s?的方案数，满足 s1，s2 和 s3 中字符 '1' 的数目相同。

由于答案可能很大，请将它对 10^9 + 7 取余后返回。

?

示例 1：

输入：s = "10101"
输出：4
解释：总共有 4 种方法将 s 分割成含有 '1' 数目相同的三个子字符串。
"1|010|1"
"1|01|01"
"10|10|1"
"10|1|01"
示例 2：

输入：s = "1001"
输出：0
示例 3：

输入：s = "0000"
输出：3
解释：总共有 3 种分割 s 的方法。
"0|0|00"
"0|00|0"
"00|0|0"
示例 4：

输入：s = "100100010100110"
输出：12
?

提示：

s[i] == '0'?或者?s[i] == '1'
3 <= s.length <= 10^5


class Solution {
public:
    const int mod = 1e9 + 7;
    int numWays(string s) {
        int n = s.size();
        int sum = 0;
        long ans = 0;
        for(int i = 0; i < n; i++) {
            if(s[i] == '1') sum++;
        }
        if(sum == 0){
            for(int i = 1; i <= n-2; i++){
                ans = (ans + i) % mod;
            }
            return ans;
        }
        
        if(sum % 3 != 0)    return 0;
        
        int num = sum / 3;
        int tmp = 0;
        int le = 0;
        
        for(int i = 0; i < n; i++){
            if(s[i] == '1') tmp++;
            le = i;
            if(tmp == num) break;
        }
        tmp = 0;
        int ri = 0;
        for(int i = n-1; i >= 0; i--) {
            if(s[i] == '1') tmp++;
            ri = i;
            if(tmp == num)  break;
        }
        
        int le_n = 0;
        for(int i = le+1; i < n; i++) {
            le_n++;
            if(s[i] == '1')   break;
        }
        int ri_n = 0;
        for(int i = ri-1; i >= 0; i--) {
            ri_n++;
            if(s[i] == '1')   break;
        }
        
        for(int i = 1; i <= le_n; i++){
            ans =(ri_n + ans) % mod;
        }
        return ans;
    }
};
