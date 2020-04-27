
//假设按照升序排序的数组在预先未知的某个点上进行了旋转。

//( 例如，数组?[0,1,2,4,5,6,7]?可能变为?[4,5,6,7,0,1,2]?)。

//搜索一个给定的目标值，如果数组中存在这个目标值，则返回它的索引，否则返回?-1?。

//你可以假设数组中不存在重复的元素。

//你的算法时间复杂度必须是?O(log?n) 级别。

//示例 1:

//输入: nums = [4,5,6,7,0,1,2], target = 0
//输出: 4
//示例?2:

//输入: nums = [4,5,6,7,0,1,2], target = 3
//输出: -1


class Solution {
public:
    int search(vector<int>& nums, int target) {
        int len = nums.size();

        return BinarySerch(nums,0,len-1,target);
    }

    int BinarySerch(vector<int>& nums, int left, int right, int target) {
        //如果找不到就返回-1;
        while(left <= right){
            int mid = left + (right - left) / 2;
            if(nums[mid] == target) return mid;
            //因为这是一个有序数组旋转后的结果，所以不存在左边区间的数比右边区间数小的情况
            //先判断mid处在左区间还是右区间
            //判断是否在右区间时，不能加=，计算机的除法是整除
            if(nums[mid] < nums[left]){//当前mid在右区间
                //当前数在右边
                if(nums[right] >= target && nums[mid] < target) left = mid + 1;
                else right = mid - 1;//当前数在左边
            } 
            else {//当前mid为左区间，或者单独的一个递增区间
                //当前数在左边
                if(nums[mid] > target && nums[left] <= target) right = mid - 1;
                else left = mid + 1;//当前数在右边
            }
        }
        return -1;

    }
};
