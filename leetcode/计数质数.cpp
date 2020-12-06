class Solution {
public:
    const int N = 5 * 1e6 + 10;
    int countPrimes(int n) {
        int f[N];
        memset(f,0x00,sizeof f);
        int cnt = 0;

        for(int i = 2; i < n; i++) {
            if(f[i]) continue;
            for(int j = 2 * i; j < n; j += i)   f[j] = 1; 
            cnt++;
        }
        return cnt;
    }
};

统计所有小于非负整数?n?的质数的数量。

?

示例 1：

输入：n = 10
输出：4
解释：小于 10 的质数一共有 4 个, 它们是 2, 3, 5, 7 。
示例 2：

输入：n = 0
输出：0
示例 3：

输入：n = 1
输出：0
?

提示：

0 <= n <= 5 * 106

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/count-primes
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
