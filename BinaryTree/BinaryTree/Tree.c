#include "Tree.h"
#include "Queue.h"
#include "Stack.h"

BTNode *BuyBTNode(TDateType x)//����һ���ڵ�
{
	BTNode *node = (BTNode *)malloc(sizeof(BTNode));
	node->left = NULL;
	node->right = NULL;
	node->date = x;
	return node;
}

BTNode *BinaryTreeCreate(TDateType *a,int n,int *pi)
{
	if(a[*pi] != '#')
	{
		BTNode *root = BuyBTNode(a[*pi]);//��Ϊ�վʹ����ڵ�
		(*pi)++; //�������Ĵ���
		root->left = BinaryTreeCreate(a,n,pi);

		(*pi)++;//�������Ĵ���
		root->right
			= BinaryTreeCreate(a,n,pi);

		return root;
	}
	else
	{
		return NULL;
	}
}

void BinaryTreeInOrder(BTNode* root)
{
	if(root == NULL)
	{
		return ;
	}
	BinaryTreeInOrder(root->left);
	printf("%c ",root->date);
	BinaryTreeInOrder(root->right);
}

void BinaryTreePostOrder(BTNode* root)
{
	if(root == NULL)
	{
		return ;
	}
	BinaryTreePostOrder(root->left);
	BinaryTreePostOrder(root->right);
	printf("%c ",root->date);
}

void BinaryTreeDestory(BTNode* root)
{
	if(root != NULL)
	{
		if(root->left)
		{
			BinaryTreeDestory(root->left);
			root->left = NULL;
		}
		if(root->right)
		{
			BinaryTreeDestory(root->right);
			root->right = NULL;
		}
		if(root != NULL)
		{
			free(root);
			root = NULL;
		}
	}	
}

void BinaryTreePrevOrder(BTNode* root)
{
	if(root == NULL)
	{
		return ;
	}
	printf("%c ",root->date);
	BinaryTreePrevOrder(root->left);
	BinaryTreePrevOrder(root->right);
}

int BinaryTreeLeafSize(BTNode* root)
{
	if(root == NULL)
	{
		return 0;
	}
	if(root->left == NULL && root->right == NULL)
	{
		return 1;
	}
	return BinaryTreeLeafSize(root->left) + BinaryTreeLeafSize(root->right);
}

int BinaryTreeSize(BTNode* root)
{
	if(root == NULL)
	{
		return 0;
	}
	return BinaryTreeSize(root->left) + BinaryTreeSize(root->right) + 1;
}

int BinaryTreeLevelKSize(BTNode* root, int k)
{
	if(k == 0)
	{
		return 0;
	}
	if(k == 1)
	{
		return 1;
	}
	return BinaryTreeLevelKSize(root->left,k-1) + BinaryTreeLevelKSize(root->right,k-1);
}

BTNode *BinaryTreeFind(BTNode *root,TDateType x)
{
	BTNode *ret;
	if(root == NULL || root->date == x)
	{
		return root;
	}
	ret = BinaryTreeFind(root->left,x);
	if(ret)
	{
		return ret;
	}
	return BinaryTreeFind(root->right,x);
}

void BinaryTreeLevelOrder(BTNode* root)
{
	Queue q;
	BTNode *ret;
	QueueInit(&q);
	if(root != NULL)
	{
		QueuePush(&q,root);
	}
		while(QueueEmpty(&q) != 0)
		{
			ret = QueueFront(&q);
			printf("%c ",ret->date);
			QueuePop(&q);
			if(ret->left != NULL)
			{
				QueuePush(&q,ret->left);
			}
			if(ret->right != NULL)
			{
				QueuePush(&q,ret->right);
			}
		}
}

void BinaryTreePrevOrderNonR(BTNode* root) //�ǵݹ��ǰ�����
{
	BTNode *cur = root;
	BTNode *top;
	Stack s;
	StackInit(&s);
	while(cur || StackEmpty(&s))  //����Ϊ�ջ��� ջ��Ϊ��
	{
		while(cur)//������������
		{
			StackPush(&s,cur);
			printf("%c ",cur->date);
			cur = cur->left;
		}
		top = StackTop(&s);
		StackPop(&s);
		cur = top->right;
	}
	printf("\n");
}

void BinaryTreeInOrderNonR(BTNode* root)
{
	BTNode *cur = root;
	BTNode *top;
	Stack s;
	StackInit(&s);
	while(cur || StackEmpty(&s))  //����Ϊ�ջ��� ջ��Ϊ��
	{
		while(cur)//������������
		{
			StackPush(&s,cur);
			cur = cur->left;
		}
		top = StackTop(&s);
		printf("%c ",top->date);
		StackPop(&s);
		cur = top->right;
	}
	printf("\n");
}

void BinaryTreePostOrderNonR(BTNode* root)
{
	BTNode *cur = root;
	BTNode *top;
	BTNode *prev = NULL;
	Stack s;
	StackInit(&s);
	while(cur || StackEmpty(&s))  //����Ϊ�ջ��� ջ��Ϊ��
	{
		while(cur)//������������
		{
			StackPush(&s,cur);
			cur = cur->left;
		}
		top = StackTop(&s);
	
		if(top->right == NULL || top->right == prev)
		{
			printf("%c ",top->date);
			prev = top;
			StackPop(&s);
		}
		else
		{
			cur = top->right;
		}
	}
	printf("\n");
}

int BinaryTreeComplete(BTNode* root) //���ò�������ķ������ 
{                                      //����֮��ʼ��һ�����ֿ�  ��������ȫΪ�ղ�����ȫ������������
	Queue q;
	BTNode *cur;                         //��Ϊ��ȫ��������������
	QueueInit(&q);
	if(root)
	{
		QueuePush(&q,root);
	}
	cur = QueueFront(&q);
	while(cur) //���в�Ϊ��
	{
		QueuePush(&q,cur->left);
		QueuePush(&q,cur->right);
		QueuePop(&q);
		cur = QueueFront(&q);
	}
	while(QueueEmpty(&q) != 0)
	{
		if(QueueFront(&q))
		{
			QueueDestory(&q);
			return -1;
		}
		else
		{
			QueuePop(&q);
		}
	}
	return 0;
}


void TestBinaryTree()
{
	char arr[] = {'A', 'B', 'D', '#', '#','#', 'C',
		'E', '#', '#', 'F', '#', '#'};
	int i = 0;
	BTNode *ret;
	BTNode *tree = BinaryTreeCreate(arr,sizeof(arr)/sizeof(TDateType),&i);
	BinaryTreePrevOrder(tree);
	printf("\n");
	BinaryTreePrevOrderNonR(tree);
	BinaryTreeInOrder(tree);
	printf("\n");
	BinaryTreeInOrderNonR(tree);
	BinaryTreePostOrder(tree);
	printf("\n");
    BinaryTreePostOrderNonR(tree);
	printf("%d   ",BinaryTreeLeafSize(tree));
	printf("\n");
	printf("%d   ",BinaryTreeSize(tree));
	printf("\n");
	printf("%d ",BinaryTreeLevelKSize(tree,2));
	printf("\n");
	ret = BinaryTreeFind(tree,'D');
	printf("%c ",ret->date);
	printf("\n");
	BinaryTreeLevelOrder(tree);
	printf("%d ",BinaryTreeComplete(tree));
	BinaryTreeDestory(tree);


}
