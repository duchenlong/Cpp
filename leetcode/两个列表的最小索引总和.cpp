class Solution {
public:
    struct node {
        node* _son[55];
        int _index;
        node() {
            for(int i = 0; i < 55; i++)    _son[i] = nullptr;
            _index = -1;
        }
    };

    node* root;

    inline int GetIdx(char ch) {
        if(ch == ' ') return 26 * 2;
        else if(ch <= 'Z' && ch >= 'A') return ch - 'A';

        return 26 + ch - 'a';
    }

    void insert(const string& str,int idx) {
        int n = str.size();
        node* cur = root;
        for(int i = 0; i < n; i++) {
            int p = GetIdx(str[i]);
            if(cur->_son[p] == nullptr)    cur->_son[p] = new node();
            
            cur = cur->_son[p];
        }
        cur->_index = idx;
    }

    bool check(const string& str,int& idx) {
        int n = str.size();
        node* cur = root;
        for(int i = 0; i < n; i++) {
            int p = GetIdx(str[i]);
            if(cur->_son[p] == nullptr) return false;

            cur = cur->_son[p];
        }
        if(cur->_index == -1) return false;

        idx = cur->_index;
        return true;
    }

    vector<string> findRestaurant(vector<string>& list1, vector<string>& list2) {
        root = new node();
        for(int i = 0; i < list1.size(); i++) insert(list1[i],i);
        
        vector<string> ans;
        int minN = INT_MAX;
        for(int i = 0; i < list2.size(); i++) {
            int idx = -1;
            if(check(list2[i],idx) == true){
                if(idx + i <= minN) {
                    if(idx + i < minN) ans.clear(), minN = idx + i;
                    ans.push_back(list2[i]);
                }
            } 
        }

        return ans;
    }
};

假设Andy和Doris想在晚餐时选择一家餐厅，并且他们都有一个表示最喜爱餐厅的列表，每个餐厅的名字用字符串表示。

你需要帮助他们用最少的索引和找出他们共同喜爱的餐厅。 如果答案不止一个，则输出所有答案并且不考虑顺序。 你可以假设总是存在一个答案。

示例 1:

输入:
["Shogun", "Tapioca Express", "Burger King", "KFC"]
["Piatti", "The Grill at Torrey Pines", "Hungry Hunter Steakhouse", "Shogun"]
输出: ["Shogun"]
解释: 他们唯一共同喜爱的餐厅是“Shogun”。
示例 2:

输入:
["Shogun", "Tapioca Express", "Burger King", "KFC"]
["KFC", "Shogun", "Burger King"]
输出: ["Shogun"]
解释: 他们共同喜爱且具有最小索引和的餐厅是“Shogun”，它有最小的索引和1(0+1)。
提示:

两个列表的长度范围都在?[1, 1000]内。
两个列表中的字符串的长度将在[1，30]的范围内。
下标从0开始，到列表的长度减1。
两个列表都没有重复的元素。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/minimum-index-sum-of-two-lists
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
