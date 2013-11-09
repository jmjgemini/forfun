#include "btree.h"
#include <stdio.h>
#include <stdlib.h>

#define QUE_SIZE 64

void btree_make_empty(Btree t)
{
	if (t != NULL)
	{
		btree_make_empty(t->lchild);
		btree_make_empty(t->rchild);
		free(t);
	}
}

void btree_preorder_traversal(Btree t,visit_func visit)
{
	if (t == NULL)
		return;
	visit(t);
	btree_preorder_traversal(t->lchild,visit);
	btree_preorder_traversal(t->rchild,visit);
}

void btree_postorder_traversal(Btree t,visit_func visit)
{
	if (t == NULL)
		return;
	btree_preorder_traversal(t->lchild,visit);
	btree_preorder_traversal(t->rchild,visit);
	visit(t);
}

void btree_middleorder_traversal(Btree t,visit_func visit)
{
	if (t == NULL)
		return;
	btree_preorder_traversal(t->lchild,visit);
	visit(t);
	btree_preorder_traversal(t->rchild,visit);
}

void btree_level_travelsal(Btree t,visit_func visit)
{
	TreeNode *que[QUE_SIZE];		
	int front = 0,rear = 0;
	rear = (rear+1)%QUE_SIZE;
	que[rear] = t;
	TreeNode *p;
	if (t != NULL)
	{
		while(front != rear)
		{
			front = (front+1)%QUE_SIZE;
			p = que[front];
			visit(p);
			if (p->lchild != NULL)
			{
				if ((rear+1)%QUE_SIZE != front)
				{
					rear = (rear+1)%QUE_SIZE;
					que[rear] = p->lchild;
				}
			}
			if (p->rchild != NULL)
			{
				if ((rear+1)%QUE_SIZE != front)
				{
					rear = (rear+1)%QUE_SIZE;
					que[rear] = p->rchild;
				}
			}
		}
	}
}






