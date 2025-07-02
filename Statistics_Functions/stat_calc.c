#include <stdio.h>
#include <string.h>
#include <time.h>
#define MAX 100
void swap(int *x, int *y)
{
    int temp = *x;
    *x = *y;
    *y = temp;
}


float mean(int *arr, int size)
{
    float sum;
    for(int i = 0; i < size;i++)
    {
        sum += *arr;
        arr++;
    }
    return (sum/(float)size);
}

float mode(int *arr, int size)
{
    float maxValue = 0,maxCount = 0;
    for(int i = 0; i < size;i++)
    {
        int cnt = 0;
        for(int j = 0;j < size;j++)
        {
            if(arr[i] == arr[j])
            cnt++;
        }
        if(cnt > maxCount)
        {
            maxCount = cnt;
            maxValue = arr[i];
        }
    }
    return maxValue;
}
int partition(int arr[], int low, int high)
{
    int i = low;
    int j = high;
    int p = arr[low];

    while(i < j)
    {
        while(arr[i] <= p && i < (high-1))
        {
            i++;
        }

        while(arr[j] > p && j >= (low+1))
        {
            j--;
        }
        if(i < j)
            swap(&arr[i],&arr[j]);
    }
    swap(&arr[low], &arr[j]);
    return j;
}
void quicksort(int arr[],int low, int high)
{
    if(low < high){
        int res = partition(arr,low,high);

        quicksort(arr,low, res-1);
        quicksort(arr,res+1,high);

    }
}



float median(int arr[],int size)
{
    quicksort(arr,0,size-1);

    if(size % 2 == 0)
        return (arr[size/2 -1] + arr[size/2])/(2.0);
    else
        return arr[size/2];
}

int main(void){
    int name[] = {1,0,3,2,5,6};
    printf("%f\n",mode(name, 6));
    printf("%f\n",mean(name, 6));
    printf("%f\n",median(name,6));
    return 0;
}

































/*
struct healthCare{
    char firstname[MAX];char lastname[MAX];char gender[MAX];int d;int m;int y;float h;float w;
};

int main(void)
{
    struct healthCare ob;
    time_t t = time(NULL);struct tm tm = *localtime(&t);
    printf("Enter your firstname: ");
    scanf("%s", ob.firstname);
    printf("Enter your lastname: ");
    scanf("%s", ob.lastname);
    printf("Enter your gender: ");
    scanf("%s", ob.gender);
    printf("Enter your day, month, year, height and wight: ");
    scanf("%d %d %d %f %f", &ob.d,&ob.m,&ob.y,&ob.h,&ob.w);
    printf("Firstname: %s, Lastname: %s, Gender: %s\n",ob.firstname,ob.lastname,ob.gender);
    printf("Day: %d,Month: %d, Year: %d\n",ob.d,ob.m,ob.y);
    printf("Age:%d, BMI:%0.5f",((tm.tm_year+1900)-ob.y),(ob.w/(ob.h*ob.h)));
    return 0;
}




*/


// abcd dcba


/*  int num1,num2,op;
    printf("Enter 2 integers: ");
    scanf("%d %d", &num1,&num2);
    printf("Enter Your operation between 1 to 4, addition to division: ");
    scanf("%d",&op);
    switch(op)
    {
    case 1:
        printf("Addition: %d",(num1+num2));
        break;
    case 2:
        printf("Subtraction: %d",(num1-num2));
        break;
    case 3:
        printf("Multiplication: %d",(num1*num2));
        break;
    case 4:
        (num2 != 0)?printf("Division: %d",(num1/num2)):printf("Error");
         break;
    default: printf("Error operation");
    }
    return 0;
    */
