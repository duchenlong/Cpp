//你一份旅游线路图，该线路图中的旅行线路用数组 paths 表示，其中 paths[i] = [cityAi, cityBi] 表示该线路将会从 cityAi 直接前往 cityBi 。请你找出这次旅行的终点站，即没有任何可以通往其他城市的线路的城市。

//题目数据保证线路图会形成一条不存在循环的线路，因此只会有一个旅行终点站。

//?

//示例 1：

//输入：paths = [["London","New York"],["New York","Lima"],["Lima","Sao Paulo"]]
//输出："Sao Paulo" 
//解释：从 "London" 出发，最后抵达终点站 "Sao Paulo" 。本次旅行的路线是 "London" -> "New York" -> "Lima" -> "Sao Paulo" 。
//示例 2：

//输入：paths = [["B","C"],["D","B"],["C","A"]]
//输出："A"
//解释：所有可能的线路是：
//"D" -> "B" -> "C" -> "A".?
//"B" -> "C" -> "A".?
//"C" -> "A".?
//"A".?
//显然，旅行终点站是 "A" 。
//示例 3：

//输入：paths = [["A","Z"]]
//输出："Z"


class Solution {
public:
    int ans = 0;
    string destCity(vector<vector<string>>& paths) 
    {
        vector<vector<int> > map(205);
        int len = paths.size();
        vector<string> str;
        vector<int> visit(1000,0);
        for(int i = 0; i < len; i++)
        {
            int l = FindPos(str,paths[i][0]);
            int r = FindPos(str,paths[i][1]);
            map[l].push_back(r);
        }
        
        
        dfs(map,str,0,visit);
        return str[ans];
    }
    
    void dfs(vector<vector<int> >& map,vector<string>& str,int index,vector<int>& visit)
    {
        if(map[index].size() == 0)
        {
            ans = index;
            return ;
        }
        for(int i = 0; i < map[index].size(); i++)
        {
            if(!visit[map[index][i]])
            {
                visit[map[index][i]] = 1;
                dfs(map,str,map[index][i],visit);
                visit[map[index][i]] = 0;
            }
        }
    }
    
    int FindPos(vector<string>& str,string& s)
    {
        int i = 0;
        for(i = 0; i < str.size(); i++)
        {
            if(str[i] == s) return i;
        }
        str.push_back(s);
        return i;
    }
};
