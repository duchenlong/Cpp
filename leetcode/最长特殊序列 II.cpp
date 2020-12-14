class Solution {
public:
    int findLUSlength(vector<string>& strs) {
        int n = strs.size();
        int ans = -1;
        //sort(strs.begin(),strs.end());
        for(int i = 0; i < n; i++) {
            int j = 0;
            for(; j < n; j++) {
                if(i == j)
                    continue;
                if(check(strs[j],strs[i]))
                    break;
            }
            if(j == n) 
                ans = max(ans,(int)strs[i].size());
        }

        return ans;
    }

    bool check(string& le,string ri) {
        int n = le.size();
        int m = ri.size();
        int id = 0;
        for(int i = 0; i < n && id < m; i++) {
            if(le[i] == ri[id])
                id++;
        }
        return id == m;
    }
};


给定字符串列表，你需要从它们中找出最长的特殊序列。最长特殊序列定义如下：该序列为某字符串独有的最长子序列（即不能是其他字符串的子序列）。

子序列可以通过删去字符串中的某些字符实现，但不能改变剩余字符的相对顺序。空序列为所有字符串的子序列，任何字符串为其自身的子序列。

输入将是一个字符串列表，输出是最长特殊序列的长度。如果最长特殊序列不存在，返回 -1 。

?

示例：

输入: "aba", "cdc", "eae"
输出: 3
?

提示：

所有给定的字符串长度不会超过 10 。
给定字符串列表的长度将在 [2, 50 ] 之间。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/longest-uncommon-subsequence-ii
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
