给定一个整型数组, 你的任务是找到所有该数组的递增子序列，递增子序列的长度至少是2。

示例:

输入: [4, 6, 7, 7]
输出: [[4, 6], [4, 7], [4, 6, 7], [4, 6, 7, 7], [6, 7], [6, 7, 7], [7,7], [4,7,7]]
说明:

给定数组的长度不会超过15。
数组中的整数范围是?[-100,100]。
给定数组中可能包含重复数字，相等的数字应该被视为递增的一种情况。

class Solution {
public:
    int n = 0;
    vector<vector<int>> findSubsequences(vector<int>& nums) {
        n = nums.size();
        vector<int> tmp;
        set<vector<int> > ans;
        dfs(ans,0,nums,tmp);

        return vector<vector<int> > (ans.begin(),ans.end());
    }

    void dfs(set<vector<int> >& ans,int idx,vector<int>& nums,vector<int>& tmp){
        if(tmp.size() > 1) ans.insert(tmp);
        if(idx >= n)    return;

        int pre = (tmp.size() == 0) ?  INT_MIN : tmp.back();
        for(int i = idx; i < n; i++){
            tmp.push_back(nums[i]);

            if(tmp.back() >= pre)
                dfs(ans,i+1,nums,tmp);

            tmp.pop_back();
        }
    }
};
