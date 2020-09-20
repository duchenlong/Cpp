class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int> > ans;
        int n = nums.size();

        for(int i = 0; i < n; i++) {
            int m = ans.size();
            for(int j = 0; j < m; j++) {
                vector<int> tmp = ans[j];
                tmp.push_back(nums[i]);
                ans.push_back(tmp);
            }
            ans.push_back({nums[i]});
        }
        ans.push_back({});

        return ans;
    }
};


给定一组不含重复元素的整数数组?nums，返回该数组所有可能的子集（幂集）。

说明：解集不能包含重复的子集。

示例:

输入: nums = [1,2,3]
输出:
[
  [3],
? [1],
? [2],
? [1,2,3],
? [1,3],
? [2,3],
? [1,2],
? []
]

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/subsets
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
