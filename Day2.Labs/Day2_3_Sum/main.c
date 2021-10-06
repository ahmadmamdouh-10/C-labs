#include <stdio.h>
#include <stdlib.h>

int main()
{
    int x=0;
    int sum=0;
    while (sum < 1000)

{

           printf("Enter a number ");
        scanf("%int",&x);
        sum = sum +x;

}
    printf("sum: %i",sum);


    return 0;
}
