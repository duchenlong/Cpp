class Solution {
public:
    double largestSumOfAverages(vector<int>& A, int K) {
        int n = A.size();
        double f[n+1][K+1];
        double sum[n+1];
        memset(sum,0x00,sizeof sum);
        memset(f,0x00,sizeof f);

        for(int i = 1; i <= n; i++) {
            sum[i] = A[i-1] + sum[i-1];
            f[i][1] = sum[i] / i;
        }

        for(int i = 1; i <= n; i++)
            for(int k = 2; k <= K; k++)
                for(int j = 0; j < i; j++)
                    f[i][k] = max(f[i][k],f[j][k-1] + (sum[i] - sum[j]) / (i - j));
        
        return f[n][K];
    }
};


我们将给定的数组?A?分成?K?个相邻的非空子数组 ，我们的分数由每个子数组内的平均值的总和构成。计算我们所能得到的最大分数是多少。

注意我们必须使用 A 数组中的每一个数进行分组，并且分数不一定需要是整数。

示例:
输入: 
A = [9,1,2,3,9]
K = 3
输出: 20
解释: 
A 的最优分组是[9], [1, 2, 3], [9]. 得到的分数是 9 + (1 + 2 + 3) / 3 + 9 = 20.
我们也可以把 A 分成[9, 1], [2], [3, 9].
这样的分组得到的分数为 5 + 2 + 6 = 13, 但不是最大值.
说明:

1 <= A.length <= 100.
1 <= A[i] <= 10000.
1 <= K <= A.length.
答案误差在?10^-6?内被视为是正确的。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/largest-sum-of-averages
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
