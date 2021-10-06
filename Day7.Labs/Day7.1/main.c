#include <stdio.h>
#include <stdlib.h>

int main()
{
    // Static Array Declaration:
    //int arr[10];
    //int *ptr=arr;

    //Dynamic Array Declaration:
    int arrsize;
    int *ptr = (int *) malloc(arrsize *sizeof(int));
    int * ptrStart;
    ptrStart=ptr;

    printf("Please Enter Number of Grades: ");
    scanf("%i", &arrsize);




    // Fill Array Items:

    for (int i=0;i< arrsize ;i++)
    {
        printf("Please Enter Grade of Subject %i : ", i+1 );
        scanf("%i", ptr);
        ptr++;
    }


    ptr=ptrStart;

  // Display Array Items:

    for(int i=0;i<arrsize;i++)
    {
        printf("The Grade of Subject %i is %i \n", i+1, *ptr);
        ptr++;
    }

    return 0;
}

