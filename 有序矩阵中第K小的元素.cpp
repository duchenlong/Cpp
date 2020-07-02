给定一个?n x n?矩阵，其中每行和每列元素均按升序排序，找到矩阵中第 k 小的元素。
请注意，它是排序后的第 k 小元素，而不是第 k 个不同的元素。

?

示例：

matrix = [
   [ 1,  5,  9],
   [10, 11, 13],
   [12, 13, 15]
],
k = 8,

返回 13。
?

提示：
你可以假设 k 的值永远是有效的，1 ≤ k ≤ n2?。


class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        int n = matrix.size();
        int le = matrix[0][0];
        int ri = matrix[n-1][n-1];

        while(le < ri)
        {
            int mid = le + (ri - le) / 2;
            int num = BinaryFind(matrix,mid,n);

            if(num < k)
                le = mid + 1;
            else if(num >= k)
                ri = mid;
        }

        return le;
    }

    int BinaryFind(vector<vector<int> >& matrix,int mid,int n)
    {
        //按行找比mid小的元素个数
        int x = 0;
        int y = n - 1;
        int ans = 0;
        while(x < n && y >= 0)
        {
            if(matrix[x][y] <= mid)
            {
                ans += y + 1;
                x++; 
            }
            else
                y--;
        }
        return ans;
    }
};
