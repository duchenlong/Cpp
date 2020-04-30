//给定一个?n?个元素有序的（升序）整型数组?nums 和一个目标值?target ?，写一个函数搜索?nums?中的 target，如果目标值存在返回下标，否则返回 -1。


//示例 1:

//输入: nums = [-1,0,3,5,9,12], target = 9
//输出: 4
//解释: 9 出现在 nums 中并且下标为 4
//示例?2:

//输入: nums = [-1,0,3,5,9,12], target = 2
//输出: -1
//解释: 2 不存在 nums 中因此返回 -1

class Solution {
public:
    int search(vector<int>& nums, int target) {
        int len = nums.size();
        int left = 0;
        int right = len - 1;
        //[left,right]，左闭右闭区间 
        while(left <= right) {
            int  mid = (left + right)>>1;
            if(nums[mid] == target) return mid;
            else if(nums[mid] > target) right = mid - 1;
            else left = mid + 1;
        }
        return -1;
    }
}; 
//给定一个按照升序排列的整数数组 nums，和一个目标值 target。找出给定目标值在数组中的开始位置和结束位置。

//你的算法时间复杂度必须是?O(log n) 级别。

//如果数组中不存在目标值，返回?[-1, -1]。

class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int len = nums.size();
        vector<int> ans(2,-1);
        ans[0] = BinaryFindLeft(nums,target,0,len-1);
        ans[1] = BinaryFindRight(nums,target,0,len-1);
        return ans;
    }
    //寻找左侧边界
    int BinaryFindLeft(vector<int>& nums, int target,int left,int right) {
        if(left > right) return -1;
        int len = right + 1;
        //[left,right) 左闭右开的写法
        right += 1;
        while(left < right) //终止条件是left == right
            int mid = (left + right) / 2;
            int num = nums[mid];

            if(num == target) right = mid;
            else if(num < target) left = mid + 1;
            else if(num > target) right = mid;
        }

        //[left,right] 左闭右闭的写法
        // while(left <= right) {//终止条件是 left - 1 = right
        //     int mid = (left + right) / 2;
        //     int num = nums[mid];
        //     if(num == target) right = mid - 1;
        //     else if(num > target) right = mid - 1;
        //     else if(num < target) left = mid + 1;
        // }
        if(left >= len || nums[left] != target) return -1;
        return left;
    }
    //寻找右侧边界
    int BinaryFindRight(vector<int>& nums,int target,int left,int right) {
        if(left > right) return -1;
        int len = right + 1;
        //[left,right) 左闭右开的写法
        right += 1;
        while(left < right) {//终止条件是left == right
            int mid = (left + right) / 2;
            int num = nums[mid];

            if(num == target) left = mid + 1;
            else if(num < target) left = mid + 1;
            else if(num > target) right = mid;
        }
        if(right <= 0 || nums[right-1] != target) return -1;
        return right-1;//右侧区间为开区间

        //[left,right] 左闭右闭的写法
        // while(left <= right) {
        //     int mid = (left + right) / 2;
        //     int num = nums[mid];
        //     if(num == target) left = mid + 1;
        //     else if(num > target) right = mid - 1;
        //     else if(num < target) left = mid + 1;
        // }

        //if(right < 0 || nums[right] != target) return -1;
        //return right;
    }
};
