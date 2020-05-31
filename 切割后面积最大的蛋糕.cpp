//矩形蛋糕的高度为 h 且宽度为 w，给你两个整数数组 horizontalCuts 和 verticalCuts，其中 horizontalCuts[i] 是从矩形蛋糕顶部到第? i 个水平切口的距离，类似地， verticalCuts[j] 是从矩形蛋糕的左侧到第 j 个竖直切口的距离。

//请你按数组 horizontalCuts 和 verticalCuts 中提供的水平和竖直位置切割后，请你找出 面积最大 的那份蛋糕，并返回其 面积 。由于答案可能是一个很大的数字，因此需要将结果对 10^9 + 7 取余后返回。

//?



class Solution {
public:
    int maxArea(int h, int w, vector<int>& hv, vector<int>& vv) {
        sort(hv.begin(),hv.end());
        sort(vv.begin(),vv.end());
        hv.insert(hv.begin(),0);
        hv.push_back(h);
        vv.insert(vv.begin(),0);
        vv.push_back(w);
        int lenh = hv.size();
        int lenv = vv.size();
        
        int ans = 0;
        int maxh = 0;
        for(int i = 1; i < lenh; i++)
            maxh = max(hv[i]-hv[i-1],maxh);
        
        int maxv = 0;
        for(int i = 1; i < lenv; i++)
            maxv = max(vv[i]-vv[i-1],maxv);
        
        ans = ((long long)maxh * (long long)maxv) % 1000000007;
        return ans;
    }
};
