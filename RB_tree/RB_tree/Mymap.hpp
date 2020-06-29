#pragma once

#include "head.hpp"
#include <string>

namespace dcl
{
	template<class K,class V>
	class map
	{
		//比较的函数
		struct MapKOfV
		{
			const K& operator()(const pair<K, V>& data)
			{
				return data.first;
			}
		};
		typedef typename RBTree<K, pair<K, V>, MapKOfV> RB_type;
		typedef typename RB_type::iterator iterator;
	public:
		iterator begin()
		{
			return _t.begin();
		}

		iterator end()
		{
			return _t.end();
		}
		
		V& operator[](const K& k)
		{
			pair<iterator, bool> ans = _t.Insert(make_pair(k, V()));
			return ans.first->second;
		}
	private:
		RB_type _t;//红黑树
	};

	void text2()
	{
		string strs[] = { "西瓜", "樱桃", "西瓜", "苹果", "西瓜", "西瓜", "西瓜", "苹果" };
		map<string, int> countMap;
		for (auto& str : strs)
		{
			// 1、如果数据不在map中，则operator[]会插入pair<str, 0>, 返回映射对象(次数)的引用进行了++。
			// 2、如果数据在map中，则operator[]返回数据对应的映射对象(次数)的引用，对它++。
			countMap[str]++;
		}

		for (auto kv : countMap)
		{
			cout << kv.first << ":" << kv.second << endl;
		}
	}
}