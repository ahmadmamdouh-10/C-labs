#include<stdio.h>

//function Prototype:
int CalculateSum (int a, int b);
int CalculateSubtract (int a, int b);


int main ()
{
int x=0;
int y=0;
int Sum=0;
int Subtract=0;

printf("Please Enter Two Numbers:", x,y);
scanf("%i %i", &x,&y);
//Function Call:

Sum= CalculateSum(x,y);
printf("The Sum of your Numbers is %i", Sum);

Subtract= CalculateSubtract(x,y);
printf("\nThe Subtract of your Numbers is %i", Subtract);





}

//Function Implementations:

int CalculateSum (int a, int b)
{
return a+b;
}
int CalculateSubtract (int a, int b)
{
return a-b;
}
