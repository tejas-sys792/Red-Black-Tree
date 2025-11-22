/*******************************************************************************************************************************************************************
*Title			: Delete Minimum
*Description		: This function deletes the minimum data from the given Red Black tree.
*Prototype		: int delete_minimum(tree_t **root);
*Input Parameters	: root – Pointer to the root node of the Red Black tree.
*Output			: Status (SUCCESS / FAILURE)
*******************************************************************************************************************************************************************/
#include "rbt.h"

int delete_minimum(tree_t **root)
{
    if (!root || !*root)
    {
        return 0;
    }

    tree_t *temp = *root;

    while (temp->left)
    {
        temp = temp->left;
    }

    return delete(root, temp->data);
}

tree_t *tree_minimum(tree_t *x)
{
    while (x && x->left)
    {
        x = x->left;
    }
    return x;
}