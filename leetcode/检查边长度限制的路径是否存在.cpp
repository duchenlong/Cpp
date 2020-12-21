const int N = 1e5 + 10;

struct node{
    int a,b,c,d;
    bool operator<(const node& t) {
        return c < t.c;
    }
}e[N],q[N];

class Solution {
public:
    vector<int> p;

    int find(int x) {
        if(x != p[x]) p[x] = find(p[x]);
        return p[x];
    }

    vector<bool> distanceLimitedPathsExist(int nn, vector<vector<int>>& ee, vector<vector<int>>& qq) {
        int n = ee.size(), m  = qq.size();
        p.resize(nn);
        for(int i = 0; i < nn; i++) p[i] = i;
        for(int i = 0; i < n; i++) e[i] = {ee[i][0],ee[i][1],ee[i][2]};
        for(int i = 0; i < m; i++) q[i] = {qq[i][0],qq[i][1],qq[i][2],i};
        sort(e,e+n);
        sort(q,q+m);

        vector<bool> ans(m,false);

        for(int i = 0, j = 0; i < m; i++) {
            while(j < n && e[j].c < q[i].c) {
                p[find(e[j].a)] = find(e[j].b);
                j++;
            }

            ans[q[i].d] = (find(q[i].a) == find(q[i].b));
        }

        return ans;
    }
};


给你一个 n?个点组成的无向图边集?edgeList?，其中?edgeList[i] = [ui, vi, disi]?表示点?ui 和点?vi?之间有一条长度为?disi?的边。请注意，两个点之间可能有 超过一条边?。

给你一个查询数组queries?，其中?queries[j] = [pj, qj, limitj]?，你的任务是对于每个查询?queries[j]?，判断是否存在从?pj?到?qj?的路径，且这条路径上的每一条边都 严格小于?limitj?。

请你返回一个 布尔数组?answer?，其中?answer.length == queries.length?，当?queries[j]?的查询结果为?true?时，?answer 第?j?个值为?true?，否则为?false?。

?

示例 1：


输入：n = 3, edgeList = [[0,1,2],[1,2,4],[2,0,8],[1,0,16]], queries = [[0,1,2],[0,2,5]]
输出：[false,true]
解释：上图为给定的输入数据。注意到 0 和 1 之间有两条重边，分别为 2 和 16 。
对于第一个查询，0 和 1 之间没有小于 2 的边，所以我们返回 false 。
对于第二个查询，有一条路径（0 -> 1 -> 2）两条边都小于 5 ，所以这个查询我们返回 true 。
示例 2：


输入：n = 5, edgeList = [[0,1,10],[1,2,5],[2,3,9],[3,4,13]], queries = [[0,4,14],[1,4,13]]
输出：[true,false]
解释：上图为给定数据。
?

提示：

2 <= n <= 105
1 <= edgeList.length, queries.length <= 105
edgeList[i].length == 3
queries[j].length == 3
0 <= ui, vi, pj, qj <= n - 1
ui != vi
pj != qj
1 <= disi, limitj <= 109
两个点之间可能有 多条?边。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/checking-existence-of-edge-length-limited-paths
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
