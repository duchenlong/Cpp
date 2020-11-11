class Solution {
public:
    const int N = 10010;
    int longestArithSeqLength(vector<int>& A) {
        int n = A.size();

        int f[n][2 * N];        // 1-10000 正数公差  10001 - 20000 负数公差  0
        memset(f,0x00,sizeof f);
        int ans = 0;
        for(int i = 0; i < n; i++) {
            f[i][0] = 1;
            for(int j = 0; j < i; j++) {
                int len = A[i] - A[j];
                if(len < 0) len = 10000 - len;

                if(f[j][len] == 0) f[i][len] = 2;
                else f[i][len] = f[j][len] + 1;
                ans = max(ans,f[i][len]);
            }
        }

        return ans;
        //unordered_map<int,int> mp[n];  // map[n][m] 公差为 n 的等差数列长度为 m
        // int ans = 1;
        // for(int i = 0; i < n; i++) {
        //     mp[i][0] = 1;
        //     for(int j = 0; j < i; j ++) {
        //         int len = A[i] - A[j];
        //         auto pos = mp[j].find(len);
        //         if(pos == mp[j].end()) {
        //             mp[i][len] = 2;
        //         } else {
        //             mp[i][len] = max(mp[j][len] + 1,mp[i][len]);
        //         }

        //         ans = max(ans,mp[i][len]);
        //     }
        // }

        // return ans;
    }
};


给定一个整数数组?A，返回 A?中最长等差子序列的长度。

回想一下，A?的子序列是列表?A[i_1], A[i_2], ..., A[i_k] 其中?0 <= i_1 < i_2 < ... < i_k <= A.length - 1。并且如果?B[i+1] - B[i](?0 <= i < B.length - 1) 的值都相同，那么序列?B?是等差的。

?

示例 1：

输入：[3,6,9,12]
输出：4
解释： 
整个数组是公差为 3 的等差数列。
示例 2：

输入：[9,4,7,2,10]
输出：3
解释：
最长的等差子序列是 [4,7,10]。
示例 3：

输入：[20,1,15,3,10,5,8]
输出：4
解释：
最长的等差子序列是 [20,15,10,5]。
?

提示：

2 <= A.length <= 2000
0 <= A[i] <= 10000

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/longest-arithmetic-subsequence
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
