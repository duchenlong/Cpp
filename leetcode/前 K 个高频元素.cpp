给定一个非空的整数数组，返回其中出现频率前?k?高的元素。

?

示例 1:

输入: nums = [1,1,1,2,2,3], k = 2
输出: [1,2]
示例 2:

输入: nums = [1], k = 1
输出: [1]
?

提示：

你可以假设给定的?k?总是合理的，且 1 ≤ k ≤ 数组中不相同的元素的个数。
你的算法的时间复杂度必须优于 O(n log n) ,?n?是数组的大小。
题目数据保证答案唯一，换句话说，数组中前 k 个高频元素的集合是唯一的。
你可以按任意顺序返回答案。


class Solution {
public:
    struct cmp
    {
        bool operator()(const pair<int,int>& x,const pair<int,int>& y)
        {
            if(x.first != y.first)  
                return x.first > y.first;
            return x.second > y.second;
        }
    };

    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int> map;
        for(auto& num : nums)   map[num]++;

        //小根堆 greater x>y
        using type = pair<int,int>;
        priority_queue<type,vector<type>, cmp> heap;

        cmp com;
        for(auto& eoch : map)
        {
            type tmp = {eoch.second,eoch.first};
            if(heap.size() == k)
            {
                if(com(tmp,heap.top()) == false) continue;
                heap.pop();
            }
            heap.push(tmp);
        }

        vector<int> ret;
        while(k--)
        {
            ret.push_back(heap.top().second);
            heap.pop();
        }
        return ret;
    }
};
