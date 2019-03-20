#include <stdio.h>
#include <limits.h>

void merge(int *a, int p, int q, int r)
{
        int n1 = q - p + 1;
        int n2 = r - q + 1;

        int l1[n1], l2[n2];

        int i;
        for (i = 0; i < n1; ++i)
                l1[i] = a[p + i];
        l1[i] = INT_MAX;
        for (i = 0; i < n2; ++i)
                l2[i] = a[q + 1 + i];
        l2[i] = INT_MAX;

        int j, k;
        i = 0; j = 0; k = p;

        for (; i <= n1 && j <= n2 && k <= r; ++k)
        {
                if (l1[i] <= l2[j])
                        a[k] = l1[i++];
                else
                        a[k] = l2[j++];
        }
}

void mergesort(int *a, int p, int r)
{
        if (p >= r)
                return;

        int q = (p + r) / 2;
        mergesort(a, p, q);
        mergesort(a, q+1, r);
        merge(a, p, q, r);
}

int main()
{
        int a[] = {4, 2, 6, 3, 8, 5, 7, 9, 1};
        int size = sizeof a / sizeof a[0];

        mergesort(a, 0, size - 1);

        for (int i = 0; i < size; ++i)
                printf("%d ", a[i]);
        putchar('\n');
}
