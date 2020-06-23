给你两个二进制字符串，返回它们的和（用二进制表示）。

输入为 非空 字符串且只包含数字?1?和?0。

?

示例?1:

输入: a = "11", b = "1"
输出: "100"
示例?2:

输入: a = "1010", b = "1011"
输出: "10101"
?

提示：

每个字符串仅由字符 '0' 或 '1' 组成。
1 <= a.length, b.length <= 10^4
字符串如果不是 "0" ，就都不含前导零。



class Solution {
public:
    string addBinary(string a, string b) {
        int pa = a.size() - 1;
        int pb = b.size() - 1;

        string ans = "";
        int cur = 0;
        while(~pa || ~pb || cur)
        {
            if(~pa) cur += a[pa--] - '0';

            if(~pb) cur += b[pb--] - '0';

            //cur的取值        0 1 2 3
            //对应当前位的数据 0 1 0 1
            //cur变化后的数据  0 0 1 1
            ans += (cur & 1) ? "1" : "0";
            cur = (cur < 2) ? 0 : 1;
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};
