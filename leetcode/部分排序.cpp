class Solution {
public:
    vector<int> subSort(vector<int>& array) {
        vector<int> ans({-1,-1});

        int n = array.size();
        int cnt = INT_MIN;
        // 顺序查找 end 比左边最大值大的位置
        for(int i = 0; i < n; i++)
            if(array[i] >= cnt) cnt = array[i];
            else ans[1] = i;
        if(ans[1] == -1) return ans;    // 已经是有序

        // 逆序找 start 比右边最小值大的位置
        cnt = INT_MAX;
        for(int i = n - 1; i >= 0; i--) 
            if(array[i] <= cnt) cnt = array[i];
            else ans[0] = i;
        return ans;
    }
};


给定一个整数数组，编写一个函数，找出索引m和n，只要将索引区间[m,n]的元素排好序，整个数组就是有序的。注意：n-m尽量最小，也就是说，找出符合条件的最短序列。函数返回值为[m,n]，若不存在这样的m和n（例如整个数组是有序的），请返回[-1,-1]。

示例：

输入： [1,2,4,7,10,11,7,12,6,7,16,18,19]
输出： [3,9]
提示：

0 <= len(array) <= 1000000

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/sub-sort-lcci
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
