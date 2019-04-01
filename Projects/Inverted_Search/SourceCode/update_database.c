/***************************************************************************************************************************************************
*Author         :Emertxe(http://www.emertxe.com)
*Date           :Mon 22 May 2017 14:10:05 IST
*File           :read_datafile
*Title          :To process the files one by one
*Description    :Open the file “FileList” and read the names of the files. This is an iterative process which reads one file name from the 
		:FileList and open that file in read mode.
****************************************************************************************************************************************************/
#include "inverted_search.h"

int update_database(Slist **head, FILE* file, char *filename)
{
        // Definition here //
        create_database(head, file, filename);
        return SUCCESS;
}
