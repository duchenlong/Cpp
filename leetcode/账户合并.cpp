class Solution {
public:
    int f[1010];
    int find(int x) {
        if( x != f[x] ) f[x] = find(f[x]);
        return f[x];
    }

    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        int n = accounts.size();
        unordered_map<string,int> mp;
        for(int i = 1; i <= n; i++) f[i] = i;
        for(int i = 0; i < n; i++) {
            int m = accounts[i].size();
            for(int j = 1; j < m; j++) {
                string s = accounts[i][j];
                if(mp.count(s)) {
                    int x = find(mp[s]);
                    int y = find(i);
                    f[x] = y;
                } else mp[s] = i;
            }
        }

        vector<vector<string> > res;
        unordered_map<int,vector<string> > hash;
        for(auto& e : mp) {
            int v = find(e.second);
            hash[v].push_back(e.first);
        }
        for(auto& e : hash) {
            auto& vec = e.second;
            sort(vec.begin(),vec.end());
            vector<string> t = {accounts[e.first][0]};
            t.insert(t.end(),vec.begin(),vec.end());
            res.push_back(t);
        }
        return res;
    }
};

给定一个列表 accounts，每个元素 accounts[i]?是一个字符串列表，其中第一个元素 accounts[i][0]?是?名称 (name)，其余元素是 emails 表示该账户的邮箱地址。

现在，我们想合并这些账户。如果两个账户都有一些共同的邮箱地址，则两个账户必定属于同一个人。请注意，即使两个账户具有相同的名称，它们也可能属于不同的人，因为人们可能具有相同的名称。一个人最初可以拥有任意数量的账户，但其所有账户都具有相同的名称。

合并账户后，按以下格式返回账户：每个账户的第一个元素是名称，其余元素是按顺序排列的邮箱地址。账户本身可以以任意顺序返回。

?

示例 1：

输入：
accounts = [["John", "johnsmith@mail.com", "john00@mail.com"], ["John", "johnnybravo@mail.com"], ["John", "johnsmith@mail.com", "john_newyork@mail.com"], ["Mary", "mary@mail.com"]]
输出：
[["John", 'john00@mail.com', 'john_newyork@mail.com', 'johnsmith@mail.com'],  ["John", "johnnybravo@mail.com"], ["Mary", "mary@mail.com"]]
解释：
第一个和第三个 John 是同一个人，因为他们有共同的邮箱地址 "johnsmith@mail.com"。 
第二个 John 和 Mary 是不同的人，因为他们的邮箱地址没有被其他帐户使用。
可以以任何顺序返回这些列表，例如答案 [['Mary'，'mary@mail.com']，['John'，'johnnybravo@mail.com']，
['John'，'john00@mail.com'，'john_newyork@mail.com'，'johnsmith@mail.com']] 也是正确的。
?

提示：

accounts的长度将在[1，1000]的范围内。
accounts[i]的长度将在[1，10]的范围内。
accounts[i][j]的长度将在[1，30]的范围内。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/accounts-merge
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
