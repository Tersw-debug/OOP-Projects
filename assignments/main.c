#include <stdio.h> //22



void convertToBase(int n,int target)
{
    (target == 16)? printf("Result is: %X",n):printf("Result is: %o",n);
}
int main(void)
{
    int num1,target;
    printf("Please enter a number: ");scanf("%d",&num1);
    printf("Choose the target base either 8 for octal or 16 for hexadecimal: ");scanf("%d",&target);
    if(target == 16 || target == 8)
    {
        convertToBase(num1,target);
    }
    else{
        printf("Unsupported target base.");
    }
    return 0;

}








/*    int op;float num1,num2;
    while(1)
    {
        printf("\nCalculator Menu: \n");
        printf("1. Add\n");
        printf("2. Subtract\n");
        printf("3. Multiply\n");
        printf("4. Divide\n");
        printf("0. Exit\n");
        printf("Enter your choice: ");
        scanf("%d",&op);
        if(op == 0){printf("Exiting the"
        " calculator. Goodbye!"); break;}
        else if(op >= 1 && op <= 4){
            printf("Enter two numbers: ");
            scanf("%f%f",&num1,&num2
);
            switch(op)
            {

            case 1:printf("Result: %f\n",
(num1+num2));break;
            case 2:
                printf("Result: %f\n",(num1-num2));
                break;
            case 3:
                printf("Result: %f\n",(num1*num2));
                break;
            case 4:
                (num2 == 0)?printf("Error: Division by zero is not allowed.\n") :printf("Result: %f\n",(num1/num2));
                break;
            default:
                    printf("Invalid choice. Please enter a number between 0 and 4.\n");
            }
        }
        else{
            printf("Invalid choice. Please enter a number between 0 and 4.\n");
        }
    }
*/
