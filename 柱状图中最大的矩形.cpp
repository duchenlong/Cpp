//给定 n 个非负整数，用来表示柱状图中各个柱子的高度。每个柱子彼此相邻，且宽度为 1 。

//求在该柱状图中，能够勾勒出来的矩形的最大面积。

//?



//以上是柱状图的示例，其中每个柱子的宽度为 1，给定的高度为?[2,1,5,6,2,3]。

//?



//图中阴影部分为所能勾勒出的最大矩形面积，其面积为?10?个单位。

//?

//示例:

//输入: [2,1,5,6,2,3]
//输出: 10



class Solution {
public:
    //暴力解法 时间复杂度O(N * N)
    int largestRectangleArea1(vector<int>& heights) {
        int ret = 0;

        for(int i = 0; i < heights.size(); i++)
        {
            int left = i;
            int right = i;

            //左边第一个比他小的高度
            while(left > 0 && heights[left-1] >= heights[i])
                left--;
            
            //右边第一个比他小的高度
            while(right < heights.size()-1 && heights[right+1] >= heights[i])
                right++;
            
            int area = (right-left+1) * heights[i];
            //cout<<left<<' '<<right<<' '<<area<<endl;
            ret = max(area,ret);
        }
        return ret;
    }

    //单调栈 + 前后哨兵位
    int largestRectangleArea(vector<int>& heights)
    {
        stack<int> st;
        int ret = 0;
        //前后加0，防止单调递增，和单调递减的情况
        heights.insert(heights.begin(),0);
        heights.push_back(0);
        int len = heights.size();
        for(int i = 0; i < len; i++)
        {
            while(!st.empty() && heights[i] < heights[st.top()])
            {
                //计算栈顶元素可以勾勒出矩形的面积
                int top = st.top();
                st.pop();
                //i-top 就是矩形的宽，矩形的高度为栈顶元素的下标所代表的的数据
                int area = (i - st.top() - 1) * heights[top];
                ret = max(ret,area);
            }
            st.push(i);
        }

        return ret;
    }
};
