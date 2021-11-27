#include "header.h"

/* print_hash_table: print the contents of hash table */
void print_hash_table(Hash_table *table)
{
        for (int i = 0; i < SIZE; ++i)
        {
                Hash_table *temp = table + i;
                printf("%d. ", i);
                /* check for all the nodes in every index */
                while (temp)
                {
                        printf("%d->", temp->data);
                        temp = temp->link;
                }
                putchar('\n');
        }
}
