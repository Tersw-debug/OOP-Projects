#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

void bucketSort(int arr[], int size)
{
    int newArr[10][size];
    int temp = 0,index = 0;
    for(int i = 0; i < 10;++i){
        for(int j = 0;j < size;++j)
            newArr[i][j] = 0;
    }

    for(int i = 0;i < size;++i)
    {
        temp = (arr[i] / 10) %10;
        if(newArr[temp][index] == 0)
        {
            newArr[temp][index] = arr[i];
        }
        else
        {
            while(newArr[temp][index] != 0 && index < size)
            {
                ++index;
            }
            newArr[temp][index] = arr[i];
            index = 0;
        }
    }
    for(int i = 0; i < 10;++i){
        for(int j = 0;j < size;++j)
            printf("%d\t", newArr[i][j]);
        printf("\n");
    }


}



int main(void)
{
    int arr1[5] = {900090,22,53,23,24};
    bucketSort(arr1,5);
    return 0;
}







