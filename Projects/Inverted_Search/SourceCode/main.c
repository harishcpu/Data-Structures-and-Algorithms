/***************************************************************************************************************
*Author		:Emertxe(http://www.emertxe.com)
*Date		:Mon Sun 10 Mar 2019 14:00:05 IST
*File		:main.c
*Title		:Driver function
*Description	:This function acts like the driver function for the project inverted search
****************************************************************************************************************/
#include "inverted_search.h"

#define MAX_SIZE 26
#define MAX_FILES 10
#define NAME_FOUND 1

int select_operation(void);
int store_filenames(char *filename);

char *filenames[MAX_FILES];

int main(int argc, char *argv[])
{
	/* Define the main function here */

        Slist *head[MAX_SIZE] = {NULL};
        char filename[MAX_SIZE];
        char word[MAX_SIZE];
        FILE *fptr = NULL;
        int ch;
        do
        {
                FILE *fileptr = NULL;
                switch(select_operation())
                {
                        case 1:
                                /* Create database */
                                printf("Enter the file name: ");
                                scanf("%[^\n]s", filename);

                                if (store_filenames(filename) == NAME_FOUND)
                                {
                                        printf("\t\t\tFile information is already saved!!\n");
                                        continue;
                                }

                                fileptr = fopen(filename, "r");
                                if (fileptr == NULL)
                                {
                                        printf("Error: Failed opening file\n");
                                        exit(FAILURE);
                                }
                                create_database(head, fileptr, filename);
                                fclose(fileptr);
                                break;
                        case 2:
                                /* Display database */
                                print_ht(head);
                                break;
                        case 3:
                                printf("Enter the file name: ");
                                scanf("%[^\n]s", filename);

                                if (store_filenames(filename) == NAME_FOUND)
                                {
                                        printf("\t\t\tFile information is already saved!!\n");
                                        continue;
                                }

                                fileptr = fopen(filename, "r");
                                if (fileptr == NULL)
                                {
                                        printf("Error: Failed opening file\n");
                                        exit(FAILURE);
                                }
                                if (SUCCESS == update_database(head, fileptr, filename))
                                        printf("\t\t\t\tDatabase is updated\n");
                                break;
                        case 4:
                                printf("Enter the word: ");
                                scanf("%[^\n]s", word);
                                if (DATA_NOT_FOUND == search(head, word))
                                        printf("Sorry, the word is not found\n");

                                break;
                        case 5:
                                fptr = fopen("database.txt", "w");
                                if (fptr == NULL)
                                {
                                        printf("Failed opening file database.txt\n");
                                        exit(FAILURE);
                                }

                                write_databasefile(NULL, head, fptr);
	                        ProgBar(" Saving", 75, 100000);
                                while ((ch = getc(fptr)) != EOF)
                                        putchar(ch);
                                printf("\t\t\t\tSuccessfully Saved\n");
                                fclose(fptr);
                                break;
                        case 6:
                                return 0;
                }
        } while (1);
}

int select_operation(void)
{
        int choice;

        printf("Options:\n");
        /* display the available operations */
        printf("\t1. Create Database\n");
        printf("\t2. Display Database\n");
        printf("\t3. Update Database\n");
        printf("\t4. Search\n");
        printf("\t5. Save Database\n");
        printf("\t6. Exit\n");

        printf("Your choice: ");
        /* scan user's choice */
        scanf("%d", &choice); getchar();

        return choice;
}

int store_filenames(char *filename)
{
        int i = 0;
        while (i < MAX_FILES && filenames[i] != NULL)
        {
                if (!strcmp(filenames[i], filename))
                        return NAME_FOUND;
                ++i;
        }
        filenames[i] = (char *)malloc(sizeof (MAX_SIZE));
        strcpy(filenames[i], filename);
        return SUCCESS;
}
