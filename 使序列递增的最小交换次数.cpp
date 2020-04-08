//我们有两个长度相等且不为空的整型数组?A?和?B?。

//我们可以交换?A[i]?和?B[i]?的元素。注意这两个元素在各自的序列中应该处于相同的位置。

//在交换过一些元素之后，数组?A?和?B?都应该是严格递增的（数组严格递增的条件仅为A[0] < A[1] < A[2] < ... < A[A.length - 1]）。

//给定数组?A?和?B?，请返回使得两个数组均保持严格递增状态的最小交换次数。假设给定的输入总是有效的。

//示例:
//输入: A = [1,3,5,4], B = [1,2,3,7]
//输出: 1
//解释: 
//交换 A[3] 和 B[3] 后，两个数组如下:
//A = [1, 3, 5, 7] ， B = [1, 2, 3, 4]
//两个数组均为严格递增的。


class Solution {
public:
    //空间复杂度O(n)
    int minSwap1(vector<int>& A, vector<int>& B) {
        int len = A.size();
        vector<vector<int> > dp(len,vector<int>(2,0));
        dp[0][1] = 1;
        for(int i = 1; i < len; i++)
        {
            if(A[i] <= A[i-1] || B[i] <= B[i-1])//前一列没有交换,这一列需要交换
            {
                dp[i][0] = dp[i-1][1];
                dp[i][1] = dp[i-1][0] + 1;
            }
            else if( B[i] <= A[i-1] || A[i] <= B[i-1])//前一列发生交换，这一列不需要交换
            {
                dp[i][0] = dp[i-1][0];
                dp[i][1] = dp[i-1][1] + 1;
            }
            else//可交换，可不交换
            {
                dp[i][0] = min(dp[i-1][1],dp[i-1][0]);
                dp[i][1] = dp[i][0] + 1;
            }

        }
        return min(dp[len-1][0],dp[len-1][1]);
    }
    //空间复杂度O(n)
    int minSwap2(vector<int>& A, vector<int>& B) {
        int len = A.size();
        vector<vector<int> > dp(len,vector<int>(2,0));
        dp[0][1] = 1;
        for(int i = 1; i < len; i++)
        {
            dp[i][0] = dp[i][1] = 3000;
            if(A[i] > A[i-1] && B[i] > B[i-1])//前一列没有发生交换
            {
                dp[i][0] = min(dp[i][0],dp[i-1][0]);
                dp[i][1] = min(dp[i][1],dp[i-1][1] + 1);
            }

            if( A[i] > B[i-1] &&  B[i] > A[i-1] )//前一列发生交换
            {
                dp[i][0] = min(dp[i][0],dp[i-1][1]);
                dp[i][1] = min(dp[i][1],dp[i-1][0] + 1);
            }

        }
        return min(dp[len-1][0],dp[len-1][1]);
    }
    //空间复杂度O(1)
    int minSwap3(vector<int>& A, vector<int>& B) {
        int len = A.size();
        int dp[2] = {0,1};
        for(int i = 1; i < len; i++)
        {
            int n0 =3000, n1 = 3000;
            if(A[i] > A[i-1] && B[i] > B[i-1])//前一列没有发生交换
            {
                n0 = min(n0,dp[0]);
                n1 = min(n1,dp[1] + 1);
            }

            if( A[i] > B[i-1] &&  B[i] > A[i-1] )//前一列发生交换
            {
                n0 = min(n0,dp[1]);
                n1 = min(n1,dp[0] + 1);
            }

            dp[0] = n0,dp[1] = n1;
        }
        return min(dp[0],dp[1]);
    }
    //空间复杂度O(1)
     int minSwap(vector<int>& A, vector<int>& B) {
        int len = A.size();
        int dp[2] = {0,1};
        for(int i = 1; i < len; i++)
        {
            int n0 = dp[0],n1 = dp[1];
            if(A[i] > A[i-1] && B[i] > B[i-1])//前一列没有交换，这一列不需要交换
            {
                if( A[i] > B[i-1] &&  B[i] > A[i-1] )//前一列发生交换，这一列不需要交换
                {
                    //取上一列两种情况最小值
                    dp[0] = min(n0,n1);
                    dp[1] = dp[0] + 1;
                }
                else//前一列发生交换，这一列需要交换
                    dp[1]++;
            }
            else//这一列需要交换
            {
                dp[1] = dp[0] + 1;
                dp[0] = n1; 
            }

        }
        return min(dp[0],dp[1]);
    }
};
