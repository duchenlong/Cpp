实现?strStr()?函数。

给定一个?haystack 字符串和一个 needle 字符串，在 haystack 字符串中找出 needle 字符串出现的第一个位置 (从0开始)。如果不存在，则返回? -1。

示例 1:

输入: haystack = "hello", needle = "ll"
输出: 2
示例 2:

输入: haystack = "aaaaa", needle = "bba"
输出: -1
说明:

当?needle?是空字符串时，我们应当返回什么值呢？这是一个在面试中很好的问题。

对于本题而言，当?needle?是空字符串时我们应当返回 0 。这与C语言的?strstr()?以及 Java的?indexOf()?定义相符。


class Solution {
public:
    int strStr(string haystack, string needle) {
        int n = haystack.size();
        int m = needle.size();

        if(m == 0) return 0;
        else if(n == 0) return -1;

        vector<int> next(m,0);
        for(int i = 1,j = 0; i < m; i++)
        {
            while(j && needle[j] != needle[i])
                j = next[j-1];
            if(needle[j] == needle[i])
                j++;
            next[i] = j;
        }

        for(int i = 0,j = 0; i < n; i++)
        {
            while(j && haystack[i] != needle[j])
                j = next[j-1];
            
            if(haystack[i] == needle[j])
                j++;
            if(j == m)
                return i - m + 1;
        }
        return -1;
    }
};
