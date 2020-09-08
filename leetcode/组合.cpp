给定两个整数 n 和 k，返回 1 ... n 中所有可能的 k 个数的组合。

示例:

输入:?n = 4, k = 2
输出:
[
  [2,4],
  [3,4],
  [2,3],
  [1,2],
  [1,3],
  [1,4],
]


class Solution {
public:
    vector<vector<int> > ans;
    vector<vector<int>> combine(int n, int k) {
        vector<int> tmp;
        dfs(tmp,1,n,k);

        return ans;
    }

    void dfs(vector<int>& tmp,int idx,int n,int k) {
        if(tmp.size() == k) {
            ans.push_back(tmp);
            return ;
        }

        for(int i = idx; i <= n; i++) {
            tmp.push_back(i);

            dfs(tmp,i+1,n,k);
            
            tmp.pop_back();
        }
    }
};
