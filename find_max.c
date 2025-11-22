/*******************************************************************************************************************************************************************
*Title			: Find Maximum
*Description		: This function finds the maximum data from the given Red Black tree.
*Prototype		: int find_maximum(tree_t **root, data_t *max);
*Input Parameters	: root – Pointer to the root node of the Red Black tree.
			: max – Maximum data present in the tree is collected via this pointer.
*Output			: Status (SUCCESS / FAILURE)
*******************************************************************************************************************************************************************/
#include "rbt.h"

int find_maximum(tree_t **root, data_t *max)
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

    *max = temp->data;

    return 1;
}
