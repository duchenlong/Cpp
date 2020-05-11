//给定一个无向、连通的树。树中有 N 个标记为 0...N-1 的节点以及 N-1?条边?。

//第 i 条边连接节点?edges[i][0] 和 edges[i][1]?。

//返回一个表示节点 i 与其他所有节点距离之和的列表 ans。

//示例 1:

//输入: N = 6, edges = [[0,1],[0,2],[2,3],[2,4],[2,5]]
//输出: [8,12,6,10,10,10]
//解释: 
//如下为给定的树的示意图：
//  0
// / \
//1   2
//   /|\
//  3 4 5

//我们可以计算出 dist(0,1) + dist(0,2) + dist(0,3) + dist(0,4) + dist(0,5) 
//也就是 1 + 1 + 2 + 2 + 2 = 8。 因此，answer[0] = 8，以此类推。
//说明:?1 <= N <= 10000


class Solution {
public:
    vector<int> dis;        //i点的所有子节点到i的距离之和
    vector<int> res;
    vector<int> children;   //以i为跟的树的孩子节点数量，包括根节点
    vector<vector<int> > map;

    vector<int> sumOfDistancesInTree(int N, vector<vector<int>>& edges) {
        map = vector<vector<int>>(N,vector<int>());
        dis = vector<int>(N,0);
        res = vector<int>(N,0);
        children = vector<int>(N,1);

        for(auto& e : edges)
        {
            map[e[0]].push_back(e[1]);
            map[e[1]].push_back(e[0]);
        }

        //求以0为根节点的距离之和，再求出分别求出以i为根节点的子树节点数量和
        dfs1(0,-1);
        //cout<<children[2];
        dfs2(N,0,-1);
        return res;
    }

    void dfs1(int index,int father)
    {
        for(auto& child : map[index])
            if(child != father)
            {
                dfs1(child,index);

                children[index] += children[child];
                res[index] += res[child] + children[child];
            }
    }

    //从0向下递归再推出子树，再由子树推出所有子树
    void dfs2(int n,int index,int father)
    {
        for(auto& child : map[index])
            if(child != father)
            {
                //res[index] 父亲节点延伸的距离
                //(n - children[child]) 从孩子节点到父亲节点的距离
                //children[child] child到孩子节点的距离
                res[child] = res[index] + (n - children[child]) - children[child];
                dfs2(n,child,index);
            }
    }
};
