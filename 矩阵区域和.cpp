//给你一个?m * n?的矩阵?mat?和一个整数?K ，请你返回一个矩阵?answer?，其中每个?answer[i][j]?是所有满足下述条件的元素?mat[r][c] 的和：?

//i - K <= r <= i + K, j - K <= c <= j + K?
//(r, c)?在矩阵内。
//?

//示例 1：

//输入：mat = [[1,2,3],[4,5,6],[7,8,9]], K = 1
//输出：[[12,21,16],[27,45,33],[24,39,28]]
//示例 2：

//输入：mat = [[1,2,3],[4,5,6],[7,8,9]], K = 2
//输出：[[45,45,45],[45,45,45],[45,45,45]]


class Solution {
public:
    vector<vector<int>> matrixBlockSum1(vector<vector<int>>& mat, int k) {
        int len = mat.size();
        vector<vector<int> > ans(len);

        for(int i = 0; i < mat.size(); i++)
        {
            for(int j = 0; j < mat[i].size(); j++)
            {
                slove(mat,ans,k,i,j);
            }
        }
        return ans;
    }

    void slove(vector<vector<int>>& mat, vector<vector<int> >& ans,int k,int x,int y)
    {
        int num = 0;
        int rowb = max(0,x-k);
        int rowe = min((int)mat.size()-1,x+k);
        int colb = max(0,y-k);
        int cole = min((int)mat[0].size()-1,y+k);

        for(int i = rowb; i <= rowe; i++)
        {
            for(int j = colb; j <= cole; j++)
                num += mat[i][j];
        }
        ans[x].push_back(num);
    }
    //矩阵前缀和
    vector<vector<int>> matrixBlockSum(vector<vector<int>>& mat, int k)
    {
        int row = mat.size();
        int col = mat[0].size();

        vector<vector<int> > ans(row,vector<int>(col));
        vector<vector<int> > tmp(row+1,vector<int>(col+1));

        for(int i = 0; i < row; i++)
            for(int j = 0; j < col; j++)
                tmp[i+1][j+1] = tmp[i][j+1] + tmp[i+1][j] - tmp[i][j] + mat[i][j];
        
        for(int i = 0; i < row; i++)
            for(int j = 0; j < col; j++)
            {
                int rowb = max(0,i-k);
                int rowe = min((int)mat.size()-1,i+k);
                int colb = max(0,j-k);
                int cole = min((int)mat[0].size()-1,j+k);
                ans[i][j] = tmp[rowe + 1][cole + 1] - tmp[rowb][cole+1] - tmp[rowe+1][colb] + tmp[rowb][colb];
            }
        return ans;
    }
};
