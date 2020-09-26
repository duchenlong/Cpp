class Solution {
public:
    const int mod = 1e9 + 7;
    int sumSubseqWidths(vector<int>& A) {
        int n = A.size();
        sort(A.begin(),A.end());

        vector<long> pown(n,1);
        for(int i = 1; i < n; i++) pown[i] = pown[i-1] * 2 % mod;

        long ans = 0;
        for(int i = 0; i < n; i++) ans = (ans + (pown[i] - pown[n-1-i]) * A[i]) % mod;

        return ans;
    }
};


给定一个整数数组 A ，考虑 A 的所有非空子序列。

对于任意序列 S ，设 S 的宽度是 S 的最大元素和最小元素的差。

返回 A 的所有子序列的宽度之和。

由于答案可能非常大，请返回答案模 10^9+7。

?

示例：

输入：[2,1,3]
输出：6
解释：
子序列为 [1]，[2]，[3]，[2,1]，[2,3]，[1,3]，[2,1,3] 。
相应的宽度是 0，0，0，1，1，2，2 。
这些宽度之和是 6 。
?

提示：

1 <= A.length <= 20000
1 <= A[i] <= 20000

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/sum-of-subsequence-widths
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
