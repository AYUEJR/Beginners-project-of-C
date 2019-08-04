#include"CircularList.h"


void DListinit(DListNode **phead)
{
	assert(phead);
	(*phead) = BuyListNode(0);
	(*phead)->next = (*phead);
	(*phead)->prev = (*phead);
}

DListNode* BuyListNode(DataType data)
{
	DListNode* ret = (DListNode*)malloc(sizeof(DListNode));
	if (NULL == ret)
	{
		assert(0);
	}
	else
	{
		ret->data = data;
		ret->next = NULL;
		ret->prev = NULL;
	}
	return ret;
}

//尾插
void DListPushBack(DListNode* phead, DataType data)
{
	DListNode*cur = NULL;
	if (phead->next == phead)
	{
		cur = BuyListNode(data);
		phead->next = cur;
		cur->prev = phead;
		cur->next = phead;
		phead->prev = cur;
	}
	else
	{
		cur = BuyListNode(data);
		phead->prev->next = cur;
		cur->prev = phead->prev;
		phead->prev = cur;
		cur->next = phead;
	}
}
//尾删
void DListPopBack(DListNode* phead)
{
	DListNode* cur = NULL;
	//如果链表内只有头结点，不用删除直接返回
	if (phead == phead->next)
		return;
	else
	{
		cur = phead->prev;//记录要删除的节点
		phead->prev = cur->prev;
		cur->prev->next = phead;
		free(cur);
		cur = NULL;
	}
}
//头插
void DListPushFront(DListNode* phead, DataType data)
{
	DListNode* cur = BuyListNode(data);
	//当链表只有头结点时
	if (phead->next == phead)
	{
		phead->next = cur;
		cur->next = phead;
		cur->prev = phead;
		phead->prev = cur;
	}
	else
	{
		cur->next = phead->next;
		phead->next->prev = cur;
		cur->prev = phead;
		phead->next = cur;
	}
}
//头删
void DListPopFront(DListNode *phead)
{
	DListNode* cur = phead->next;
	if (phead->next == phead)
	{
		return;
	}
	else
	{
		phead->next = cur->next;

	}
}
//在指定位置插入一个节点
void DListInsert(DListNode* pos, DataType data)
{
	DListNode* cur = BuyListNode(data);
	if (NULL == pos)
		return;
	//指定位置插入
	else
	{
		cur->next = pos->next;
		cur->prev = pos;
		pos->next = cur;
		pos->next->prev = cur;
	}
}
//在指定位置删除一个节点
void DListErase(DListNode* pos)
{
	if (pos = NULL)//指定点为空
		return;
	else
	{
		pos->prev->next = pos->next;
		pos->next->prev = pos->prev;
		free(pos);
		pos = NULL;
	}
}
//查找data的数据节点
DListNode* DListFind(DListNode* phead, DataType data)
{
	DListNode* cur = phead->next;//记录头结点位置
	while (cur != phead)
	{
		if (cur->data == data)
			return cur;
		else
			cur = cur->next;
	}
	return NULL;
}
//销毁双向链表
void DListDestroy(DListNode* phead)
{
	DListNode* cur = phead->next;
	while (cur != phead)
	{
		DListNode* ret = cur;
		cur = cur->next;
		free(ret);
		ret = NULL;
	}
	free(phead);
	phead = NULL;
}




//检测函数


void Text()
{
	DListNode *phead = NULL;
	DListinit(&phead);
	DListPushBack(phead, 1);
	DListPushBack(phead, 2);
	DListPushBack(phead, 3);
	DListPushFront(phead, 4);
	DListPushFront(phead, 5);
	DListPopFront(phead);
	DListInsert(DListFind(phead, 3), 6);
	DListErase(DListFind(phead, 4));
	DListDestroy(phead);
}


//主函数
int main()
{
	Text();
	return 0;
}

