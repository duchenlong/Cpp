给定一个未经排序的整数数组，找到最长且连续的的递增序列，并返回该序列的长度。

?

示例 1:

输入: [1,3,5,4,7]
输出: 3
解释: 最长连续递增序列是 [1,3,5], 长度为3。
尽管 [1,3,5,7] 也是升序的子序列, 但它不是连续的，因为5和7在原数组里被4隔开。 
示例 2:

输入: [2,2,2,2,2]
输出: 1
解释: 最长连续递增序列是 [2], 长度为1。


class Solution {
public:
    int findLengthOfLCIS(vector<int>& nums) {
        int n = nums.size();
        if(n == 0)  return 0;
        int le = 0;
        int len = 1;
        int ans = 1;

        for(int i = 1; i < n; i++){
            if(nums[i] <= nums[i-1]){
                le = i;
                len = 1;
                continue;
            }

            len++;
            ans = max(ans,len);
        }

        return ans;
    }
};
