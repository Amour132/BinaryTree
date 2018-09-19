#pragma once

#include <stdio.h>
#include <malloc.h>
#include <assert.h>

typedef struct BinaryTreeNode* DateType;
typedef struct Stack
{
	DateType *a;
	int top; //栈顶
	int capacity; //容量
}Stack;

void StackInit(Stack *ps); //初始化栈
void StackDstory(Stack *ps); //销毁栈
void StackPush(Stack *ps, DateType x); //入栈
void StackPop(Stack *ps); //出栈
int StackEmpty(Stack *ps); //判断栈为空
DateType StackTop(Stack *ps); //栈顶数据
int StackSize(Stack *ps); //栈大小
void TestStack();