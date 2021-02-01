class unionFind{
    public:
        unionFind(int n) :f(n) {
            for(int i = 0; i < n; i++) f[i] = i;
        }

        int find(int x) {
            if(f[x] != x) f[x] = find(f[x]);
            return f[x];
        }

        bool merge(int x,int y) {
            x = find(x), y = find(y);
            if(x == y) return false;
            f[x] = y;
            return true;
        }
    private:
        vector<int> f;
};

const int N = 50 * 50 * 2 + 10;
struct edge{
    int u,v,w;
    bool operator<(const edge& t) const  {
        return w < t.w;
    }
}e[N];

class Solution {
public:
    int swimInWater(vector<vector<int>>& grid) {
        int n = grid.size();
        int cnt = 0;
        for(int i = 0; i < n; i++)
            for(int j = 0; j < n; j++) {
                int idx = i * n + j;
                if(i > 0) e[cnt ++] = {idx,idx - n, max(grid[i][j],grid[i-1][j])};
                if(j > 0) e[cnt ++] = {idx,idx - 1, max(grid[i][j],grid[i][j-1])};
            }
        
        sort(e,e+cnt);
        unionFind uf(n*n);
        int res = 0;
        for(int i = 0; i < cnt; i++) {
            int x = e[i].u, y = e[i].v, w = e[i].w;
            if(w > res) res = w;
            uf.merge(x,y);
            if(uf.find(0) == uf.find(n*n-1)) return res;
        }
        return 0;
    }
};

在一个 N x N 的坐标方格?grid 中，每一个方格的值 grid[i][j] 表示在位置 (i,j) 的平台高度。

现在开始下雨了。当时间为?t?时，此时雨水导致水池中任意位置的水位为?t?。你可以从一个平台游向四周相邻的任意一个平台，但是前提是此时水位必须同时淹没这两个平台。假定你可以瞬间移动无限距离，也就是默认在方格内部游动是不耗时的。当然，在你游泳的时候你必须待在坐标方格里面。

你从坐标方格的左上平台 (0，0) 出发。最少耗时多久你才能到达坐标方格的右下平台?(N-1, N-1)？

?

示例 1:

输入: [[0,2],[1,3]]
输出: 3
解释:
时间为0时，你位于坐标方格的位置为 (0, 0)。
此时你不能游向任意方向，因为四个相邻方向平台的高度都大于当前时间为 0 时的水位。

等时间到达 3 时，你才可以游向平台 (1, 1). 因为此时的水位是 3，坐标方格中的平台没有比水位 3 更高的，所以你可以游向坐标方格中的任意位置
示例2:

输入: [[0,1,2,3,4],[24,23,22,21,5],[12,13,14,15,16],[11,17,18,19,20],[10,9,8,7,6]]
输出: 16
解释:
 0  1  2  3  4
24 23 22 21  5
12 13 14 15 16
11 17 18 19 20
10  9  8  7  6

最终的路线用加粗进行了标记。
我们必须等到时间为 16，此时才能保证平台 (0, 0) 和 (4, 4) 是连通的
?

提示:

2 <= N <= 50.
grid[i][j] 是 [0, ..., N*N - 1] 的排列。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/swim-in-rising-water
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
