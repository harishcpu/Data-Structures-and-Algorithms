#include "header.h"

int main(void)
{
        create_hash_table(Hash_ary, SIZE);

        data_t data;

        while(1)
        {
                switch(select_operation())
                {
                        case 1:
                                printf("Enter data: ");
                                scanf("%d", &data);
                                insert_node(Hash_ary, data);
                                break;
                        case 2:
                                printf("Enter data: ");
                                scanf("%d", &data);
                                delete_node(Hash_ary, data);
                                break;
                        case 3:
                                print_hash_table(Hash_ary);
                                break;
                        case 4:
                                printf("Enter data: ");
                                scanf("%d", &data);
                                if (search_node(Hash_ary, data) == DATA_NOT_FOUND)
                                        printf("\t\t\tdata not found\n");
                                else
                                        printf("\t\t\tdata found\n");
                                break;
                        case 5:
                                delete_table(Hash_ary);
                                break;
                }
        }
}

int select_operation(void)
{
        int choice;

        printf("Options: \n");

        printf("\t1. Insert a node\n");
        printf("\t2. Delete a node\n");
        printf("\t3. Print table\n");
        printf("\t4.Search an element\n");
        printf("\t5.Delete entire table\n");

        printf("Your choice: ");
        scanf("%d", &choice);

        return choice;
}

/* function to initialize the hash table*/
int create_hash_table(Hash_table *ary, int size)
{
        for (int i = 0; i < size; ++i)
        {
                (ary + i)->index = i;
                (ary + i)->data = -1;
                (ary + i)->link = NULL;
        }
}
