在一个仓库里，有一排条形码，其中第 i 个条形码为?barcodes[i]。

请你重新排列这些条形码，使其中两个相邻的条形码 不能 相等。 你可以返回任何满足该要求的答案，此题保证存在答案。

?

示例 1：

输入：[1,1,1,2,2,2]
输出：[2,1,2,1,2,1]
示例 2：

输入：[1,1,1,1,2,2,3,3]
输出：[1,3,1,3,2,1,2,1]
?

提示：

1 <= barcodes.length <= 10000
1 <= barcodes[i] <= 10000

class Solution {
public:
    using key = pair<int,int>;
    struct cmp
    {
        bool operator()(const key& a,const key& b)
        {
            return a.second < b.second;//大堆
        }
    };
    vector<int> rearrangeBarcodes(vector<int>& barcodes) {
        unordered_map<int,int> map;
        for(auto& num : barcodes)
            map[num]++;

        priority_queue<key,vector<key>,cmp> que;
        for(auto& eoch : map)
        {
            key tmp;
            tmp.first = eoch.first;
            tmp.second = eoch.second;
            que.push(tmp);
        }

        vector<int> ans(barcodes.size(),0);
        int p = 0;
        while(!que.empty())
        {
            auto top = que.top();
            que.pop();

            while(top.second > 0)
            {
                if(p >= barcodes.size()) p = 1;
                ans[p] = top.first;
                p += 2;
                top.second--;
            }
        }

        return ans;
    }
};
