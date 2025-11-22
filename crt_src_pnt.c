#include "rbt.h"
// create node
tree_t *create_node(data_t val)
{
    tree_t *n = malloc(sizeof(tree_t));
    if (!n) exit(1);
    n->data = val;
    n->color = RED;
    n->left = n->right = n->parent = NULL;
    return n;
}
//search element
tree_t *search_node(tree_t *root, data_t key)
{
    while (root)
    {
        if (key == root->data)
        {
            return root;
        }
        else if (key < root->data)
        {
            root = root->left;
        }
        else
        {
            root = root->right;
        }
    }
    return NULL;
}
//print tree
void print_tree(tree_t *root)
{
    
    if (root)
    {
        
        print_tree(root->left);
        printf("%d(%c) ", root->data, root->color == RED ? 'R' : 'B');
        print_tree(root->right);
    }
}
