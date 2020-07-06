
验证给定的字符串是否可以解释为十进制数字。

例如:

"0"?=>?true
" 0.1 "?=>?true
"abc"?=>?false
"1 a"?=>?false
"2e10"?=>?true
" -90e3? ?"?=>?true
" 1e"?=>?false
"e3"?=>?false
" 6e-1"?=>?true
" 99e2.5?"?=>?false
"53.5e93"?=>?true
" --6 "?=>?false
"-+3"?=>?false
"95a54e53"?=>?false

说明:?我们有意将问题陈述地比较模糊。在实现代码之前，你应当事先思考所有可能的情况。这里给出一份可能存在于有效十进制数字中的字符列表：

数字 0-9
指数 - "e"
正/负号 - "+"/"-"
小数点 - "."
当然，在输入中，这些字符的上下文也很重要。

class Solution {
public:
    bool isNumber(string s) {
        int len = s.size();

        if(len == 0)    return false;
        int p = 0;
        //去掉前后空格
        while(p < len && s[p] == ' ' )  p++;
        while(len > 0 && s[len-1] == ' ')  len--;
        if(len - 1 < p) return false;
        
        //第一个正负号
        if(s[p] == '-' || s[p] == '+') p++;

        //第一个e
        int idx = s.find('e',p);
        if(idx == len || idx == p) return false;    //"e9"  "9e"
        if(idx != -1)
        {
            int n = idx + 1;
            if(s[n] == '-' || s[n] == '+') n++;
            if(n == len)    return false;
            for(int i = n; i < len; i++)
                if(s[i] < '0' || s[i] > '9')    return false;
        }

        idx = (idx == -1) ? len : idx;//防止 idx=-1 也就是没有 e 的情况
        int flag = true;
        if(s[p] == '.')
        {
            p++;
            if(p < idx) //".1"
                flag = false;
            else
                return false;
        }  

        //e之前的数字是否合法
        while(p < idx)
        {
            if(s[p] == '.' && flag)
            {
                flag = false;
                p++;
                continue;
            }
            if(s[p] < '0' || s[p] > '9')    return false;
            p++;
        } 
        return true;
    }
};
