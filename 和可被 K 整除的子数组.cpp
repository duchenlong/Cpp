//给定一个整数数组 A，返回其中元素之和可被 K?整除的（连续、非空）子数组的数目。

//?

//示例：

//输入：A = [4,5,0,-2,-3,1], K = 5
//输出：7
//解释：
//有 7 个子数组满足其元素之和可被 K = 5 整除：
//[4, 5, 0, -2, -3, 1], [5], [5, 0], [5, 0, -2, -3], [0], [0, -2, -3], [-2, -3]
//?

//提示：

//1 <= A.length <= 30000
//-10000 <= A[i] <= 10000
//2 <= K <= 10000


class Solution {
public:
    //O（n ^ 2）
    int subarraysDivByK1(vector<int>& A, int K) {
        int len = A.size();
        vector<int> tmp(len+1,0);

        //前缀和
        for(int i = 0; i < len; i++)
            tmp[i+1] = tmp[i] + A[i];
        
        int ans = 0;
        for(int i = 1; i <= len; i++)
            for(int j = 0; j < i; j++)
            {
                if((tmp[i] - tmp[j]) % K == 0) ans++;
            }
 
        return ans;
    }

    //哈希表
    //(tmp[i] - tmp[j]) % K == 0  --->   tmp[i] % K ==  tmp[j] % K
    int subarraysDivByK(vector<int>& A, int K)
    {
        int len = A.size();
        vector<int> map(K,0);
        map[0] = 1;
        int sum = 0;
        int ans = 0;
        for(int i = 0; i < len; i++)
        {
            sum += A[i];
            int pos = (sum%K + K) % K;
            ans += map[pos];
            map[pos]++;
        }

        return ans;
    } 
};
