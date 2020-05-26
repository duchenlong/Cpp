//给你一个未排序的整数数组，请你找出其中没有出现的最小的正整数。

//?

//示例?1:

//输入: [1,2,0]
//输出: 3
//示例?2:

//输入: [3,4,-1,1]
//输出: 2
//示例?3:

//输入: [7,8,9,11,12]
//输出: 1


class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int len = nums.size();

        for(int i = 0; i < len; i++)
            while(nums[i] > 0 && nums[i] <= len && nums[i] != nums[nums[i] - 1])
                Swap(nums,nums[i] - 1, i);//将数字放在前len个数字排序后的位置，3 --》 2号位置
        
        // [1, -1, 3, 4]
        for(int i = 0; i < len; i++)
            if(nums[i] != i + 1) return i + 1;
        return len+1;
    }

    void Swap(vector<int>& nums,int num,int i)
    {
        int tmp = nums[i];
        nums[i] = nums[num];
        nums[num] = tmp;
    }
};
