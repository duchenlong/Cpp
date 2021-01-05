class Solution {
public:
    int findMin(vector<int>& nums) {
        int n = nums.size();
        if(nums[n - 1] > nums[0]) return nums[0];

        int le = 0, ri = n - 1;
        while (le < ri) {
            // 排除相同元素的影响
            while(le < ri && nums[le] == nums[ri]) le++;
            
            int mid = le + ri >> 1;
           
            // 和右区间相比，[3,1,3,3]
            // 最后的结果和右区间相比才有单调性
            if(nums[mid] > nums[n - 1])
                le = mid + 1;
            else
                ri = mid;
        }

        return nums[le];
    }
};

假设按照升序排序的数组在预先未知的某个点上进行了旋转。

( 例如，数组?[0,1,2,4,5,6,7] 可能变为?[4,5,6,7,0,1,2]?)。

请找出其中最小的元素。

注意数组中可能存在重复的元素。

示例 1：

输入: [1,3,5]
输出: 1
示例?2：

输入: [2,2,2,0,1]
输出: 0
说明：

这道题是?寻找旋转排序数组中的最小值?的延伸题目。
允许重复会影响算法的时间复杂度吗？会如何影响，为什么？

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/find-minimum-in-rotated-sorted-array-ii
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
