#include <stdio.h>
#include <stdlib.h>

int main()
{
    float amount=0;
    int years=0;
    float interest= 0.1;

    printf("Enter The Amount:");
    scanf("%f",&amount);
    printf("Enter Years:");
    scanf("%i",&years);

    for(int i=0;i<years;i++)
    {
         amount = amount + amount * interest;
         printf("Your Amount will be %f after %i years \n",amount,i+1);
    }


    return 0;
}
