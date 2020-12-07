class Solution {
public:
    bool isPossible(vector<int>& nums) {
        unordered_map<int,int> cnt,need;
        for(int e : nums) cnt[e]++;

        for(int e : nums) {
            if(cnt[e] == 0) continue;

            if(need[e] > 0) {
                need[e] --;
                need[e + 1] ++;
            } else if(cnt[e + 1] && cnt[e + 2]) {
                cnt[e + 1] --;
                cnt[e + 2] --;
                need[e + 3] ++;
            } else {
                return false;
            }

            cnt[e] --;
        }

        return true;
    }
};


class Solution {
public:
    bool isPossible(vector<int>& nums) {
        unordered_map<int,priority_queue<int,vector<int>,greater<int> > > mp;
        for(int e : nums) {
            if(mp.count(e) == 0) {
                mp[e] = priority_queue<int,vector<int>,greater<int> > ();
            }

            if(mp.count(e - 1)) {
                auto& pq = mp[e - 1];
                int preLen = pq.top();
                pq.pop();
                if(pq.empty()) mp.erase(e - 1);
                mp[e].push(preLen + 1);
            } else {
                mp[e].push(1);
            }
        }

        for(auto& e : mp) {
            auto pq = e.second;
            if(pq.top() < 3) return false;
        }
        return true;
    }
};


给你一个按升序排序的整数数组 num（可能包含重复数字），请你将它们分割成一个或多个子序列，其中每个子序列都由连续整数组成且长度至少为 3 。

如果可以完成上述分割，则返回 true ；否则，返回 false 。

?

示例 1：

输入: [1,2,3,3,4,5]
输出: True
解释:
你可以分割出这样两个连续子序列 : 
1, 2, 3
3, 4, 5
?

示例 2：

输入: [1,2,3,3,4,4,5,5]
输出: True
解释:
你可以分割出这样两个连续子序列 : 
1, 2, 3, 4, 5
3, 4, 5
?

示例 3：

输入: [1,2,3,4,4,5]
输出: False
?

提示：

输入的数组长度范围为 [1, 10000]

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/split-array-into-consecutive-subsequences
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
