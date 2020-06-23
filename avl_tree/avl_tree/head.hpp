#pragma once

#include <iostream>
#include <cmath>
#include <assert.h>
#include <map>
#include <algorithm>

using namespace std;

template<class Key,class Val>
struct tree_node
{
	typedef tree_node<Key, Val> node;
	typedef pair<Key, Val> data_type;

	node* _parent;	//双亲节点
	node* _left;	//左孩子节点
	node* _right;	//右孩子节点
	data_type _data;//节点的值
	int _bf;		//平衡因子

	tree_node(const data_type& data)
		:_data(data), _bf(0)
	{
		_parent = _left = _right = nullptr;
	}
};

template<class key, class val>
class avl_tree
{
public:
	typedef key key_type;
	typedef val val_type;
	typedef tree_node<key_type,val_type> node;
	avl_tree()
		:root(nullptr)
	{}

	bool insert(const pair<key_type,val_type>& data)
	{
		//如果树中没有节点
		if (root == nullptr)
		{
			root = new node(data);
			return true;
		}

		node* parent = nullptr;
		node* cur = root;
		
		//找到要插入的位置
		while (cur)
		{
			if (cur->_data.first == data.first) return false;
			parent = cur;
			//cur = (cur->_data.first < data.first) ? cur->_right : cur->_left;
			if (cur->_data.first < data.first)
			{
				//cur->_bf++;
				cur = cur->_right;
			}
			else if (cur->_data.first > data.first)
			{
				//cur->_bf--;
				cur = cur->_left;
			}
		}

		cur = new node(data);
		//插入 cur 到指定位置
		if (parent->_data.first < data.first)
			parent->_right = cur;
		else
			parent->_left = cur;
		cur->_parent = parent;

		//更新平衡因子
		while (parent)
		{
			if (cur == parent->_right)
			{
				parent->_bf++;
			}
			else if (cur == parent->_left)
			{
				parent->_bf--;
			}

			if (parent->_bf == 0)
			{
				break;
			}
			else if (abs(parent->_bf) == 1)
			{
				cur = parent;
				parent = parent->_parent;
			}
			else if (abs(parent->_bf) == 2)
			{
				//此时parent的子树已经不平衡，需要调整
				if (parent->_bf == -2) //左边高
				{
					if (cur->_bf == -1)//左边的左边高
						Left_Left(parent);
					else if (cur->_bf == 1)
						Left_Right(parent);
				}
				else if (parent->_bf == 2)
				{
					if (cur->_bf == 1) //右边的右边高
						Right_Right(parent);
					else
						Right_Left(parent);
				}

				return true;
			}
			else
			{
				//这里表示出现了不合法的平衡因子
				assert(false);
			}
		}

		return true;
	}

	//中序遍历
	void Show()
	{
		_midShow(root);
		cout << endl;
	}

	//判断是否是平衡二叉树
	bool IsBF()
	{
		return _IsBF(root);
	}
private:
	//右，右，左旋
	void Right_Right(node* parent)
	{
		//保留父亲的父亲节点
		node* pParent = parent->_parent;
		//父亲的右节点
		node* pRight = parent->_right;
		//右节点的左节点
		node* pRLeft = pRight->_left;

		//先把 pRLeft 和 parent 节点连接起来
		parent->_right = pRLeft;
		//更新 pRLeft 的父亲节点为 parent
		if (pRLeft) pRLeft->_parent = parent;

		//开始左旋
		pRight->_left = parent;
		parent->_parent = pRight;

		//pRight 此时作为新的父亲节点，需要判断是否是新的根节点
		//并连接 pRight 和 pParent 
		if (pParent == nullptr)
			root = pRight;
		else
			(pParent->_left == parent) ? pParent->_left = pRight : pParent->_right = pRight;
		
		pRight->_parent = pParent;
		pRight->_bf = parent->_bf = 0;
	}

	//左，左，右旋
	void Left_Left(node* parent)
	{
		// 保留父亲的父亲节点
		node* pParent = parent->_parent;
		//父亲的左节点
		node* pLeft = parent->_left;
		//左节点的右节点
		node* pLRight = pLeft->_right;

		//先把 pLRight 和 parent 节点连接起来
		parent->_left = pLRight;
		//更新 pLRight 的父亲节点为 parent
		if (pLRight) pLRight->_parent = parent;

		//开始右旋
		pLeft->_right = parent;
		parent->_parent = pLeft;

		//pLeft 此时作为新的父亲节点，需要判断是否是新的根节点
		//并连接 pLeft 和 pParent 
		if (pParent == nullptr)
			root = pLeft;
		else
			(parent == pParent->_left) ? pParent->_left = pLeft : pParent->_right = pLeft;

		pLeft->_parent = pParent;
		pLeft->_bf = parent->_bf = 0;
	}

	//左，右，双旋
	void Left_Right(node* parent)
	{
		node* pLeft = parent->_left;
		node* pLRight = pLeft->_right;
		int pLRbf = pLRight->_bf;
		//右，右，单旋
		Right_Right(pLeft);

		//左，左，单旋
		Left_Left(parent);

		if (pLRbf == 1)
		{
			parent->_bf = 0;
			pLeft->_bf = -1;
			pLRight->_bf = 0;
		}
		else if (pLRbf == -1)
		{
			parent->_bf = 1;
			pLeft->_bf = 0;
			pLRight->_bf = 0;
		}
		else if (pLRbf == 0)
		{
			parent->_bf = 0;
			pLeft->_bf = 0;
			pLRight->_bf = 0;
		}
	}

	void Right_Left(node* parent)
	{
		node* pRight = parent->_right;
		node* pRLeft = pRight->_left;
		int pRLbf = pRLeft->_bf;
		//左，左，单旋
		Left_Left(pRight);

		//右，右，单旋
		Right_Right(parent);

		if (pRLbf == 1)
		{
			parent->_bf = -1;
			pRight->_bf = 0;
			pRLeft->_bf = 0;
		}
		else if (pRLbf == -1)
		{
			parent->_bf = 0;
			pRight->_bf = 1;
			pRLeft->_bf = 0;
		}
		else if (pRLbf == 0)
		{
			parent->_bf = 0;
			pRight->_bf = 0;
			pRLeft->_bf = 0;
		}
	}

	//show
	void _midShow(node* root)
	{
		if (root == nullptr) return;

		_midShow(root->_left);
		cout << root->_data.first << ' ';
		_midShow(root->_right);
	}

	//判断是否是平衡
	bool _IsBF(node* root)
	{
		if (root == nullptr) return true;

		int leH = _Height(root->_left);//左子树高度
		int riH = _Height(root->_right);//右子树高度

		if (riH - leH != root->_bf)
		{
			cout << root->_data.first << " 平衡因子异常" << endl;
			return false;
		}
			
		return _IsBF(root->_left) && _IsBF(root->_right);
	}

	//由根节点确定子树高度
	int _Height(node* root)
	{
		if (root == nullptr)
			return 0;
		return 1 + max(_Height(root->_left), _Height(root->_right));
	}
private:
	node* root;
};