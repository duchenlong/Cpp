class Solution {
public:
    vector<vector<int> > statu = 
        {
            { 0,  1,  2,  6, -1, -1},
            {-1, -1,  2,  6, -1, -1},
            {-1, -1, -1,  3, -1, -1},
            { 8, -1, -1,  3,  4, -1},
            {-1,  7, -1,  5, -1, -1},
            { 8, -1, -1,  5, -1, -1},
            { 8, -1,  3,  6,  4, -1},
            {-1, -1, -1,  5, -1, -1},
            { 8, -1, -1, -1, -1, -1}
        };

    bool isNumber(string s) {
        int st = 0;
        int n = s.size();
        for(int i = 0; i < n; i++) {
            int idx = check(s[i]);
            st = statu[st][idx];
            if(st == -1) return false; 
        }

        vector<bool> finals({0, 0, 0, 1, 0, 1, 1, 0, 1}); // 合法的终止状态
        return finals[st];
    }

    int check(char& ch) {
        switch(ch) {
            case ' ':   return 0;
            case '+':
            case '-':   return 1;
            case '.':   return 2;
            case 'e':   return 4;
            default:
                if(ch >= '0' && ch <= '9') return 3;
        }

        return 5;
    }
};

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

