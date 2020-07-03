#pragma once

#include <vector>
#include <iostream>
#include <string>
#include <map>
#include <ctime>
using namespace std;

namespace dcl
{
	//节点
	template<class T>
	struct HashNode
	{
		T _data;
		HashNode<T>* _next;

		HashNode(const T& data)
			:_data(data)
			, _next(nullptr)
		{}
	};
	// 前置声明
	template<class K, class T, class KeyOfT, class Hash>
	class HashTable;

	//迭代器
	template<class K,class T,class KeyOfT,class Hash>
	struct __HashTableIterator
	{
		typedef __HashTableIterator<K, T, KeyOfT, Hash> Self;
		typedef HashTable<K, T, KeyOfT, Hash> HT;
		typedef HashNode<T> node;
		node* _node;
		HT* _pht;

		__HashTableIterator(node* n,HT* pht)
			:_node(n)
			, _pht(pht)
		{}

		T& operator*()
		{
			return _node->_data;
		}

		T* operator->()
		{
			return &(_node->_data);
		}

		Self operator++()
		{
			if (_node->_next != nullptr)
			{
				_node = _node->_next;
				return *this;
			}

			//当前权值的桶已经走完了，需要找到下一个桶
			KeyOfT koft;
			size_t i = _pht->HashFunc(koft(_node->_data)) % _pht->_table.size();
			i++;//到下一个桶的位置
			for (; i < _pht->_table.size(); i++)
			{
				node* cur = _pht->_table[i];
				if (cur)
				{
					_node = cur;
					return *this;
				}
			}
			_node = nullptr;//这里说明遍历完了最后一个桶
			return *this;
		}

		bool operator!=(const Self& s)
		{
			return _node != s._node;
		}
		bool operator==(const Self& s)
		{
			return _node == s._node;
		}
	};

	//得到当前位置的数据
	template<class T>
	struct _Hash
	{
		const T& operator()(const T& key)
		{
			return key;
		}
	};
	//特化字符串类型数据
	template<>
	struct _Hash < string >
	{
		size_t operator()(const string& key)
		{
			size_t ans = 0;
			for (size_t i = 0; i < key.size(); i++)
			{
				ans *= 131;
				ans += key[i];
			}
			return ans;
		}
	};


	//桶哈希
	template<class K, class T, class KeyOfT, class Hash>
	class HashTable
	{
	public:
		typedef HashNode<T> node;
		//设置迭代器为自己的友元
		friend struct __HashTableIterator < K, T, KeyOfT, Hash > ;
		typedef __HashTableIterator< K, T, KeyOfT, Hash > iterator;
	public:
		HashTable()
			:_num(0)
		{
			_table.clear();
			_table.resize(11);//设置初始容量
		}
		~HashTable()
		{
			Clear();
		}

		//迭代器
		iterator begin()
		{
			for (size_t i = 0; i < _table.size(); i++)
				if (_table[i] != nullptr)
					return iterator(_table[i], this);
			//说明表中没有数据
			return end();
		}
		iterator end()
		{
			return iterator(nullptr, this);
		}

		//得到当前位置的数据，转为数字类型
		size_t HashFunc(const K& key)
		{
			Hash hash;
			return hash(key);
		}

		//插入
		pair<iterator, bool> insert(const T& data)
		{
			KeyOfT koft;

			//桶哈希中，如果负载因子 = 1，就进行扩容
			if (_table.size() == _num)
			{
				vector<node*> newTable;
				size_t newSize = _table.size() * 2;
				newTable.resize(newSize);

				for (size_t i = 0; i < _table.size(); i++)
				{
					node* cur = _table[i];
					while (cur != nullptr)
					{
						node* next = cur->_next;
						//计算应该插入到新表中的位置
						size_t idx = HashFunc(koft(cur->_data)) % newSize;
						//进行头插
						cur->_next = newTable[idx];
						newTable[idx] = cur;
						cur = next;
					}
					//这个节点以经没有数据了
					_table[i] = nullptr;
				}
				_table.swap(newTable);
			}

			//插入这个新的数据
			//计算插入位置
			size_t idx = HashFunc(koft(data)) % _table.size();
			//找到插入的地方
			node* cur = _table[idx];
			while (cur != nullptr)
			{
				//该数据已经在表中，不需要插入了
				if (koft(cur->_data) == koft(data))
					return make_pair(iterator(cur, this), false);
				cur = cur->_next;
			}
			//确保表中没有该数据，进行头插
			node* newNode = new node(data);
			newNode->_next = _table[idx];
			_table[idx] = newNode;

			_num++;
			return make_pair(iterator(newNode, this), true);
		}

		//查找
		node* find(const K& key)
		{
			KeyOfT koft;
			size_t idx = HashFunc(koft(key)) % _table.size();
			node* cur = _table[idx];

			while (cur != nullptr)
			{
				if (koft(cur->_data) == key)
					return cur;
				cur = cur->_next;
			}
			//这里说明没有找到
			return nullptr;
		}

		//删除
		bool erase(const K& key)
		{
			KeyOfT koft;
			size_t idx = HashFunc(koft(key)) % _table.size();
			node* cur = _table[idx];
			node* pre = nullptr;

			while (cur != nullptr)
			{
				if (koft(cur->_data) == key)
				{
					if (pre == nullptr)//删除第一个节点
						_table[idx] = cur->_next;
					else
						pre->_next = cur->_next;
					delete cur;
					return true;
				}
				pre = cur;
				cur = cur->_next;
			}
			return false;
		}
	private:
		void Clear()
		{
			for (size_t i = 0; i < _table.size(); i++)
			{
				node* cur = _table[i];
				while (cur != nullptr)
				{
					node* _next = cur->_next;
					delete cur;
					cur = _next;
				}
				_table[i] = nullptr;
			}
		}
	private:
		vector<node*> _table;
		size_t _num;
	};

	template<class T>
	struct KofT
	{
		const T& operator()(const T& data)
		{
			return data;
		}
	};

	
}



namespace dcl_sanlie
{
	//哈希表中每一个位置的状态
	enum Status
	{
		EMPTY,//空
		EXITS,//存在
		DELETE,//删除
	};

	//数组的类型
	template<class T>
	struct HashData
	{
		T _data;
		Status _status;//当前位置的状态
	};

	template<class K, class T, class KOfT>
	class HashTable
	{
	public:
		HashTable()
			:_num(0)
		{
			//初始的容量不能为0,
			_table.resize(10);
		}
		bool Insert(const T& d)
		{
			KOfT _koft;
			//是否需要扩容
			if (_num * 10 / _table.size() >= 7)
			{
				//扩容
				//第一种写法，建立一个vector
				/*
				vector<HashData<T>> newTable;
				newTable.resize(_table.size() * 2);
				for (size_t i = 0; i < _table.size(); i++)
				{
				if (_table[i]._status == EXITS)
				{
				//计算在新表中的数据
				size_t idx = _koft(_table[i]._data) % newTable.size();
				//找到插入位置
				while (newTable[idx]._status == EXITS)
				idx = (idx + 1) % newTable.size();
				newTable[idx]._data = _table[i]._data;
				newTable[idx]._status = EXITS;
				}
				}
				swap(newTable, _table);
				*/

				//第二种写法，新建一个hashtable
				HashTable<K, T, KofT<K>> newHash;
				newHash._table.resize(_table.size() * 2);
				for (size_t i = 0; i < _table.size(); i++)
					if (_table[i]._status == EXITS)
						newHash.Insert(_table[i]._data);
				_table.swap(newHash._table);
			}


			//计算映射位置
			//线性探测
			/*
			size_t idx = _koft(d) % _table.size();
			while (_table[idx]._status == EXITS)
			{
			//如果该数据已经存在
			if (_koft(_table[idx]._data) == _koft(d))
			return false;

			//向后查找的时候，需要组成一个循环查找
			idx = (idx + 1) % _table.size();
			}

			_table[idx]._data = d;
			_table[idx]._status = EXITS;
			_num++;
			*/

			//二次探测
			size_t start = _koft(d) % _table.size();
			size_t idx = start;
			int i = 1;
			while (_table[idx]._status == EXITS)
			{
				if (_koft(_table[idx]._data) == _koft(d))
					return false;
				idx = start + i * i;
				i++;
				idx %= _table.size();
			}
			_table[idx]._data = d;
			_table[idx]._status = EXITS;
			_num++;
			return true;
		}

		//查找
		HashData<T>* Find(const K& key)
		{
			size_t idx = key % _table.size();

			size_t start = idx;
			size_t i = 1;

			while (_table[idx]._status != EMPTY)
			{
				if (_table[idx]._data == key)
				{
					if (_table[idx]._status == EXITS)
						return &_table[idx];
					else if (_table[idx]._status == DELETE)
						return nullptr;
				}
				idx = (start + i * i) % _table.size();
				i++;
			}

			return nullptr;
		}

		//删除
		bool Erase(const K& key)
		{
			HashData* ret = Find(key);
			if (ret)
			{
				ret->_status = DELETE;
				_num--;
				return true;
			}

			//数据不存在
			return false;
		}

	private:
		vector<HashData<T> > _table;
		size_t _num;//所存储数据的数量
	};
}