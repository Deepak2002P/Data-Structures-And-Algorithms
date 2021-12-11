// Program of Linear Search in an Array using C
#include <stdio.h>
void display(int arr[], int size)
{
    int i;
    for (i = 0; i < size; i++)
        printf("%d\t", arr[i]);
}
int linearSearch(int arr[], int size, int element)
{
    int i;
    for (i = 0; i < size; i++)
    {
        if (arr[i] == element)
            return i;
    }
    return -1;
}
int main()
{
    int arr[] = {2, 4, 6, 7, 3, 4, 4, 2};
    int size = sizeof(arr) / sizeof(int), element, inpelement, indSearch;
    printf("Array is \n");
    display(arr, size);
    printf("\nElement You Want to Find:");
    scanf("%d", &inpelement);
    element = inpelement;
    indSearch = linearSearch(arr, size, element);
    printf("Element %d is at %d index", element, indSearch);
    return 0;
}