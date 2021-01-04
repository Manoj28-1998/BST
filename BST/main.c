#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <stdint.h>
#include <stdlib.h>
#include "bst.h"

void test_new(){
	BST tree1 = bst_new();
	BST *tree = &tree1;
	assert(bst_count(tree) == 0);
}

void test_add(){
	BST tree1 = bst_new();
	BST *tree = &tree1;
	tree=bst_add(tree,50);
	tree=bst_add(tree,20);
	tree=bst_add(tree,90);
	assert(bst_count(tree)==3);
}

void test_height(){
    BST tree1 = bst_new();
	BST *tree = &tree1;
	tree=bst_add(tree,50);
	tree=bst_add(tree,70);
	tree=bst_add(tree,20);
	tree=bst_add(tree,10);
	tree=bst_add(tree,100);
	tree=bst_add(tree,80);
	tree=bst_add(tree,5);
    assert(bst_height(tree)==4);
}

void test_leaf_count(){
    BST tree1 = bst_new();
	BST *tree = &tree1;
	tree=bst_add(tree,50);
	tree=bst_add(tree,70);
	tree=bst_add(tree,20);
	tree=bst_add(tree,10);
	tree=bst_add(tree,100);
	tree=bst_add(tree,80);
	tree=bst_add(tree,5);
    assert(leaf_count(tree)==2);
}

void test_inorder(){
	BST tree1 = bst_new();
	BST *tree = &tree1;
	tree=bst_add(tree,50);
	tree=bst_add(tree,70);
	tree=bst_add(tree,20);
	tree=bst_add(tree,10);
	tree=bst_add(tree,100);
	tree=bst_add(tree,80);
	tree=bst_add(tree,5);
	bst_inorder(tree);
}

void test_postorder(){
	BST tree1 = bst_new();
	BST *tree = &tree1;
	tree=bst_add(tree,50);
	tree=bst_add(tree,70);
	tree=bst_add(tree,20);
	tree=bst_add(tree,10);
	tree=bst_add(tree,100);
	tree=bst_add(tree,80);
	tree=bst_add(tree,5);
	bst_postorder(tree);

}

void test_preorder(){
	BST tree1 = bst_new();
	BST *tree =&tree1;
	tree=bst_add(tree,50);
	tree=bst_add(tree,70);
	tree=bst_add(tree,20);
	tree=bst_add(tree,10);
	tree=bst_add(tree,100);
	tree=bst_add(tree,80);
	tree=bst_add(tree,5);
	bst_preorder(tree);

}
void test_min(){
	BST tree1 = bst_new();
	BST *tree =&tree1;
	tree=bst_add(tree,50);
	tree=bst_add(tree,70);
	tree=bst_add(tree,20);
	tree=bst_add(tree,10);
	tree=bst_add(tree,100);
	tree=bst_add(tree,80);
	tree=bst_add(tree,5);
	assert(bst_min(tree)==5);

}
void test_max(){
	BST tree1 = bst_new();
	BST *tree =&tree1;
	tree=bst_add(tree,50);
	tree=bst_add(tree,70);
	tree=bst_add(tree,20);
	tree=bst_add(tree,10);
	tree=bst_add(tree,100);
	tree=bst_add(tree,80);
	tree=bst_add(tree,5);
	assert(bst_max(tree)==100);

}
void test_ascending(){
	BST tree1 = bst_new();
	BST *tree =&tree1;
	tree=bst_add(tree,50);
	tree=bst_add(tree,70);
	tree=bst_add(tree,20);
	tree=bst_add(tree,10);
	tree=bst_add(tree,100);
	tree=bst_add(tree,80);
	tree=bst_add(tree,5);
	bst_ascending(tree);
}

int main()
{
    test_add();
    test_new();
    test_inorder();
    printf("\n");
    test_postorder();
    printf("\n");
    test_preorder();
    printf("\n");
    test_ascending();
    test_height();
    test_leaf_count();
    test_max();
    test_min();

    return 0;
}