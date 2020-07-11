给定一个整数数组 nums，按要求返回一个新数组?counts。数组 counts 有该性质： counts[i] 的值是? nums[i] 右侧小于?nums[i] 的元素的数量。

示例:

输入: [5,2,6,1]
输出: [2,1,1,0] 
解释:
5 的右侧有 2 个更小的元素 (2 和 1).
2 的右侧仅有 1 个更小的元素 (1).
6 的右侧有 1 个更小的元素 (1).
1 的右侧有 0 个更小的元素.

class Solution {
public:
    struct TreeNode
    {
        TreeNode* _left;
        TreeNode* _right;
        int _val;
        int _count;//左子树节点个数
        TreeNode(int _v = 0)
            :_val(_v),_left(nullptr),_right(nullptr),_count(0)
        {}
    };
    //树状 二分
    vector<int> countSmaller2(vector<int>& nums)
    {
        TreeNode* root = nullptr;
        int len = nums.size();
        vector<int> ans(len,0);
        for(int i = len-1; i >= 0; i--)
            dfs(root,nums[i],ans,i);
        return ans;
    }

    void dfs(TreeNode*& root,int val,vector<int>& ans,int p)
    {
        if(root == nullptr)
        {
            root = new TreeNode(val);
            return;
        }

        if(val <= root->_val)
        {
            root->_count++;
            dfs(root->_right,val,ans,p);
        }
        else
        {
            ans[p] += root->_count + 1;
            dfs(root->_left,val,ans,p);
        }
    }
    
    vector<int> countSmaller(vector<int>& nums)
    {
        int len = nums.size();
        vector<int> ans(len,0);
        deque<int> tmp;
        for(int i = nums.size()-1; i >= 0; i--)
        {
            ans[i] = BinaryFind(tmp,nums[i]);
            tmp.insert(tmp.begin() + ans[i],nums[i]);
        }
        return ans;
    }

    int BinaryFind(deque<int>& arr,int num)
    {
        if(arr.size() == 0)
            return 0;
        int le = 0;
        int ri = arr.size();
        while(le < ri)
        {
            int mid = (le + ri) / 2;
            if(arr[mid] < num) le = mid + 1;
            else if(arr[mid] >= num) ri = mid;
        }
        return le;
    }


    //归并
    vector<int> countSmaller1(vector<int>& nums) {
        vector<pair<int,int> > copy;
        for(int i = 0; i < nums.size(); i++)
            copy.push_back({nums[i],i});
        vector<pair<int,int> > tmp = copy;
        vector<int> ans(nums.size(),0);

        MergerSort(copy,tmp,0,nums.size()-1,ans);
        return ans;
    }

    void MergerSort(vector<pair<int,int> >& nums,vector<pair<int,int> >& tmp,int le,int ri,vector<int>& ans)
    {
        if(le >= ri)    return;
        int mid = (le + ri) / 2;
        MergerSort(nums,tmp,le,mid,ans);
        MergerSort(nums,tmp,mid+1,ri,ans);
        //防止本身就是有序的数组
        if(nums[mid].first <= nums[mid+1].first)
            return;

        int pl = le;
        int pr = mid+1;
        for(int i = le; i <= ri; i++)
        {
            if(pl > mid)//左区间元素排列完毕
            {
                tmp[i] = nums[pr++];
            }
            else if(pr > ri)//右区间元素排列完毕
            {
                tmp[i] = nums[pl++];
                ans[tmp[i].second] += ri - mid;//此时右区间所有元素都比这个数小
            }
            else if(nums[pl].first <= nums[pr].first)//比较小的元素在左区间
            {
                tmp[i] = nums[pl++];
                ans[tmp[i].second] += pr - mid - 1;
            }
            else if(nums[pl].first > nums[pr].first)//比较小的元素在右区间
            {
                tmp[i] = nums[pr++];
            }
        }

        for(int i = le; i <= ri; i++)
            nums[i] = tmp[i];
    }
};
