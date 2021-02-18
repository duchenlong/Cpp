class Solution {
public:
    const int mod = 1e9 + 7;
    int countHomogenous(string s) {
        long long res = 0;
        long long t = 1;
        s += " ";
        for(int i = 0; i < s.size() - 1; i++) {
            if(s[i] == s[i + 1]) {
                t ++;
            } else {
                res = (res + t * (t + 1) / 2) % mod;
                t = 1;
            }
        }
        
        return res;
    }
};


给你一个字符串 s ，返回 s 中 同构子字符串 的数目。由于答案可能很大，只需返回对 109 + 7 取余 后的结果。

同构字符串 的定义为：如果一个字符串中的所有字符都相同，那么该字符串就是同构字符串。

子字符串 是字符串中的一个连续字符序列。

?

示例 1：

输入：s = "abbcccaa"
输出：13
解释：同构子字符串如下所列：
"a"   出现 3 次。
"aa"  出现 1 次。
"b"   出现 2 次。
"bb"  出现 1 次。
"c"   出现 3 次。
"cc"  出现 2 次。
"ccc" 出现 1 次。
3 + 1 + 2 + 1 + 3 + 2 + 1 = 13
示例 2：

输入：s = "xy"
输出：2
解释：同构子字符串是 "x" 和 "y" 。
示例 3：

输入：s = "zzzzz"
输出：15
?

提示：

1 <= s.length <= 105
s 由小写字符串组成

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/count-number-of-homogenous-substrings
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
