//给定一个字符串，逐个翻转字符串中的每个单词。

//?

//示例 1：

//输入: "the sky is blue"
//输出:?"blue is sky the"
//示例 2：

//输入: " ?hello world! ?"
//输出:?"world! hello"
//解释: 输入字符串可以在前面或者后面包含多余的空格，但是反转后的字符不能包括。
//示例 3：

//输入: "a good ? example"
//输出:?"example good a"
//解释: 如果两个单词间有多余的空格，将反转后单词间的空格减少到只含一个。

class Solution {
public:
    string reverseWords(string s) {
        //逆置字符串
        reverse(s.begin(),s.end());
        int start = 0;
        int lenWord = 0;//翻转单词长度
        int len = s.size();
        int i = 0;
        //排除前面的空格
        while(i < len && s[i] == ' ')
            i++;

        for(; i < len; i++)
        {
            if(s[i] != ' ')
            {
                lenWord++;
                continue;
            }
               
            //找到一个空格,逆置从start到该位置的单词
            reverse(&s[start],&s[i]);
            start += lenWord + 1;
            lenWord = 0;
            int flag = 0;
            //向后找下一个不是空格的字母
            while(i < len && s[i] == ' ')
            {
                i++;
                flag = 1;
            }
            if(flag)
                i--;
        }
        reverse(&s[start],&s[len]);
        //去掉后面的空格
        while(i>0 &&  s[i-1] == ' ')
        {
            s[i-1] = '\0';
            i--;
        }
        return s;
    }
};
