给定一个正整数数组 A，如果 A?的某个子数组中不同整数的个数恰好为 K，则称 A 的这个连续、不一定独立的子数组为好子数组。

（例如，[1,2,3,1,2] 中有?3?个不同的整数：1，2，以及?3。）

返回?A?中好子数组的数目。

?

示例 1：

输入：A = [1,2,1,2,3], K = 2
输出：7
解释：恰好由 2 个不同整数组成的子数组：[1,2], [2,1], [1,2], [2,3], [1,2,1], [2,1,2], [1,2,1,2].
示例 2：

输入：A = [1,2,1,3,4], K = 3
输出：3
解释：恰好由 3 个不同整数组成的子数组：[1,2,1,3], [2,1,3], [1,3,4].
?

提示：

1 <= A.length <= 20000
1 <= A[i] <= A.length
1 <= K <= A.length

class Solution {
public:
    
    int ans = 0;
    int subarraysWithKDistinct(vector<int>& A, int K) {
        int n = A.size();
        vector<int> hash(n+1,0);
        int le = 0;
        int sum = 0;

        for(int i = 0; i < n; i++)
        {
            if(hash[A[i]] == 0) sum++;
            hash[A[i]]++;

            while(sum > K && le < i)
            {
                //从i -> le 搜索
                dfs(hash,A,K,le,i,sum);
                hash[A[le]]--;
                if(hash[A[le]] == 0)    sum--;
                le++;
            }
        }

        while(sum == K && le < n)
        {
            dfs(hash,A,K,le,n-1,sum);
            hash[A[le]]--;
            if(hash[A[le]] == 0)    sum--;
            le++;
        }
        return ans;
    }

    void dfs(vector<int>& hash,vector<int>& A,int K,int le,int ri,int& sum)
    {
        if(sum < K || le > ri) return;
        if(sum == K)    ans++;
        
        hash[A[ri]]--;

        if(hash[A[ri]] == 0)    sum--;
        dfs(hash,A,K,le,ri-1,sum);
        if(hash[A[ri]] == 0)    sum++;

        hash[A[ri]]++;
    }
};
