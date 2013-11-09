#include "btree.h"
#include <stdio.h>
#include <stdlib.h>

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


