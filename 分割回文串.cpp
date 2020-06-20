

class Solution {
public:
    vector<vector<string>> partition(string s) {
        vector<vector<string> > ans;
        vector<string> tmp;
        int len = s.size();
        dfs(ans,tmp,s,len,0);
        return ans;
    }

    void dfs(vector<vector<string> >& ans,vector<string>& tmp, string& s,int len,int idx)
    {
        if(idx == len)
        {
            ans.push_back(tmp);
            return;
        }

        string t = "";
        for(int i = idx; i < len; i++)
        {
            t += s[i];
            if(!IsHui(t)) continue;
            tmp.push_back(t);
            dfs(ans,tmp,s,len,i+1);
            tmp.pop_back();
        }
    }

    bool IsHui(string& s)
    {
        int ri = s.size() - 1;
        int le = 0;

        while(le < ri)
        {
            if(s[le] != s[ri])
                return false;
            le++;
            ri--;
        }
        return true;
    }
};
