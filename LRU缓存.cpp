//运用你所掌握的数据结构，设计和实现一个? LRU (最近最少使用) 缓存机制。它应该支持以下操作： 获取数据 get 和 写入数据 put 。

//获取数据 get(key) - 如果密钥 (key) 存在于缓存中，则获取密钥的值（总是正数），否则返回 -1。
//写入数据 put(key, value) - 如果密钥已经存在，则变更其数据值；如果密钥不存在，则插入该组「密钥/数据值」。当缓存容量达到上限时，它应该在写入新数据之前删除最久未使用的数据值，从而为新的数据值留出空间。

//?

//进阶:

//你是否可以在?O(1) 时间复杂度内完成这两种操作？

//?

//示例:

//LRUCache cache = new LRUCache( 2 /* 缓存容量 */ );

//cache.put(1, 1);
//cache.put(2, 2);
//cache.get(1);       // 返回  1
//cache.put(3, 3);    // 该操作会使得密钥 2 作废
//cache.get(2);       // 返回 -1 (未找到)
//cache.put(4, 4);    // 该操作会使得密钥 1 作废
//cache.get(1);       // 返回 -1 (未找到)
//cache.get(3);       // 返回  3
//cache.get(4);       // 返回  4

struct node
{
    node* _pre;
    node* _next;
    int _key;
    int _value;

    node(int key,int value)
        :_key(key)
        ,_value(value)
        ,_pre(NULL)
        ,_next(NULL)
    {}
};

class LRUCache {
public:
    LRUCache(int capacity) {
        _capacity = capacity;
        head = new node(-1,-1);
        head->_next = head->_pre = head;
    }
    ~LRUCache()
    {
        delete head;
        _capacity = -1;
    }

    //从链表中移除该节点
    void RemoveNode(node* cur)
    {
        cur->_next->_pre = cur->_pre;
        cur->_pre->_next = cur->_next;
    }

    //头插
    void PushFront(node* cur)
    {
 
        head->_next->_pre = cur;
        cur->_next = head->_next;

        head->_next = cur;
        cur->_pre = head;
    }

    int get(int key) {
        if(map.find(key) != map.end())
        {
            node* cur = map[key];
            //移除该节点
            RemoveNode(cur);
            //把该节点放到头部
            PushFront(cur);
            return cur->_value;
        }
        return -1;
    }
    
    void put(int key, int value) {
        //如果存在key
        if(map.find(key) != map.end())
        {
            node* cur = map[key];
            //移除
            RemoveNode(cur);
            //头插
            PushFront(cur);
            cur->_value = value;
            return ;
        }

        //这里不存在key,value
        //判断内存是否满了
        if(map.size() == _capacity)
        {
            //移除队尾元素
            node* tail = head->_pre;
            RemoveNode(tail);
            map.erase(tail->_key);
            delete tail;
        }
        //队头插入key
        node* cur = new node(key,value);
        PushFront(cur);
        map[key] = cur;
    }
private:
    int _capacity;
    node* head;
    unordered_map<int,node*> map;
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
