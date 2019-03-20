#include <stdio.h>

void swap(int *a, int *b)
{
        int temp = *a;
        *a= *b;
        *b = temp;
}

void insertion_sort(int *a, int size)
{
        for (int i = 1; i < size; ++i)
        {
                int j = i;
                int val = a[j];
                while (j > 0 && a[j - 1] > val)
                {
                        a[j] = a[j - 1];
                        --j;
                }
                a[j] = val;
        }
}

int main()
{
        int a[] = {3, 1, 2, 7, 9, 4, 6, 8, 5};
        insertion_sort(a, sizeof a / sizeof a[0]);

        for (int i = 0; i < sizeof a / sizeof a[0]; ++i)
                printf("%d ", a[i]);
        putchar('\n');
}
