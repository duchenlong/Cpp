//给定一个字符串 s，你可以通过在字符串前面添加字符将其转换为回文串。
//找到并返回可以用这种方式转换的最短回文串。

//示例?1:

//输入: "aacecaaa"
//输出: "aaacecaaa"
//示例 2:

//输入: "abcd"
//输出: "dcbabcd"




class Solution {
public:
    //暴力法
    string shortestPalindrome1(string s) {
        int len = s.size();
        string src(s);//拷贝构造
        reverse(src.begin(),src.end()); //逆置一份拷贝的字符串

        for(int i = 0; i < len; i++)
        {
            if(s.substr(0,len - i) == src.substr(i))
                return src.substr(0,i) + s;
        }

        //程序在for循环中就会终止，调用return 排除空字符串的情况
        return "";
    }

    //递归
    string shortestPalindrome2(string s) {
        int len = s.size();
        
        int left = 0;
        int right = len - 1;
        for(; right >= 0; right--)
        {
            //找到和左边字符匹配的字符
            if(s[left] == s[right])
                left++;
        }
        //如果左边和右边完全匹配，就是回文字符串
        if(left == len)
            return s;

        //如果不匹配，说明 [left,len) 的字符串都是不合适的
        string src = s.substr(left,len);
        reverse(src.begin(),src.end());
        return src + shortestPalindrome2(s.substr(0,left)) + s.substr(left);
    }

    //KMP算法
    string shortestPalindrome(string s) {
        int len = s.size();
        string src(s);
        reverse(src.begin(),src.end());
        string s_new = s + '#' + src; //'#'字符来区分两个字符串 "abc" --> abc # cba

        int new_len = s_new.size();
        vector<int> arr(new_len,0);

        for(int i = 1; i < new_len; i++)
        {
            int t = arr[i-1];
            //如果两个字符不相等，就找公共前缀的后缀坐标
            while(t > 0 && s_new[i] != s_new[t])
                t = arr[t-1];
            //下一个查找位置就是，公共前缀的长度 + 1
            if(s_new[i] == s_new[t])
                t++;
            arr[i] = t;
        }

        return src.substr(0, len - arr[new_len-1]) + s;
    }
};
