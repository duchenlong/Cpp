class Solution {
public:
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        unordered_map<string,int> mp;
        int n = equations.size();
        int idx = 0;
        for(auto& e : equations) {
            if(mp.count(e[0]) == 0) mp[e[0]] = idx++;
            if(mp.count(e[1]) == 0) mp[e[1]] = idx++;
        }

        vector<vector<double> > f(idx,vector<double> (idx,0));
        for(int i = 0; i < n; i++) {
            int x = mp[equations[i][0]], y = mp[equations[i][1]];
            f[x][y] = values[i];
            f[y][x] = 1.0 / values[i];
        }

        for(int k = 0; k < idx; k++)
            for(int i = 0; i < idx; i++)
                for(int j = 0; j < idx; j++)
                    if(f[i][k] != 0 && f[k][j] != 0)
                        f[i][j] = f[i][k] * f[k][j];
        
        vector<double> res;
        for(auto& e : queries) {
            double t = -1.0;
            if(mp.count(e[0]) && mp.count(e[1])) {
                int x = mp[e[0]], y = mp[e[1]];
                if(f[x][y] != 0)    t = f[x][y];
            }
            res.push_back(t);
        }
        return res;
    }
};

给你一个变量对数组 equations 和一个实数值数组 values 作为已知条件，其中 equations[i] = [Ai, Bi] 和 values[i] 共同表示等式 Ai / Bi = values[i] 。每个 Ai 或 Bi 是一个表示单个变量的字符串。

另有一些以数组 queries 表示的问题，其中 queries[j] = [Cj, Dj] 表示第 j 个问题，请你根据已知条件找出 Cj / Dj = ? 的结果作为答案。

返回 所有问题的答案 。如果存在某个无法确定的答案，则用 -1.0 替代这个答案。

?

注意：输入总是有效的。你可以假设除法运算中不会出现除数为 0 的情况，且不存在任何矛盾的结果。

?

示例 1：

输入：equations = [["a","b"],["b","c"]], values = [2.0,3.0], queries = [["a","c"],["b","a"],["a","e"],["a","a"],["x","x"]]
输出：[6.00000,0.50000,-1.00000,1.00000,-1.00000]
解释：
条件：a / b = 2.0, b / c = 3.0
问题：a / c = ?, b / a = ?, a / e = ?, a / a = ?, x / x = ?
结果：[6.0, 0.5, -1.0, 1.0, -1.0 ]
示例 2：

输入：equations = [["a","b"],["b","c"],["bc","cd"]], values = [1.5,2.5,5.0], queries = [["a","c"],["c","b"],["bc","cd"],["cd","bc"]]
输出：[3.75000,0.40000,5.00000,0.20000]
示例 3：

输入：equations = [["a","b"]], values = [0.5], queries = [["a","b"],["b","a"],["a","c"],["x","y"]]
输出：[0.50000,2.00000,-1.00000,-1.00000]
?

提示：

1 <= equations.length <= 20
equations[i].length == 2
1 <= Ai.length, Bi.length <= 5
values.length == equations.length
0.0 < values[i] <= 20.0
1 <= queries.length <= 20
queries[i].length == 2
1 <= Cj.length, Dj.length <= 5
Ai, Bi, Cj, Dj 由小写英文字母与数字组成

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/evaluate-division
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
