class Solution {
public:
    int calculate(string s) {
        s += "+";
        stack<int> st;
        char oper = '+';
        int t = 0;
        for(auto& e : s) {
            if(e <= '9' && e >= '0') {
                t = t * 10 + (e - '0');
                continue;
            }
            if(e == ' ') continue;

            if(oper == '+') st.push(t);
            else if(oper == '-') st.push(-t);
            else if(oper == '*') {
                t *= st.top();st.pop();
                st.push(t);
            } else {
                t = st.top() / t;st.pop();
                st.push(t);
            }
            t = 0;
            oper = e;
        }

        int res = 0;
        while(st.size()) {
            res += st.top();
            st.pop();
        }
        return res;
    }
};

给定一个包含正整数、加(+)、减(-)、乘(*)、除(/)的算数表达式(括号除外)，计算其结果。

表达式仅包含非负整数，+， - ，*，/ 四种运算符和空格??。 整数除法仅保留整数部分。

示例?1:

输入: "3+2*2"
输出: 7
示例 2:

输入: " 3/2 "
输出: 1
示例 3:

输入: " 3+5 / 2 "
输出: 5
说明：

你可以假设所给定的表达式都是有效的。
请不要使用内置的库函数 eval。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/calculator-lcci
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
