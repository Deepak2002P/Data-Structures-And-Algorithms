#include <stdio.h>

void PrintArray(int *A, int n)
{
    int i;
    for (i = 0; i < n; i++)
    {
        printf("%d ", A[i]);
    }
    printf("\n");
}

void SelectionSort(int *A, int n)
{
    int indexofMin, i, j, temp;
    printf("Running Selection Sort......\n");
    for (i = 0; i < n - 1; i++)
    {
        indexofMin = i;
        for (j = i + 1; j < n; j++)
        {
            if (A[j] < A[indexofMin])
            {
                indexofMin = j;
            }
        }
        // Swap A[i] and A[indexofMin]
        temp = A[i];
        A[i] = A[indexofMin];
        A[indexofMin] = temp;
    }
}

int main()
{
    int A[] = {3, 5, 2, 13, 12};
    int n = 5;
    PrintArray(A, n);
    SelectionSort(A, n);
    PrintArray(A, n);
    return 0;
}
