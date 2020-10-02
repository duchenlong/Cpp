class Solution {
public:
    using ll = long long;
    int numberOfArithmeticSlices(vector<int>& A) {
        int n = A.size();

        // dp[i][j]  n->i  j为公差
        vector<unordered_map<ll,int> > dp(n,unordered_map<ll,int> ());   

        int ans = 0;
        for(int i = 1;  i < n; i++)
            for(int j = 0;  j < i; j++) {
                ll len = (ll)A[i] - (ll)A[j];
                if(dp[j].count(len) > 0) {
                    dp[i][len] += dp[j][len] + 1;
                    ans += dp[j][len];
                } else dp[i][len]++;
            }
        return ans;
    }
};

如果一个数列至少有三个元素，并且任意两个相邻元素之差相同，则称该数列为等差数列。

例如，以下数列为等差数列:

1, 3, 5, 7, 9
7, 7, 7, 7
3, -1, -5, -9
以下数列不是等差数列。

1, 1, 2, 5, 7
?

数组 A 包含 N 个数，且索引从 0 开始。该数组子序列将划分为整数序列?(P0, P1, ..., Pk)，P 与 Q 是整数且满足 0 ≤ P0 < P1 < ... < Pk < N。

?

如果序列 A[P0]，A[P1]，...，A[Pk-1]，A[Pk] 是等差的，那么数组 A 的子序列 (P0，P1，…，PK) 称为等差序列。值得注意的是，这意味着 k ≥ 2。

函数要返回数组 A 中所有等差子序列的个数。

输入包含 N 个整数。每个整数都在 -231 和 231-1 之间，另外 0 ≤ N ≤ 1000。保证输出小于 231-1。

?

示例：

?

输入：[2, 4, 6, 8, 10]

输出：7

解释：
所有的等差子序列为：
[2,4,6]
[4,6,8]
[6,8,10]
[2,4,6,8]
[4,6,8,10]
[2,4,6,8,10]
[2,6,10]
?

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/arithmetic-slices-ii-subsequence
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
