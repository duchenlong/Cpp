给你一个整数数组?arr?和一个整数?k。

首先，我们要对该数组进行修改，即把原数组 arr 重复?k?次。

举个例子，如果?arr?= [1, 2] 且 k = 3，那么修改后的数组就是?[1, 2, 1, 2, 1, 2]。

然后，请你返回修改后的数组中的最大的子数组之和。

注意，子数组长度可以是 0，在这种情况下它的总和也是 0。

由于?结果可能会很大，所以需要 模（mod）?10^9 + 7?后再返回。?

?

示例 1：

输入：arr = [1,2], k = 3
输出：9
示例 2：

输入：arr = [1,-2,1], k = 5
输出：2
示例 3：

输入：arr = [-1,-2], k = 7
输出：0
?

提示：

1 <= arr.length <= 10^5
1 <= k <= 10^5
-10^4 <= arr[i] <= 10^4


class Solution {
public:
    int kConcatenationMaxSum(vector<int>& arr, int k) {
        const int mod = 1e9 + 7;
        int n = arr.size();
        long maxRi= 0;
        long maxLe = 0;
        long ans = 0;
        long sum = 0;
        long tmp = 0;

        for(int i = 0; i < n; i++)
        {
            if(tmp < 0)
                tmp = arr[i];
            else
                tmp += arr[i];
            sum += arr[i];

            maxLe = max(sum,maxLe);
            ans = max(tmp,ans);
        }
        if(k == 1)  return max((int)ans,0);

        tmp = 0;
        for(int i = n-1; i >= 0; i--)
        {
            tmp += arr[i];
            maxRi = max(maxRi,tmp);
        }

        return max(ans,max(maxLe + maxRi,maxRi + maxLe + (k-2) * sum)) % mod;
    }
};
