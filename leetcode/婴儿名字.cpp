class Solution {
public:
    unordered_map<string,int> id;
    vector<int> f;
    vector<int> sz;
    int find(int x) {
        if(x != f[x]) f[x] = find(f[x]);
        return f[x];
    }

    vector<string> trulyMostPopular(vector<string>& names, vector<string>& synonyms) {
        int n = names.size();
        vector<string> vec(n);
        f.reserve(n);
        sz.reserve(n);
        for(int i = 0; i < n; i++) f[i] = i;
        for(int i = 0; i < n; i++) {
            int start = names[i].find("(");
            int end = names[i].find(")");
            string name = names[i].substr(0,start);
            int cnt = stoi(names[i].substr(start+1,end-start-1));
            id[name] = i;
            vec[i] = name;
            sz[i] = cnt;
        }

        for(auto& e : synonyms) {
            int pos = e.find(",");
            string le = e.substr(1,pos-1);
            string ri = e.substr(pos+1,e.size()-2-pos);
            auto leid = id[le];
            auto riid = id[ri];
            int x = find(leid);
            int y = find(riid);
            if(x == y) continue;
            
            if(vec[x] > vec[y]) swap(x,y);
            f[y] = x;
            sz[x] += sz[y];
        }

        set<int> st;
        vector<string> res;
        for(auto& e : vec) {
            auto eid = id[e];
            int fa = find(eid);
            if(!st.count(fa)) {
                res.push_back(vec[fa] + "(" + to_string(sz[fa]) + ")");
                st.insert(fa);
            }
        }

        return res;
    }
};

每年，政府都会公布一万个最常见的婴儿名字和它们出现的频率，也就是同名婴儿的数量。有些名字有多种拼法，例如，John 和 Jon 本质上是相同的名字，但被当成了两个名字公布出来。给定两个列表，一个是名字及对应的频率，另一个是本质相同的名字对。设计一个算法打印出每个真实名字的实际频率。注意，如果 John 和 Jon 是相同的，并且 Jon 和 Johnny 相同，则 John 与 Johnny 也相同，即它们有传递和对称性。

在结果列表中，选择 字典序最小 的名字作为真实名字。

?

示例：

输入：names = ["John(15)","Jon(12)","Chris(13)","Kris(4)","Christopher(19)"], synonyms = ["(Jon,John)","(John,Johnny)","(Chris,Kris)","(Chris,Christopher)"]
输出：["John(27)","Chris(36)"]
?

提示：

names.length <= 100000

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/baby-names-lcci
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
