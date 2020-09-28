class Solution {
public:
    struct node {
        int _x;
        int _y;
        int _v;
    };

    int n = 0;
    int m = 0;
    
    int vis[55][55];
    int cutOffTree(vector<vector<int>>& forest) {
        n = forest.size();
        m = forest[0].size();

        // >0 记录
        node nums[55*55];
        int len = 0;
        for(int i = 0; i < n; i++)
            for(int j = 0; j < m; j++)
                if(forest[i][j] > 0) nums[len++] = {i,j,forest[i][j]};
        sort(nums,nums + len,[](const auto& a,const auto& b)->bool {
            return a._v < b._v;
        });

        int ans = 0;
        int ret = BFS(forest,0,0,nums[0]._x,nums[0]._y);
        if(ret == -1) return -1;
        ans += ret;

        for(int i = 0; i < len-1; i++) {
            ret = BFS(forest,nums[i]._x,nums[i]._y,nums[i+1]._x,nums[i+1]._y);
            if(ret == -1) return -1;
            ans += ret;
        }

        return ans;
    }

    int BFS(vector<vector<int> >& forest,int x,int y,int r,int c) {
        static int dir[4][2] = {1,0,-1,0,0,-1,0,1};
        int ret = 0;
        if(x == r && y == c) return ret;
        using key = pair<int,int>;
        queue<key> que;
        que.push(make_pair(x,y));
        memset(vis,0x00,sizeof(vis));

        while(que.empty() == false) {
            int size = que.size();
            ret++;

            while(size --) {
                auto f = que.front();
                que.pop();

                for(int i = 0; i < 4; i++) {
                    int tx = f.first + dir[i][0];
                    int ty = f.second + dir[i][1];
                    if(tx < 0 || tx >= n || ty < 0 || ty >= m 
                        || vis[tx][ty] == 1 || forest[tx][ty] == 0) continue;
                    
                    if(tx == r && ty == c) return ret;
                    que.push(make_pair(tx,ty));
                    vis[tx][ty] = 1;
                }
            }
        }

        return -1;
    }
};


你被请来给一个要举办高尔夫比赛的树林砍树. 树林由一个非负的二维数组表示， 在这个数组中：

0 表示障碍，无法触碰到.
1?表示可以行走的地面.
比 1 大的数?表示一颗允许走过的树的高度.
每一步，你都可以向上、下、左、右四个方向之一移动一个单位，如果你站的地方有一棵树，那么你可以决定是否要砍倒它。

你被要求按照树的高度从低向高砍掉所有的树，每砍过一颗树，树的高度变为 1 。

你将从（0，0）点开始工作，你应该返回你砍完所有树需要走的最小步数。 如果你无法砍完所有的树，返回 -1 。

可以保证的是，没有两棵树的高度是相同的，并且你至少需要砍倒一棵树。

?

示例?1:

输入: 
[
 [1,2,3],
 [0,0,4],
 [7,6,5]
]
输出: 6
示例?2:

输入: 
[
 [1,2,3],
 [0,0,0],
 [7,6,5]
]
输出: -1
示例?3:

输入: 
[
 [2,3,4],
 [0,0,5],
 [8,7,6]
]
输出: 6
解释: (0,0) 位置的树，你可以直接砍去，不用算步数
?

提示：

1 <= forest.length <= 50
1 <= forest[i].length <= 50
0 <= forest[i][j]?<= 10^9

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/cut-off-trees-for-golf-event
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
