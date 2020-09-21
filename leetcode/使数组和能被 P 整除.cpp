class Solution {
public:
    using ll = long long;
    int minSubarray(vector<int>& nums, int p) {
        ll mod = 0;
        ll sum = 0;
        int n = nums.size();
        for(int i = 0; i < n; i++) {
            mod = (mod + nums[i]) % p;
            sum += nums[i];
        }

        if(sum < p) return -1;
        if(mod == 0) return 0;

        int ans = INT_MAX;
        int s = 0;
        unordered_map<int,int> m;
        m[0] = -1;
        for(int i = 0; i < n; i++) {
            s =  (s + nums[i]) % p;
            int cur = (s - mod + p) % p;
            if(m.count(cur) > 0) {
                ans = min(ans,i - m[cur]);
            }

            m[s] = i;
        }

        return ans >= n ? -1 : ans;
    }
};

给你一个正整数数组?nums，请你移除 最短?子数组（可以为 空），使得剩余元素的 和?能被 p?整除。 不允许?将整个数组都移除。

请你返回你需要移除的最短子数组，如果无法满足题目要求，返回 -1?。

子数组?定义为原数组中连续的一组元素。

?

示例 1：

输入：nums = [3,1,4,2], p = 6
输出：1
解释：nums 中元素和为 10，不能被 p 整除。我们可以移除子数组 [4] ，剩余元素的和为 6 。
示例 2：

输入：nums = [6,3,5,2], p = 9
输出：2
解释：我们无法移除任何一个元素使得和被 9 整除，最优方案是移除子数组 [5,2] ，剩余元素为 [6,3]，和为 9 。
示例?3：

输入：nums = [1,2,3], p = 3
输出：0
解释：和恰好为 6 ，已经能被 3 整除了。所以我们不需要移除任何元素。
示例? 4：

输入：nums = [1,2,3], p = 7
输出：-1
解释：没有任何方案使得移除子数组后剩余元素的和被 7 整除。
示例 5：

输入：nums = [1000000000,1000000000,1000000000], p = 3
输出：0
?

提示：

1 <= nums.length <= 105
1 <= nums[i] <= 109
1 <= p <= 109

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/make-sum-divisible-by-p
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
