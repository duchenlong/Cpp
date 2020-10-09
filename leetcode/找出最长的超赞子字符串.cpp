class Solution {
public:
    int longestAwesome(string s) {
        int n = s.size();
        int um[1<<10];
        memset(um,0x3f,sizeof(um));
        //unordered_map<int,int> um;
        um[0] = -1;

        int ans = 0;
        int status = 0;
        for(int i = 0; i < n; i++) {
            status ^= (1 << (s[i] - '0'));

            if(um[status] == 0x3f3f3f3f) um[status] = i;
            else ans = max(ans,i - um[status]);

            for(int j = 0; j < 10; j++) {
                int st = (1 << j) ^ status;
                if(um[st] != 0x3f3f3f3f) ans = max(ans,i-um[st]);
            }
            
            // 与当前状态相同，前一次出现的位置
            // auto pos = um.find(status);
            // if(pos != um.end()) ans = max(ans,i - pos->second);
            // else um[status] = i;

            // 不同
            // int bit = 1;
            // int cnt = 10;
            // while (cnt --) {
            //     int st = status ^ bit;  // 只有一位不同的前一次出现的位置
            //     pos = um.find(st);
            //     if(pos != um.end()) ans = max(ans,i - pos->second);
            //     bit <<= 1;
            // }
        }

        return ans;
    }
};


给你一个字符串 s 。请返回 s 中最长的 超赞子字符串 的长度。

「超赞子字符串」需满足满足下述两个条件：

该字符串是 s 的一个非空子字符串
进行任意次数的字符交换后，该字符串可以变成一个回文字符串
?

示例 1：

输入：s = "3242415"
输出：5
解释："24241" 是最长的超赞子字符串，交换其中的字符后，可以得到回文 "24142"
示例 2：

输入：s = "12345678"
输出：1
示例 3：

输入：s = "213123"
输出：6
解释："213123" 是最长的超赞子字符串，交换其中的字符后，可以得到回文 "231132"
示例 4：

输入：s = "00"
输出：2
?

提示：

1 <= s.length <= 10^5
s 仅由数字组成

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/find-longest-awesome-substring
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
