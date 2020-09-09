给定一个元素都是正整数的数组A?，正整数 L?以及?R?(L <= R)。

求连续、非空且其中最大元素满足大于等于L?小于等于R的子数组个数。

例如 :
输入: 
A = [2, 1, 4, 3]
L = 2
R = 3
输出: 3
解释: 满足条件的子数组: [2], [2, 1], [3].
注意:

L, R? 和?A[i] 都是整数，范围在?[0, 10^9]。
数组?A?的长度范围在[1, 50000]。


class Solution {
public:
    int numSubarrayBoundedMax1(vector<int>& A, int L, int R) {
        int n = A.size();

        int ans = 0;
        int pre = -1;
        int le = -1;

        for(int i = 0; i < n; i++) {
            if(A[i] >= L && A[i] <= R){
                ans += i - le;
                pre = i;
            } else if (A[i] < L) {
                if(pre > le) ans += pre - le;
            } else {
                le = i;
            }
        }

        return ans;
    }

    int numSubarrayBoundedMax(vector<int>& A, int L, int R) {
        return check(A,R) - check(A,L-1);
    }

    int check(vector<int>& A,int num) {
        int n = A.size();
        int sum = 0;
        int ret = 0;

        for(int i = 0; i < n; i++) {
            if(A[i] <= num) {
                sum++;
                ret += sum;
            } else {
                sum = 0;
            }
        }

        return ret;
    }
};
