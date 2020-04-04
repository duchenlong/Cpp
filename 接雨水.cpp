//给定?n 个非负整数表示每个宽度为 1 的柱子的高度图，计算按此排列的柱子，下雨之后能接多少雨水。



//上面是由数组 [0,1,0,2,1,0,1,3,2,1,2,1] 表示的高度图，在这种情况下，可以接 6 个单位的雨水（蓝色部分表示雨水）。?感谢 Marcos 贡献此图。

//示例:

//输入: [0,1,0,2,1,0,1,3,2,1,2,1]
//输出: 6




class Solution {
public:
    int trap(vector<int>& height) {
        int left = 0;
        int right = height.size()-1;
        int leftMax = 0, rightMax = 0;
        int ans = 0;

        while(left < right)
        {
            if(height[left] < height[right])
            {
                //如果左边的高度比左边以保存的最大高度还大
                if(height[left] > leftMax)
                    leftMax = height[left];
                else
                    ans += leftMax - height[left];

                left++;
            }
            else
            {
                 //如果右边的高度比右边以保存的最大高度还大
                 if(height[right] > rightMax)
                    rightMax = height[right];
                else
                    ans += rightMax - height[right];
                right--;
            }
        }

        return ans;
    }
};
