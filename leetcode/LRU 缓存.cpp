class LRUCache {
public:
    typedef pair<int,int> PII;

    LRUCache(int capacity) : _size(capacity){

    }
    
    int get(int key) {
        if(_hash.count(key) <= 0)
            return -1;
        auto it = _hash[key];
        _list.push_front(*it);
        _list.erase(it);
        _hash[key] = _list.begin();

        return _list.begin()->second;
    }
    
    void put(int key, int value) {
        auto it = _hash.find(key);
        if(it == _hash.end()) {
            if(_size == 0) {
                auto del = _list.back();
                _hash.erase(del.first);
                _list.pop_back();
                _size++;
            }

            _list.push_front({key,value});
            _hash[key] = _list.begin();
            _size--;
        } else {
            get(key);
            _list.begin()->second = value;
        }
    }
private:
    int _size;
    list<PII> _list;
    unordered_map<int,list<PII>::iterator> _hash;
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
