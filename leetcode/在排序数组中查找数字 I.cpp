class Solution {
public:
    int search(vector<int>& nums, int target) {
        int n = nums.size();
        int le = 0, ri = n -1;
        while(le < ri) {
            int mid = le + ri >> 1;
            if(nums[mid] >= target) ri = mid;
            else le = mid + 1;
        }

        if(!n || nums[le] != target) return 0;
        int a = le;
        le = 0, ri = n - 1;
        while(le < ri) {
            int mid = le + ri + 1 >> 1;
            if(nums[mid] <= target) le = mid;
            else ri = mid - 1;
        }
        return le - a + 1;
    }
};


统计一个数字在排序数组中出现的次数。

?

示例 1:

输入: nums = [5,7,7,8,8,10], target = 8
输出: 2
示例?2:

输入: nums = [5,7,7,8,8,10], target = 6
输出: 0
?

限制：

0 <= 数组长度 <= 50000

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/zai-pai-xu-shu-zu-zhong-cha-zhao-shu-zi-lcof
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
