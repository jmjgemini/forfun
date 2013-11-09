#include "search_tree.h"
#include <stdio.h>
#include <stdlib.h>

void search_tree_insert(SearchTree *t,key_t key)
{
	if (*t == NULL)
	{
		*t = malloc(sizeof(TreeNode));
		if (*t == NULL)
		{
			fprintf(stderr, "Error:can not create TreeNode\n");
			return;
		}
		(*t)->key = key;
		(*t)->lchild = NULL;
		(*t)->rchild = NULL;
	}
	else if (key < (*t)->key)
		search_tree_insert(&((*t)->lchild),key);
	else if (key > (*t)->key)
		search_tree_insert(&((*t)->rchild),key);
	/* else key == t->key then do nothing */
}

Position search_tree_find(SearchTree t,key_t key)
{
	if (t == NULL)
		return NULL;
	if (key < t->key)
		return search_tree_find(t->lchild,key);
	else if (key > t->key)
		return search_tree_find(t->rchild,key);
	else
		return t;
}

Position search_tree_find_min(SearchTree t)
{
	if (t == NULL)
		return NULL;
	if (t->lchild == NULL)
		return t;
	else
		return search_tree_find_min(t->lchild);
}
Position search_tree_find_max(SearchTree t)
{
	if (t == NULL)
		return NULL;
	if (t->rchild == NULL)
		return t;
	else
		return search_tree_find_max(t->rchild);

}

void search_tree_preorder_travelsal(SearchTree t,visit_func visit)
{
	btree_preorder_traversal(t,visit);
}

void search_tree_postorder_travelsal(SearchTree t,visit_func visit)
{
	btree_postorder_traversal(t,visit);
}

void search_tree_middleorder_travesal(SearchTree t,visit_func visit)
{
	btree_middleorder_traversal(t,visit);
}
