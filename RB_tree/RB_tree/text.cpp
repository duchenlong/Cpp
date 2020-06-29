#define _CRT_SECURE_NO_WARNINGS 1

#include "head.hpp"
#include "Mymap.hpp"
#include <cstdlib>
#include <ctime>


template<class K,class V>
struct cmp
{
	const K& operator()(const pair<K, V>& kv)
	{
		return kv.first;
	}
};

void text1()
{
	RBTree<int, pair<int,int>,cmp<int,int>> rb;
	srand((int)time(0));

	for (int i = 0; i < 100; i++)
	{
		rb.Insert(make_pair(rand() % 100, i));
		cout << rb.IsRBTree() << endl;
	}

	rb.Inorder();

	/*for (auto& eoch : rb)
		cout << eoch.first << endl;*/

	rb.end();
	
}



int main()
{
	text1();
	dcl::text2();
	return 0;
}