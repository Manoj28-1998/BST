  
#ifndef BST_H_INCLUDED
#define BST_H_INCLUDED
#include <stdint.h>


typedef struct _tree_node_ TreeNode;
struct _tree_node_{
    int32_t data;
    TreeNode *left;
    TreeNode *right;
};

typedef struct _bst_ BST;
struct _bst_{
    TreeNode *root;
    int32_t mass;
};

BST bst_new();
uint32_t bst_count(const BST *tree);
uint32_t bst_lookup(const BST *tree,int32_t key);
BST* bst_add(BST* tree,int32_t element);
BST* bst_delete(BST* tree,int32_t element);
void bst_inorder(BST *tree);
void bst_preorder(BST *tree);
void bst_postorder(BST *tree);
void bst_levelordertraversal(BST *tree);
uint32_t bst_height(const BST *tree);
uint32_t leaf_count(BST *tree);
void bst_ascending(BST *tree);
void bst_decending(BST *tree);
int32_t bst_min(const BST *tree);
int32_t bst_max(const BST *tree);





#endif 