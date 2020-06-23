#define _CRT_SECURE_NO_WARNINGS 1


#include "head.hpp"
#include <time.h>
#include <vector>


int main()
{
	srand((int)time(0));

	avl_tree<int, int> obj;
	//vector<int> arr({ 16, 3, 7, 11, 9, 26, 18, 14, 15 });
	vector<int> arr({ 4, 2, 6, 1, 3, 5, 15, 7, 16, 14 });
	
	/*for (auto& i : arr)
	{
	pair<int, int> a = make_pair(i , i);
	obj.insert(a);
	obj.Show();
	cout << obj.IsBF() << endl;
	}*/

	for (int i = 0; i < 100; i++)
	{
		pair<int, int> a = make_pair(rand() % 100, i);
		obj.insert(a);
		obj.Show();
		cout << obj.IsBF() << endl;
	}
		
	
	return 0;
}
