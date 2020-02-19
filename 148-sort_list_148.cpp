#include <iostream>

struct ListNode
{
	int val;
	struct ListNode *next;
};


static void Plist(struct ListNode *list)
{
	while (list != NULL)
	{
		printf("%d ", list->val);
		list = list->next;
	}
	printf("\n");
}

static struct ListNode* creatNode(int n)
{
	struct ListNode* p = (struct ListNode*)malloc(sizeof(struct ListNode));
	p->val = n;
	p->next = NULL;
	return p;
}
static struct ListNode* insertNode(struct ListNode* p, struct ListNode* node)
{
	while (p)
	{
		if (p->next == NULL)
		{
			p->next = node;
			break;
		}
		p = p->next;
	}
	return p;
}


struct ListNode *sortList(struct ListNode *head)
{

	struct ListNode *result = head;

	while (result)
	{
		struct ListNode *tmp = result;
		while (tmp)
		{
			if (result->val > tmp->val)
			{
				int t = result->val;
				result->val = tmp->val;
				tmp->val = t;
			}
			tmp = tmp->next;
		}
		result = result->next;
	}
	return head;
}

void sort_list_148()
{

	struct ListNode *l1 = NULL;

	struct ListNode *l2 = NULL;

	l1 = creatNode(1);
	insertNode(l1, creatNode(-1));
	insertNode(l1, creatNode(9));

	l2 = creatNode(1);
	insertNode(l2, creatNode(3));
	insertNode(l2, creatNode(4));

	Plist(l1);
	Plist(l2);
	struct ListNode *reult = sortList(l1);

	Plist(reult);
}