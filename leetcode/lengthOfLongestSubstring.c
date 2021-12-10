#define SIZE 128

static inline int isPresent(int *set, char c) {
    return *(set + (c % SIZE)) ? 1 : 0;
}

static inline void addIt(int *set, char c) {
    set[c % SIZE] = 1;
}

static inline void removeIt(int *set, char c) {
    set[c % SIZE] = 0;
}

int lengthOfLongestSubstring(char * s){
    int set[SIZE] = {0};
    int i, j;
    i = j = 0;
    
    int n = strlen(s);
    int count = 0;
    
    if(!s) return -1;
    
    while(j < n) {
        if(!isPresent(set, s[j])) {
            addIt(set, s[j]);
            if(count < (j-i+1)) ++count;
            ++j;
        } else {
            removeIt(set, s[i]);
            ++i;
        }
    }
    
    return count;
}
