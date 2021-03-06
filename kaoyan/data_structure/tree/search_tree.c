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
void search_tree_level_travelsal(Btree t,visit_func visit)
{
	btree_level_travelsal(t,visit);
}

void search_tree_delete(SearchTree *t,key_t key)
{
	if (*t == NULL)
	{
		fprintf(stderr, "search_tree_delete:Element not found!\n");
		return;
	}
	if ((*t)->key == key)
	{
		/* found !*/
		if ((*t)->lchild && (*t)->rchild)
		{
			/* have two childs */
			Position p = search_tree_find_max((*t)->rchild);
			(*t)->key = p->key;
			search_tree_delete(&((*t)->rchild),p->key);
		}
		else
		{
			Position p;
			/* have one child or no child */
			if ((*t)->lchild == NULL)
				p = (*t)->rchild;
			else
				p = (*t)->lchild;
			free(*t);
			*t = p;
		}
	}
	else if (key < (*t)->key)
		search_tree_delete(&((*t)->lchild),key);
	else
		search_tree_delete(&((*t)->rchild),key);

}

void search_tree_free(SearchTree t)
{
	if (t == NULL)
		return;
	search_tree_free(t->lchild);
	search_tree_free(t->rchild);
	free(t);
}


