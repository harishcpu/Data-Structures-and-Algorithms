#include <stdio.h>

void swap(int *a, int *b)
{
        int temp = *a;
        *a= *b;
        *b = temp;
}

void selection_sort(int *a, int size)
{
        int min;
        for (int i = 0; i < size; ++i)
        {
                min = i;
                for (int j = i+1; j < size; ++j)
                {
                        if (a[min] > a[j])
                                min = j;
                }
                swap(&a[i], &a[min]);
        }
}

int main()
{
        int a[] = {1,3,2,5,4};
        selection_sort(a, sizeof a / sizeof a[0]);

        for (int i = 0; i < sizeof a / sizeof a[0]; ++i)
                printf("%d ", a[i]);
        putchar('\n');
}
