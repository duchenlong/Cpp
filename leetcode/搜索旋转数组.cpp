class Solution {
public:
    int search(vector<int>& arr, int target) {
        int n = arr.size();
        int le = 0, ri = arr.size() - 1;

        while(le < ri) {
            while(le < ri && arr[le] == arr[ri]) ri--;  // 调整两边重复的元素
            int mid = (le + ri) / 2;

            // 调整中间重复的元素
            while(mid - 1 > le && arr[mid] == arr[mid - 1]) mid--;
            // 左边升序
            if(arr[le] <= arr[mid]) {
                if(target <= arr[mid] && target >= arr[le]) ri = mid;
                else le = mid + 1;
            } else {    // 右升序
                if(target >= arr[mid] && target <= arr[ri]) le = mid;
                else ri = mid - 1; 
            }
        }

        if(arr[le] == target) return le;
        return -1;
    }
};

搜索旋转数组。给定一个排序后的数组，包含n个整数，但这个数组已被旋转过很多次了，次数不详。请编写代码找出数组中的某个元素，假设数组元素原先是按升序排列的。若有多个相同元素，返回索引值最小的一个。

示例1:

 输入: arr = [15, 16, 19, 20, 25, 1, 3, 4, 5, 7, 10, 14], target = 5
 输出: 8（元素5在该数组中的索引）
示例2:

 输入：arr = [15, 16, 19, 20, 25, 1, 3, 4, 5, 7, 10, 14], target = 11
 输出：-1 （没有找到）
提示:

arr 长度范围在[1, 1000000]之间

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/search-rotate-array-lcci
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
