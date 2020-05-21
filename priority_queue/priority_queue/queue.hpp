#pragma once
#include <vector>
#include <iostream>
#include <functional>//greater算法头文件

using std::vector;
using std::cout;
using std::endl;

//建大堆
template<class T>
struct less
{
	bool operator()(const T& left, const T& right)
	{
		return left < right;
	}
};

//建小堆
template<class T>
struct greater
{
	bool operator()(const T& left, const T& right)
	{
		return left > right;
	}
};

//优先级队列中默认是建立大堆，小于号的重载
template<class T, class Container = vector<T>, class Compare = less<T>>
class priority_queue
{
public:
	priority_queue()
		:arr()
	{}


	//入队
	void push(T x)
	{
		arr.push_back(x);

		//向上调整,选择传一个有效的位置
		AdjestUp(arr.size()-1);
	}

	//出队，删除队头元素
	void pop()
	{
		//队列中要有元素
		if (empty())
			return;

		std::swap(arr.front(), arr.back());
		arr.pop_back();
		//向下调整
		AdjestDown(0);
	}

	//返回优先级队列中元素的大小
	size_t size() const
	{
		return arr.size();
	}

	//判断优先级队列是否为空
	bool empty() const
	{
		return arr.empty();
	}
	
	//堆顶元素不允许修改，可能会破坏堆的结构
	const T& top()const
	{
		return arr.front();
	}
	void show()
	{
		for (size_t i = 0; i < arr.size(); i++)
		{
			cout << arr[i] << ',';
		}
		cout << endl;
	}
private:
	//向上调整，在原有堆的基础上调整
	void AdjestUp(size_t child)
	{
		size_t parent = (child - 1) / 2;

		while (child > 0)
		{
			if (com(arr[parent], arr[child]))
			{
				std::swap(arr[child], arr[parent]);
				child = parent;
				parent = (child - 1) / 2;
			}
			else
				break;
		}
	}

	//向下调整
	void AdjestDown(size_t parent)
	{
		size_t child = parent * 2 + 1;
		size_t len = arr.size();

		while (child < len)
		{
			//找左右孩子中最大的
			if (child + 1 < len && com(arr[child] , arr[child + 1]))
				child++;

			//判断孩子和父亲
			if (com(arr[parent], arr[child]))
			{
				std::swap(arr[child], arr[parent]);
				parent = child;
				child = parent * 2 + 1;
			}
			else
				break;
		}
	}

private:
	Container arr;	//存储模式
	Compare com;	//比较的访函数
};