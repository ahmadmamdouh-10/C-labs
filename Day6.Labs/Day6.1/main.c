#include <stdio.h>
#include <stdlib.h>



struct Employee
{  //Member Variables
     int Id;
     char Name [20];
     float Salary;
     char Mobile[14];
};

int main()
{
struct Employee emp[5];  //five Employees
for(int i=0;i<5;i++)
{
    //Set struct Emp:
    printf("Enter Employee %i Id:", i+1);
    scanf("%i", &emp[i].Id);
    printf("Enter Employee %i Name:", i+1);
    scanf("%s", &emp[i].Name);
    printf("Enter Employee %i Salary:", i+1);
    scanf("%f", &emp[i].Salary);
    printf("Enter Employee %i Mobile:", i+1);
    scanf("%s", &emp[i].Mobile);
    printf("\n =======================================\n");

}

for(int i=0;i<5;i++)
{

    //Display Struct Emp:
    printf("Employee %i Id : %i \n", i+1,emp[i].Id);
    printf("Employee %i Name: %s \n",i+1, emp[i].Name);
    printf("Employee %i Salary: %f \n",i+1, emp[i].Salary);
    printf("Employee %i Mobile: %s \n", i+1, emp[i].Mobile);
    printf("\n =======================================\n");
}

    getch();
    return 0;
}
