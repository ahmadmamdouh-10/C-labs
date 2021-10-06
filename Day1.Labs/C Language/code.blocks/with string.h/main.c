#include <stdio.h>
#include <stdlib.h>

int main()
{

    char FirstName[10]={"Ahmed"};
    char LastName[10]={"Mamdouh"};
    char FullName[22]={};

         for(int i=0;i<10;i++)
            {
             FullName[i]=FirstName[i];
         if (FirstName[i]!=0)
            {
             FullName[i]=FirstName[i];
            }
         else
         {
            FullName[i]=0;
         }
         }

         for(int i=0;i<22;i++)
         {
             FullName[i]=LastName[i];
         if (LastName[i]==0)
         {
             FullName[i]=LastName[i];
          }
          }
printf("Your Full Name is %s", FullName);


    return 0;
}
