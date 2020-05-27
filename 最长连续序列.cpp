//给定一个未排序的整数数组，找出最长连续序列的长度。

//要求算法的时间复杂度为?O(n)。

//示例:

//输入:?[100, 4, 200, 1, 3, 2]
//输出: 4
//解释: 最长连续序列是 [1, 2, 3, 4]。它的长度为 4。

class UnionFind
{
public:
    unordered_map<int,int> parent;
    unordered_map<int,int> cnt;

    UnionFind(vector<int>& nums)
    {
        for(auto& eoch : nums)
        {
            parent[eoch] = eoch;
            cnt[eoch] = 1;
        }
    }

    //找父亲节点，只有父亲节点的两个值是相同的
    int Find(int pos)
    {
       	// while(pos != parent[pos])
        //     pos = parent[pos];

        //路径压缩
        if(pos != parent[pos]) parent[pos] = Find(parent[pos]);
        return parent[pos];
    }

    //并查集的合并
    void UnionElem(int p,int r)
    {
        int proot = Find(p);
        int rroot = Find(r);
        //不相等说明不在同一个集合中，可以合并
        if(proot != rroot)
        {
            parent[proot] = rroot;
            cnt[rroot] += cnt[proot];
        }
    }
};

class Solution {
public:
    //并查集 O(n)
    int longestConsecutive(vector<int>& nums)
    {
        int len = nums.size();
        if(len < 1) return 0;

        UnionFind uf(nums);
        for(auto& num : nums)
            if(uf.parent.find(num+1) != uf.parent.end())//确认下一个元素存在 
                uf.UnionElem(num,num+1);//判断是否可以合并
        
        int ans = 0;
        //统计长度
        for(auto& eoch : uf.cnt)
            ans = max(ans,eoch.second);
        return ans;
    }

    //排序 O(n * log(n))
    int longestConsecutive1(vector<int>& nums) {
        int len = nums.size();
        if(len < 1) return 0;
        sort(nums.begin(),nums.end());
        for(int i = 0; i < len - 1; i++)
            nums[i] = nums[i+1] - nums[i];
        
        nums[len-1] = -1;//防止 [1,1,1]
        int ans = 1;
        int count = 0;
        for(int i = 0; i < len; i++)
            if(nums[i] == 1)
            {
                count++;
                ans = max(ans,count+1);
            }
            else if(nums[i] != 0)
                count = 0;
        return ans;
    }

   
};


