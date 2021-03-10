class Solution {
public:
    int calculate(string s) {
        s += " ";
        string oper("");
        vector<int> st;

        for(int i = 0, j = -1; i < s.size(); i++) {
            if(s[i] >= '0' && s[i] <= '9') {
                if(j == -1) j = 0;
                j = j * 10 + (s[i] - '0');
                continue;
            }

            if(j != -1) {
                st.push_back(j);
            }

            if(st.size() > 1 && j != -1 && (oper.back() == '*' || oper.back() == '/')) {
                int a = st.back();
                st.pop_back();
                int b = st.back();
                st.pop_back();

                st.push_back(check(b,a,oper.back()));
                oper.pop_back();
            }

            if(s[i] != ' ') oper += s[i];
            j = -1;
        }

       int res = st[0];
       for(int i = 1; i < st.size(); i++) {
           res = check(res,st[i],oper[i - 1]);
       }

       return res;
    }
    int check(int a,int b,char oper) {
        if(oper == '+')
            return a + b;
        if(oper == '-')
            return a - b;
        if(oper == '*')
            return a * b;
        return a / b;
    }

};


实现一个基本的计算器来计算一个简单的字符串表达式的值。

字符串表达式仅包含非负整数，+， - ，*，/ 四种运算符和空格??。 整数除法仅保留整数部分。

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
链接：https://leetcode-cn.com/problems/basic-calculator-ii
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
