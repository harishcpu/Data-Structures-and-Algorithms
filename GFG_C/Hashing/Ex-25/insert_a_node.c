#include "header.h"

/* insert_node: insert a node in a hash table */
int insert_node(Hash_table *table, data_t data)
{
        /* find the right index in hash table */
        Hash_table *temp = (table + (data % SIZE));

        /* if the slot is already occupied */
        if ((temp)->data != -1)
        {
                /* Chaining method */

                /* find the last node in that slot */
                while ((temp)->link)
                        (temp) = (temp)->link;
                /* join one more node at the end */
                Hash_table *temp1 = (Hash_table *)malloc(sizeof (Hash_table));
                (temp1)->data = data;
                (temp1)->link = NULL;
                (temp)->link = temp1;
                
                return SUCCESS;
        }
        
        /* if the slot is free, just put in the data */
        (temp)->data = data;
        (temp)->link = NULL;
        return SUCCESS;
}
