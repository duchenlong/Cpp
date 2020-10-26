class Solution {
public:
// 并查集
    class Union {
    public:
        Union(int n) {
            fa.reserve(n);
            for(int i = 0; i < n; i++) fa[i] = i;
        }

        int find(int p) {
            while(p != fa[p]) {
                fa[p] = fa[fa[p]];
                p = fa[p];
            }
            return fa[p];
        }

        void check(int x,int y) {
            int tx = find(x);
            int ty = find(y);
            if(tx == ty) return ;
            fa[ty] = tx;
        }

        bool connect(int x,int y) {
            int tx = find(x);
            int ty = find(y);
            return tx == ty;
        }
    private:
        vector<int> fa;
    };
    struct Edge {
        int x,y,z;
        Edge(int _x,int _y,int _z) :x(_x),y(_y),z(_z)
        {}
        bool operator<(const Edge& b) {
            return z < b.z;
        }
    };
    int minimumEffortPath(vector<vector<int>>& h) {
        int n = h.size();
        int m = h[0].size();

        vector<Edge> e;
        for(int i = 0; i < n; i++) 
            for(int j = 0; j < m; j++) {
                int idx = i * m + j;
                if(i > 0) e.push_back({idx - m,idx,abs(h[i][j] - h[i-1][j])});
                if(j > 0) e.push_back({idx - 1,idx,abs(h[i][j] - h[i][j-1])});
            }
        
        Union un(n*m);
        sort(e.begin(),e.end());

        for(auto& ed : e) {
            un.check(ed.x,ed.y);
            if(un.connect(0,n * m - 1)) return ed.z;
        }

        return 0;
    }
};


你准备参加一场远足活动。给你一个二维?rows x columns?的地图?heights?，其中?heights[row][col]?表示格子?(row, col)?的高度。一开始你在最左上角的格子?(0, 0)?，且你希望去最右下角的格子?(rows-1, columns-1)?（注意下标从 0 开始编号）。你每次可以往 上，下，左，右?四个方向之一移动，你想要找到耗费 体力 最小的一条路径。

一条路径耗费的 体力值?是路径上相邻格子之间 高度差绝对值?的 最大值?决定的。

请你返回从左上角走到右下角的最小?体力消耗值?。

?

示例 1：



输入：heights = [[1,2,2],[3,8,2],[5,3,5]]
输出：2
解释：路径 [1,3,5,3,5] 连续格子的差值绝对值最大为 2 。
这条路径比路径 [1,2,2,2,5] 更优，因为另一条路劲差值最大值为 3 。
示例 2：



输入：heights = [[1,2,3],[3,8,4],[5,3,5]]
输出：1
解释：路径 [1,2,3,4,5] 的相邻格子差值绝对值最大为 1 ，比路径 [1,3,5,3,5] 更优。
示例 3：


输入：heights = [[1,2,1,1,1],[1,2,1,2,1],[1,2,1,2,1],[1,2,1,2,1],[1,1,1,2,1]]
输出：0
解释：上图所示路径不需要消耗任何体力。
?

提示：

rows == heights.length
columns == heights[i].length
1 <= rows, columns <= 100
1 <= heights[i][j] <= 106

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/path-with-minimum-effort
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
