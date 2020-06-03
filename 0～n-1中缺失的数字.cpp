一个长度为n-1的递增排序数组中的所有数字都是唯一的，并且每个数字都在范围0～n-1之内。在范围0～n-1内的n个数字中有且只有一个数字不在该数组中，请找出这个数字。

?

示例 1:

输入: [0,1,3]
输出: 2
示例?2:

输入: [0,1,2,3,4,5,6,7,9]
输出: 8
?

限制：

1 <= 数组长度 <= 10000



class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int left = 0;
        int right = nums.size()-1;

        while(left < right)
        {
            int mid = (left + right) / 2;

            if(mid == nums[mid])
                left = mid+1;
            else if(mid < nums[mid])
                right = mid;
        }

        return left == nums.size()-1 && nums[left] == left ? left+1 : left;
    }
};
