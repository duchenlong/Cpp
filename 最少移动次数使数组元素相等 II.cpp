//给定一个非空整数数组，找到使所有数组元素相等所需的最小移动数，其中每次移动可将选定的一个元素加1或减1。 您可以假设数组的长度最多为10000。

//例如:

//输入:
//[1,2,3]

//输出:
//2

//说明：
//只有两个动作是必要的（记得每一步仅可使其中一个元素加1或减1）： 

//[1,2,3]  =>  [2,2,3]  =>  [2,2,2]


class Solution {
public:
    int minMoves1(vector<int>& nums) {
        int len = nums.size();
        if(len < 2) return 0;
        sort(nums.begin(),nums.end());
        int midNum = nums[len/2];

        int ret = 0;
        for(auto& eoch : nums)
            ret += abs(eoch - midNum);
        return ret;
    }

    int minMoves2(vector<int>& nums)
    {
        sort(nums.begin(),nums.end());
        int left = 0;
        int right = nums.size() - 1;
        int ret = 0;

        while(left < right)
        {
            ret += nums[right--] - nums[left++];
        }
        return ret;
    }
};
