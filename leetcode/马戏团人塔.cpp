class Solution {
public:
    int bestSeqAtIndex(vector<int>& height, vector<int>& weight) {
        int n = height.size();
        using key = pair<int,int>;
        vector<key> nums;
        for(int i = 0; i < n; i++) nums.push_back(make_pair(height[i],weight[i]));
        
        // 体重升序排列，相同体重安装身高降序
        // 每次二分找第一个比自己大的
        sort(nums.begin(),nums.end(),[](const key& a,const key& b)->bool{
            if(a.first != b.first) return a.first < b.first;
            return a.second > b.second;
        });

        
        vector<int> dp;
        dp.push_back(nums[0].second);

        for(int i = 1; i < n; i++) {    // 重量的最长递增子序列长度
        int l = 0, r = dp.size() - 1, w = nums[i].second;
            if(dp.back() < w) {     // 排除本身就比最后一个重的情况
                dp.push_back(w);
                continue;
            }

            // 找第一个比自己重的
            while(l < r) {
                int mid = (l + r) >> 1;
                if(dp[mid] < w)   l = mid + 1;
                else if(dp[mid] >= w)  r = mid;
            }
            dp[l] = w;

        }
        return dp.size();

        // n ^ 2
        // int ans = 0;
        // for(int i = 0; i < n; i++) {
        //     dp[i] = 1;
        //     for(int j = 0; j < i; j ++) 
        //         if(nums[i].first > nums[j].first && nums[i].second > nums[j].second)    // i 比 j 高，重
        //             dp[i] = max(dp[i],dp[j] + 1);
        //     ans = max(ans, dp[i]);
        // }

        // return ans;
    }
};

有个马戏团正在设计叠罗汉的表演节目，一个人要站在另一人的肩膀上。出于实际和美观的考虑，在上面的人要比下面的人矮一点且轻一点。已知马戏团每个人的身高和体重，请编写代码计算叠罗汉最多能叠几个人。

示例：

输入：height = [65,70,56,75,60,68] weight = [100,150,90,190,95,110]
输出：6
解释：从上往下数，叠罗汉最多能叠 6 层：(56,90), (60,95), (65,100), (68,110), (70,150), (75,190)
提示：

height.length == weight.length <= 10000

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/circus-tower-lcci
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
