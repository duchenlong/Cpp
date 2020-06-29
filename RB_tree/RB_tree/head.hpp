#pragma once

#include <iostream>
#include <map>

using namespace std;

enum Color
{
	BLACK,
	RED,
};

template<class T>
struct RBTreeNode
{
	typedef RBTreeNode<T> node;

	node* _left;
	node* _right;
	node* _parent;
	T _data;
	Color _col;

	RBTreeNode(const T& data)
	{
		_left = _right = _parent = nullptr;
		_data = data;
		_col = RED;
	}
};

template<class T,class Ref,class Ptr>
struct __TreeIterator
{
	typedef RBTreeNode<T> Node;
	typedef __TreeIterator<T, Ref, Ptr> Self;
	Node* _node;

	__TreeIterator(Node* node)
		:_node(node)
	{}

	Ref operator*()
	{
		return _node->_data;
	}

	Ptr operator->()
	{
		return &_node->_data;
	}

	Self& operator++()
	{
		//如果存在右子树，那么下一个节点就是右子树中最小的那个节点
		if (_node->_right)
		{
			Node* cur = _node->_right;
			while (cur->_left)
				cur = cur->_left;
			_node = cur;
		}
		else
		{
			//右子树不存在，
			Node* cur = _node;
			Node* parent = cur->_parent;
			while (parent && cur == parent->_right)
			{
				cur = cur->_parent;
				parent = parent->_parent;
			}
			_node = parent;
		}
		return *this;
	}

	Self& operator--()
	{
		if (_node->_left != nullptr)
		{
			//找到左子树中最大的一个节点
			Node* cur = _node->_left;
			while (cur->_right)
				cur = cur->_right;
			_node = cur;
		}
		else
		{
			Node* cur = _node;
			Node* parent = cur->_parent;
			while (parent && cur == parent->_left)
			{
				cur = parent;
				parent = parent->_parent;
			}
			_node = parent;
		}

		return *this;
	}

	bool operator!=(const Self& s)
	{
		return _node != s._node;
	}

	bool operator==(const Self& s)
	{
		return _node == s._node;
	}
};

template<class K,class T,class KOfT>
class RBTree
{
public:
	typedef RBTreeNode<T> node;
	//迭代器
	typedef __TreeIterator<T, T&, T*> iterator;
	typedef __TreeIterator<T, const T&, const T*> const_iterator;
public:
	RBTree()
		:_root(nullptr)
	{}

	//迭代器
	iterator begin()//返回最小的节点的iterator迭代器
	{
		node* cur = _root;
		while (cur && cur->_left)
			cur = cur->_left;
		return iterator(cur);
	}

	iterator end()//返回最大元素的下一个元素，即为空
	{
		return iterator(nullptr);
	}

	//插入
	pair<iterator,bool> Insert(const T& data)
	{
		//找到插入节点
		if (_root == nullptr)
		{
			_root = new node(data);
			_root->_col = BLACK;
			return make_pair(iterator(_root),true);
		}

		KOfT koft;//比较的函数
		node* parent = nullptr;
		node* cur = _root;
		while (cur)
		{
			if (koft(cur->_data) == koft(data))
				return make_pair(iterator(cur),false);
			parent = cur;
			cur = (koft(cur->_data) < koft(data)) ? cur->_right : cur->_left;
		}

		//此时cur为插入节点的位置，cur即为nullptr
		cur = new node(data);
		node* newNode = cur;
		if (koft(parent->_data) < koft(cur->_data))
		{
			parent->_right = cur;
			cur->_parent = parent;
		}
		else if (koft(parent->_data) > koft(cur->_data))
		{
			parent->_left = cur;
			cur->_parent = parent;
		}

		//调节
		while (parent && parent->_col == RED)
		{
			//找到父亲的父亲节点
			node* grandfather = parent->_parent;
			//通过grandfather节点，找到cur的叔叔节点
			
			if (grandfather->_left == parent)
			{
				//叔叔节点为grandfather右节点
				node* uncle = grandfather->_right;
				
				// 1. uncle 存在，并且该节点为红色
				if (uncle != nullptr && uncle->_col == RED)
				{
					parent->_col = uncle->_col = BLACK;
					grandfather->_col = RED;

					//继续向上处理
					cur = grandfather;
					parent = cur->_parent;
				}
				else
				{
					//3.cur 是parent的右子树节点
					if (cur == parent->_right)
					{
						Right_Right(parent);
						swap(parent, cur);
					}

					//2.uncle节点为nullptr，说明cur结点一定是新增节点，而不是向上调整后的节点
					//uncle节点存在，那么此时他一定是黑色节点
					//对grandfather进行一次右旋
					Left_Left(grandfather);
					parent->_col = BLACK;
					grandfather->_col = RED;

					break;
				}
			}
			else if (grandfather->_right = parent)
			{
				node* uncle = grandfather->_left;

				if (uncle != nullptr && uncle->_col == RED)
				{
					parent->_col = uncle->_col = BLACK;
					grandfather->_col = RED;

					cur = grandfather;
					parent = cur->_parent;
				}
				else
				{
					if (cur == parent->_left)
					{
						Left_Left(parent);
						swap(parent, cur);
					}

					Right_Right(grandfather);
					grandfather->_col = RED;
					parent->_col = BLACK;

					break;
				}
			}
		}

		_root->_col = BLACK;
		return make_pair(iterator(newNode),true);
	}

	//中序遍历
	void Inorder()
	{
		_Inorder(_root);
	}

	//判断是否是红黑树
	bool IsRBTree()
	{
		node* proot = _root;
		//空树也是红黑树
		if (nullptr == proot)
			return true;

		//根节点必须为黑色
		if (BLACK != proot->_col)
		{
			cout << "根节点不为黑色" << endl;
			return false;
		}

		//获取任意一条路径中，黑色节点的数量
		size_t blackNum = 0;
		node* cur = proot;
		while (cur != nullptr)
		{
			if (BLACK == cur->_col)
				blackNum++;
			cur = cur->_left;
		}

		size_t k = 0;
		return _IsRBTree(proot, k, blackNum);
	}

	iterator Find(const K& key)
	{
		KOfT koft;
		node* cur = _root;
		while (cur)
		{
			if (koft(cur) == key)
				return iterator(cur);
			cur = (koft(cur->_data) < key) ? cur->_right : cur->_left;
		}
		return iterator(nullptr);
	}
private:
	bool _IsRBTree(node* root, size_t k, size_t blackNum)
	{
		//走到了叶子节点，判断黑色节点是否相等
		if (nullptr == root)
		{
			if (k != blackNum)
			{
				cout << "路径中黑色节点数量不相等" << endl;
				return false;
			}
			return true;
		}

		// 统计黑色节点的个数
		if (BLACK == root->_col)
			k++;

		// 检测当前节点与其双亲是否都为红色
		node* pParent = root->_parent;
		if (pParent != nullptr && RED == pParent->_col && RED == root->_col)
		{
			cout << "有两个相连的红色节点" << endl;
			return false;
		}
		return _IsRBTree(root->_left, k, blackNum) && _IsRBTree(root->_right, k, blackNum);
	}
	//右旋
	void Left_Left(node* parent)
	{
		node* pParent = parent->_parent;
		node* pLeft = parent->_left;
		node* pLRight = pLeft->_right;

		parent->_left = pLRight;
		if (pLRight)	pLRight->_parent = parent;

		pLeft->_right = parent;
		parent->_parent = pLeft;

		if (pParent == nullptr)
			_root = pLeft;
		else
			(parent == pParent->_left) ? pParent->_left = pLeft: pParent->_right = pLeft;
		pLeft->_parent = pParent;
	}

	//左旋
	void Right_Right(node* parent)
	{
		node* pParent = parent->_parent;
		node* pRight = parent->_right;
		node* pRLeft = pRight->_left;

		parent->_right = pRLeft;
		if(pRLeft)	pRLeft->_parent = parent;

		pRight->_left = parent;
		parent->_parent = pRight;

		if (pParent == nullptr)
			_root = pRight;
		else
			(pParent->_left == parent) ? pParent->_left = pRight : pParent->_right = pRight;
		pRight->_parent = pParent;
	}

	//中序遍历
	void _Inorder(node* root)
	{
		if (root == nullptr)
			return;

		_Inorder(root->_left);
		cout << root->_data.first << " : " << root->_data.second << endl;
		_Inorder(root->_right);
	}
private:
	node* _root;
};