//给你一个数组 favoriteCompanies ，其中 favoriteCompanies[i] 是第 i 名用户收藏的公司清单（下标从 0 开始）。

//请找出不是其他任何人收藏的公司清单的子集的收藏清单，并返回该清单下标。下标需要按升序排列。

// 

//示例 1：

//输入：favoriteCompanies = [["leetcode","google","facebook"],["google","microsoft"],["google","facebook"],["google"],["amazon"]]
//输出：[0,1,4] 
//解释：
//favoriteCompanies[2]=["google","facebook"] 是 favoriteCompanies[0]=["leetcode","google","facebook"] 的子集。
//favoriteCompanies[3]=["google"] 是 favoriteCompanies[0]=["leetcode","google","facebook"] 和 favoriteCompanies[1]=["google","microsoft"] 的子集。
//其余的收藏清单均不是其他任何人收藏的公司清单的子集，因此，答案为 [0,1,4] 。
//示例 2：

//输入：favoriteCompanies = [["leetcode","google","facebook"],["leetcode","amazon"],["facebook","google"]]
//输出：[0,1] 
//解释：favoriteCompanies[2]=["facebook","google"] 是 favoriteCompanies[0]=["leetcode","google","facebook"] 的子集，因此，答案为 [0,1] 。
//示例 3：

//输入：favoriteCompanies = [["leetcode"],["google"],["facebook"],["amazon"]]
//输出：[0,1,2,3]

class Solution {
public:

        vector<int> peopleIndexes(vector<vector<string>>& ff)
        {
            int n = ff.size();
            vector<vector<int> > f(n);
            unordered_map<string,int> map;
            
            for(int i = 0; i < n; i++)
            {
                for(auto& eoch : ff[i])
                {
                    if(!map.count(eoch)) map[eoch] = map.size();
                    
                    f[i].push_back(map[eoch]);
                }
                sort(f[i].begin(),f[i].end());
            }
            
            vector<int> ans;
            for(int i = 0; i < n; i++)
            {
                bool flag = false;
                for(int j = 0; j < n; j++)
                    if(i != j && f[i].size() < f[j].size() && check(f,i,j))
                    {
                        flag = true;
                        break;
                    }
                if(!flag) ans.push_back(i);
            }
            return ans;
        }
    
        bool check(vector<vector<int> >& f,int x,int y)
        {
            int len = 0;
            for(int i = 0; i < f[x].size(); i++)
            {
                while(len < f[y].size() && f[x][i] != f[y][len])
                    len++;
                if(len == f[y].size())
                    return false;
            }
            return true;
        }

//      超时    
//     vector<int> peopleIndexes(vector<vector<string>>& f) {
//         unordered_map<string,vector<int> > map;
//         unordered_map<string,int> hash;
//         int n = 0;
//         for(int i = 0; i < f.size(); i++)
//             for(auto& e : f[i])
//             {
//                 if(hash.find(e) == hash.end())
//                     hash[e] = n++;
//             }
//         // for(int i = 0; i < f[0].size(); i++)
//         //     cout<<hash[f[0][i]]<<' ';

//         for(int i = 0; i < f.size(); i++)
//             for(auto& e : f[i])
//                 map[e].push_back(i);
        
        
        
//         vector<int> ret;
//         for(int i = 0; i < f.size(); i++)
//         {
//             bool flag = true;
//             for(auto& eoch : f[i])
//             {
//                 flag = dfs(eoch,map,hash,f,i);
//                 if(!flag)
//                     break;
//             }
//             if(flag) ret.push_back(i);
//         }
//         return ret;
       
//     }
    
//     static bool dfs(string& str, unordered_map<string,vector<int> >& map,unordered_map<string,int>& hash,vector<vector<string>>& f,int index)
//     {
//         for(auto& eoch : map[str])
//         {
//             if(index == eoch)
//                 continue;
//             int n = 0;
//             if(f[eoch].size() < f[index].size()) continue;
            
            
//             for(auto& a : f[index])
//             {
//                 int tmp = n;
//                 for(auto& e : f[eoch])
//                     if(hash[e] == hash[a])
//                     {
//                         n++;
//                         break;
//                     }
                
//                 if(n == tmp)
//                     break;
//             }
                
//             if(n == f[index].size()) return false;
//         }
        
//         return true;
//     }
};
