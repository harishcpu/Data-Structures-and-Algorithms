/****************************************************************************************************************************
* Author         : Emertxe(http://www.emertxe.com)
* Date           : Sun 10 Mar 2019 14:04:05 IST
* File           : create_database.c
* Title          : To create the database
* Description    : The list of the files can be provided by storing all the file names in another file, 
*                  FileList the names of the files which are to be documented are provided by this file. 
*                  When a file is added or removed, FileList is changed accordingly. So read the file names and start indexing.
******************************************************************************************************************************/

#include "inverted_search.h"

#define TRUE 1
#define FALSE 0

Slist* create_node(data_t *filename, data_t *word);
Slist_file_table *create_new_file_table(data_t *filename);
int avoid_words(char *word);

int create_database(Slist *head[], FILE *filelist, data_t *filename)
{
	/* Definition here */
        int i = 0;
        data_t the_word[MAX_SIZE];   

        int ch;
        /* parse each word from the list of words */
        while ((ch = fgetc(filelist)) != EOF)
        {
                if (isalpha(ch))
                        the_word[i++] = ch;
                else
                {
                        the_word[i] = '\0';
                        i = 0;
#if 0
                        printf("\t\t\t\t\t%s\n", the_word);
#endif
                        int index;
                        
                        if (strlen(the_word) < 2)
                                continue;

                        /* check for the unwanted words */
                        if (avoid_words(the_word))
                                continue;
                        
                        /* find the index */
                        if (isupper(the_word[i]))
                                index = the_word[i] % 'A';
                        else    // if(islower(the_word[i]))
                                index = the_word[i] % 'a';
                        
                        if (head[index] != NULL)
                        {
                                Slist *temp = head[index];
                                Slist *prev = temp;
                                while (temp)
                                {
                                        if (!strcasecmp(the_word, temp->word))
                                        {
                                                if (!strcmp(temp->file_table->file_name, filename))
                                                {
                                                        Slist_file_table* temp1 = temp->file_table;
                                                        
                                                        while(temp1->tab_link)
                                                                temp1 = temp1->tab_link;

                                                        ++temp1->word_count;
                                                        index = -1;
                                                        break;
                                                }
                                                else
                                                {
                                                        ++(temp->file_count);
                                                        Slist_file_table *temp1 = temp->file_table;
                                                        while(temp1->tab_link)
                                                                temp1 = temp1->tab_link;

                                                        temp1->tab_link = create_new_file_table(filename);
                                                        index = -1;
                                                        break;
                                                }
                                        }
                                        prev = temp;
                                        temp = temp->link;
                                }
                                if (index >= 0)
                                        prev->link = create_node(filename, the_word);
                        }
                        else
                                head[index] = create_node(filename, the_word);
                }
        }
}

Slist* create_node(data_t *filename, data_t *word)
{
        Slist *new = (Slist *)malloc(sizeof(Slist));
        if (new == NULL)
        {
                printf("Failed: Creating new node in Create_Database\n");
                exit(FAILURE);
        }

        /* update new node */
        
        /* 1. new->file_table */
        new->file_table = create_new_file_table(filename);

        /* 2.  new->file count*/
        new->file_count = 1;

        /* 3. new->word */
        new->word = (char *)malloc(strlen(word) + 1);
        //printf("\n%s\n", word);
        strcpy(new->word, word);

        /* 4. new->link */
        new->link = NULL;

        return new;
}

Slist_file_table *create_new_file_table(data_t *filename)
{
        Slist_file_table *new = (Slist_file_table *)malloc(sizeof(Slist_file_table));
        if (new == NULL)
        {
                printf("Failed: Creating new node in Create_Database\n");
                exit(FAILURE);
        }
        
        new->word_count = 1;
        strcpy(new->file_name, filename);
        new->tab_link = NULL;

        return new;
}

int avoid_words(char *word)
{
#define NO_STR 12

        char *ary[] = {"a", "an", "the", "for", "that", "and", "to", "in", "it", "on", "\n", " "};

        for (int i = 0; i < NO_STR; ++i)
        {
                if (!strcasecmp(ary[i], word))
                        return TRUE;
        }

        return FALSE;
}
