//给你一幅由 N × N 矩阵表示的图像，其中每个像素的大小为 4 字节。请你设计一种算法，将图像旋转 90 度。

//不占用额外内存空间能否做到？

//?

//示例 1:

//给定 matrix = 
//[
//  [1,2,3],
//  [4,5,6],
//  [7,8,9]
//],

//原地旋转输入矩阵，使其变为:
//[
//  [7,4,1],
//  [8,5,2],
//  [9,6,3]
//]
//示例 2:

//给定 matrix =
//[
//  [ 5, 1, 9,11],
//  [ 2, 4, 8,10],
//  [13, 3, 6, 7],
//  [15,14,12,16]
//], 

//原地旋转输入矩阵，使其变为:
//[
//  [15,13, 2, 5],
//  [14, 3, 4, 1],
//  [12, 6, 8, 9],
//  [16, 7,10,11]
//]


class Solution {
public:
    //空间复杂度O(n*n)
    void rotate1(vector<vector<int>>& matrix) {
        vector<vector<int>> tmp = matrix;
        int n = matrix.size();
        int row = n-1;
        for(int i = 0; i < n; i++)//第i列
        {
            for(int j = 0; j < n; j++)//第j行
                tmp[j][i] = matrix[row][j];
            row--;
        }
            
        
        for(int i = 0; i < n; i++)
            for(int j = 0; j < n; j++)
                matrix[i][j] = tmp[i][j];
    }
    
    //不使用额外空间
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size();

        for(int i = 0; i < n; i++)
        {
            // \ 对角线旋转
            for(int j = 0; (j + i) < n; j++)
                swap(matrix[i][i+j],matrix[i+j][i]);

            //交换第i行元素
            for(int j = 0; j < n / 2; j++)
                swap(matrix[i][j],matrix[i][n-1-j]);
        }
    }
};
