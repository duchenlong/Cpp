在由若干?0?和?1? 组成的数组?A?中，有多少个和为 S?的非空子数组。

?

示例：

输入：A = [1,0,1,0,1], S = 2
输出：4
解释：
如下面黑体所示，有 4 个满足题目要求的子数组：
[1,0,1,0,1]
[1,0,1,0,1]
[1,0,1,0,1]
[1,0,1,0,1]
?

提示：

A.length <= 30000
0 <= S <= A.length
A[i]?为?0?或?1

class Solution {
public:
    int numSubarraysWithSum(vector<int>& A, int S) {
        int le = 0;
        int sum = 0;
        int n = A.size();

        int ans = 0;
        for(int i = 0; i < n; i++){
            sum += A[i];
            
            while(le < i && sum > S){
                sum -= A[le];
                le++;
            }

            int idx = le;
            int tmp = sum;
            while(idx <= i && tmp == S){
                ans++;
                tmp -= A[idx++];
            }
        }

        return ans;
    }
};
