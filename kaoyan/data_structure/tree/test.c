#include <stdio.h>
#include "search_tree.h"

void visit(TreeNode *node)
{
	printf("%d ",node->key);
}
int main(void)
{
	SearchTree tree= NULL;
	search_tree_insert(&tree,2);
	search_tree_insert(&tree,1);
	search_tree_insert(&tree,5);
	search_tree_insert(&tree,4);
	search_tree_insert(&tree,3);
	search_tree_preorder_travelsal(tree,visit);
	printf("\n");

	TreeNode *p = search_tree_find_max(tree);
	if (p != NULL)
		printf("max = %d\n",p->key);
	search_tree_free(tree);
	return 0;
}
