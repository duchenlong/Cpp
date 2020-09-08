
给定一个数组?candidates?和一个目标数?target?，找出?candidates?中所有可以使数字和为?target?的组合。

candidates?中的每个数字在每个组合中只能使用一次。

说明：

所有数字（包括目标数）都是正整数。
解集不能包含重复的组合。?
示例?1:

输入: candidates =?[10,1,2,7,6,1,5], target =?8,
所求解集为:
[
  [1, 7],
  [1, 2, 5],
  [2, 6],
  [1, 1, 6]
]
示例?2:

输入: candidates =?[2,5,2,1,2], target =?5,
所求解集为:
[
? [1,2,2],
? [5]
]

class Solution {
public:
    vector<vector<int> > ans;
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<int> tmp;
        sort(candidates.begin(),candidates.end(),[](const int a,const int b)->bool{
            return a < b;
        });

        dfs(tmp,candidates,0,0,target);

        return ans;
    }

    void dfs(vector<int>& tmp,vector<int>& candidates,int idx,int cur,int target) {
        if(cur > target) return ;
        if(cur == target) {
            ans.push_back(tmp);
            return ;
        }

        for(int i = idx; i < candidates.size(); i++) {
            if(i > idx && candidates[i] == candidates[i-1]) continue;
            
            tmp.push_back(candidates[i]);

            dfs(tmp,candidates,i+1,cur + candidates[i],target);

            tmp.pop_back();
        }
    }
};
