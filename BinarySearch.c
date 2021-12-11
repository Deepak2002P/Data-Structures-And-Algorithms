// Program of Binary Search in an Array using C
#include <stdio.h>
void display(int arr[], int size)
{
    int i;
    for (i = 0; i < size; i++)
        printf("%d\t", arr[i]);
}
int BinarySearch(int arr[], int size, int element)
{
    int low, mid, high;
    low = 0;
    high = size - 1;
    //Start Searching
    while (low <= high)
    {
        mid = (low + high) / 2;
        if (arr[mid] == element)
        {
            return mid;
        }
        if (arr[mid] < element)
        {
            low = mid + 1;
        }
        else
        {
            high = mid - 1;
        }

    } // Searching Ends
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
    indSearch = BinarySearch(arr, size, element);
    printf("Element %d is at %d index", element, indSearch);
    return 0;
}