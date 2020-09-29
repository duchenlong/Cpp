class Solution {
public:
    bool parseBoolExpr(string expression) {
        return check(expression,0,expression.size());
    }

    bool check(string& str,int le,int ri) {
        if(le == ri-1) return str[le] == 't' ? true : false;
        if(str[le] == '!') return !check(str,le+2,ri-1);

        int cnt = 1;
        int p = le+2;
        bool ans = (str[le] == '&');

        for(int i = p; cnt!= 0; i++) {
            if(str[i] == '(') ++cnt;
            else if(str[i] == ')') --cnt;

            // )   &(&(f,t),|(t,f))
            if(cnt == 0 || (str[i] == ',' && cnt==1)) {
                if(str[le] == '&')  ans = ans && check(str,p,i);
                else if(str[le] == '|') ans = ans || check(str,p,i);

                p = i + 1; 
            }
        }

        return ans;
    }
};


给你一个以字符串形式表述的?布尔表达式（boolean） expression，返回该式的运算结果。

有效的表达式需遵循以下约定：

"t"，运算结果为 True
"f"，运算结果为 False
"!(expr)"，运算过程为对内部表达式 expr 进行逻辑 非的运算（NOT）
"&(expr1,expr2,...)"，运算过程为对 2 个或以上内部表达式 expr1, expr2, ... 进行逻辑 与的运算（AND）
"|(expr1,expr2,...)"，运算过程为对 2 个或以上内部表达式 expr1, expr2, ... 进行逻辑 或的运算（OR）
?

示例 1：

输入：expression = "!(f)"
输出：true
示例 2：

输入：expression = "|(f,t)"
输出：true
示例 3：

输入：expression = "&(t,f)"
输出：false
示例 4：

输入：expression = "|(&(t,f,t),!(t))"
输出：false
?

提示：

1 <= expression.length <= 20000
expression[i] 由 {'(', ')', '&', '|', '!', 't', 'f', ','} 中的字符组成。
expression 是以上述形式给出的有效表达式，表示一个布尔值。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/parsing-a-boolean-expression
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
