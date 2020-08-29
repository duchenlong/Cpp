给定一个二进制数组, 找到含有相同数量的 0 和 1 的最长连续子数组（的长度）。

?

示例 1:

输入: [0,1]
输出: 2
说明: [0, 1] 是具有相同数量0和1的最长连续子数组。
示例 2:

输入: [0,1,0]
输出: 2
说明: [0, 1] (或 [1, 0]) 是具有相同数量0和1的最长连续子数组。
?

注意:?给定的二进制数组的长度不会超过50000。

class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        unordered_map<int,int> map_t;
        int n = nums.size();
        int ans = 0;
        int sum = 0;

        for(int i = 0; i < n; i++){
            if(nums[i] == 0) sum--;
            else sum++;

            if(sum == 0){
                ans = i+1;
                continue;
            }
            
            if(map_t.count(sum) > 0){
                ans = max(i - map_t[sum],ans);
            }
            else{
                map_t[sum] = i;
            }
        }

        return ans;
    }
};
