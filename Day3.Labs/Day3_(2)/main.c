#include <stdio.h>
#include <stdlib.h>


int main()
{
int a,b;
    printf("enter first number X :");
    scanf("%i",&a);
    printf("enter first number Y :");
    scanf("%i",&b);
    swap (a,b);
    printf("the swap is x= %i y= %i \n",a,b);

return 0;
}
 int swap(int x, int y)
{


    int temp;
    temp=x;
    x=y;
    y=temp;
    printf("after swap x= %i y= %i \n",x,y);
}


