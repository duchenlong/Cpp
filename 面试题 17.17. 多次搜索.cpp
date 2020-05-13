//给定一个较长字符串big和一个包含较短字符串的数组smalls，设计一个方法，
//根据smalls中的每一个较短字符串，对big进行搜索。
//输出smalls中的字符串在big里出现的所有位置positions，其中positions[i]为smalls[i]出现的所有位置。

//示例：

//输入：
//big = "mississippi"
//smalls = ["is","ppi","hi","sis","i","ssippi"]
//输出： [[1,4],[8],[],[3],[1,4,7,10],[5]]
//提示：

//0 <= len(big) <= 1000
//0 <= len(smalls[i]) <= 1000
//smalls的总字符数不会超过 100000。
//你可以认为smalls中没有重复字符串。
//所有出现的字符均为英文小写字母。




class Solution {
public:
    //KMP
    vector<vector<int>> multiSearch1(string big, vector<string>& smalls) {
        vector<vector<int> > ans;

        for(auto& eoch : smalls)
            ans.push_back(KMP(big,eoch));
        return ans;
    }

    vector<int> KMP(string& s,string& p)
    {
        vector<int> ret;

        int lens = s.size();
        int lenp = p.size();
        //如果有空串，直接返回
        if(!lens || !lenp) return ret;

        vector<int> next(lenp,0);
        for(int i = 1, j = 0; i < lenp; i++)
        {
            while(j && p[i] != p[j])
                j = next[j-1];
            if(p[i] == p[j])
                j++;
            next[i]=j;
        }

        for(int i = 0,j = 0; i < lens; i++)
        {
            while(j && s[i]!=p[j])
                j = next[j-1];
            if(s[i]==p[j])
                j++;
            if(j == lenp)
            {
                ret.push_back(i-lenp+1);
                j = next[j-1];
            }
        }

        return ret;
    }

    //字典树
    const static int N = 100010;
    int son[N][26];
    int idx;
    string key[N];//记录叶子节点
    vector<vector<int>> multiSearch(string big, vector<string>& smalls) {
        for(auto& eoch : smalls)
            insert(eoch);
        
        unordered_map<string,vector<int> > hash;
        for(int i = 0; i < big.size(); i++)
            search(big,i,hash);

        vector<vector<int> > ans;
        for(auto& eoch : smalls)
            ans.push_back(hash[eoch]);
        return ans;
    }

    void insert(string& s)
    {
        int p = 0;
        for(int i = 0; i < s.size(); i++)
        {
            int u = s[i] - 'a';
            if(!son[p][u]) son[p][u] = ++idx;
            p = son[p][u];
        }
        key[p]=s;
    }

    void search(string& s,int index,unordered_map<string,vector<int> >& hash)
    {
        int p = 0;
        for(int i = index; i < s.size(); i++)
        {
            int u = s[i] - 'a';
            if(!son[p][u]) return ;
            p = son[p][u];
            if(key[p]!="") hash[key[p]].push_back(index);
        }
    }
    
};
