class unionFind {
    public:
        unionFind(int n) :f(n){
            cnt = n;
            for(int i = 1; i < n; i++) f[i] = i;
        }

        int find(int x) {
            if(f[x] != x) f[x] = find(f[x]);
            return f[x];
        }

        bool merge(int x,int y) {
            x = find(x), y = find(y);
            if(x == y) return false;
            f[x] = y;
            cnt --;
            return true;
        }

        int get() {
            return cnt;
        }
    private:
        vector<int> f;
        int cnt;
};

class Solution {
public:
    int regionsBySlashes(vector<string>& grid) {
        int n = grid.size();
        unionFind uf(n * n * 4);

        for(int i = 0; i < n; i++)
            for(int j = 0; j < n; j++) {
                int idx = (i * n + j) * 4;
                if(i + 1 < n) uf.merge(idx + 3,idx + 4 * n + 1);
                if(j + 1 < n) uf.merge(idx + 2,idx + 4);

                char oper = grid[i][j];
                if(oper == ' ') {
                    uf.merge(idx,idx + 1);
                    uf.merge(idx + 1,idx + 2);
                    uf.merge(idx + 2,idx + 3);
                } else if(oper == '/') {
                    uf.merge(idx,idx + 1);
                    uf.merge(idx + 2,idx + 3);
                } else if(oper == '\\') {
                    uf.merge(idx,idx + 3);
                    uf.merge(idx + 1,idx + 2);
                }
            }
        
        return uf.get();
    }
};


在由 1 x 1 方格组成的 N x N 网格?grid 中，每个 1 x 1?方块由 /、\ 或空格构成。这些字符会将方块划分为一些共边的区域。

（请注意，反斜杠字符是转义的，因此 \ 用 "\\"?表示。）。

返回区域的数目。

?

示例 1：

输入：
[
? " /",
? "/ "
]
输出：2
解释：2x2 网格如下：

示例 2：

输入：
[
? " /",
? "  "
]
输出：1
解释：2x2 网格如下：

示例 3：

输入：
[
? "\\/",
? "/\\"
]
输出：4
解释：（回想一下，因为 \ 字符是转义的，所以 "\\/" 表示 \/，而 "/\\" 表示 /\。）
2x2 网格如下：

示例 4：

输入：
[
? "/\\",
? "\\/"
]
输出：5
解释：（回想一下，因为 \ 字符是转义的，所以 "/\\" 表示 /\，而 "\\/" 表示 \/。）
2x2 网格如下：

示例 5：

输入：
[
? "//",
? "/ "
]
输出：3
解释：2x2 网格如下：

?

提示：

1 <= grid.length == grid[0].length <= 30
grid[i][j] 是?'/'、'\'、或?' '。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/regions-cut-by-slashes
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
