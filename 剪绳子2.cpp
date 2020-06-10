给你一根长度为 n 的绳子，请把绳子剪成整数长度的 m 段（m、n都是整数，n>1并且m>1），每段绳子的长度记为 k[0],k[1]...k[m] 。请问 k[0]*k[1]*...*k[m] 可能的最大乘积是多少？例如，当绳子的长度是8时，我们把它剪成长度分别为2、3、3的三段，此时得到的最大乘积是18。

答案需要取模 1e9+7（1000000007），如计算初始结果为：1000000008，请返回 1。

?

示例 1：

输入: 2
输出: 1
解释: 2 = 1 + 1, 1 × 1 = 1
示例?2:

输入: 10
输出: 36
解释: 10 = 3 + 3 + 4, 3 ×?3 ×?4 = 36
?

提示：

2 <= n <= 1000


class Solution {
public:
    const int mod = (int)1000000007;
    int cuttingRope(int n) {
       if(n < 4) return n - 1;

       long long ret = 1;
       while(n > 4)
       {
           n -= 3;
           ret = (ret * 3) % mod;
       }

       return (int)((n * ret) % (int)mod);
    }
};

请实现一个函数，输入一个整数，输出该数二进制表示中 1 的个数。例如，把 9?表示成二进制是 1001，有 2 位是 1。因此，如果输入 9，则该函数输出 2。

示例 1：

输入：00000000000000000000000000001011
输出：3
解释：输入的二进制串 00000000000000000000000000001011?中，共有三位为 '1'。
示例 2：

输入：00000000000000000000000010000000
输出：1
解释：输入的二进制串 00000000000000000000000010000000?中，共有一位为 '1'。
示例 3：

输入：11111111111111111111111111111101
输出：31
解释：输入的二进制串 11111111111111111111111111111101 中，共有 31 位为 '1'。


class Solution {
public:
    int hammingWeight(uint32_t n) {
        int ans = 0;

        while(n)
        {
            n = n & (n-1);
            ans++;
        }

        return ans;
    }
};
