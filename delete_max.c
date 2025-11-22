/*******************************************************************************************************************************************************************
*Title			: Delete Maximum
*Description		: This function deletes the maximum data from the given Red Black tree.
*Prototype		: int delete_maximum(tree_t **root);
*Input Parameters	: root – Pointer to the root node of the Red Black tree.
*Output			: Status (SUCCESS / FAILURE)
*******************************************************************************************************************************************************************/
#include "rbt.h"

int delete_maximum(tree_t **root)
{
    if (!root || !*root)
    {
        return 0;
    }

    tree_t *temp = *root;

    while (temp->right)
    {
        temp = temp->right;
    }

    return delete(root, temp->data);
}

tree_t *tree_maximum(tree_t *x)
{
    while (x && x->right)
    {
        x = x->right;
    }
    return x;
}