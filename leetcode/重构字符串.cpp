class Solution {
public:
    typedef pair<int,int> PII;
    struct com{
        bool operator()(const PII& a,const PII& b) {
            return a.second < b.second;
        }
    };
    
    string reorganizeString(string s) {
        int f[26];
        memset(f,0x00,sizeof f);
        for(auto& ch : s) f[ch - 'a'] ++;

        priority_queue<PII,vector<PII>,com> pq;
        for(int i = 0; i < 26; i++) 
            if(f[i]) pq.push(make_pair(i + 'a',f[i]));

        string ans("");
        PII pre = make_pair(0,0);
        while(!pq.empty()) {
            auto t = pq.top();
            pq.pop();
            ans += t.first;
            if(pre.second) pq.push(pre);
            pre = t;
            pre.second--;
        }

        return pre.second ? "" : ans;
    }
};


给定一个字符串S，检查是否能重新排布其中的字母，使得两相邻的字符不同。

若可行，输出任意可行的结果。若不可行，返回空字符串。

示例?1:

输入: S = "aab"
输出: "aba"
示例 2:

输入: S = "aaab"
输出: ""
注意:

S 只包含小写字母并且长度在[1, 500]区间内。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/reorganize-string
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
