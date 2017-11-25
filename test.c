#include<stdio.h> 
#include<stdlib.h> 
#include<assert.h>
#define DateType int 

typedef struct Node {
	DateType data;
	struct Node* next;
}Node, *pNode;
void InitList(pNode *head)//��ʼ�� 
{
	assert(head); (*head) = NULL;
}
pNode BuyNode(DateType e)//�����½ڵ�
{
	pNode lk = (pNode)malloc(sizeof(Node));
	if (!lk)
		return NULL;
	lk->data = e;
	return lk;
}
void PushBack(pNode *head, DateType e)//β��
{
	pNode nd, tmp; assert(head);
	nd = BuyNode(e);
	if (!nd)
		return;
	else if (*head == NULL)
	{
		*head = nd; nd->next = NULL;
	}
	else
	{
		tmp = *head;
		while (tmp->next) { tmp = tmp->next; }
		tmp->next = nd; nd->next = NULL;
	}

}
void PopBack(pNode *head)//βɾ 
{
	pNode tmp;
	pNode q = NULL;
	assert(head);
	if (*head == NULL) return;
	tmp = *head;
	while (tmp->next)
	{
		q = tmp; tmp = tmp->next;
	}
	if (q != NULL)//����ڵ� 
	{
		q->next = NULL;
		free(tmp);
	}
	else//һ���ڵ� 
	{
		free(tmp);
		*head = NULL;
	}
}
void PrintList(pNode head)//��ӡ���� 
{
	pNode tmp = head;
	while (tmp)
	{
		printf("%d-->", tmp->data);
		tmp = tmp->next;
	} printf("NULL\n");
}
void PushFront(pNode *head, DateType e)//ͷ��
{
	pNode nd = BuyNode(e);
	assert(head);
	if (nd)
	{
		nd->next = *head;
		*head = nd;
	}
}
void PopFront(pNode *head)//ͷɾ
{
	pNode tmp;
	assert(head);
	if (!*head) return;
	tmp = *head;
	*head = (*head)->next;
	free(tmp);
}
pNode Find(pNode head, DateType e)//�ҵ�ָ��Ԫ�ص�λ�ò�����,û�ҵ�����NULL
{
	pNode tmp; assert(head);
	tmp = head;
	while (tmp->data != e)
	{
		tmp = tmp->next;
		if (tmp == NULL) return NULL;
	}
	return tmp;
}
void Inster(pNode *head, pNode pos, DateType e)//ָ��λ�ò���
{
	pNode nd;
	assert(head);
	if (pos && *head)
	{
		nd = BuyNode(e);
		nd->next = pos->next;
		pos->next = nd;
	}
}
void Erase(pNode *head, pNode pos)//ָ��λ��ɾ�� 
{
	pNode tmp; pNode q = NULL;//q�Ǽ�¼tmp��ǰһ��λ�� 
	assert(head); if (*head && pos)
	{
		tmp = *head;
		while (tmp != pos)
		{
			q = tmp;
			tmp = tmp->next;
		}
		if (q != NULL)
		{
			q->next = tmp->next;
			free(tmp);
		}
		else
		{
			free(tmp);
			*head = NULL;
		}

	}
}
int LenList(pNode head)//������
{
	int count = 0;
	pNode tmp = head;
	while (tmp)
	{
		tmp = tmp->next;
		++count;
	}
	return count;
}
void Destroy(pNode *head)//��������
{
	pNode tmp = *head;
	pNode del = NULL;
	while (tmp)
	{
		del = tmp;
		tmp = tmp->next;
		free(del);
		del = NULL;
	}
	*head = NULL;
}
void deleteNotTailNode(pNode pos)//ɾ��һ����ͷ������ķ�β�ڵ�
{
	pNode posNext = NULL;
	assert(pos);
	if (pos == NULL || pos->next == NULL)
		return;
	posNext = pos->next;
	pos->data = posNext->data;
	pos->next = posNext->next;
	free(posNext);
	posNext = NULL;
}
void insetNothead(pNode pos, DateType d)//����ͷ�������һ���ڵ㣨ͷ��㴦Ҳ���ԣ����鷳�ˣ�ǰ����һ���ڵ㣨�����ñ�����
{
	pNode pnewNode = (pNode)malloc(sizeof(Node));
	assert(pos);
	if (pos == NULL)
		return;
	pnewNode->next = pos->next;
	pnewNode->data = pos->data;
	pos->next = pnewNode;
	pos->data = d;
}
pNode yosephcircle(pNode phead, size_t num)//ʵ��Լɪ���㷨
{
	int count = 0;
	pNode pcurNext = NULL;
	pNode pcur = NULL;
	assert(phead);
	if (phead == NULL || phead->next == NULL)//���ֻ��һ����0��Ԫ�أ����ÿ�ʼ
		return NULL;
	pcur = phead;
	while (pcur->next)//����
	{
		pcur = pcur->next;
	}
	pcur->next = phead;
	pcur = phead;
	while (pcur->next != pcur)
	{
		count=num-1;
		while (--count)
		{
			pcur = pcur->next;
		}
		pcurNext = pcur->next;
		pcur->next = pcurNext->next;
		free(pcurNext);
		pcurNext = NULL;
		pcur = pcur->next;
	}
	pcur->next = NULL;//�⻷
	return pcur;
}
void printlistlast(pNode head)//�Ӻ���ǰ��ӡ����
{
	if (head)
	{
		printlistlast(head->next);
		printf("%d-->",head->data);
	}
}
void Destroylistlast(pNode* phead)//�Ӻ���ǰɾ���ڵ�
{
	assert(phead);
	if (*phead)
	{
		Destroylistlast((*phead)->next);
		free(*phead);
		*phead = NULL;
	}
}
pNode findminNode(pNode phead)//����һ�Σ��ҵ��м�ڵ�
{
	pNode pslow = phead;
	pNode pfast = phead;
	while (pfast&&pfast->next)
	{
		pslow = pslow->next;
		pfast = pfast->next->next;
	}
	return pslow;
}

void reverselist(pNode *phead)//���������
{
	pNode pcur = NULL;
	pNode pcurNext = NULL;
	pNode pPre = NULL;
	assert(phead);
	if (phead == NULL || (*phead)->next == NULL)
		return ;
	pPre=pcur = *phead;
	pcurNext = pcur->next;
	while (pcurNext)
	{
		pcur->next = pcurNext->next;
		pPre = pcurNext;
		pcurNext = pcurNext->next;
		pPre->next = (*phead);
		(*phead) = pPre;
	}
}

/***********���Դ���1*****************/
void test1()
{
	pNode list;
	pNode pos;
	InitList(&list);
	PushBack(&list, 1);
	//1->NULL 
	PushBack(&list,2);
	//1->2->NULL 
	PushBack(&list,3);
	//1->2->3->NULL 
	PushFront(&list,0);
	//0->1->2->3->NULL 
	PopFront(&list);
	//1->2->3->NULL 
	PrintList(list); 
	//PopBack(&list); 
	//PopBack(&list);
	//1->2->NULL 
	//PopBack(&list);
	//1->NULL 
	//PopBack(&list);
	//NULL 
	//PushFront(&list,0);
	//0->NULL 
	//PopFront(&list);
	//NULL 
	//PrintList(list); 
	pos = Find(list, 2);
	Inster(&list, pos, 233);
	//1->2->233->3->NULL 
	PrintList(list);
	pos = Find(list, 233);
	Erase(&list, pos);
	//1->2->3->NULL 
	PrintList(list); 
	PopBack(&list);
	PopBack(&list);
	//1->NULL 
	pos = Find(list,1); 
	Erase(&list, pos);
	//NULL 
	PrintList(list); 
	Destroy(&list);
}
/***********���Դ���2*****************/
void test2()
{
	pNode list;
	pNode pos;
	pNode q;
	InitList(&list);
	PushBack(&list, 1);
	//1->NULL 
	PushBack(&list, 2);
	//1->2->NULL 
	PushBack(&list, 3);
	//1->2->3->NULL 
	PrintList(list);
	pos = Find(list, 2);
	deleteNotTailNode(pos);
	//1->3->NULL
	PrintList(list);

	insetNothead(pos,2);
	//1->2->3->NULL 
	PrintList(list);

	PushBack(&list, 4);
	PushBack(&list, 5);
	PushBack(&list, 6);
	PushBack(&list, 7);
	PrintList(list);
	//1->2->3->4->5->6->7->NULL 
	q = yosephcircle(list,3);
	//��Ȧʱ��3--6--2--7--5--1--4
	printf("%d\n",q->data);
	//q = yosephcircle(list, 4);
	//��Ȧʱ��4--1--6--5--7--3--2
	//printf("%d\n", q->data);

	Destroy(&list);
	PrintList(list);
}
/***********���Դ���3*****************/
void test3()
{
	pNode list;
	//pNode pos;
	pNode q;
	InitList(&list);
	PushBack(&list, 1);
	//1->NULL 
	PushBack(&list, 2);
	//1->2->NULL 
	PushBack(&list, 3);
	//1->2->3->NULL 
	printlistlast(list);
	//3-->2-->1
	printf("\n");

	//����һ�Σ��ҵ��м�ڵ㣨test��
	PushBack(&list, 4);
	PushBack(&list, 5);
	PushBack(&list, 6);
	PushBack(&list, 7);
	PrintList(list);
	//1->2->3->4->5->6->7->NULL 
	q=findminNode(list);
	printf("%d\n",q->data);
	//4
	PushBack(&list, 8);
	PrintList(list);
	//1->2->3->4->5->6->7->8->NULL 
	q = findminNode(list);
	printf("%d\n", q->data);
	//5
	reverselist(&list);
	PrintList(list);
	//8->7->6->5->4->3->2->1->NULL 

	Destroylistlast(&list);
	PrintList(list);

}
int main()
{
	//test1();
	//test2();
	test3();
	system("pause");
	return 0;
}