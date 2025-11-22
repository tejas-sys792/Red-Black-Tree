/*******************************************************************************************************************************************************************
*Title			: Deletion
*Description		: This function performs deleting of the given data from the given Red Black tree.
*Prototype		: int delete(tree_t **root, data_t item); 
*Input Parameters	: root – Pointer to the root node of the Red Black tree.
			: item – Data to be deleted from the Red Black tree.
*Output			: Status (SUCCESS / FAILURE)
*******************************************************************************************************************************************************************/
#include "rbt.h"

int delete(tree_t **root, data_t item)
{
    tree_t *z = search_node(*root, item);
    if (!z)
    {
        return 0;
    }

    tree_t *y = z;
    color_t y_color = y->color;
    tree_t *x = NULL;
    tree_t *xp = NULL;

    if (!z->left)
    {
        x = z->right;
        xp = z->parent;
        transplant(root, z, z->right);
    }
    else if (!z->right)
    {
        x = z->left;
        xp = z->parent;
        transplant(root, z, z->left);
    }
    else
    {
        y = tree_minimum(z->right);
        y_color = y->color;
        x = y->right;

        if (y->parent == z)
        {
            xp = y;
            if (x) x->parent = y;
        }
        else
        {
            xp = y->parent;
            transplant(root, y, y->right);
            y->right = z->right;
            y->right->parent = y;
        }

        transplant(root, z, y);

        y->left = z->left;
        y->left->parent = y;
        y->color = z->color;
    }

    free(z);

    if (y_color == BLACK)
    {
        delete_fixup(root, x, xp);
    }

    return 1;
}

// delete fixup adapted for NULL leaves
void delete_fixup(tree_t **root, tree_t *x, tree_t *xp)
{
    while ((x != *root) && (x == NULL || x->color == BLACK))
    {
        tree_t *w;
        if (!xp) break;

        if (x == xp->left)
        {
            w = xp->right;
            if (w && w->color == RED)
            {
                w->color = BLACK;
                xp->color = RED;
                left_rotate(root, xp);
                w = xp->right;
            }

            if ((!w || (w->left == NULL || w->left->color == BLACK)) &&
                (!w || (w->right == NULL || w->right->color == BLACK)))
            {
                if (w) w->color = RED;
                x = xp;
                xp = x ? x->parent : NULL;
            }
            else
            {
                if (!w || (w->right == NULL || w->right->color == BLACK))
                {
                    if (w && w->left) w->left->color = BLACK;
                    if (w) w->color = RED;
                    if (w) right_rotate(root, w);
                    w = xp->right;
                }
                if (w) w->color = xp->color;
                xp->color = BLACK;
                if (w && w->right) w->right->color = BLACK;
                left_rotate(root, xp);
                x = *root;
                break;
            }
        }
        else
        {
            w = xp->left;
            if (w && w->color == RED)
            {
                w->color = BLACK;
                xp->color = RED;
                right_rotate(root, xp);
                w = xp->left;
            }

            if ((!w || (w->left == NULL || w->left->color == BLACK)) &&
                (!w || (w->right == NULL || w->right->color == BLACK)))
            {
                if (w) w->color = RED;
                x = xp;
                xp = x ? x->parent : NULL;
            }
            else
            {
                if (!w || (w->left == NULL || w->left->color == BLACK))
                {
                    if (w && w->right) w->right->color = BLACK;
                    if (w) w->color = RED;
                    if (w) left_rotate(root, w);
                    w = xp->left;
                }
                if (w) w->color = xp->color;
                xp->color = BLACK;
                if (w && w->left) w->left->color = BLACK;
                right_rotate(root, xp);
                x = *root;
                break;
            }
        }
    }

    if (x) x->color = BLACK;
}

// transplant u with v
void transplant(tree_t **root, tree_t *u, tree_t *v)
{
    if (!u->parent)
    {
        *root = v;
    }
    else if (u == u->parent->left)
    {
        u->parent->left = v;
    }
    else
    {
        u->parent->right = v;
    }

    if (v) v->parent = u->parent;
}


// insert fixup 
void insert_fixup(tree_t **root, tree_t *z)
{
    while (z->parent && z->parent->color == RED)
    {
        tree_t *gp = z->parent->parent;
        if (z->parent == gp->left)
        {
            tree_t *uncle = gp->right;
            if (uncle && uncle->color == RED)
            {
                z->parent->color = BLACK;
                uncle->color = BLACK;
                gp->color = RED;
                z = gp;
            }
            else
            {
                if (z == z->parent->right)
                {
                    z = z->parent;
                    left_rotate(root, z);
                }
                z->parent->color = BLACK;
                gp->color = RED;
                right_rotate(root, gp);
            }
        }
        else
        {
            tree_t *uncle = gp->left;
            if (uncle && uncle->color == RED)
            {
                z->parent->color = BLACK;
                uncle->color = BLACK;
                gp->color = RED;
                z = gp;
            }
            else
            {
                if (z == z->parent->left)
                {
                    z = z->parent;
                    right_rotate(root, z);
                }
                z->parent->color = BLACK;
                gp->color = RED;
                left_rotate(root, gp);
            }
        }
    }
    if (*root) (*root)->color = BLACK;
}

