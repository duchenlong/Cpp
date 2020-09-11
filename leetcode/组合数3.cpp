找出所有相加之和为?n 的?k?个数的组合。组合中只允许含有 1 -?9 的正整数，并且每种组合中不存在重复的数字。

说明：

所有数字都是正整数。
解集不能包含重复的组合。?
示例 1:

输入: k = 3, n = 7
输出: [[1,2,4]]
示例 2:

输入: k = 3, n = 9
输出: [[1,2,6], [1,3,5], [2,3,4]]

class Solution {
public:
    vector<vector<int> > ans;
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<int> tmp;
        dfs(1,0,k,n,tmp);
        return ans;
    }

    void dfs(int idx,int sum,int k,int n,vector<int>& tmp) {
        if(sum == n && tmp.size() == k) {
            ans.push_back(tmp);
            return ;
        }
        if (sum > n || tmp.size() > k) 
            return ;

        for(int i = idx; i <= 9; i++) {
            tmp.push_back(i);
            dfs(i + 1, sum + i,k,n,tmp);
            tmp.pop_back();
        }
    }
};
