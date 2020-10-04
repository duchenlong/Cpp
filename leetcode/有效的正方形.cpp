class Solution {
public:
    using key = pair<int,int>;
    bool validSquare(vector<int>& p1, vector<int>& p2, vector<int>& p3, vector<int>& p4) {
        set<int> st;
        vector<key> arr{{p1[0],p1[1]}, {p2[0],p2[1]}, {p3[0],p3[1]}, {p4[0],p4[1]} };
        for(int i = 0; i < 4; i++) 
            for(int j = i + 1; j < 4; j++) {
                int num = check(arr[i],arr[j]);
                if(num == 0) return false;
                st.insert(num);
            }
               
        
        return st.size() == 2;
    }

    int check(const key& a,const key& b) {
        int x = abs(a.first - b.first);
        int y = abs(a.second - b.second);

        return x*x + y*y;
    }
};

给定二维空间中四点的坐标，返回四点是否可以构造一个正方形。

一个点的坐标（x，y）由一个有两个整数的整数数组表示。

示例:

输入: p1 = [0,0], p2 = [1,1], p3 = [1,0], p4 = [0,1]
输出: True
?

注意:

所有输入整数都在 [-10000，10000] 范围内。
一个有效的正方形有四个等长的正长和四个等角（90度角）。
输入点没有顺序。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/valid-square
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
