class Solution {
public:
    int subarrayBitwiseORs(vector<int>& A) {
        int n = A.size();
        int maxNum = 0;
        for(int i = 0; i < n; i++) maxNum |= A[i];  //计算最大值

        unordered_set<int> hash;    // 去重
        hash.insert(maxNum);
        for(int i = 0; i < n; i++) {
            int cur = 0;
            for(int j = i; j >= 0 && cur != maxNum; j--) {
                cur |= A[j];
                if(hash.find(cur) == hash.end()) hash.insert(cur);
            }
        }

        return hash.size();
    }
};

我们有一个非负整数数组?A。

对于每个（连续的）子数组?B =?[A[i], A[i+1], ..., A[j]] （?i <= j），我们对?B?中的每个元素进行按位或操作，获得结果?A[i] | A[i+1] | ... | A[j]。

返回可能结果的数量。 （多次出现的结果在最终答案中仅计算一次。）

?

示例 1：

输入：[0]
输出：1
解释：
只有一个可能的结果 0 。
示例 2：

输入：[1,1,2]
输出：3
解释：
可能的子数组为 [1]，[1]，[2]，[1, 1]，[1, 2]，[1, 1, 2]。
产生的结果为 1，1，2，1，3，3 。
有三个唯一值，所以答案是 3 。
示例?3：

输入：[1,2,4]
输出：6
解释：
可能的结果是 1，2，3，4，6，以及 7 。
?

提示：

1 <= A.length <= 50000
0 <= A[i] <= 10^9

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/bitwise-ors-of-subarrays
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
