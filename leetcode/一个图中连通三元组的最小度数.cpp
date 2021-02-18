const int N = 500;
int f[N][N];

class Solution {
public:
    int minTrioDegree(int n, vector<vector<int>>& edges) {
        memset(f,0x00,sizeof f);
        vector<int> d(n+1,0);
        unordered_map<int,set<int> > mp;
        for(auto& e : edges) {
            ++ d[e[0]]; 
            mp[e[0]].insert(e[1]);
            ++ d[e[1]]; 
            mp[e[1]].insert(e[0]);
            f[e[0]][e[1]] = 1;
            f[e[1]][e[0]] = 1;
        }
        
        int res = 1e9;
        for(int i = 1; i <= n; i++) {
            if(d[i] < 2) continue;
            for(auto& j : mp[i]) {
                if(d[j] < 2 || j <= i) continue;
                for(auto& k : mp[j]) {
                    if(f[k][i]==0 || k <= j) continue;
                    
                    res = min(res,d[i] + d[j] + d[k] - 6);
                }
            }
        }
        
        return (res == 1e9) ? -1 : res;
    }
};


给你一个整数数组?nums?，其中?nums[i]?表示第?i?个袋子里球的数目。同时给你一个整数?maxOperations?。

你可以进行如下操作至多?maxOperations?次：

选择任意一个袋子，并将袋子里的球分到?2 个新的袋子中，每个袋子里都有 正整数?个球。
比方说，一个袋子里有?5?个球，你可以把它们分到两个新袋子里，分别有 1?个和 4?个球，或者分别有 2?个和 3?个球。
你的开销是单个袋子里球数目的 最大值?，你想要 最小化?开销。

请你返回进行上述操作后的最小开销。

?

示例 1：

输入：nums = [9], maxOperations = 2
输出：3
解释：
- 将装有 9 个球的袋子分成装有 6 个和 3 个球的袋子。[9] -> [6,3] 。
- 将装有 6 个球的袋子分成装有 3 个和 3 个球的袋子。[6,3] -> [3,3,3] 。
装有最多球的袋子里装有 3 个球，所以开销为 3 并返回 3 。
示例 2：

输入：nums = [2,4,8,2], maxOperations = 4
输出：2
解释：
- 将装有 8 个球的袋子分成装有 4 个和 4 个球的袋子。[2,4,8,2] -> [2,4,4,4,2] 。
- 将装有 4 个球的袋子分成装有 2 个和 2 个球的袋子。[2,4,4,4,2] -> [2,2,2,4,4,2] 。
- 将装有 4 个球的袋子分成装有 2 个和 2 个球的袋子。[2,2,2,4,4,2] -> [2,2,2,2,2,4,2] 。
- 将装有 4 个球的袋子分成装有 2 个和 2 个球的袋子。[2,2,2,2,2,4,2] -> [2,2,2,2,2,2,2,2] 。
装有最多球的袋子里装有 2 个球，所以开销为 2 并返回 2 。
示例 3：

输入：nums = [7,17], maxOperations = 2
输出：7
?

提示：

1 <= nums.length <= 105
1 <= maxOperations, nums[i] <= 109
通过次数1,143提交次数2,556

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/minimum-limit-of-balls-in-a-bag
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
