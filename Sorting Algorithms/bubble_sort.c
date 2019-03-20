#include <stdio.h>

void swap(int *a, int *b)
{
        int temp = *a;
        *a = *b;
        *b = temp;
}

void bubble_sort(int a[], int size)
{
        for (int i = 0; i < size; ++i)
        {
                for (int j = i + 1; j < size; ++j)
                {
                        if (a[i] > a[j])
                                swap (&a[i], &a[j]);
                }
        }
}

int main()
{
        int a[] = {3, 5, 2, 7, 1, 4, 6, 8, 9};
        bubble_sort(a, sizeof a / sizeof a[0]);

        for (int i = 0; i < sizeof a / sizeof a[0]; ++i)
                printf("%d ", a[i]);
        putchar('\n');
}
