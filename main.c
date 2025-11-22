/**************************************************************************************************************************************************************
*          Author       : Tejas B Gowda
*          Date         : 23/11/2025
*          Title		: Red-Black Tree using Data Structure in C
*          Description	: To design and implement red-black tree that stores values abiding the rules of RB tree
***************************************************************************************************************************************************************/
#include "rbt.h"

int main()
{
    tree_t *root = NULL;
    data_t data;
    data_t minimum;
    data_t maximum;
    char option;
    int operation;

    while(1)
    {
        printf("\n1. Insert\n2. Delete\n3. Find Minimum\n4. Delete Minimum\n5. Find Maximum\n6. Delete Maximum\n7.Exit\n");
        scanf("%d", &operation);

        switch (operation)
        {
            case 1:
                printf("Enter the data to be inserted into the RB Tree: ");
                scanf("%d", &data);
                insert(&root, data);
                print_tree(root);
                break;

            case 2:
                printf("Enter the data to be deleted from the RB Tree: ");
                scanf("%d", &data);
                delete(&root, data);
                print_tree(root);
                break;

            case 3:
                if (find_minimum(&root, &minimum))
                {
                    printf("Minimum data: %d\n", minimum);
                }
                print_tree(root);
                break;

            case 4:
                delete_minimum(&root);
                print_tree(root);
                break;

            case 5:
                if (find_maximum(&root, &maximum))
                {
                    printf("Maximum data: %d\n", maximum);
                }
                print_tree(root);
                break;

            case 6:
                delete_maximum(&root);
                print_tree(root);
                break;
            case 7: printf("Thank you..!\n");
                    return 0;
            default: printf("Enter valid operation..!\n");
            break;
        }

    }
    return 0;
}