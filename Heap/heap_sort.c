#include <stdio.h>

void Heap_Sort(int a[], int size);
void Max_Heap(int *a, int index, int size);
void swap(int *a, int *b);

int main(void)
{
        int size;
        printf("Enter the ary size: ");
        scanf("%d", &size);

        int a[size];
        printf("Enter ary elements: ");
        for (int i = 0; i < size; ++i)
                scanf("%d", &a[i]);

        Heap_Sort(a, (sizeof(a) / sizeof(a[0])));

        return 0;
}

void Heap_Sort(int a[], int size)
{
        for (int i = (size / 2 - 1); i >= 0; --i)
                Max_Heap(a, i, size);


        for (int i = size - 1; i >= 0; --i)
        {
                swap(&a[0], &a[i]);
                Max_Heap(a, 0, i);
        }

        for (int i = 0; i < size; ++i)
                printf("%d ", a[i]);
        putchar('\n');
}

void Max_Heap(int *a, int index, int size)
{
        int left = 2 * index + 1;
        int right = 2 * index + 2;
        int large_index = index;

        if (a[left] > a[large_index] && left < size)
                large_index = left;
        if (a[right] > a[large_index] && right < size)
                large_index = right;

        if (index != large_index)
        {
                swap(&a[index], &a[large_index]);
                Max_Heap(a, large_index, size);
        }
}

void swap(int *a, int *b)
{
        int temp = *a;

        *a = *b;
        *b = temp;
}
