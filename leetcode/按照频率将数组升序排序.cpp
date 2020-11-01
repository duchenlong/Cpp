class Solution {
public:
    vector<int> frequencySort(vector<int>& nums) {
        int ans = 0;
        unordered_map<int,int> hash;    // 统计出现次数
        for(auto& n : nums) hash[n]++;

        sort(nums.begin(),nums.end(),[&](const int a,const int b)->bool{
            int le = hash[a], ri = hash[b];
            return (le != ri) ? le < ri : a > b;
        });

        return nums;
        // unordered_map<int,int> hash;
        // for(auto& num : nums)   hash[num]++;
        
        // vector<int> ans;
        // int len = 1;
        // for(int i = 1; i <= 100; i++) {
        //     vector<int> t;
        //     for(auto& eoch : hash)  if(eoch.second == i) t.push_back(eoch.first);
            
        //     sort(t.begin(),t.end(),[](const int& a,const int& b)->bool{
        //         return a > b;
        //     });
            
        //     for(auto& n : t)
        //         for(int j = 0; j < i; j++)  ans.push_back(n);
        // }
        
        // return ans;
    }
};
给你一个整数数组?nums?，请你将数组按照每个值的频率 升序 排序。如果有多个值的频率相同，请你按照数值本身将它们 降序 排序。?

请你返回排序后的数组。

?

示例 1：

输入：nums = [1,1,2,2,2,3]
输出：[3,1,1,2,2,2]
解释：'3' 频率为 1，'1' 频率为 2，'2' 频率为 3 。
示例 2：

输入：nums = [2,3,1,3,2]
输出：[1,3,3,2,2]
解释：'2' 和 '3' 频率都为 2 ，所以它们之间按照数值本身降序排序。
示例 3：

输入：nums = [-1,1,-6,4,5,-6,1,4,1]
输出：[5,-1,4,4,-6,-6,1,1,1]
?

提示：

1 <= nums.length <= 100
-100 <= nums[i] <= 100

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/sort-array-by-increasing-frequency
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
