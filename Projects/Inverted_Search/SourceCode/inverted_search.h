#ifndef MAIN_H
#define MAIN_H

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
#include <unistd.h>
#include "colors.h"

#define MAX_SIZE 26

#define FAILURE -1
#define EMPTY 5
#define DATA_NOT_FOUND -2
#define SUCCESS 0

#define CREATE_DATABASE 1
#define DISPLAY_DATABASE 2
#define UPDATE_DATABASE 3
#define SEARCH 4
#define SAVE_DATABASE 5

typedef char data_t;

typedef struct fi_tab
{
	int word_count;
	char file_name[20];
	struct fi_tab *tab_link;
}Slist_file_table;

typedef struct node
{
	int file_count;
	struct node *link;
	char *word;
	struct fi_tab *file_table;
}Slist;

int create_database(Slist **head, FILE *filelist, data_t *filename);
int update_database(Slist **head, FILE *filelist, data_t *filename);
int save_db(Slist **head, int index, FILE *fd);
int search(Slist **head, data_t *string);
void print_ht(Slist **head);
int write_databasefile(char *wordlist, Slist **head, FILE* databasefile);

int ProgBar(char* str, int end, useconds_t usec);
#endif
