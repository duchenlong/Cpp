你有?k?个升序排列的整数数组。找到一个最小区间，使得?k?个列表中的每个列表至少有一个数包含在其中。

我们定义如果?b-a < d-c?或者在?b-a == d-c?时?a < c，则区间 [a,b] 比 [c,d] 小。

示例 1:

输入:[[4,10,15,24,26], [0,9,12,20], [5,18,22,30]]
输出: [20,24]
解释: 
列表 1：[4, 10, 15, 24, 26]，24 在区间 [20,24] 中。
列表 2：[0, 9, 12, 20]，20 在区间 [20,24] 中。
列表 3：[5, 18, 22, 30]，22 在区间 [20,24] 中。
注意:

给定的列表可能包含重复元素，所以在这里升序表示 >= 。
1 <= k <= 3500
-105 <= 元素的值?<= 105
对于使用Java的用户，请注意传入类型已修改为List<List<Integer>>。重置代码模板后可以看到这项改动。


class Solution {
public:
    vector<int> smallestRange(vector<vector<int>>& nums) {
        vector<pair<int,int> > goods;

        for(int i = 0; i < nums.size(); i++)
            for(int j = 0; j < nums[i].size(); j++)
                goods.push_back({nums[i][j],i});
        
        sort(goods.begin(),goods.end(),
            [](const pair<int,int>& a,const pair<int,int>& b)->bool
            {
                if(a.first != b.first)
                    return a.first < b.first;
                return a.second < b.second;
            }
        );

        int le = 0;
        int sum = 0;
        vector<int> arr(nums.size(),0);

        int ans_le = 0;
        int ans_ri = 0;
        int len = INT_MAX;

        for(int i = 0; i < goods.size(); i++)
        {
            if(arr[goods[i].second] == 0)   sum++;
            arr[goods[i].second]++;

            while((le <= i) && (arr[goods[le].second] > 1))
            {
                 arr[goods[le].second]--;
                 le++;
            }
               
            int tmp = goods[i].first - goods[le].first;
            if(sum == nums.size() && tmp < len)
            {
                ans_le = le;
                ans_ri = i;
                len = tmp;
            }
        }

        return {goods[ans_le].first,goods[ans_ri].first};
    }
};
