给定一个包含非负整数的数组，你的任务是统计其中可以组成三角形三条边的三元组个数。

示例 1:

输入: [2,2,3,4]
输出: 3
解释:
有效的组合是: 
2,3,4 (使用第一个 2)
2,3,4 (使用第二个 2)
2,2,3
注意:

数组长度不超过1000。
数组里整数的范围为 [0, 1000]。

class Solution {
public:
    int triangleNumber(vector<int>& nums) {
        int ans = 0;
        int le = 0;
        int ri = 0;
        sort(nums.begin(),nums.end());
        int n = nums.size();

        for (int i = 0; i < n - 2; i++) {
            for (int j = i + 1; j < n - 1; j++) {
                int sum = nums[i] + nums[j];
                int p = n-1;
                while(p > j && nums[p] >= sum) {
                    p--;
                }
                ans += p - j;
            }
        }
        return ans;
    }
};
