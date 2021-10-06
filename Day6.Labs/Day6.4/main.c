#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
//#include <malloc.h>


#define NormalColor 15
#define HighlightColor 75

struct Employee //struct defintion:
{
    int id;
    char name[20];
    char address[25];
    int salary;
    char phone[14];
};

//prototype Functions:

void gotoxy(int x,int y);
void textattr(int i);
void PrintMenu(char *ptr,int size,int current);
void add(struct  Employee *emp ,int size);
void displayAll(struct  Employee *emp ,int size);
void display(struct  Employee *emp );
void edit(struct  Employee *emp );


int main()
{
    int size =5;
    char arr[5][12]={"add","edit","display","display All","Exit"};
    char c;
    int QuitFlag=0;
    int current=0;

   // printf ("ENter Number of Employees: ");
   // scanf("%i", &size);


    // static array declaration :
    struct Employee empl[5]; // array of 5 emplyees





    do
     {
            PrintMenu(arr,size,current);
            c=getch();

            switch(c)
            {
            case -32 :
                c=getch();
                switch(c)
                {
                case 72: //up
                    if(current>0)
                    {
                        current--;
                    }
                    break;
                case 80: // down
                    if(current<size-1)
                    {
                        current++;
                    }
                    break;
                }

                break;
            case 27: // Esc
                QuitFlag=1;
                break;
            case 13 : // Enter
                switch(current)
                {
                    case 0 :
                        system("cls");
                        printf(" \n add \n");

                       add(empl,5);
                        break;

                    case 1 :
                        system("cls");
                         printf(" \n edit");
                         int index;
                        printf("Enter Employee index : ");
                        scanf("%i",&index);

                        if(index>0 && index<=5)
                        {
                        edit(&empl[index-1]);
                        }
                        else
                        {
                            printf("Out of range");
                        }
                        getch();
                         break;
                    case 2 :
                        system("cls");
                        printf(" \n display\n");
                        int index2;
                        printf("Enter Employee index : ");
                        scanf("%i",&index2);

                        if(index2>0 && index2<=5)
                        {
                        display(&empl[index2-1]);
                        }
                        else
                        {
                            printf("Out of range");
                        }
                        getch();
                        break;

                    case 3 :
                        system("cls");
                        printf(" \n display all\n");

                        displayAll(empl,5);
                        getch();
                        break;
                    case 4 :
                        system("cls");
                        printf(" \n exit");
                        getch();
                        break;
                }

                break;
            default:

                break;
            }

     }while(QuitFlag != 1);


    return 0;
}


// Functions Implementations:
void gotoxy(int x,int y)
 {
   COORD coord={0,0};
   coord.X=x;
   coord.Y=y;
   SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),coord);
 }
void textattr(int i)
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), i);
}
void PrintMenu(char *ptr,int size,int current)
{
    int StartRow=10,StartCol=10;
    textattr(NormalColor);
    system("cls");
    for(int i=0;i<size;i++)
    {
        if(i==current)
        {
            textattr(HighlightColor);
        }
        else
        {
           textattr(NormalColor);
        }
        gotoxy(StartCol,StartRow++);
        printf("%s",ptr+(i*12));
    }
    textattr(NormalColor);
}
void add(struct  Employee *emp ,int size)
{
     for(int i=0;i<5;i++)
    {
        printf("Enter Employee %i id : ",i+1);
        scanf("%i",&emp->id);
        printf("Enter Employee %i name : ",i+1);
        scanf("%s",emp->name);
        printf("Enter Employee %i address : ",i+1);
        scanf("%s",emp->address);
        printf("Enter Employee %i salary : ",i+1);
        scanf("%i",&emp->salary);
        printf("Enter Employee %i phone : ",i+1);
        scanf("%s",emp->phone);

        emp++;
        printf("\n-------------------------------\n");
    }
}

void displayAll(struct  Employee *emp ,int size)
{
    for(int i=0;i<5;i++)
    {
        printf(" Employee %i id is -> %i",i+1,emp->id);
        printf("\n Employee %i name is -> %s",i+1,emp->name);
        printf("\n Employee %i salary is -> %i",i+1,emp->salary);
        printf("\n Employee %i phone is -> %s",i+1,emp->phone);
        emp++;
        printf("\n-------------------------------\n");
    }
}

void display(struct  Employee *emp )
{
     printf(" Employee  id is -> %i",emp->id);
     printf("\n Employee  name is -> %s",emp->name);
     printf("\n Employee  salary is -> %i",emp->salary);
     printf("\n Employee  phone is -> %s",emp->phone);
}

void edit(struct  Employee *emp)
{
    printf("Enter Employee id : ");
    scanf("%i",&emp->id);
    printf("Enter Employee name : ");
    scanf("%s",emp->name);
    printf("Enter Employee salary : ");
    scanf("%i",&emp->salary);
    printf("Enter Employee phone : ");
    scanf("%s",emp->phone);

}
