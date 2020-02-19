#include <iostream>

//Definition for singly-linked list.
struct ListNode
{
    int val;
    struct ListNode *next;
};

struct ListNode *creatNode(int n)
{
    struct ListNode *p = (struct ListNode *)malloc(sizeof(struct ListNode));
    p->val = n;
    p->next = NULL;
    return p;
}
struct ListNode *insertNode(struct ListNode *p, struct ListNode *node)
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

void Plist(struct ListNode *list)
{
    while (list != NULL)
    {
        printf("%d ", list->val);
        list = list->next;
    }
    printf("\n");
}

struct ListNode *mergeTwoLists(struct ListNode *l1, struct ListNode *l2)
{

    struct ListNode *base = NULL;
    struct ListNode *ext = NULL;

    if (l1 == 0 && l2 == 0)
    {
        return NULL;
    }

    if (l1 == NULL && l2 != NULL)
    {
        base = l2;
        ext = l1;
    }
    else if (l2 == NULL && l1 != NULL)
    {
        base = l1;
        ext = l2;
    }
    else
    {
        base = l1;
        ext = l2;
    }
    struct ListNode *result = base;

    while (result)
    {
        if (result->next == NULL)
        {
            result->next = ext;
            break;
        }
        result = result->next;
    }

    result = base;
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
    return base;
}

/* 递归的做法 */
struct ListNode *mergeTwoLists1(struct ListNode *l1, struct ListNode *l2)
{
    if (l1 == NULL)
    {
        return l2;
    }
    if (l2 == NULL)
    {
        return l1;
    }
    if (l1->val < l2->val)
    {
        l1->next = mergeTwoLists1(l1->next, l2);
        return l1;
    }
    else
    {
        l2->next = mergeTwoLists1(l1, l2->next);
        return l2;
    }
}

/*  递推 */
struct ListNode *mergeTwoLists2(struct ListNode *l1, struct ListNode *l2)
{

    struct ListNode tmpNode;
    struct ListNode *per = &tmpNode;
    while (l1 != NULL && l2 != NULL)
    {
        if (l1->val < l2->val)
        {
            per->next = l1;
            l1 = l1->next;
        }
        else
        {
            per->next = l2;
            l2 = l2->next;
        }
        per = per->next;
    }
    per->next = (l1 == NULL ? l2 : l1);

    return &tmpNode;
}

void merge_two_sorted_lists_21()
{
    struct ListNode *l1 = NULL;

    struct ListNode *l2 = NULL;

    l1 = creatNode(1);
    insertNode(l1, creatNode(2));
    insertNode(l1, creatNode(3));

    l2 = creatNode(1);
    insertNode(l2, creatNode(3));
    insertNode(l2, creatNode(4));

    Plist(l1);
    Plist(l2);
    struct ListNode *reult = mergeTwoLists2(l1, l2);

    Plist(reult);
}