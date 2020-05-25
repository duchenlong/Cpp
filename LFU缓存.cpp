//请你为 最不经常使用（LFU）缓存算法设计并实现数据结构。它应该支持以下操作：get?和?put。

//get(key)?- 如果键存在于缓存中，则获取键的值（总是正数），否则返回 -1。
//put(key, value)?- 如果键已存在，则变更其值；如果键不存在，请插入键值对。当缓存达到其容量时，则应该在插入新项之前，使最不经常使用的项无效。在此问题中，当存在平局（即两个或更多个键具有相同使用频率）时，应该去除最久未使用的键。
//「项的使用次数」就是自插入该项以来对其调用 get 和 put 函数的次数之和。使用次数会在对应项被移除后置为 0 。

//?

//进阶：
//你是否可以在?O(1)?时间复杂度内执行两项操作？

//?

//示例：

//LFUCache cache = new LFUCache( 2 /* capacity (缓存容量) */ );

//cache.put(1, 1);
//cache.put(2, 2);
//cache.get(1);       // 返回 1
//cache.put(3, 3);    // 去除 key 2
//cache.get(2);       // 返回 -1 (未找到key 2)
//cache.get(3);       // 返回 3
//cache.put(4, 4);    // 去除 key 1
//cache.get(1);       // 返回 -1 (未找到 key 1)
//cache.get(3);       // 返回 3
//cache.get(4);       // 返回 4


struct node
{
    int _key;
    int _value;
    int _freq;//出现的频率

    node(int key,int value,int _freq)
        :_key(key)
        ,_value(value)
        ,_freq(_freq)
    {}
};

class LFUCache {
public:
    LFUCache(int capacity) {
        freq_map.clear();
        key_map.clear();
        _minfreq = 0;
        _capacity = capacity;
    }
    ~LFUCache()
    {
        freq_map.clear();
        key_map.clear();
        _capacity = _minfreq = -1;
    }

    int get(int key) {
        //如果容量为0 ，直接退出
        if(_capacity == 0) return -1;

        //如果当前值不存在，也直接退出
        if(key_map.find(key) == key_map.end()) return -1;

        list<node>::iterator cur = key_map[key];
        int val = cur->_value;
        int freq = cur->_freq;
 
        //移除key的节点，在freq的使用频率链表中
        freq_map[freq].erase(cur);

        //如果当前链表删除后为空
        if(freq_map[freq].size() == 0)
        {
            freq_map.erase(freq);
            if(_minfreq == freq) _minfreq++;
        }

        //插入key的点到 freq+1 的出现频率中,头插法
        freq_map[freq+1].push_front(node(key,val,freq+1));
        key_map[key] = freq_map[freq+1].begin();
        return val;
    }
    
    void put(int key, int value) {
        if(_capacity == 0) return ;
        //如果存在Key
        if(key_map.find(key) != key_map.end())
        {
            list<node>::iterator cur = key_map[key];
            int freq = cur->_freq;
            freq_map[freq].erase(cur);

            if(freq_map[freq].size() == 0)
            {
                freq_map.erase(freq);
                if(_minfreq == freq) _minfreq++;
            }
            freq_map[freq+1].push_front(node(key,value,freq+1));
            key_map[key] = freq_map[freq+1].begin();
            return ;
        }

        //此处是不存在key，需要插入的情况
        if(key_map.size() == _capacity)
        {
            //链表已经满了
            //通过当前的最小访问频率，拿到链表的尾部数据
            node tail = freq_map[_minfreq].back();
            key_map.erase(tail._key);
            freq_map[_minfreq].pop_back();

            if(freq_map[_minfreq].size() == 0) freq_map.erase(_minfreq);
        }

        _minfreq = 1;//更新当前最小访问次数
        freq_map[_minfreq].push_front(node(key,value,1));//新结点值访问了一次
        key_map[key] = freq_map[_minfreq].begin();
    }
private:
    unordered_map<int,list<node> > freq_map; //以出现的频率来建图
    unordered_map<int,list<node>::iterator> key_map; //通过key值找到这个节点的迭代器
    int _minfreq;  //当前最小使用次数
    int _capacity;//容量 
};

/**
 * Your LFUCache object will be instantiated and called as such:
 * LFUCache* obj = new LFUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
