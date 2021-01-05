class Solution {
public:
    int waysToSplit(vector<int>& nums) {
        int n = nums.size(), mod = 1e9 + 7;
        int res = 0;

        vector<int> f(n + 1);
        for(int i = 0; i < n; i++) f[i + 1] = f[i] + nums[i];

        // [1,x) [x,i) [i,n]
        // j 为 x 的下界， k 为 x 的上界
        for(int i = 3, j = 2, k = 2; i <= n; i++) {
            // 确定中间部分左边界 的下界
            while(f[n] - f[i - 1] < f[i - 1] - f[j - 1]) j++;
            // 确定中间部分左边界 的上界
            while(k < i - 1 && f[i - 1] - f[k] >= f[k]) k++;

            if(j <= k && f[n] - f[i - 1] >= f[i - 1] - f[k - 1] && f[i - 1] - f[j - 1] >= f[j - 1])
                res = (res + k - j + 1) % mod;
        } 

        return res;
    }
};

我们称一个分割整数数组的方案是 好的?，当它满足：

数组被分成三个 非空?连续子数组，从左至右分别命名为?left?，?mid?，?right?。
left?中元素和小于等于?mid?中元素和，mid?中元素和小于等于?right?中元素和。
给你一个 非负 整数数组?nums?，请你返回?好的 分割 nums?方案数目。由于答案可能会很大，请你将结果对 109?+ 7?取余后返回。

?

示例 1：

输入：nums = [1,1,1]
输出：1
解释：唯一一种好的分割方案是将 nums 分成 [1] [1] [1] 。
示例 2：

输入：nums = [1,2,2,2,5,0]
输出：3
解释：nums 总共有 3 种好的分割方案：
[1] [2] [2,2,5,0]
[1] [2,2] [2,5,0]
[1,2] [2,2] [5,0]
示例 3：

输入：nums = [3,2,1]
输出：0
解释：没有好的分割方案。
?

提示：

3 <= nums.length <= 105
0 <= nums[i] <= 104

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/ways-to-split-array-into-three-subarrays
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
