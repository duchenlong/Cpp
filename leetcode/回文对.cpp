给定一组唯一的单词， 找出所有不同?的索引对(i, j)，使得列表中的两个单词，?words[i] + words[j]?，可拼接成回文串。

示例 1:

输入: ["abcd","dcba","lls","s","sssll"]
输出: [[0,1],[1,0],[3,2],[2,4]] 
解释: 可拼接成的回文串为 ["dcbaabcd","abcddcba","slls","llssssll"]
示例 2:

输入: ["bat","tab","cat"]
输出: [[0,1],[1,0]] 
解释: 可拼接成的回文串为 ["battab","tabbat"]

class Solution {
public:
    vector<vector<int>> palindromePairs(vector<string>& words) {
        unordered_map<string,int> map;
        for(int i = 0; i < words.size(); i++)
        {
            string key = words[i];
            reverse(key.begin(),key.end());
            map[key]=i;
        }

        vector<vector<int> > ans;
        if(map.count("") > 0)//存在""字符串时
        {
            int pos = map[""];
            for(auto& eoch : map)
            {
                auto str = eoch.first;
                if(str == "")    continue;
                if(isPalindrome(str) == true)
                    ans.push_back({pos,eoch.second});
            }
        }

        for(int i = 0; i < words.size(); i++)
            for(int j = 0; j < words[i].size(); j++)
            {
                string le = words[i].substr(0,j);
                string ri = words[i].substr(j);

                //le + ri + le的逆序  ri为回文字符串
                if(map.count(le) > 0 && isPalindrome(ri) && map[le] != i)
                    ans.push_back({i,map[le]});
                
                //ri的逆序 + le + ri  le为回文字符串
                if(map.count(ri) > 0 && isPalindrome(le) && map[ri] != i)
                    ans.push_back({map[ri],i});
            }
        return ans;
    }

    bool isPalindrome(string str)
    {
        int le = 0;
        int ri = str.size()-1;
        while(le < ri && str[le] == str[ri])
        {
            le++;
            ri--;
        }

        return !(le < ri);
    }
};
