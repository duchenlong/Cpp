#pragma once

#include <iostream>
#include <vector>

template<class T>
class unionFindSet
{
public:
	unionFindSet(const int size)
	{
		_ufs = vector<T> (size,-1);
	}

	//递归查找
	int Find_recu(const int pos)
	{
		if (_ufs[pos] >= 0)
			_ufs[pos] = Find(_ufs[pos]);
		return _ufs[pos];
	}

	//迭代查找
	int Find_iter(const int pos)
	{
		int res = _ufs[pos];
		while (res >= 0)
			res = _ufs[res];
		return res;
	}

	/*
	 **		le_root ri_root			分别为两个节点的根节点的位置
	 **			le_root == ri_root	说明两个节点在同一棵树中，不需要进行合并
	 **
	 **			le_root != ri_root	说明不在同一棵树中，需要进行合并
	 **					le 位置需要 + ri位置所存节点个数;  再更新 ri 位置的根节点下标 为 le
	*/
	bool Union(const int le, const int ri)
	{
		int le_root = Find_iter(le);
		int ri_root = Find_iter(ri);

		if (le_root == ri_root)
			return false;

		_ufs[le] += _ufs[ri];
		_ufs[ri] = le;
		return true;
	}
private:
	vector<T> _ufs;
};