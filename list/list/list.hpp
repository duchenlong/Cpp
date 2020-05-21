#pragma  once

#include <iostream>
#include <assert.h>
using std::cin;
using std::cout;
using std::endl;

//保存链表的每一个结点信息的结构体
template<class T>
struct __list_node
{
	T _val;
	__list_node<T>* _pre;
	__list_node<T>* _next;

	__list_node(const T val = T())
	{
		_val = val;
		_pre = _next = nullptr;
	}
};

//定义迭代器  Ref是引用类型  Ptr是指针类型 T是普通类型
template<class T, class Ref, class Ptr>
struct __list_iterator
{
	/*typedef __list_iterator<T, T&, T*>  iterator;
	typedef __list_iterator<T, const T&, const T*> const_iterator;*/
	typedef __list_iterator< T, Ref, Ptr > Self;
	typedef __list_node<T> node;
	node* _node;

	__list_iterator(node* node_)
		:_node(node_)
	{}

	//* 解引用运算符重载
	Ref operator*()
	{
		return (*_node)._val;
	}

	//-> 
	Ptr operator->()
	{
		//return &_node->_val;
		return &(operator*());
	}

	//++i 
	Self& operator++()
	{
		_node = _node->_next;
		return *this;
	}

	//i++ 
	Self operator++(T)
	{
		Self tmp(*this);
		_node = _node->_next;
		return tmp;
	}

	//--i
	Self& operator--()
	{
		_node = _node->_pre;
		return *this;
	}

	//i--
	Self operator--(T)
	{
		 Self tmp = *this;
		_node = _node->_pre;
		return tmp;
	}

	//!=
	bool operator!=(const Self& it)
	{
		return _node != it._node;
	}

	//==
	bool operator==(const Self& it)
	{
		return _node == it._node;
	}
	
};

template <class T>
class list
{
public:
	//对结构体进行封装
	typedef __list_node<T> node;
	typedef __list_iterator<T, T&, T*>  iterator;
	typedef __list_iterator<T, const T&, const T*> const_iterator;

	list()
	{
		_head = new node;
		_head->_next = _head->_pre = _head;
	}
	~list()
	{
		clear();
		delete _head;
		_head = nullptr;
	}
	list(const list<T>& it)
	{
		_head = new node;

		_head->_pre = _head->_next = _head;
		for (auto& eoch : it)
			push_back(eoch);
	}

	list<T>& operator=(const list<T>& it)
	{
		if (*this != it)
		{
			clear();
			for (auto eoch : it)
				push_back(eoch);
		}
	}

	//调用运算符重载的 ->
	iterator begin()
	{
		return iterator(_head->_next);
	}

	//调用运算符重载 *
	iterator end()
	{
		return iterator(_head);
	}

	const_iterator begin() const
	{
		return const_iterator(_head->_next);
	}
	const_iterator end() const
	{
		return const_iterator(_head);
	}

	//带头双向循环链表的尾插
	void push_back(T x)
	{
		/*node* cur = new node(x);

		_head->_pre->_next = cur;
		cur->_pre = _head->_pre;

		_head->_pre = cur;
		cur->_next = _head;*/

		insert(_head,x);
	}
	//尾删
	void pop_back()
	{
		/*node* del = _head->_pre;

		if (del == _head)
			return;

		del->_pre->_next = _head;
		_head->_pre = del->_pre;

		delete del;*/

		erase(_head->_pre);
	}

	//头插
	void push_front(T x)
	{
		/*node* cur = new node(x);

		_head->_next->_pre = cur;
		cur->_next = _head->_next;

		_head->_next = cur;
		cur->_pre = _head;*/

		insert(_head->_next, x);
	}

	//头删
	void pop_front()
	{
		//node* del = _head->_next;
		////没有元素不能删除
		//if (del == _head)
		//	return;
		//del->_next->_pre = _head;
		//_head->_next = del->_next;

		//delete del;

		erase(_head->_next);
	}

	void insert(iterator pos,const T& x)
	{
		node* cur = new node(x);
		
		//通过迭代器找到待插入位置
		node* p = pos._node;
		
		p->_pre->_next = cur;
		cur->_pre = p->_pre;

		cur->_next = p;
		p->_pre = cur;
	}

	//clear
	void clear()
	{
		iterator it = begin();
		/*while (it != end())
		{
			iterator next = it;
			next++;

			delete it._node;
			it = next;
		}
		_head->_next = _head;
		_head->_pre = _head;*/

		while (it != end())
			erase(it++);
	}

	//earse
	iterator erase(iterator pos)
	{
		//没有元素的时候不能删除
		assert(pos != end());

		//迭代器的成员是node的一个结构体
		node* del = pos._node;
		node* ret = del->_next;
		node* pre = del->_pre;

		pre->_next = ret;
		ret->_pre = pre;
		delete del;

		//调用*运算符重载，返回解引用
		return iterator(ret);
	}

private:
	node* _head;
};