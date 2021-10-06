#include <stdio.h>
#include <stdlib.h>
int main()
{
     int x;
    do
        {

     //system("clear");

     printf("For add menu press 1 \n");
     printf("For edit menu press 2 \n");
     printf("For display menu press 3 \n");
     printf("For exit press 4 \n");
     printf("Enter Your choice :  ");


     scanf("%i",&x);

     switch(x)
     {
        case 1:
        printf("\nYour choice is : add  \n");
        break;

        case 2:
        printf("\nYour choice is : edit  \n");
        break;

        case 3:
        printf("\nYour choice is : display  \n");
        break;

        case 4:
        exit(0);
        break;

        default:
        printf("Invalid choice  \n");

    }

    }

         while(x!=4);


    return 0;
}
