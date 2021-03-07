class Solution {
public:
    bool checkOnesSegment(string s) {
        int n = s.size();
        for(int i = 0, j = 0; i < n; i ++) {
            if(s[i] == '0') continue;
            
            if(i == 0 || s[i - 1] == '1') {
                j = 1;
            } else {
                j ++;
            }
            
            if(j > 1) return false;
        }
        return true;
    }
};


给你一个二进制字符串 s ，该字符串 不含前导零 。

如果 s 最多包含 一个由连续的 '1' 组成的字段 ，返回 true??? 。否则，返回 false 。

?

示例 1：

输入：s = "1001"
输出：false
解释：字符串中的 1 没有形成一个连续字段。
示例 2：

输入：s = "110"
输出：true
?

提示：

1 <= s.length <= 100
s[i]???? 为 '0' 或 '1'
s[0] 为 '1'

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/check-if-binary-string-has-at-most-one-segment-of-ones
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
