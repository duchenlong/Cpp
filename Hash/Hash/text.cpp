#define _CRT_SECURE_NO_WARNINGS 1

#include "head.hpp"
#include "Myunordered_map.hpp"

void Text()
{
	dcl::HashTable<int, int, dcl::KofT<int>, dcl::_Hash<int> > ht;
	srand((int)time(0));
	for (int i = 0; i < 100; i++)
	{
		int num = rand() % 100;
		ht.insert(num);

		for (auto eoch : ht)
			cout << eoch << " ";
		cout << endl;
	}

	for (int i = 0; i < 100; i++)
	{
		auto n = ht.find(i);
		if (n != nullptr)
			cout << (n->_data) << endl;
		ht.erase(i);
	}
	for (auto eoch : ht)
		cout << eoch << " ";
	cout << endl;
}


void test_unordered_map()
{
	dcl_map::unordered_map<string, string> dict;
	dict.insert(make_pair("sort", "ÅÅÐò"));
	dict.insert(make_pair("left", "×ó±ß"));
	dict.insert(make_pair("string", "×Ö·û´®"));
	dict["left"] = "Ê£Óà";
	dict["end"] = "Î²²¿";

	//unordered_map<string, string>::iterator it = dict.begin();
	auto it = dict.begin();
	while (it != dict.end())
	{
		cout << it->first << ":" << it->second << endl;
		++it;
	}
}

int main()
{
	//Text();
	test_unordered_map();
	return 0;
}
