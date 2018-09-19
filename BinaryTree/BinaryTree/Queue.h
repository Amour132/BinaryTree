#pragma once 

#include <stdio.h>
#include <assert.h>
#include <malloc.h>

typedef struct BinaryTreeNode* QDateType;

typedef struct QueueNode
{
	QDateType date;
	struct QueueNode *next;
}QueueNode;

typedef struct Queue
{
	QueueNode *head; //队头
	QueueNode *tail; //队尾
}Queue;

void QueueInit(Queue *pq); //队列的初始化
void QueueDestory(Queue *pq); //队列的销毁
void QueuePush(Queue *pq, QDateType x); //队尾入数据
void QueuePop(Queue *pq); //队头出数据
QDateType QueueFront(Queue *pq); //队头数据
QDateType QueueBack(Queue *pq); //队尾数据
size_t QueueSize(Queue *pq); //队列大小
int QueueEmpty(Queue *pq); //队列是否为空
QueueNode *BuyQueueNode(QDateType x); //创建一个新的节点

void TestQueue();