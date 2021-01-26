class Solution {
public:
    int minCharacters(string a, string b) {
        int f[300];
        int n = a.size(), m =  b.size();
        memset(f,0x00,sizeof f);
        for(auto& e : a) f[e] ++;
        for(auto& e : b) f[e] ++;
        
        int maxt = 0;
        for(int i = 1; i < 300; i++) if(f[i] > f[maxt]) maxt = i;
        int res = n + m - f[maxt];
        
        vector<vector<int> > tfi(26,vector<int> (2,0));
        vector<vector<int> > tfa(26,vector<int> (2,0));
        for(int i = 0;i < 26; i++) {
            for(auto& e : a) {
                tfi[i][0] += e > (i + 'a'); // 最大 = i
                tfa[i][0] += e < (i + 'a'); // 最小 = i
            }
            for(auto& e : b) {
                tfi[i][1] += e > (i + 'a');
                tfa[i][1] += e < (i + 'a');
            }
        }
        for(int i = 0; i < 26; i++)
            for(int j =i + 1 ;  j < 26; j++) {
                res = min(res,tfi[i][0] + tfa[j][1]);
                res = min(res,tfi[i][1] + tfa[j][0]);
            }
        return res;
    }
    
};

给你两个字符串 a 和 b ，二者均由小写字母组成。一步操作中，你可以将 a 或 b 中的 任一字符 改变为 任一小写字母 。

操作的最终目标是满足下列三个条件 之一 ：

a 中的 每个字母 在字母表中 严格小于 b 中的 每个字母 。
b 中的 每个字母 在字母表中 严格小于 a 中的 每个字母 。
a 和 b 都 由 同一个 字母组成。
返回达成目标所需的 最少 操作数。

?

示例 1：

输入：a = "aba", b = "caa"
输出：2
解释：满足每个条件的最佳方案分别是：
1) 将 b 变为 "ccc"，2 次操作，满足 a 中的每个字母都小于 b 中的每个字母；
2) 将 a 变为 "bbb" 并将 b 变为 "aaa"，3 次操作，满足 b 中的每个字母都小于 a 中的每个字母；
3) 将 a 变为 "aaa" 并将 b 变为 "aaa"，2 次操作，满足 a 和 b 由同一个字母组成。
最佳的方案只需要 2 次操作（满足条件 1 或者条件 3）。
示例 2：

输入：a = "dabadd", b = "cda"
输出：3
解释：满足条件 1 的最佳方案是将 b 变为 "eee" 。
?

提示：

1 <= a.length, b.length <= 105
a 和 b 只由小写字母组成

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/change-minimum-characters-to-satisfy-one-of-three-conditions
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
