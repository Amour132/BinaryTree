#include "Queue.h"

void QueueInit(Queue *pq)
{
	assert(pq);
	pq->head  = NULL;
	pq->tail = NULL;
}

void QueueDestory(Queue *pq)
{
	QueueNode *cur = pq->head;
	assert(pq);
	while(cur)
	{
		pq->head = cur->next;
		free(cur);
		cur = pq->head;
	}
	pq->tail = NULL;
}

QueueNode *BuyQueueNode(QDateType x)
{
	QueueNode *newNode = (QueueNode *)malloc(sizeof(QueueNode));
	if(newNode == NULL)
	{
		perror("fail for the malloc");
	}
	newNode->date = x;
	newNode->next = NULL;
	return newNode;
}

void QueuePush(Queue *pq, QDateType x)
{
	assert(pq);
	if(pq->tail == NULL && pq->head == NULL)
	{
	
		pq->head = pq->tail = BuyQueueNode(x);
		/*printf("%d" ,pq->tail->date);*/
	}
	else
	{
	
		pq->tail->next = BuyQueueNode(x);
		pq->tail = pq->tail->next;
		/*printf("%d" ,pq->tail->date);*/
	}
}

void QueuePop(Queue *pq)
{
	QueueNode *cur = pq->head->next;
	assert(pq);
	assert(pq->head);
	if(pq->head == pq->tail)
	{
		/*printf("%d ",pq->head->date);*/
		free(pq->head);
		pq->head = NULL;
		pq->tail = NULL;
	}
	else
	{
		/*printf("%d ",pq->head->date);*/
		free(pq->head);
		pq->head = cur;
	}
}

QDateType QueueFront(Queue *pq)
{
	assert(pq);
	return pq->head->date;
}

QDateType QueueBack(Queue *pq)
{
	assert(pq);
	return pq->tail->date;
}

size_t QueueSize(Queue *pq)
{
	QueueNode *cur = pq->head;
	int count = 0;
	assert(pq);
	while(cur)
	{
		count++;
		cur = cur->next;
	}
	return count;
}

int QueueEmpty(Queue *pq)
{
	assert(pq);
	return pq->head == NULL ? 0 : 1;
}

//void TestQueue()
//{
//	Queue q;
//	QueueInit(&q);
//	QueuePush(&q,1);
//	QueuePush(&q,2);
//	QueuePush(&q,3);
//	QueuePush(&q,4);
//	QueuePop(&q);
//	QueuePop(&q);
//	QueuePop(&q);
//	QueuePop(&q);
//	QueueDestory(&q);
//}