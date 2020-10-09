class Solution {
public:
    void wiggleSort(vector<int>& nums) {
        int n = nums.size();
        nth_element(nums.begin(),nums.begin() + n / 2,nums.end());
        int mid = nums[n/2];        // 找中位数 
        
        // +++ === ---
        int le = 0, ri = n - 1;
        int pos = 0;
        while(pos <= ri) {
            if(nums[pos] > mid) swap(nums[pos++],nums[le++]);
            else if(nums[pos] < mid) swap(nums[pos],nums[ri--]);
            else if(nums[pos] == mid) pos++;
        }

        // 0 - 1  1 - 3 2 - 5
        vector<int> copy = nums;
        for(int i = 0; i < n; i++) nums[(i * 2 + 1) % (n | 1)] = copy[i];
    }
};


给定一个无序的数组?nums，将它重新排列成?nums[0] < nums[1] > nums[2] < nums[3]...?的顺序。

示例?1:

输入: nums = [1, 5, 1, 1, 6, 4]
输出: 一个可能的答案是 [1, 4, 1, 5, 1, 6]
示例 2:

输入: nums = [1, 3, 2, 2, 3, 1]
输出: 一个可能的答案是 [2, 3, 1, 3, 1, 2]
说明:
你可以假设所有输入都会得到有效的结果。

进阶:
你能用?O(n) 时间复杂度和 / 或原地 O(1) 额外空间来实现吗？

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/wiggle-sort-ii
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。 
