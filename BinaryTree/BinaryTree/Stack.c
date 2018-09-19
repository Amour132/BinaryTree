#include "Stack.h"

void StackInit(Stack *ps)
{
	assert(ps);
	ps->a = (DateType*)malloc(sizeof(DateType)*3);
	if(ps->a == NULL)
	{
		perror("fail for malloc\n");	
	}
	ps->top = 0;
	ps->capacity = 3;
}

void StackDstory(Stack *ps)
{
	assert(ps);
	free(ps->a);
	ps->a = NULL;
	ps->top = 0;
	ps->capacity = 0;
}

void StackPush(Stack *ps, DateType x)
{
	assert(ps);
	if(ps->top == ps->capacity)
	{
		ps->a = (DateType*)realloc(ps->a,sizeof(DateType)*2*ps->capacity);
	}
	ps->a[ps->top] = x;
	ps->top ++;
}

void StackPop(Stack *ps)
{
	assert(ps);
	assert(ps->top != 0);
	ps->top--;
}

int StackEmpty(Stack *ps)
{
	assert(ps);
	return ps->top == 0 ? 0 : 1;
}

DateType StackTop(Stack *ps)
{
	assert(ps);
	return ps->a[ps->top-1];
}

int StackSize(Stack *ps)
{
	assert(ps);
	return ps->top;
}

//void TestStack()
//{
//	int i = 0;
//	Stack s;
//	StackInit(&s);
//	
//	StackPush(&s,1);
//	StackPush(&s,2);
//	StackPush(&s,3);
//	StackPush(&s,4);
//	StackPop(&s);
//	StackPop(&s);
//	StackPush(&s,7);
//	StackPush(&s,8);
//	for(i=0; i<4; i++)
//	{
//		printf("%d ",StackTop(&s));
//		StackPop(&s);
//	}
//	StackDstory(&s);
//}