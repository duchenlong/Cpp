#define _CRT_SECURE_NO_WARNINGS 1

#include "head.hpp"
#include <time.h>

void show(TreeNode<int>* cur)
{
	cur ? cout << cur->_key << endl : cout << "没有该节点" << endl;
}

int main()
{
	STree<int> ST;
	int arr[] = { 4, 1, 6, 0, 2, 5, 7, 3, 8 };

	srand((unsigned)time(NULL));

	for (int i = 0; i < sizeof(arr) / sizeof(arr[1]); i++)
		ST.Insert(arr[i]);
		

	ST.Show();

	//Find
	/*TreeNode<int>* cur = ST.Find(10);
	show(cur);*/

	for (int i = 8; i >= 0; i--)
	{
		TreeNode<int>* del = ST.Find(i);
		if (!del) continue;
		ST.EarseR(i);
		ST.Show();
	}
		
	
	return 0;
}