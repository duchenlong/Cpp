给定一个字符串数组，将字母异位词组合在一起。字母异位词指字母相同，但排列不同的字符串。

示例:

输入: ["eat", "tea", "tan", "ate", "nat", "bat"]
输出:
[
  ["ate","eat","tea"],
  ["nat","tan"],
  ["bat"]
]
说明：

所有输入均为小写字母。
不考虑答案输出的顺序。




class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string,vector<string> > hash;

        vector<vector<string> > ans;

        for(auto& str : strs)
        {
            string key = str;
            sort(key.begin(),key.end());
            hash[key].push_back(str);
        }

        for(auto& it : hash)
            ans.push_back(it.second);
        return ans;
    }
};
