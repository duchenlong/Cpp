给定一个可包含重复数字的序列，返回所有不重复的全排列。

示例:

输入: [1,1,2]
输出:
[
  [1,1,2],
  [1,2,1],
  [2,1,1]
]

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/permutations-ii
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。

class Solution {
public:
    vector<vector<int> > ans;
    vector<int> tmp;
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int n = nums.size();

        dfs(nums,0,n);

        return ans;
    }

    void dfs(vector<int>& nums,int idx,int n) {
        if(idx == n) {
            ans.push_back(tmp);
            return ;
        }

        int pre = 0x3f3f3f3f;
        for(int i = 0; i < n; i++) {
            if(nums[i] == 0x3f3f3f3f || nums[i] == pre) continue;
            pre = nums[i];
            tmp.push_back(nums[i]);
            nums[i] = 0x3f3f3f3f;
            
            dfs(nums,idx+1,n);

            tmp.pop_back();
            nums[i] = pre;
        }
    }
};
