#pragma once
#include<stdlib.h>
#include<assert.h>

typedef int DataType;

typedef struct DListNode
{
	DataType data;
	struct DListNode *next;
	struct DListNode *prev;
}DListNode;

DListNode *BuyListNode(DataType data);
void DListinit(DListNode **pHead);
void DListPushBack(DListNode *pHead, DataType data);
void DListPopBack(DListNode *pHead);
void DListPushFront(DListNode *pHead, DataType data);
void DListPopFront(DListNode *pHead);
void DListInsert(DListNode *pos, DataType data);
void DListErase(DListNode *pos);
DListNode *DListFind(DListNode *pHead, DataType data);
void DListDestroy(DListNode *pHead);


