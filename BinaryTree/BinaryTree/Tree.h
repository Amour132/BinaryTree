#pragma once

#include <stdio.h>
#include <assert.h>
#include <malloc.h>
#include <stdlib.h>


typedef char TDateType;
typedef struct BinaryTreeNode
{
	TDateType date;
	struct BinaryTreeNode *left; //ָ����������ָ��
	struct BinaryTreeNode *right; //ָ����������ָ��
}BTNode;


BTNode *BinaryTreeCreate(TDateType *a,int n,int *pi); //�������Ĵ���
void BinaryTreeDestory(BTNode* root); //������������

int BinaryTreeSize(BTNode* root); //�ڵ���
int BinaryTreeLeafSize(BTNode* root); //Ҷ�ڵ���
int BinaryTreeLevelKSize(BTNode* root, int k); //��K��Ľ����

// ����  �ݹ�
void BinaryTreePrevOrder(BTNode* root); //ǰ��
void BinaryTreeInOrder(BTNode* root); //����
void BinaryTreePostOrder(BTNode* root); //����
void BinaryTreeLevelOrder(BTNode* root); //����

BTNode *BinaryTreeFind(BTNode *root,TDateType x);
//�ǵݹ����
void BinaryTreePrevOrderNonR(BTNode* root);
void BinaryTreeInOrderNonR(BTNode* root);
void BinaryTreePostOrderNonR(BTNode* root);

int BinaryTreeComplete(BTNode* root); //�ж��Ƿ�����ȫ������

void TestBinaryTree();