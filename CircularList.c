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

//β��
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
//βɾ
void DListPopBack(DListNode* phead)
{
	DListNode* cur = NULL;
	//���������ֻ��ͷ��㣬����ɾ��ֱ�ӷ���
	if (phead == phead->next)
		return;
	else
	{
		cur = phead->prev;//��¼Ҫɾ���Ľڵ�
		phead->prev = cur->prev;
		cur->prev->next = phead;
		free(cur);
		cur = NULL;
	}
}
//ͷ��
void DListPushFront(DListNode* phead, DataType data)
{
	DListNode* cur = BuyListNode(data);
	//������ֻ��ͷ���ʱ
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
//ͷɾ
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
//��ָ��λ�ò���һ���ڵ�
void DListInsert(DListNode* pos, DataType data)
{
	DListNode* cur = BuyListNode(data);
	if (NULL == pos)
		return;
	//ָ��λ�ò���
	else
	{
		cur->next = pos->next;
		cur->prev = pos;
		pos->next = cur;
		pos->next->prev = cur;
	}
}
//��ָ��λ��ɾ��һ���ڵ�
void DListErase(DListNode* pos)
{
	if (pos = NULL)//ָ����Ϊ��
		return;
	else
	{
		pos->prev->next = pos->next;
		pos->next->prev = pos->prev;
		free(pos);
		pos = NULL;
	}
}
//����data�����ݽڵ�
DListNode* DListFind(DListNode* phead, DataType data)
{
	DListNode* cur = phead->next;//��¼ͷ���λ��
	while (cur != phead)
	{
		if (cur->data == data)
			return cur;
		else
			cur = cur->next;
	}
	return NULL;
}
//����˫������
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




//��⺯��


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


//������
int main()
{
	Text();
	return 0;
}

