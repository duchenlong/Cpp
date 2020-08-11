给定一个数字字符串 S，比如 S = "123456579"，我们可以将它分成斐波那契式的序列 [123, 456, 579]。

形式上，斐波那契式序列是一个非负整数列表 F，且满足：

0 <= F[i] <= 2^31 - 1，（也就是说，每个整数都符合 32 位有符号整数类型）；
F.length >= 3；
对于所有的0 <= i < F.length - 2，都有 F[i] + F[i+1] = F[i+2] 成立。
另外，请注意，将字符串拆分成小块时，每个块的数字一定不要以零开头，除非这个块是数字 0 本身。

返回从 S 拆分出来的任意一组斐波那契式的序列块，如果不能拆分则返回 []。

?

示例 1：

输入："123456579"
输出：[123,456,579]
示例 2：

输入: "11235813"
输出: [1,1,2,3,5,8,13]
示例 3：

输入: "112358130"
输出: []
解释: 这项任务无法完成。
示例 4：

输入："0123"
输出：[]
解释：每个块的数字不能以零开头，因此 "01"，"2"，"3" 不是有效答案。
示例 5：

输入: "1101111"
输出: [110, 1, 111]
解释: 输出 [11,0,11,11] 也同样被接受。
?

提示：

1 <= S.length?<= 200
字符串 S 中只含有数字。

class Solution {
public:
    int n;
    vector<int> splitIntoFibonacci(string s) {
        vector<int> ans;
        n = s.size();
        if(n < 3)  return ans;

        vector<long> cur; 
        dfs(0,cur,s,ans);

        return ans;
    }

    void dfs(int idx,vector<long>& cur,string& s,vector<int>& ans)
    {
        if(ans.size() != 0) return;

        //进行拷贝
        if(idx == n && cur.size() > 2)
        {
            for(auto num : cur)
                ans.push_back((int)num);
            return;
        }

        long num = 0;
        for(int i = idx; i < n; i++)
        {
            if(i == idx + 1 && num == 0)    break;
            num = num * 10 + (s[i] -'0');
            
            if(num > INT_MAX)   break;

            int len = cur.size();
            if(len >= 2)
            {
                long pre = cur[len - 1] + cur[len - 2];
                if(pre < num || pre > INT_MAX)  break;

                if(pre > num)   continue;
            }

            // len < 2 
            // cur[len - 1] + cur[len - 2] == num
            cur.push_back(num);
            dfs(i+1,cur,s,ans);
            if(ans.size() > 0)  return;
            cur.pop_back();
        }
    }
};
