#include <stdio.h>

void swap(int *a, int *b)
{
        int temp = *a;
        *a = *b;
        *b = temp;
}

int partition(int *a, int left, int right)
{
        int pivot = a[right];
        int i = left - 1;
        for (int j = left; j <= right - 1; ++j)
        {
                if (a[j] <= pivot)
                {
                        ++i;
                        swap(&a[i], &a[j]);
                }
        }
        swap(&a[i+1], &a[right]);
        return i + 1;
}

int quicksort(int *a, int left, int right)
{
        if (left < right)
        {
                int index = partition(a, left, right);
                quicksort(a, left, index-1);
                quicksort(a, index + 1, right);
        }
}

int main()
{
        int a[] = {4, 2, 3, 1, 5, 6, 2, 6, 7, 8,9, 10};

        int size =  sizeof a / sizeof a[0];

       quicksort(a, 0, size-1);
       for (int i = 0; i < size; ++i)
               printf("%d ", a[i]);
       putchar('\n');
}
