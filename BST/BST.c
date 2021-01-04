#include <assert.h>
#include <stdint.h>
#include "bst.h"
#include <stdio.h>

BST bst_new(){
    BST b1 = {NULL,0};
    return b1;
}

uint32_t bst_count(const BST *tree){
    assert(tree!=NULL);
    return tree->mass;
}

static TreeNode* _get_new_node(int32_t ele){
	TreeNode *newnode = (TreeNode*)malloc(sizeof(TreeNode));
	newnode->data = ele;
	newnode->left=NULL;
	newnode->right=NULL;
	return newnode;
}

BST* bst_add(BST* tree,int32_t element){
    	assert(tree != NULL);
	TreeNode *current, *parent;
	current = parent = tree->root;

	while(current !=NULL && element != current->data){
		parent=current;
		if (element <current->data){
			current = current->left;
		}else if(element > current->data){
			current=current->right;
		}

	}

	if (current == NULL){
		TreeNode *newnode = _get_new_node(element);
		if(parent == NULL){
			tree->root=newnode;

		}else if(element < parent->data){
			parent->left=newnode;

		}else if(element>parent->data){
			parent->right=newnode;
		}
		++tree->mass;
	}
	return tree;
}
uint32_t bst_lookup(const BST *tree,int32_t key){
	assert(tree!=NULL);
	TreeNode *current = tree->root;

	while(current!=NULL && key!=current->data){
		if(key<current->data){
			current=current->left;
		}else if(key > current->data){
			current=current->right;
		}
	}
	return (current !=NULL);
}

static TreeNode* _findMin_(TreeNode *node){
	if(node->left == NULL){
		return node;
	}else{
		return (_findMin_(node->left));

			}
}

static TreeNode* _findMax_(TreeNode *node){
	if(node->right == NULL){
		return node;
	}else{
		return (_findMax_(node->right));

			}
}

static TreeNode* _delete_ (BST *tree,TreeNode *node,int32_t element){
	TreeNode *temp;
	if(node==NULL){
		return node;
	}
	else if(element<node->data){
		node->left=_delete_(tree,node->left,element);
	}else if(element>node->data){
		node->right=_delete_(tree,node->right,element);
	}else if(node->left && node->right){
		temp = _findMin_(node->right);
		node->data = temp->data;
		node->right = _delete_(tree,node->right,node->data);

	}else{
		temp = node;
		if(node->right == NULL){
			node = node->left;
		}else {
			node = node->right;
		}
		free(temp);
		--tree->mass;
		return node;
	}
}

BST* bst_delete(BST *tree, int32_t element){
	assert(tree!=NULL);
	tree->root=_delete_(tree,tree->root,element);

}

static void _inorder_(TreeNode *node){
	if(node){
		_inorder_(node->left);
		printf("%d\t",node->data);
		_inorder_(node->right);
	}

}
void bst_inorder(BST *tree){
	assert(tree!=NULL);
	_inorder_(tree->root);
}
static void _postorder_(TreeNode *node){
    if(node){
		_postorder_(node->left);
		_postorder_(node->right);
		printf("%d\t",node->data);
	}

}

void bst_postorder(BST *tree){
	assert(tree!=NULL);
	_postorder_(tree->root);
}

static void _preorder_(TreeNode *node){
    if(node){
         printf("%d\t",node->data);
		_preorder_(node->left);
		_preorder_(node->right);

	}

}

void bst_preorder(BST *tree){
	assert(tree!=NULL);
	_preorder_(tree->root);
}

uint32_t bst_height(const BST *tree){
    assert(tree!=NULL);
    int left=bst_height(tree->root->left);
    int right=bst_height(tree->root->right);
    if (left > right)
           return(left+1);
       else return(right+1);
}

uint32_t leaf_count(BST *tree)
{
  assert(tree!=NULL);
  uint32_t count;
  if(tree->root->left == NULL && tree->root->right==NULL)
    count=1;
  else {
    count = leaf_count(tree->root->left)+
            leaf_count(tree->root->right);
  }
  return count;
}

void bst_ascending(BST *tree){
    assert(tree!=NULL);
	_inorder_(tree->root);
}

int32_t bst_min(const BST *tree){
    TreeNode *temp;
    temp=_findMin_(tree->root);
    return (temp->data);
}

int32_t bst_max(const BST *tree){
    TreeNode *temp;
    temp=_findMax_(tree->root);
    return (temp->data);
}

