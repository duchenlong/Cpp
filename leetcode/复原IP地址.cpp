给定一个只包含数字的字符串，复原它并返回所有可能的 IP 地址格式。

有效的 IP 地址正好由四个整数（每个整数位于 0 到 255 之间组成），整数之间用 '.' 分隔。

?

示例:

输入: "25525511135"
输出: ["255.255.11.135", "255.255.111.35"]


class Solution {
public:
    vector<string> restoreIpAddresses(string s) {
        vector<string> ans;

        dfs(s,0,"",ans,0);

        return ans;
    }

    void dfs(string& s,int idx,string&& cur,vector<string>& ans,int cnt)
    {
        if(idx == s.size() && cnt == 4)
        {
            cur.pop_back();
            ans.push_back(cur);
            return;
        }

        if(cnt >= 4) return ;

        int num = 0;
        int p = idx;
        int sum = 0;
        while(num <= 255 && p < s.size())
        {
            num = num * 10 + s[p++]-'0';
            if(num < sum)  break;
            sum = (sum == 0) ? 10 : sum * 10;
            if(num <= 255)
                dfs(s,p,cur + to_string(num) + '.',ans,cnt+1);
        }
    }
};
