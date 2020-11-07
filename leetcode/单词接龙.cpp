class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> hash(wordList.begin(),wordList.end());
        if(hash.find(endWord) == hash.end()) return 0;

        queue<string> que;
        que.push(beginWord);
        
        int ans = 0;
        while(!que.empty()) {
            int size = que.size();
            ans ++;
            while(size --) {
                string f = que.front();
                que.pop();

                for(int i = 0; i < f.size(); i++) {
                    int ch = f[i];
                    for(char j = 'a'; j <= 'z'; j++) {
                        if(j == ch) continue;
                        f[i] = j;
                        if(hash.find(f) == hash.end()) continue;
                        if(f == endWord) {
                            //cout << f << endl;
                            return ans + 1;
                        }
                        que.push(f);
                        hash.erase(f);
                    }
                    f[i] = ch;
                }
            }
        }

        return 0;
    }
};


给定两个单词（beginWord?和 endWord）和一个字典，找到从?beginWord 到?endWord 的最短转换序列的长度。转换需遵循如下规则：

每次转换只能改变一个字母。
转换过程中的中间单词必须是字典中的单词。
说明:

如果不存在这样的转换序列，返回 0。
所有单词具有相同的长度。
所有单词只由小写字母组成。
字典中不存在重复的单词。
你可以假设 beginWord 和 endWord 是非空的，且二者不相同。
示例?1:

输入:
beginWord = "hit",
endWord = "cog",
wordList = ["hot","dot","dog","lot","log","cog"]

输出: 5

解释: 一个最短转换序列是 "hit" -> "hot" -> "dot" -> "dog" -> "cog",
     返回它的长度 5。
示例 2:

输入:
beginWord = "hit"
endWord = "cog"
wordList = ["hot","dot","dog","lot","log"]

输出:?0

解释:?endWord "cog" 不在字典中，所以无法进行转换。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/word-ladder
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
