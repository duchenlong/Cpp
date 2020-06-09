给定一个数字，我们按照如下规则把它翻译为字符串：0 翻译成 “a” ，1 翻译成 “b”，……，11 翻译成 “l”，……，25 翻译成 “z”。
一个数字可能有多个翻译。请编程实现一个函数，用来计算一个数字有多少种不同的翻译方法。

?

示例 1:

输入: 12258
输出: 5
解释: 12258有5种不同的翻译，分别是"bccfi", "bwfi", "bczi", "mcfi"和"mzi"
?

提示：

0 <= num < 231



class Solution {
public:
    int translateNum1(int num) {
       int ans = 0;
       dfs(num,ans);
       return ans; 
    }

    void dfs(int num,int& ans)
    {
        if(num < 10)
        {
            ans++;
            return;
        }

        dfs(num/10,ans);

        int tmp = num % 100;
        if(tmp <= 25 && tmp > 9)   dfs(num/100,ans);
    }



    int translateNum(int num)
    {
        if(num < 10)    return 1;
        int tmp = num % 100;
        int ret2 = 0;
        if(tmp <= 25 && tmp > 9)   ret2 = translateNum(num/100);
        return translateNum(num/10) + ret2;
    }
};
