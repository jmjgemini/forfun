#ifndef BTREE_H
#define BTREE_h

typedef int key_t;

typedef struct _TreeNode
{
	key_t key;
	struct _TreeNode *lchild;
	struct _TreeNode *rchild;
	
}TreeNode;

typedef TreeNode *Position;
typedef TreeNode *Btree;

void btree_make_empty(Btree t);

typedef void (*visit_func)(TreeNode*);
void btree_preorder_traversal(Btree t,visit_func visit);
void btree_postorder_traversal(Btree t,visit_func visit);
void btree_middleorder_traversal(Btree t,visit_func visit);
void btree_level_travelsal(Btree t,visit_func visit);

#endif
