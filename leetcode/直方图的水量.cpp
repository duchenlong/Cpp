class Solution {
public:
    int trap(vector<int>& height) {
        int le = 0, ri = height.size() - 1;
        int leMax = 0, riMax = 0;
        int ans = 0;

        while(le < ri) {
            if(height[le] < height[ri]) {
                leMax = max(height[le],leMax);
                ans += leMax - height[le++];
            } else {
                riMax = max(riMax,height[ri]);
                ans += riMax - height[ri--];
            }
        }

        return ans;
    }
};

给定一个直方图(也称柱状图)，假设有人从上面源源不断地倒水，最后直方图能存多少水量?直方图的宽度为 1。



上面是由数组 [0,1,0,2,1,0,1,3,2,1,2,1] 表示的直方图，在这种情况下，可以接 6 个单位的水（蓝色部分表示水）。?感谢 Marcos 贡献此图。

示例:

输入: [0,1,0,2,1,0,1,3,2,1,2,1]
输出: 6

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/volume-of-histogram-lcci
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
