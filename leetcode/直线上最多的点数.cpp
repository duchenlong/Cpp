class Solution {
public:
    typedef pair<int,int> PII;
    typedef long long LL;
    int maxPoints(vector<vector<int>>& points) {
        int n = points.size();
        if(n < 2) return n;
        map<PII,int> mp;  // 统计每个点出现的次数
        for(auto& e : points) mp[{e[0],e[1]}] ++;

        vector<pair<PII,int> > vec; // 记录每个点出现的次数
        for(auto& e : mp) vec.push_back(e);
        n = vec.size();
        if(n == 1) return vec[0].second;    // 排除只存在一个点的情况

        int res = 0;
        for(int i = 0; i < n; i++)
            for(int j = i + 1; j < n; j++) {
                // 记录 i j 的斜率
                LL x = vec[j].first.first - vec[i].first.first;
                LL y = vec[j].first.second - vec[i].first.second;
                int cur = vec[i].second + vec[j].second;    // 当前直线中点的数量

                // 统计后面的点
                for(int k = j + 1; k < n; k++) {
                    LL tx = vec[k].first.first - vec[i].first.first;
                    LL ty = vec[k].first.second - vec[i].first.second;
                    if(tx * y == ty * x) cur += vec[k].second;
                }

                res = max(res,cur);
            }
        return res;
    }
};

给定一个二维平面，平面上有?n?个点，求最多有多少个点在同一条直线上。

示例 1:

输入: [[1,1],[2,2],[3,3]]
输出: 3
解释:
^
|
| ? ? ? ?o
| ? ? o
| ?o ?
+------------->
0 ?1 ?2 ?3  4
示例?2:

输入: [[1,1],[3,2],[5,3],[4,1],[2,3],[1,4]]
输出: 4
解释:
^
|
|  o
| ????o??      o
| ????   o
| ?o ?      o
+------------------->
0 ?1 ?2 ?3 ?4 ?5 ?6

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/max-points-on-a-line
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
