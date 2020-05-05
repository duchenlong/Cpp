//给定一个包括?n 个整数的数组?nums?和 一个目标值?target。找出?nums?中的三个整数，使得它们的和与?target?最接近。返回这三个数的和。假定每组输入只存在唯一答案。

//例如，给定数组 nums = [-1，2，1，-4], 和 target = 1.

//与 target 最接近的三个数的和为 2. (-1 + 2 + 1 = 2).


class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(),nums.end());
        int len = nums.size();

        int ans_sum = Add(nums,0,1,2);
        int ans_sub =  Sub(ans_sum,target);

        for(int i = 0; i < len - 2; i++)
        {
            int left = i + 1;
            int right = len - 1;
            while(left < right)
            {
                int sum = Add(nums,i,left,right);
                int sub = Sub(sum,target);
                if(sub < ans_sub) 
                {
                    ans_sum = sum;
                    ans_sub = sub;
                }
                if(sum > target) right--;
                else left++;
            }
        }
        return ans_sum;
    }

    static int Add(vector<int>& nums,int left,int mid,int right)
    {
        return nums[left] + nums[mid] + nums[right];
    }

    static int Sub(int num, int target)
    {
        return abs(num - target);
    }
};
