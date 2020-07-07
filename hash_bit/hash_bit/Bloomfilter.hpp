#pragma  once
#include "head.hpp"
#include <string>

namespace dcl
{
	struct HashStr1
	{
		size_t operator()(const string& key)
		{
			size_t ans = 0;
			for (size_t i = 0; i < key.size(); i++)
			{
				ans += ans * 131 + key[i];
			}
			return ans;
		}
	};

	struct HashStr2
	{
		size_t operator()(const string& key)
		{
			size_t ans = 0;
			for (size_t i = 0; i < key.size(); i++)
			{
				ans += ans * 65599 + key[i];
			}
			return ans;
		}
		
	};


	struct HashStr3
	{
		size_t operator()(const string& key)
		{
			size_t ans = 0;
			for (size_t i = 0; i < key.size(); i++)
			{
				ans += ans * 63689 + key[i];
			}
			return ans;
		}
	};


	template<class K = string,class Hash1 = HashStr1,
				class Hash2 = HashStr2,class Hash3 = HashStr3>
	class bloomFilter
	{
	public:
		bloomFilter(size_t num)
			:_bs(num * 3)
		{}


		void set(const K& key)
		{
			size_t idx1 = Hash1()(key);
			size_t idx2 = Hash2()(key);
			size_t idx3 = Hash3()(key);

			_bs.set(idx1);
			_bs.set(idx2);
			_bs.set(idx3);
		}

		bool test(const K& key)
		{
			size_t idx1 = Hash1()(key);
			if (_bs.test(idx1) == false)
				return false;
			
			size_t idx2 = Hash2()(key);
			if (_bs.test(idx2) == false)
				return false;
			
			size_t idx3 = Hash3()(key);
			if (_bs.test(idx3) == false)
				return false;

			return true;
		}


	private:
		HashBit _bs;
	};
}