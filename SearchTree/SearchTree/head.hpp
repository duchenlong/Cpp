#pragma once

#include <iostream>
#include <cstdlib>
using namespace std;

//存储树中节点的结构体
template<class T>
struct TreeNode
{
	T _key;
	TreeNode<T>* _left;
	TreeNode<T>* _right;

	TreeNode(const T key = 0)
		:_key(key), _left(nullptr), _right(nullptr)
	{}
};

template<class T>
class STree
{
public:
	typedef TreeNode<T> TreeNode;
public:
	STree()
		:root(nullptr)
	{}
	//迭代插入
	bool Insert(const T key)
	{
		TreeNode* cur = root;
		TreeNode* parent = nullptr;

		//找到需要插入的位置，如果这个位置是真，说明还不是待插入的地方
		while (cur)
		{
			//先排除等于的情况
			if (cur->_key == key) return true;
			parent = cur;

			//如果当前节点的值 比 key 大，说明该数据要插在自己的 左子树
			//如果当前节点的值 比 key 小，说明该数据要插在自己的 右子树
			cur = cur->_key > key ? cur->_left : cur->_right;
		}

		cur = new TreeNode(key);
		//注意当前cur节点为nullptr，他是没有地址的，我们需要把新申请的节点和他的父亲节点手动连接
		parent == nullptr ? root = cur : (parent->_key > key ? parent->_left = cur : parent->_right = cur);
		return true;
	}

	//递归插入
	bool InsertR(const T key)
	{
		return _InsertR(root, key);
	}
	
	//迭代查找
	TreeNode* Find(const T key)
	{
		TreeNode* cur = root;

		while (cur)
		{
			if (cur->_key == key) return cur;

			cur = cur->_key > key ? cur->_left : cur->_right;
		}
		//这里的时候，cur为nullptr ，说明没有找到，返回nullptr
		return nullptr;
	}

	//递归查找
	TreeNode* FindR(const T key)
	{
		return _FindR(root, key);
	}

	//递归删除节点
	bool EarseR(const int key)
	{
		return _EarseR(root,key);
	}

	//迭代删除
	bool Earse(const T key)
	{
		//先查找该节点，同时保留父亲节点的位置
		TreeNode* parent = nullptr;
		TreeNode* cur = root;

		while (cur)
		{
			if (cur->_key == key) break;

			parent = cur;
			cur = cur->_key > key ? cur->_left : cur->_right;
		}

		//如果没有这个节点，就不需要删除
		if (!cur) return false;

		TreeNode* del = cur;

		//此时需要删除cur节点,注意要删除的位置是根节点的情况
		if (!cur->_left)
		{
			if (!parent)
				root = cur->_right;
			else if (cur == parent->_left) //要删除的节点是左子树
				parent->_left = cur->_right;
			else if (cur == parent->_right)	//要删除的节点是右子树
				parent->_right = cur->_right;
		}
		else if (!cur->_right)
		{
			if (!parent)
				root = cur->_left;
			else if (cur == parent->_left)//要删除的节点是左子树
				parent->_left = cur->_left;
			else if (cur == parent->_right)//要删除的节点是右子树
				parent->_right = cur->_left;
		}
		else
		{
			TreeNode* minParent = cur;
			TreeNode* minLeft = cur->_right;
			
			//找到最后一个左孩子
			while (minLeft->_left)
			{
				minParent = minLeft;
				minLeft = minLeft->_left;
			}

			//此时需要把minLeft放到cur节点的位置，然后删除minLeft节点
			cur->_key = minLeft->_key;

			//删除minLeft节点，但是防止minLeft的右孩子存在
			if (minParent->_right == minLeft) //说明第一个右孩子没有左孩子
				minParent->_right = minLeft->_right;
			else	//删除这个左孩子，他的位置就让 左孩子的右孩子顶替
				minParent->_left = minLeft->_right;

			del = minLeft;//此时的minLeft变成了要删除的节点
		}

		delete del;
		return true;
	}
	

	//打印二叉搜索树的所有节点，排序后的
	void Show()
	{
		//中序遍历接口
		_Inorder(root);
		cout << endl;
	}

	int RootKey()
	{
		return root->_key;
	}

private:
	//中序遍历接口
	void _Inorder(TreeNode* root)
	{
		if (!root) return;

		_Inorder(root->_left);
		cout << root->_key << ' ';
		_Inorder(root->_right);
	}

	//查找调用的接口
	TreeNode* _FindR(TreeNode*& root, const T key)
	{
		//根节点为空，或者根节点为Key，就直接返回root了
		if (!root || root->_key == key) return root;

		//没找到，就到子树的逻辑中找
		TreeNode* ret = root->_key > key ? _FindR(root->_left, key) : _FindR(root->_right, key);

		return ret;
	}

	//递归插入接口
	bool _InsertR(TreeNode*& root, const T key)
	{
		//根节点为 nullptr ，所以说待插入的位置就是根节点的位置
		if (!root)
		{
			root = new TreeNode(key);
			return true;
		}
		//如果根节点的值和key相同，就不需要插入
		if (root->_key == key) return true;

		//当前位置不是插入位置，判断需要递归插入左右子树哪里
		bool ret = root->_key > key ? _InsertR(root->_left, key) : _InsertR(root->_right, key);
		return ret;
	}

	//递归删除接口
	bool _EarseR(TreeNode*& root,const T key)
	{
		//根节点为空，说明没有key的节点
		if (!root) return false;

		if (root->_key != key)
			return root->_key > key ? _EarseR(root->_left, key) : _EarseR(root->_right, key);

		//这里就是root->_key == key 的逻辑
		//此时就需要删除 root 节点
		TreeNode* del = root;

		if (!root->_right)	//需要删除的位置的右节点为空，根节点 = 他的左孩子
			root = root->_left;
		else if (!root->_left)	//需要删除位置的左节点为空，根节点 = 他的右孩子
			root = root->_right;
		else  //需要删除节点左右孩子均不为空
		{
			TreeNode* cur = root->_right;
			//找到最后一个左孩子
			while (cur->_left)
			{
				cur = cur->_left;
			}

			//此时需要把cur放到根节点的位置，然后删除cur节点
			root->_key = cur->_key;

			//这里可以变成在这个右子树中，删除cur节点
			return _EarseR(root->_right, cur->_key);

			/*
			//这样会让整个树变高的可能
			//将该位置的左孩子，插入到第一个右孩子的最后一个左孩子的位置
			TreeNode* left = root->_left;
			TreeNode* right = root->_right;

			//找到第一个右孩子的左孩子中，找到最后的空节点
			TreeNode* cur = right;
			while (cur)
				cur = cur->_left;

			//连接左孩子
			cur = left;
			root = right;
			*/
		}

		delete del;
		return true;
	}
private:
	TreeNode* root;
};