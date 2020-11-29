class Solution {
public:
    vector<int> findSwapValues(vector<int>& array1, vector<int>& array2) {
        int sum1 = accumulate(array1.begin(),array1.end(),0);
        int sum2 = accumulate(array2.begin(),array2.end(),0);
        
        vector<int> ans;
        if(sum1 == sum2 || (sum1 + sum2) % 2 == 1) return ans;

        int diff = (sum2 - sum1) / 2;   // array2 相对于 array1 的偏移
        sort(array2.begin(),array2.end());
        for(auto& e : array1) {
            int le = 0;
            int ri = array2.size() - 1;
            while(le < ri) {
                int mid = le + ri >> 1;
                if(array2[mid] >= diff + e) ri = mid; 
                else le = mid + 1;
            }
            if(le != array2.size() && array2[le] == e + diff) {
                ans = {e,array2[le]};
                break;
            }
        } 

        return ans;
    }
};


给定两个整数数组，请交换一对数值（每个数组中取一个数值），使得两个数组所有元素的和相等。

返回一个数组，第一个元素是第一个数组中要交换的元素，第二个元素是第二个数组中要交换的元素。若有多个答案，返回任意一个均可。若无满足条件的数值，返回空数组。

示例:

输入: array1 = [4, 1, 2, 1, 1, 2], array2 = [3, 6, 3, 3]
输出: [1, 3]
示例:

输入: array1 = [1, 2, 3], array2 = [4, 5, 6]
输出: []
提示：

1 <= array1.length, array2.length <= 100000

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/sum-swap-lcci
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
