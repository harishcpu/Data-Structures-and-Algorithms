#include "header.h"

/* delete_node: delete a node from the hash table */
int delete_node(Hash_table *table, data_t data)
{
        Hash_table *temp = (table + (data % SIZE));

  /*             if data is present in the first node itself, 
  copy the next node data to the current node till you reach the last node
                        and free the last node.                          */
        if (temp->data == data)
        {
                Hash_table *temp1 = temp->link;
                if (temp1 == NULL)
                {
                        temp->data = -1;
                        return SUCCESS;
                }

                while (temp1->link)
                {
                        temp->data = temp1->data;
                        temp = temp1;
                        temp1 = temp1->link;
                }
                temp->data = temp1->data;
                free(temp1);
                temp->link = NULL;
                return SUCCESS;
        }

        /* 
         * if data is not found in the first node, 
         * search for the data in the same index of slots 
         * and free it by linking next node to prev node.
         */

        Hash_table *prev = NULL;
        while (temp && temp->data != data)
        {
                prev = temp;
                temp = temp->link;
        }
        if (temp)
        {
                prev->link = temp->link;
                free(temp);
                return SUCCESS;
        }

        /* if data not found at all */
        return DATA_NOT_FOUND;
}
