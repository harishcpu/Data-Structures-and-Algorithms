#include <stdio.h>
#include <string.h>

void reverseString(char *s, int i, int j) {
    char temp;
    while(i < j) {
        temp = s[i];
        s[i] = s[j];
        s[j] = temp;
        i++;
        j--;
    }
}

char *reverseWords(char *s) {
    int i, j;
    i = 0;
    
    if (s == NULL) return s;
    while(i < strlen(s) && s[i] != ' ') {
        j = i;
        while(j < strlen(s) && s[j] != ' ') j++;
        reverseString(s, i, j-1);
        i = ++j;
    }
    return s;
}
int main(int argc, char *argv[]) {
	char s[] = {'h','e','l','l','o',',',' ','w','o','r','l','d','!'};
	printf("Before reversing: %s\n", s);
	reverseWords(s);
	printf("After reversing: %s\n", s);
	return 0;
}
