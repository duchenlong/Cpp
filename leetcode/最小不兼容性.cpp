class Solution {
public:
    int minimumIncompatibility(vector<int>& nums, int k) {
        int n = nums.size(), INF = 0x3f3f3f3f;
        vector<int> f(1<<n,INF);
        vector<int> g(1<<n);
        int d[16];
        f[0] = 0;

        // 预处理
        for(int i = 1; i < 1<<n; i++) {
            g[i] = -1;
            if(__builtin_popcount(i) != n / k) continue;

            int cnt = 0;    // 得到当前集合中的数据 
            for(int j = 0; j < n; j++)
                if(i >> j & 1) d[cnt++] = nums[j];
            sort(d,d + cnt);

            bool flag = true;
            int minv = d[0],maxv = d[0];
            for(int j = 1; j < cnt; j++) {
                if(d[j] == d[j - 1]) {  // 不能有重复数字
                    flag = false;
                    continue;
                }

                minv = min(minv,d[j]);
                maxv = max(maxv,d[j]);
            }
            if(flag) g[i] = maxv - minv;
        }

        for(int i = 1;i < 1<<n; i++)
            for(int j = i; j ; j = (j - 1) & i) // 枚举子集
                if(g[j] != -1) f[i] = min(f[i],f[i-j] + g[j]);
        int res = f[(1<<n) - 1];
        return res == INF ? -1 : res;
    }
};


给你一个整数数组?nums??? 和一个整数?k?。你需要将这个数组划分到?k?个相同大小的子集中，使得同一个子集里面没有两个相同的元素。

一个子集的 不兼容性?是该子集里面最大值和最小值的差。

请你返回将数组分成 k?个子集后，各子集 不兼容性 的 和?的 最小值?，如果无法分成分成 k?个子集，返回 -1?。

子集的定义是数组中一些数字的集合，对数字顺序没有要求。

?

示例 1：

输入：nums = [1,2,1,4], k = 2
输出：4
解释：最优的分配是 [1,2] 和 [1,4] 。
不兼容性和为 (2-1) + (4-1) = 4 。
注意到 [1,1] 和 [2,4] 可以得到更小的和，但是第一个集合有 2 个相同的元素，所以不可行。
示例 2：

输入：nums = [6,3,8,1,3,1,2,2], k = 4
输出：6
解释：最优的子集分配为 [1,2]，[2,3]，[6,8] 和 [1,3] 。
不兼容性和为 (2-1) + (3-2) + (8-6) + (3-1) = 6 。
示例 3：

输入：nums = [5,3,3,6,3,3], k = 3
输出：-1
解释：没办法将这些数字分配到 3 个子集且满足每个子集里没有相同数字。
?

提示：

1 <= k <= nums.length <= 16
nums.length 能被?k 整除。
1 <= nums[i] <= nums.length

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/minimum-incompatibility
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
