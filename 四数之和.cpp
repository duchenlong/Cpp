//给定一个包含?n 个整数的数组?nums?和一个目标值?target，判断?nums?中是否存在四个元素 a，b，c?和 d?，使得?a + b + c + d?的值与?target?相等？找出所有满足条件且不重复的四元组。

//注意：

//答案中不可以包含重复的四元组。

//示例：

//给定数组 nums = [1, 0, -1, 0, -2, 2]，和 target = 0。

//满足要求的四元组集合为：
//[
//  [-1,  0, 0, 1],
//  [-2, -1, 1, 2],
//  [-2,  0, 0, 2]
//]


class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        int len = nums.size();
        if(len < 4) return {};

        sort(nums.begin(),nums.end());

        vector<vector<int> > ans;
        for(int i = 0; i < len; i++)
        {
            if(i > 0 && nums[i] == nums[i-1]) continue;
            vector<vector<int> > tmp = threeSum(nums,i+1,len-1,target - nums[i],nums[i]);

            for(auto& eoch : tmp)
                ans.push_back(eoch);
        }
        return ans;
    }

    vector<vector<int>> threeSum(vector<int>& nums,int le,int ri,int tar,int n) {
        int len = ri - le + 1;
        if(len <= 2) return {};

        vector<vector<int> > ans;

        for(int one = le; one < ri; one++)
        {
            if(one > le && nums[one] == nums[one-1]) continue;

            int target = tar - nums[one];
            int three = ri;

            for(int two = one + 1; two < ri; two++)
            {
                if(two > one + 1 && nums[two] == nums[two - 1]) continue;

                //二分
                //three = BinaryFind(nums,two + 1,three,target-nums[two]);
                // if(three != -1)
                //     ans.push_back({nums[one],nums[two],nums[three]});

                while(two < three && nums[three] > (target - nums[two]))
                    three--;

                if(two == three) continue;
                if(nums[three] == (target - nums[two]))
                    ans.push_back({n,nums[one],nums[two],nums[three]});
            }
        }

        return ans;
    }
};
