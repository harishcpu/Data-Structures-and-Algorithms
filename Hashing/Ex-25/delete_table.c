#include "header.h"

/* delete_table: delete the whole hash table */
int delete_table(Hash_table *table)
{
        for (int i = 0; i < SIZE; ++i)
        {
                (table + i)->data = -1;
                if ((table + i)->link != NULL)
                {
                        free((table + i)->link);
                        (table + i)->link = NULL;
                }
        }
}
