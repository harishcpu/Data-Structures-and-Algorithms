#include "header.h"

/* search_node: Search for a node in a hash table */
int search_node(Hash_table *table, data_t data)
{
        Hash_table *temp = (table + (data % SIZE));

        /* check if the data is in first node itself */
        if (temp->data == data)
                return DATA_FOUND;
        else
        {
                /* if not search the whole list for the data */
                while (temp)
                {
                        /* whenever found, get out */
                        if (temp->data == data)
                                return DATA_FOUND;
                        temp = temp->link;
                }
        }
        /* if not found */
        return DATA_NOT_FOUND;
}
