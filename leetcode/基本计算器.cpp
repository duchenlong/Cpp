class Solution {
public:
    int calculate(string s) {
        s = "(" + s + ") ";
        int id = 0;
        return dfs(s,id);;
    }

    int dfs(string& s,int& id) {
        int res = 0, cur = 0;
        char oper = '+';

        while(id < s.size()) {
            if(s[id] == '(') {
                cur = dfs(s,++id);
                //cout << res << " " << cur << " " << oper << endl;
                res = check(res,cur,oper);
                cur = 0;
                oper = '+';
            } else if(s[id] == ')') {
                break;
            } else if(s[id] == '+' || s[id] == '-') {
                res = check(res,cur,oper);
                oper = s[id];
                cur = 0;
            } else if(s[id] >= '0' && s[id] <= '9') {
                cur = cur * 10 + (s[id] - '0');
            } 
            id++;
        }

        return check(res,cur,oper);
    }

    int check(int a,int b,char oper) {
        if(oper == '+')
            return a + b;
        return a - b;
    }
};


实现一个基本的计算器来计算一个简单的字符串表达式 s 的值。

?

示例 1：

输入：s = "1 + 1"
输出：2
示例 2：

输入：s = " 2-1 + 2 "
输出：3
示例 3：

输入：s = "(1+(4+5+2)-3)+(6+8)"
输出：23
?

提示：

1 <= s.length <= 3?* 105
s 由数字、'+'、'-'、'('、')'、和 ' ' 组成
s 表示一个有效的表达式

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/basic-calculator
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
