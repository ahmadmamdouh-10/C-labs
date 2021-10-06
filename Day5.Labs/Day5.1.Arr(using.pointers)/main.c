#include <stdio.h>
#include <stdlib.h>

int main()
{
    // Array Declaration:

    int arr[10];
    int *ptr=arr;


    // Fill Array Items:

    for (int i=0;i<10;i++)
    {
        printf("Please Enter Grade %i : ", i+1);
        scanf("%i", ptr);
        ptr++;
    }

   // Display Array Items:

    ptr=arr;
    for(int i=0;i<10;i++)
    {
        printf("The Grade of Subject %i is %i \n", i+1,*ptr);
        ptr++;
    }

    return 0;
}

