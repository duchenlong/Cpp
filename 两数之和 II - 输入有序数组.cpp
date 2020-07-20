给定一个已按照升序排列?的有序数组，找到两个数使得它们相加之和等于目标数。

函数应该返回这两个下标值 index1 和 index2，其中 index1?必须小于?index2。

说明:

返回的下标值（index1 和 index2）不是从零开始的。
你可以假设每个输入只对应唯一的答案，而且你不可以重复使用相同的元素。
示例:

输入: numbers = [2, 7, 11, 15], target = 9
输出: [1,2]
解释: 2 与 7 之和等于目标数 9 。因此 index1 = 1, index2 = 2 。


class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int len = numbers.size();

        //二分
        // for(int i = 0; i < len-1; i++)
        // {
        //     int pos = BinaryFind(numbers,i+1,len-1,target-numbers[i]);
        //     if(numbers[pos] == target - numbers[i])
        //         return {i+1,pos+1};
        // }

        int le = 0;
        int ri = len-1;
        while(le < ri)
        {
            int num = numbers[le] + numbers[ri];
            if(num == target)
                return {le+1,ri+1};
            else if(num < target)
                le++;
            else if(num > target)
                ri--;
        }

        return {};
    }

    int BinaryFind(vector<int>& nums,int le,int ri,int n)
    {
        if(le > ri) return le;

        while(le < ri)
        {
            int mid = (le + ri) / 2;
            if(nums[mid] == n) return mid;

            if(nums[mid] < n)   le = mid + 1;
            else if(nums[mid] > n)  ri = mid - 1;
        }

        return le;
    }
};
