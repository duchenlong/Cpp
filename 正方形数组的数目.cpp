给定一个非负整数数组?A，如果该数组每对相邻元素之和是一个完全平方数，则称这一数组为正方形数组。

返回 A 的正方形排列的数目。两个排列 A1 和 A2 不同的充要条件是存在某个索引 i，使得 A1[i] != A2[i]。

?

示例 1：

输入：[1,17,8]
输出：2
解释：
[1,8,17] 和 [17,8,1] 都是有效的排列。
示例 2：

输入：[2,2,2]
输出：1
?

提示：

1 <= A.length <= 12
0 <= A[i] <= 1e9



class Solution {
public:
    unordered_map<int,int> map;
    int len = 0;
    int ans = 0;
    int numSquarefulPerms(vector<int>& A) {
        len = A.size();
        for(auto& num : A)
            map[num]++;
        
        for(auto& num : map)
            dfs(num.first,1);
        
        return ans;
    }

    void dfs(int cur,int depth)
    {
        if(depth == len)
        {
            ans++;
            return;
        }
        map[cur]--;
        for(auto& num : map)
        {
            if(map[num.first] && IsSquare(cur + num.first))
                dfs(num.first,depth+1);
        }
        map[cur]++;
    }

    bool IsSquare(int num)
    {
        int tmp = sqrt(num);
        return tmp * tmp == num;
    }
};
