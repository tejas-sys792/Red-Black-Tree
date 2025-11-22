/***************************************************************************************************************************************************************
*Title		: This the header file for the Red Black Tree
****************************************************************************************************************************************************************/
#ifndef RBT_H
#define RBT_H

#include <stdio.h>
#include <stdlib.h>

typedef int data_t;
typedef enum { RED, BLACK } color_t;

typedef struct node {
    data_t data;
    color_t color;
    struct node *left, *right, *parent;
} tree_t;

/* core helpers */
tree_t *create_node(data_t val);
tree_t *search_node(tree_t *root, data_t key);
tree_t *tree_minimum(tree_t *x);
tree_t *tree_maximum(tree_t *x);
void transplant(tree_t **root, tree_t *u, tree_t *v);

/* rotations */
void left_rotate(tree_t **root, tree_t *x);
void right_rotate(tree_t **root, tree_t *y);

/* insert */
int insert(tree_t **root, data_t item);
void insert_fixup(tree_t **root, tree_t *z);

/* delete */
int delete(tree_t **root, data_t item);
void delete_fixup(tree_t **root, tree_t *x, tree_t *xp);

/* min/max */
int find_minimum(tree_t **root, data_t *min);
int find_maximum(tree_t **root, data_t *max);
int delete_minimum(tree_t **root);
int delete_maximum(tree_t **root);

/* print */
void print_tree(tree_t *root);

#endif
