//给定一个包含?n + 1 个整数的数组?nums，其数字都在 1 到 n?之间（包括 1 和 n），可知至少存在一个重复的整数。假设只有一个重复的整数，找出这个重复的数。

//示例 1:

//输入: [1,3,4,2,2]
//输出: 2
//示例 2:

//输入: [3,1,3,4,2]
//输出: 3
//说明：

//不能更改原数组（假设数组是只读的）。
//只能使用额外的 O(1) 的空间。
//时间复杂度小于 O(n2) 。
//数组中只有一个重复的数字，但它可能不止重复出现一次。

class Solution {
public:
    int findDuplicate1(vector<int>& nums) {
        int left = 1;
        int right = nums.size()-1;

        while(left < right)
        {
            int mid = (left + right) / 2;
            int count = 0;
            for(auto& eoch : nums)
                if(eoch <= mid) count++;
            
            if(count <= mid)
                left = mid+1;
            else if(count > mid)
                right = mid;
        }
        return left;
    }

    int findDuplicate(vector<int>& nums)
    {
        int slow = 0;
        int fast = 0;
        do
        {
            slow = nums[slow];
            fast = nums[fast];
            fast = nums[fast];
        }while(slow != fast);

        int ans = 0;
        while(ans != slow)
        {
            ans = nums[ans];
            slow = nums[slow];
        }

        return ans;
    }
};
