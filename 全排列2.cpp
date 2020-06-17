给定一个可包含重复数字的序列，返回所有不重复的全排列。

示例:

输入: [1,1,2]
输出:
[
  [1,1,2],
  [1,2,1],
  [2,1,1]
]



class Solution {
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int> > ans;
        //sort(nums.begin(),nums.end());
        dfs(nums,0,nums.size() - 1,ans);

        return ans;
    }

    void dfs(vector<int>& nums,int le,int ri,vector<vector<int> >& ans)
    {
        if(le == ri)
        {
            ans.push_back(nums);
            return ;
        }

        //哈希set去重
        unordered_set<int> map;
        for(int i = le; i <= ri; i++)
        {
            if(map.count(nums[i])) continue;
            swap(nums[i],nums[le]);
            dfs(nums,le+1,ri,ans);
            swap(nums[i],nums[le]);
            map.insert(nums[i]);
        }
    }


    void dfs1(vector<int> nums,int le,int ri,vector<vector<int> >& ans)
    {
        if(le == ri)
        {
            ans.push_back(nums);
            return ;
        }

        for(int i = le; i <= ri; i++)
        {
            // if(i != le && nums[i] == nums[le])
            //     continue;
            swap(nums[i],nums[le]);
            dfs(nums,le+1,ri,ans);
        }
    }
};
