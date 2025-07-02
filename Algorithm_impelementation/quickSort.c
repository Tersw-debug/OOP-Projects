#include <stdio.h>
#include <stdlib.h>

void swap(int *first,int *second)
{
    int temp = *first;
    *first = *second;
    *second = temp;
}

int partion(int arr[],int low,int high)
{
   int f = arr[low];
   int s = low;
   int r = high;

   while(s < r)
   {
       while(arr[s] <= f && s <= high -1)
       {
           s++;
       }
       while(arr[r] > f && r >= low +1)
       {
           r--;
       }
       if(s < r)
       {
            swap(&arr[s],&arr[r]);
       }
       swap(&arr[low], &arr[r]);
   }
   return r;
}


void quickSort(int arr[],int low,int high)
{
    if(low < high){
        int pi = partion(arr,low,high);

        quickSort(arr,low,pi-1);
        quickSort(arr,pi+1,high);
    }
}




int main(void)
{

    int arr[] = { 4, 2, 5, 3, 1 };
    int n = sizeof(arr) / sizeof(arr[0]);

    // calling quickSort() to sort the given array
    quickSort(arr, 0, n - 1);

    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);
    return 0;
}
