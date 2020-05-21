#define _CRT_SECURE_NO_WARNINGS 1

#pragma once
#include <assert.h>
#include <algorithm>
#include <iostream>

using std::cin;
using std::cout;
using std::endl;

template<class T>
class vector
{
public:
	//冲定义迭代器的类型
	typedef T* iterator;
	typedef const T* const_iterator;

	//构造函数
	vector()
		:_start(nullptr)
		, _finish(nullptr)
		, _end_of_storage(nullptr)
	{}

	//析构函数
	~vector()
	{
		delete[] _start;
		_start = _finish = _end_of_storage = nullptr;
	}

	//拷贝构造
	vector(const vector<T>& obj)
	{
		_start = new T[obj.size()];
		_finish = _end_of_storage = _start + obj.size();

		memcpy(_start, obj._start, obj.size() * sizeof(T));
	}
	//赋值运算符重载
	vector<T>& operator=(vector<T> obj)
	{
		//这里需要加this指针，声明这个swap是在这个类中的交换函数，而不是std空间中的
		this->swap(obj);
		return *this;
	}
	void swap(vector<T>& obj)
	{
		std::swap(_start, obj._start);
		std::swap(_finish, obj._finish);
		std::swap(_end_of_storage, obj._end_of_storage);
	}

	//[] 运算符重载
	T& operator[](size_t pos)
	{
		assert(pos < size());//不能越界访问
		return _start[pos];
		//return *(_start + pos);
	}

	//返回容器大小
	size_t size() const
	{
		return _finish - _start;
	}
	//返回容器容量
	size_t capacity() const
	{
		return _end_of_storage - _start;
	}

	//扩容
	//reserve
	void reserve(size_t n)
	{
		//如果是没有容量，还要扩容，给一个初始值2
		if (capacity() == 0 && n == 0)
			n = 2;
		//只有比原本容量大才起作用
		if (n > capacity())
		{
			size_t len = size();
			
			T* tmp = new T[n];
			//防止出现 _start == nullptr 而报错
			if (_start)
			{
				memmove(tmp, _start, len * sizeof(T));
				delete[] _start;
			}

			_start = tmp;
			_finish = _start + len;
			_end_of_storage = _start + n;
		}
	}

	//因为这里不确定 模板T 的类型，所以缺省值不能直接给0，因为自定义类型给0的话可能会出错
	void resize(size_t n, const T& value = T())
	{
		//如果自身容量大于要求的大小，进行缩放
		//这里不能加 = ，因为 size() 返回的大小是一个左闭右开区间的尾部，最后一个值是不存在的
		if (n < size())
		{
			_finish = _start + n;
		}
		else  //自身容量小于要求的大小
		{
			//判断是否进行扩容
			if (n > capacity())
				reverse(n);

			//把需要填充的值填充在后面
			while (_finish != _start + n)
				*(_finish++) = value;
		}
	}

	//尾插
	void push_back(const T& x)
	{
		//判断是否需要扩容
		if (_finish == _end_of_storage)
			reserve(capacity() * 2);//可以2倍扩容，也可以1.5倍扩容

		*(_finish++) = x;
	}

	//尾删
	void pop_back()
	{
		assert(_finish > _start);//保证数组中有数据
		_finish--;
	}

	//中间插入元素
	void insert(iterator pos, const T& x)
	{
		assert(pos <= _finish);//插入位置必须合法

		if (_finish == _end_of_storage)//是否需要扩容
		{
			size_t offset = pos - _start;//计算偏移量
			reserve(capacity() * 2);
			pos = _start + offset;//更新新的插入位置
		}

		//把pos位置后的数据向后挪动一位
		iterator end = _finish - 1;
		while (end >= pos)
		{
			*(end + 1) = *end;
			end--;
		}
		*pos = x;
		_finish++;
	}

	//擦除数据
	iterator erase(iterator pos)
	{
		assert(pos <= _finish);//擦除数据的位置必须合法
		iterator it = pos + 1;
		while (it != _finish)
		{
			*(it - 1) = *it;
			it++;
		}
		_finish--;
		return pos;
	}

	//迭代器
	//返回数组的开始位置
	iterator begin()
	{
	return _start;
	}
	const_iterator begin() const
	{
		return _start;
	}
	//返回末尾位置，末尾是一个开区间
	iterator end()
	{
		return _finish;
	}
	const_iterator end() const
	{
		return _finish;
	}

private:
	iterator _start;
	iterator _finish;
	iterator _end_of_storage;
};