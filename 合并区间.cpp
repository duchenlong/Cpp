//给出一个区间的集合，请合并所有重叠的区间。

//示例 1:

//输入: [[1,3],[2,6],[8,10],[15,18]]
//输出: [[1,6],[8,10],[15,18]]
//解释: 区间 [1,3] 和 [2,6] 重叠, 将它们合并为 [1,6].
//示例?2:

//输入: [[1,4],[4,5]]
//输出: [[1,5]]
//解释: 区间 [1,4] 和 [4,5] 可被视为重叠区间。


class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int> > ans;
        if(intervals.size() < 2)
            return intervals;
        sort(intervals.begin(),intervals.end(),cmp);

        int start = -1;
        int end = 0;
        for(int i = 0; i < intervals.size(); i++)
        {
            if(start == -1)
            {
                start = intervals[i][0];
                end = intervals[i][1];
                continue;
            }

            if(intervals[i][0] > end) //如果当前不需要合并，start end 入数组，已经最简
            {
                ans.push_back(GetVector(start,end));
                start = intervals[i][0];
                end = intervals[i][1];
            }     
            else if(intervals[i][1] > end) // 如果当前需要合并，并且结束时间大于end，就更新end (1,4)(2,3)
                end = intervals[i][1];
        }
        if(start != -1)
            ans.push_back(GetVector(start,end));
        return ans;
    }

    vector<int> GetVector(int start,int end)
    {
        vector<int> ret(2);
        ret[0] = start;
        ret[1] = end;
        return ret;
    }

    static bool cmp(const vector<int>& a, const vector<int>& b)
    {
        if(a[0] != b[0])
            return a[0] < b[0];
        return a[1] < b[1];
    }
};
