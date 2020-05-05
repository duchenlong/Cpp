给定一个非负整数数组，你最初位于数组的第一个位置。

数组中的每个元素代表你在该位置可以跳跃的最大长度。

你的目标是使用最少的跳跃次数到达数组的最后一个位置。

示例:

输入: [2,3,1,1,4]
输出: 2
解释: 跳到最后一个位置的最小跳跃数是 2。
?    从下标为 0 跳到下标为 1 的位置，跳?1?步，然后跳?3?步到达数组的最后一个位置。
说明:

假设你总是可以到达数组的最后一个位置。


	//BFS
     int jump(vector<int>& nums) {
        int len = nums.size();
        if(len < 2) return 0;

        vector<int> visit(len,0);
        queue<int> que;
        que.push(0);//开始点入队
        visit[0] = 1;

        int ans = 0;
        while(!que.empty())
        {
            int size = que.size();
            for(int i = 0; i < size; i++)
            {
                int pos = que.front();
                que.pop();
                if(pos + nums[pos] >= len-1) return ++ans;
                for(int j = nums[pos]; ~j; j--)
                {
                    if(visit[pos + j]) continue;
                    que.push(pos + j);
                    visit[pos + j] = 1;
                }
            }
            ans++;
        }
        return -1;
    }
