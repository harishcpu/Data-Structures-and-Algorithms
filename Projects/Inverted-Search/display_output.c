/*******************************************************************************************************************
*Author         :Emertxe(http://www.emertxe.com)
*Date           :Mon 22 May 2017 16:06:15 IST
*File           :display_output.c
*Title          :To display  the results.
*Description    :When all the words are searched the ouput list is formed. In this the file with max count
		:(representing maximum word match ) can be selected and displayed. For advanced searched,
		:(weightage of words stored in database linkedlist) can also be used. So the results will be more
		:accurate.
********************************************************************************************************************/

#include "inverted_search.h"

void print_ht(Slist** head)
{
	/* Definition here */
        Slist *temp;

        printf(BOLDRED "\t\t\t\t" "--------------------------------------------------------------" RESET "\n");
        printf("\t\t\t\t" "%-8s %-10s %8s %20s   %-10s\n", "Index", "filecount", "word", "wordcount", " filename");
        printf(BOLDRED "\t\t\t\t" "--------------------------------------------------------------" RESET "\n");
        for (int i = 0; i < MAX_SIZE; ++i)
        {
                temp = head[i];
                        while (temp)
                        {
                                printf("\t\t\t\t");
                                printf(BOLDGREEN "[" RESET "%c" BOLDGREEN "]" RESET "->", i + 97);
                                printf("%5d", temp->file_count);
                                printf("\t\t%-12s", temp->word);
                                //printf("%d, ", temp->file_table->word_count);
                                //printf("%s", temp->file_table->file_name);

                                Slist_file_table *temp1 = temp->file_table;
                                while(temp1)
                                {
                                        printf("<--->   %d    ", temp1->word_count);
                                        printf("%s", temp1->file_name);

                                        temp1 = temp1->tab_link;
                                }
                                temp = temp->link;
                                putchar('\n');
                        }
        }
        printf(BOLDRED "\t\t\t\t" "---------------------------------------------------------------" RESET "\n");
}
