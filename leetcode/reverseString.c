#include <stdio.h>
#include <string.h>

void reverseString(char *s, int sSize) {
    char temp;
    for(int i = 0, j = sSize-1; i < j; i++, j--) {
        temp = s[i];
        s[i] = s[j];
        s[j] = temp;
    }
}

int main(int argc, char *argv[]) {
	char *s = "hello";
	printf("Before reversing: %s\n", s);
	reverseString(s, strlen(s));
	printf("After reversing: %s\n", s);
	return 0;
}
