给出一些不同颜色的盒子，盒子的颜色由数字表示，即不同的数字表示不同的颜色。
你将经过若干轮操作去去掉盒子，直到所有的盒子都去掉为止。每一轮你可以移除具有相同颜色的连续 k 个盒子（k?>= 1），这样一轮之后你将得到 k*k 个积分。
当你将所有盒子都去掉之后，求你能获得的最大积分和。

?

示例：

输入：boxes = [1,3,2,2,2,3,4,3,1]
输出：23
解释：
[1, 3, 2, 2, 2, 3, 4, 3, 1] 
----> [1, 3, 3, 4, 3, 1] (3*3=9 分) 
----> [1, 3, 3, 3, 1] (1*1=1 分) 
----> [1, 1] (3*3=9 分) 
----> [] (2*2=4 分)
?

提示：

1 <= boxes.length <= 100
1 <= boxes[i]?<= 100


class Solution {
public:
    int dp[101][101][101];
    int removeBoxes(vector<int>& boxes) {
        memset(dp,0x00,sizeof(dp));

        return dfs(boxes,0,boxes.size()-1,0);
    }

    int dfs(vector<int>& boxes,int le,int ri,int k)
    {
        if(le > ri) return 0;
        if(dp[le][ri][k] != 0)  return dp[le][ri][k];

        //判断右侧相同颜色的盒子数量，去掉右侧盒子
        while(le < ri && boxes[ri] == boxes[ri-1])
        {
            ri--;
            k++;
        }
        dp[le][ri][k] = dfs(boxes,le,ri-1,0) + (k + 1) * (k + 1);

        //去掉左侧的盒子
        for(int i = le; i < ri; i++)
            if(boxes[i] == boxes[ri])
                dp[le][ri][k] = max(dp[le][ri][k],dfs(boxes,le,i,k+1) + dfs(boxes,i+1,ri-1,0));
        return dp[le][ri][k];
    }
};
