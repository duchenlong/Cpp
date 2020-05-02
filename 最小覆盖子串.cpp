//给你一个字符串 S、一个字符串 T，请在字符串 S 里面找出：包含 T 所有字母的最小子串。

//示例：

//输入: S = "ADOBECODEBANC", T = "ABC"
//输出: "BANC"
//说明：

//如果 S 中不存这样的子串，则返回空字符串 ""。
//如果 S 中存在这样的子串，我们保证它是唯一的答案。

class Solution {
public:
    string minWindow(string s, string t) {
        int lens = s.size();
        int lent = t.size();
        vector<int> need(256,0);
        vector<int> n(256,0);

        //判断需要的字符数
        for(auto& eoch : t) need[eoch]++;
        //判断需要的字符
        for(auto& eoch : t) n[eoch]++;
        vector<int> copy = need;

        int left = 0;
        int right = 0;
        int l,r;
        int ans = INT_MAX;
        int selNum = 0;//t字符串中已选的字符数
        
        while(right < lens) {
            //移动右窗口，到全部出现t中字符为止
            while(right < lens && selNum != lent) {
                if(need[s[right]]){
                    need[s[right]]--;
                    selNum++;
                }
                right++;
            }
            if(selNum != lent) break;
            else if(selNum == lent) right--;
            
            //此时的右边界一定是一个合法的数据
            //收缩左窗口,从右向左收缩
            vector<int> tmp = copy;
            left = right;
            int num = lent;
            while(num) {
                if(tmp[s[left]]) {
                    tmp[s[left]]--;
                    num--;
                }
                left--;
            }
            left++;//让left 位置是第一个合法的位置
            //更新最大长度
            if(ans > (right - left + 1)) {
                l = left;
                r = right;
                ans = r - l + 1;
            }

            //收缩左窗口到下一个最短需要的字符处
            need[s[left]]++;
            left++;
            while(left < right && n[s[left]])
                left++;
            left--;
            selNum--;
            right++;
        }

        return ans == INT_MAX ? "" : s.substr(l,r-l+1);
    }
};
