class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        vector<vector<int> > ans;
        ans.push_back({});
        int n = nums.size();

        int pre = 1;
        for(int i = 0; i < n; i++) {
            int m = ans.size();
            if(i && nums[i] != nums[i - 1]) pre = m;

            for(int j = m - pre; j < m; j++) {
                
               vector<int> t = ans[j];
               t.push_back(nums[i]); 
               ans.push_back(t);
            }
        }

        return ans;
    }
};


给定一个可能包含重复元素的整数数组 nums，返回该数组所有可能的子集（幂集）。

说明：解集不能包含重复的子集。

示例:

输入: [1,2,2]
输出:
[
  [2],
  [1],
  [1,2,2],
  [2,2],
  [1,2],
  []
]

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/subsets-ii
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
