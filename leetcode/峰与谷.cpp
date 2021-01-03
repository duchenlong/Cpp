class Solution {
public:
    void wiggleSort(vector<int>& nums) {
        // sort(nums.begin(),nums.end());
        // for(int i = 1; i < nums.size(); i+=2) {
        //     swap(nums[i],nums[i-1]);
        // }

        int n = nums.size();
        // 0 峰  1 谷   
        for(int i = 1; i < n; i ++) {
            if(i & 1) {
                // 谷
                if(nums[i] > nums[i-1]) swap(nums[i],nums[i-1]);
            } else {
                // 峰
                if(nums[i] < nums[i-1]) swap(nums[i],nums[i-1]);
            }
        }
    }
};

在一个整数数组中，“峰”是大于或等于相邻整数的元素，相应地，“谷”是小于或等于相邻整数的元素。例如，在数组{5, 8, 4, 2, 3, 4, 6}中，{8, 6}是峰， {5, 2}是谷。现在给定一个整数数组，将该数组按峰与谷的交替顺序排序。

示例:

输入: [5, 3, 1, 2, 3]
输出:?[5, 1, 3, 2, 3]
提示：

nums.length <= 10000

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/peaks-and-valleys-lcci
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
