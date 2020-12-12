class Solution {
public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     * 
     * @param x string字符串 
     * @return int整型
     */
    int Maximumlength(string x) {
        // write code here
        int n = x.size();
        int ans = 0;
        vector<int> f(n + 1,0);
        for(int i = 1; i <= n; i++) 
            f[i] = f[i - 1] + (x[i - 1] == 'b' ? 1 : 0);
        int le = 0;
        int fle = x[le] == 'a';
        int ri = n - 1;
        int fri = x[ri] == 'c';
        
        while(le < ri) {
            int sum = f[ri] - f[le + 1];
            if(fle >= sum && fri >= sum) {
                ans = max(ans,sum * 3);
            }
            
            if(fle <= fri){
                le++;
                fle += x[le] == 'a';
            } else {
                ri--;
                fri += x[ri] == 'c';
            }
        }
        
        return ans;
    }
};


链接：https://ac.nowcoder.com/acm/problem/207724
来源：牛客网

牛牛现在有一个长度为len只包含小写字母‘a’-'z'的字符串x，他现在想要一个特殊的子序列，这个子序列的长度为3*n（n为非负整数），子序列的第[1,n]个字母全部为‘a’，子序列的[n+1,2*n]个字母全部为‘b’，子序列的[2*n+1,3*n]个字母全部为‘c’，牛牛想知道最长的符合条件的独特子序列的长度是多少。

示例1
输入
复制
"cbacb"
返回值
复制
0
说明
没有符合条件的非空子序列，所以输出0
示例2
输入
复制
"abaabbcccc"
返回值
复制
6
说明
最长的符合条件的子序列为"aabbcc"，所以输出6
备注:
对于30\%的数据，1 \leq len \leq 1000对于30%的数据，1≤len≤1000
对于100\%的数据，1 \leq len \leq 1e6对于100%的数据，1≤len≤1e6
