/***************************************************************************************************************************************************
*Author         :Emertxe(http://www.emertxe.com)
*Date           :Mon 22 May 2017 15:56:15 IST
*File           :search.c
*Title          :To search the words.
*Description    :Each word is now used to search in the linkedlist. The word has to be compared with
		:each word in the linked list. When found, the file details can be retrieved. Since the
		:linkedlist is in sorted order, the complexity of searching the word in the complete list
		:can be avoided. While string comparison, if the word in linkedlist is greater than the
		:word to be search, it shows the word doesnt exists in the list,
****************************************************************************************************************************************************/
#include "inverted_search.h"

int search(Slist **head, data_t *word)
{
	/* Definition here */
        int i = 0, index;
        if (isupper(word[i]))
                index = word[i] % 'A';
        else
                index = word[i] % 'a';

        Slist *temp = head[index];
        while (temp != NULL && strcasecmp(temp->word, word))
        {
                temp = temp->link;
        }

        if (temp != NULL && !strcasecmp(temp->word, word))
        {
                printf("\t\t\t\t" "%-8s %-10s %8s %20s   %-10s\n", "Index", "filecount", "word", "wordcount", " filename");
                printf(BOLDRED "\t\t\t\t" "------------------------------------------------------------" RESET "\n""\t\t\t\t");
                printf("[%d]->", index);
                printf("        %d", temp->file_count);
                printf("%15s", temp->word);
                
                Slist_file_table *temp1 = head[index]->file_table;

                while (temp1)
                {
                        printf("             %d", temp1->word_count);
                        printf("     %15s\n", temp1->file_name);
                        temp1 = temp1->tab_link;
                }
                printf(BOLDRED "\t\t\t\t" "--------------------------------------------------------------" RESET "\n");
        }
        else
                return DATA_NOT_FOUND;
}
