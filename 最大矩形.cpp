//给定一个仅包含 0 和 1 的二维二进制矩阵，找出只包含 1 的最大矩形，并返回其面积。


class Solution {
public:
    /*
    [
        ["1","0","1","0","0"],
        ["1","0","1","1","1"],
        ["1","1","1","1","1"],
        ["1","0","0","1","0"]
    ]

    第一层柱状图的高度["1","0","1","0","0"]，最大面积为1；

    第二层柱状图的高度["2","0","2","1","1"]，最大面积为3；

    第三层柱状图的高度["3","1","3","2","2"]，最大面积为6；

    第四层柱状图的高度["4","0","0","3","0"]，最大面积为4；
    */
    int maximalRectangle(vector<vector<char>>& matrix) {
        int row = matrix.size();
        if(!row || !matrix[0].size()) return 0;
        int col = matrix[0].size();

        vector<int> height(col+2,0);
        int ans = 0;

        for(int i = 0; i < row; i++)
        {
            for(int j = 0; j < col; j++)
                if(matrix[i][j] == '1') height[j+1]++;
                else height[j+1]=0;

            int area = MaxRectangle(height);
            ans = max(area,ans); 
        }
        return ans;
    }

    int MaxRectangle(vector<int>& height)
    {
        stack<int> st;
        int ret = 0;

        for(int i = 0; i < height.size(); i++)
        {
            while(!st.empty() && height[i] < height[st.top()])
            {
                int top = st.top();
                st.pop();

                int area = (i - st.top() - 1) * height[top];
                ret = max(area,ret);
            }
            st.push(i);
        }
        return ret;
    }
};
