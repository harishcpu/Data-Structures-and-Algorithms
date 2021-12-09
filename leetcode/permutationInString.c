#define SIZE 26

bool checkInclusion(char * s1, char * s2){
    int set[SIZE] = {0};
    int i, j;
    
    i = strlen(s1) - 1;
    while(i >= 0)   set[s1[i--] - 'a']++;
    i = j = 0;
    int count = strlen(s1);
    while(j < strlen(s2)) {
        if(set[s2[j++] - 'a']-- > 0)
            count--;
        if(!count)  return true;
        if(j - i == strlen(s1) && set[s2[i++] - 'a']++ >= 0)
            count++;
    }
    return false;
}
