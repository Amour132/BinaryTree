#pragma once

#include <stdio.h>
#include <assert.h>
#include <malloc.h>
#include <stdlib.h>


typedef char TDateType;
typedef struct BinaryTreeNode
{
	TDateType date;
	struct BinaryTreeNode *left; //指向左子树的指针
	struct BinaryTreeNode *right; //指向右子树的指针
}BTNode;


BTNode *BinaryTreeCreate(TDateType *a,int n,int *pi); //二叉树的创建
void BinaryTreeDestory(BTNode* root); //二叉树的销毁

int BinaryTreeSize(BTNode* root); //节点数
int BinaryTreeLeafSize(BTNode* root); //叶节点数
int BinaryTreeLevelKSize(BTNode* root, int k); //第K层的结点数

// 遍历  递归
void BinaryTreePrevOrder(BTNode* root); //前序
void BinaryTreeInOrder(BTNode* root); //中序
void BinaryTreePostOrder(BTNode* root); //后序
void BinaryTreeLevelOrder(BTNode* root); //层序

BTNode *BinaryTreeFind(BTNode *root,TDateType x);
//非递归遍历
void BinaryTreePrevOrderNonR(BTNode* root);
void BinaryTreeInOrderNonR(BTNode* root);
void BinaryTreePostOrderNonR(BTNode* root);

int BinaryTreeComplete(BTNode* root); //判断是否是完全二叉树

void TestBinaryTree();