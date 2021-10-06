#include <stdio.h>
#include <stdlib.h>


int main()
{    //intialiting
    int arr[3][4]={};
    int sum[]={};
    int avg[]={};

    //fill array items

    for(int i=0;i<3;i++)
    {
        for(int j=0;j<4;j++)
        {
        printf("enter the grade of student %i for subject %i ", i+1,j+1);
        scanf("%i", &arr[i][j]);

        }
    }
    //Display Array Item
    for(int i=0;i<3;i++)
    {
    int i=0;
    int j=0;
        for(int j=0;j<4;j++)
        {
        printf("The grade of student %i for subject %i is : %i \n", i+1,j+1,arr[i][j]);

        sum[i]+=arr[i][j];
        avg[j]+=arr[i][j];


        }
    int sum[]={};
    for(int i=0;i<3;i++)
    {
    printf("The Sum of grades of subjects for student %i is: %i \n", i+1, sum[i]);

    }

    }

    for(int j=0;j<4;j++)
    {
    int j=0;
    avg[j]=avg[j]/3;
    printf("The Average of grades is: %i \n",avg[j]);
    }






    return 0;
}
