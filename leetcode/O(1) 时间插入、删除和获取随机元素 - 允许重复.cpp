class RandomizedCollection {
public:
    /** Initialize your data structure here. */
    RandomizedCollection() {
        _mt.clear();
        _arr.clear();
    }
    
    /** Inserts a value to the collection. Returns true if the collection did not already contain the specified element. */
    bool insert(int val) {
        bool ret = _mt.find(val) == _mt.end();
        int pos = _arr.size();
        _arr.push_back(val);
        _mt[val].insert(pos);
        return ret;
    }
    
    /** Removes a value from the collection. Returns true if the collection contained the specified element. */
    bool remove(int val) {
        if(_mt.find(val) == _mt.end()) return false;
        
        // unordered_set
        int pos = *(_mt[val].begin());
        _mt[val].erase(pos);
        if(_mt[val].empty() == true) _mt.erase(val);

        int n = _arr.size();
        if(pos != n-1) {
            _arr[pos] = _arr[n-1];
            _mt[_arr[pos]].erase(n-1);
            _mt[_arr[pos]].insert(pos);
        }
        
        _arr.pop_back();
        return true;
    }
    
    /** Get a random element from the collection. */
    int getRandom() {
        int pos = rand() % _arr.size();
        return _arr[pos];
    }
private:
    unordered_map<int,unordered_set<int> > _mt;
    vector<int> _arr;
};

/**
 * Your RandomizedCollection object will be instantiated and called as such:
 * RandomizedCollection* obj = new RandomizedCollection();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */
 
 设计一个支持在平均?时间复杂度?O(1)?下，?执行以下操作的数据结构。

注意: 允许出现重复元素。

insert(val)：向集合中插入元素 val。
remove(val)：当 val 存在时，从集合中移除一个 val。
getRandom：从现有集合中随机获取一个元素。每个元素被返回的概率应该与其在集合中的数量呈线性相关。
示例:

// 初始化一个空的集合。
RandomizedCollection collection = new RandomizedCollection();

// 向集合中插入 1 。返回 true 表示集合不包含 1 。
collection.insert(1);

// 向集合中插入另一个 1 。返回 false 表示集合包含 1 。集合现在包含 [1,1] 。
collection.insert(1);

// 向集合中插入 2 ，返回 true 。集合现在包含 [1,1,2] 。
collection.insert(2);

// getRandom 应当有 2/3 的概率返回 1 ，1/3 的概率返回 2 。
collection.getRandom();

// 从集合中删除 1 ，返回 true 。集合现在包含 [1,2] 。
collection.remove(1);

// getRandom 应有相同概率返回 1 和 2 。
collection.getRandom();

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/insert-delete-getrandom-o1-duplicates-allowed
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
