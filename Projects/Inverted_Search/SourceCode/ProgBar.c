#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

/* Developed by: Harish. Date Created: 12 Dec 2018 */
/* header files required: stdio.h, unistd.h */
/* ProgBar: prints the progress bar in stdout, accepts a progress string, returns 0 if succeeded, -1 if failed and if argument > 100 */
int ProgBar(char* str, int end, useconds_t usec)
{
	#define BOLDRED     "\033[1m\033[31m"
	#define BOLDGREEN   "\033[1m\033[32m"
	#define BOLDMAGENTA "\033[1m\033[35m"
	#define RESET	    "\033[0m"
	int start = 1;
	if (end > 100 || end < 0) {
		fprintf(stderr, "error: end value is out of range! Progress bar must not be more than 100%% and less than 0%%.\nProgram terminated.\n");
		return -1;
	}

	printf(BOLDRED "%s [", str);
	while (start <= end && start <= 100) {
		if (start == 40)
			printf(BOLDMAGENTA"");
		if (start == 60)
			printf(BOLDGREEN"");
		printf("-");
		usleep(usec);				/* sleep for usec */
		fflush(stdout);
		printf("] %3d%%", start++);		/* prints the progress */
		fflush(stdout);
		printf("\b\b\b\b\b\b");
		fflush(stdout);
	}
#if 0
	int i = end;
	while (i <= 100) {
		printf(" ");
		fflush(stdout);
		++i;
	}
#endif
	if (--start == end) {
			printf(BOLDRED "\b]" BOLDGREEN " %d%% Done. Succeded.\n" RESET, start = 100);
#if 0
                if (start > 85 && start <= 100) {
			printf(BOLDRED "\b]" BOLDGREEN " %d%% Done. Succeded.\n" RESET, start);
			return 0;
		} else if (start > 75 && start <= 85) {
			printf(BOLDRED "\b]" BOLDMAGENTA " %d%% Done.\n" RESET, start);
			return 0;
		} else if (start <= 75) {
			printf("\b] %d%% Sorry. Failed. Try Again Later.\n" RESET, start);
			return 0;
		}
#endif
	} else
		return -1;
}
#if 0
int main(int argc, char* argv[])
{
        #define FAILURE 1
	int a;

        if (argc < 2)
        {
                printf("Usage: ./ProgBar <String> <%%>\n");
                printf("Ex: ./a.out Loading 100 \n");
                exit(FAILURE);
        }
	ProgBar(argv[1], atoi(argv[2]), 100000);
}
#endif
