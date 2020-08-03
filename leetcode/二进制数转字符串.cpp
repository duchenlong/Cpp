二进制数转字符串。给定一个介于0和1之间的实数（如0.72），类型为double，打印它的二进制表达式。如果该数字不在0和1之间，或者无法精确地用32位以内的二进制表示，则打印“ERROR”。

示例1:

 输入：0.625
 输出："0.101"
示例2:

 输入：0.1
 输出："ERROR"
 提示：0.1无法被二进制准确表示
提示：

32位包括输出中的"0."这两位。


class Solution {
public:
    string printBin(double num) {
        if(num >= 1 || num <= 0)    return "ERROR";

        string ans("0.");
        while(num > 0)
        {
            num *= 2;
            ans += (num - 1.0) >= 0 ? '1' : '0';
            if(num >= 1)    num -= 1;

            if(ans.size() > 32) return "ERROR";
        }

        return ans;
    }
};
