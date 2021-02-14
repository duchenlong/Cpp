class Solution {
public:
    int subarraysWithKDistinct(vector<int>& A, int K) {
        int n = A.size();
        vector<int> fLe(n + 1,0), fRi(n + 1, 0);
        int l1 = 0, l2 = 0, c1 = 0, c2 = 0;
        int res = 0;

        for(int i = 0; i < n; i++) {
            if(fLe[A[i]] ++ == 0) c1 ++;
            if(fRi[A[i]] ++ == 0) c2 ++;
            if(c1 < K) continue;

            while(c1 > K && l1 <= i)
                if(-- fLe[A[l1 ++]] == 0) c1 --;
            while(c2 >= K && l2 <= i)
                if(-- fRi[A[l2 ++]] == 0) c2 --;
            res += l2 - l1;
        }
        return res;
    }
};


给定一个正整数数组 A，如果 A?的某个子数组中不同整数的个数恰好为 K，则称 A 的这个连续、不一定独立的子数组为好子数组。

（例如，[1,2,3,1,2] 中有?3?个不同的整数：1，2，以及?3。）

返回?A?中好子数组的数目。

?

示例 1：

输入：A = [1,2,1,2,3], K = 2
输出：7
解释：恰好由 2 个不同整数组成的子数组：[1,2], [2,1], [1,2], [2,3], [1,2,1], [2,1,2], [1,2,1,2].
示例 2：

输入：A = [1,2,1,3,4], K = 3
输出：3
解释：恰好由 3 个不同整数组成的子数组：[1,2,1,3], [2,1,3], [1,3,4].
?

提示：

1 <= A.length <= 20000
1 <= A[i] <= A.length
1 <= K <= A.length

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/subarrays-with-k-different-integers
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
