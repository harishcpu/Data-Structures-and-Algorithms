#include <string.h>

int reverse_a_string(char *a, int begin, int end)
{
        char temp;
        while (begin < end)
        {
                temp = a[begin];
                a[begin] = a[end];
                a[end] = temp;
                ++begin;
                --end;
        }
}

int reverse(char *a)
{
        int begin = 0;
        int end = 0;
        int len = strlen(a);

        while (end <= len)
        {
                if (a[end] == ' ' || a[end] == '\0')
                {
                        reverse_a_string(a, begin, end - 1);
                        begin = end + 1;
                }
                ++end;
        }
        reverse_a_string(a, 0, len - 1);
}
