/******************************************************************************************************************************
* Author         : Emertxe(http://www.emertxe.com)
* Date           : Mon 22 May 2017 14:20:10 IST
* File           : write_datbasefile.c
* Title          : Saves the details into the file.
* Description    : All the files are opened and read. Words are listed. Now this list is to be stored.
		 : For this a new file “DatabaseFile” is created and opened in write mode.
		 : Now the words along with filelist (each node contents) are written to the Database file.
		 : In the file also the word should be written in sorted order.
		 : After that the file is closed properly.
*******************************************************************************************************************************/
#include "inverted_search.h"

int write_databasefile(char* wordlist, Slist **head, FILE* databasefile)
{
	/* Definition here */
        Slist *temp;

        fprintf(databasefile, "\t\t\t" "--------------------------------------------------------------" "\n");
        fprintf(databasefile, "\t\t\t" "%-8s %-10s %8s %20s   %-10s\n", "Index", "filecount", "word", "wordcount", " filename");
        fprintf(databasefile, "\t\t\t" "--------------------------------------------------------------" "\n");
        for (int i = 0; i < MAX_SIZE; ++i)
        {
                temp = head[i];
                        while (temp)
                        {
                                fprintf(databasefile, "\t\t\t");
                                fprintf(databasefile, "[%2d]->", i);
                                fprintf(databasefile, "%5d", temp->file_count);
                                fprintf(databasefile, "\t\t%-12s", temp->word);

                                Slist_file_table *temp1 = temp->file_table;
                                while(temp1)
                                {
                                        fprintf(databasefile, "<--->   %d    ", temp1->word_count);
                                        fprintf(databasefile, "%s", temp1->file_name);

                                        temp1 = temp1->tab_link;
                                }
                                temp = temp->link;
                                fprintf(databasefile, "\n");
                        }
        }
        fprintf(databasefile, "\t\t\t" "---------------------------------------------------------------" "\n");
}
