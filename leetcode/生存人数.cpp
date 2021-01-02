class Solution {
public:
    int maxAliveYear(vector<int>& birth, vector<int>& death) {
        vector<int> f(1010,0);
        int n = birth.size();
        for(int i = 0; i < n; i++) {
            f[birth[i] - 1900 + 1]++;
            f[death[i] - 1900 + 2]--;
        }

        int res = 0;
        int cnt = 0;
        for(int i = 1; i <= 1000; i++) {
            f[i] = f[i] + f[i-1];
            if(f[i] > cnt) {
                cnt = f[i];
                res = i;
            }
        } 

        return res + 1900 - 1;
    }
};


给定 N 个人的出生年份和死亡年份，第 i 个人的出生年份为 birth[i]，死亡年份为 death[i]，实现一个方法以计算生存人数最多的年份。

你可以假设所有人都出生于 1900 年至 2000 年（含 1900 和 2000 ）之间。如果一个人在某一年的任意时期处于生存状态，那么他应该被纳入那一年的统计中。例如，生于 1908 年、死于 1909 年的人应当被列入 1908 年和 1909 年的计数。

如果有多个年份生存人数相同且均为最大值，输出其中最小的年份。

?

示例：

输入：
birth = {1900, 1901, 1950}
death = {1948, 1951, 2000}
输出： 1901
?

提示：

0 < birth.length == death.length <= 10000
birth[i] <= death[i]

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/living-people-lcci
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
