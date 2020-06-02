//给你一份工作时间表?hours，上面记录着某一位员工每天的工作小时数。

//我们认为当员工一天中的工作小时数大于?8 小时的时候，那么这一天就是「劳累的一天」。

//所谓「表现良好的时间段」，意味在这段时间内，「劳累的天数」是严格 大于「不劳累的天数」。

//请你返回「表现良好时间段」的最大长度。

//?

//示例 1：

//输入：hours = [9,9,6,0,6,6,9]
//输出：3
//解释：最长的表现良好时间段是 [9,9,6]。

class Solution {
public:
    int longestWPI1(vector<int>& hours) {
        int len = hours.size(); 

        vector<int> arr(len,0);
        int sum = 0;
        for(int i = 0; i < len; i++)
        {
            sum += (hours[i]>8 ? 1 : -1);
            arr[i] = sum;
        }

        int ans = 0;
        for(int i = 0; i < len - ans; i++)
            for(int j = i + ans; j < len; j++)
            {
                if(i == 0)
                {
                    if(arr[j] > 0) ans = max(ans,j+1);
                }
                else if(arr[j] - arr[i-1] > 0)
                    ans = max(ans,j-i+1);
            }
        return ans;
    }

    int longestWPI(vector<int>& hours)
    {
        unordered_map<int,int> map;//记录满足 cur<1的最小下标
        int len = hours.size();
        int ans = 0;
        int cur = 0;
        for(int i = 0; i < len; i++)
        {
            cur += (hours[i] > 8) ? 1 : -1;
            if(cur > 0) 
                ans = i + 1;
            else
            {
                //map[cur-1] --> map[j] 表示从0 -》 j 的满足cur-1的情况
                // cur - (cur-1) == 1 > 0 ，所以这种情况需要判断的
                if(map.count(cur-1)) ans = max(ans,i - map[cur-1]);
                //如果之前没有出现cur的情况，插入cur
                if(map.count(cur) < 1) map[cur] = i;
            }
        }
        return ans;
    }
};
