#ifndef SEARCH_TREE_H
#define SEARCH_TREE_H

#include "btree.h"

typedef Btree SearchTree;

void search_tree_insert(SearchTree *t,key_t key);

Position search_tree_find(SearchTree t,key_t key);
Position search_tree_find_min(SearchTree t);
Position search_tree_find_max(SearchTree t);

void search_tree_preorder_travelsal(SearchTree t,visit_func visit);
void search_tree_postorder_travelsal(SearchTree t,visit_func visit);
void search_tree_middleorder_travesal(SearchTree t,visit_func visit);

void search_tree_free(SearchTree t);

#endif
