给定一个整数数组和一个整数?k，判断数组中是否存在两个不同的索引?i?和?j，使得?nums [i] = nums [j]，并且 i 和 j?的差的 绝对值 至多为 k。

?

示例?1:

输入: nums = [1,2,3,1], k = 3
输出: true
示例 2:

输入: nums = [1,0,1,1], k = 1
输出: true
示例 3:

输入: nums = [1,2,3,1,2,3], k = 2
输出: false

class Solution {
public:
    bool containsNearbyDuplicate1(vector<int>& nums, int k) {
        int len = nums.size();
        for(int i = 0; i < len; i++)
        {
            int le = max(0,i - k);
            int ri = min(len-1,i+k);

            for(int j = le; j <= ri; j++)
            {
                if(i != j && nums[i] == nums[j])
                    return true;
            }
        }
        return false;
    }

    bool containsNearbyDuplicate(vector<int>& nums, int k)
    {
        int len = nums.size();
        unordered_map<int,vector<int> > map;

        for(int i = 0; i < len; i++)
        {
            map[nums[i]].push_back(i);

            for(auto& n : map[nums[i]])
            {
                if(n != i && abs(n - i) <= k)
                    return true;
            }
        }
        return false;
    }
};
