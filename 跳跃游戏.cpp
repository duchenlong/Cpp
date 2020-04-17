//给定一个非负整数数组，你最初位于数组的第一个位置。

//数组中的每个元素代表你在该位置可以跳跃的最大长度。

//判断你是否能够到达最后一个位置。

//示例?1:

//输入: [2,3,1,1,4]
//输出: true
//解释: 我们可以先跳 1 步，从位置 0 到达 位置 1, 然后再从位置 1 跳 3 步到达最后一个位置。
//示例?2:

//输入: [3,2,1,0,4]
//输出: false
//解释: 无论怎样，你总会到达索引为 3 的位置。但该位置的最大跳跃长度是 0 ， 所以你永远不可能到达最后一个位置。

class Solution {
public:
    bool canJump(vector<int>& nums) {
        int len = nums.size();
        int ans = 0;

        for(int i = 0; i < len; i++)
        {
            if(i > ans)
                return false;
            ans = max(ans,i + nums[i]); 
        }

        return true;
    }
};
//
//给定一个非负整数数组，你最初位于数组的第一个位置。

//数组中的每个元素代表你在该位置可以跳跃的最大长度。

//你的目标是使用最少的跳跃次数到达数组的最后一个位置。

//示例:

//输入: [2,3,1,1,4]
//输出: 2
//解释: 跳到最后一个位置的最小跳跃数是 2。
//?    从下标为 0 跳到下标为 1 的位置，跳?1?步，然后跳?3?步到达数组的最后一个位置。


class Solution {
public:
    int jump1(vector<int>& nums) {
        int len = nums.size();
        int min_jump = 0x0000ffff;
        dfs(nums,len,0,min_jump,0);
        return min_jump;
    }
    //深搜超时  [5,6,4,4,6,9,4,4,7,4,4,8,2,6,8,1,5,9,6,5,2,7,9,7,9,6,9,4,1,6,8,8,4,4,2,0,3,8,5]
    void dfs(vector<int>& nums, int& len, int index,int& min_jump,int now_jump)
    {
        //判断是否可以直接跳到最后一步
        if(index >= len-1)
        {
            min_jump = min(min_jump,now_jump);
            return ;
        }

        for(int i = 1; i <= nums[index]; i++)
        {
            //可以加一个剪枝，如果当前可以跳到的最远距离比目前的最远距离小，就剪掉
            dfs(nums,len,index+i,min_jump,now_jump+1);
        }
    }
    //动态规划 [全1] 超时
    int jump2(vector<int>& nums) {
        int len = nums.size();
        vector<int> dp(len,0x0000ffff);//dp[i]表示跳到当前位置最小跳跃次数
        dp[0] = 0;
        for(int i = 0; i < len; i++)
        {
            int jump = min(len-1,i+nums[i]);
            for(int j = 1; j <= jump; j++)
            {
                dp[j] = min(dp[j],dp[i]+1);
            }
        }

        return dp[len-1];
    }

    //每一次遍历就找当前可以到的最远的距离进行比较
    int jump(vector<int>& nums){
        int end = 0;
        int maxPosition = 0; 
        int steps = 0;
        for(int i = 0; i < nums.size() - 1; i++)
        {
         //找能跳的最远的
            maxPosition = max(maxPosition, nums[i] + i); 
            if( i == end) //遇到边界，就更新边界，并且步数加一
            {
                end = maxPosition;
                steps++;
            }
        }
        return steps;
    }
};
