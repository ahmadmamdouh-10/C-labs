#include <stdio.h>
#include <stdlib.h>
#include <windows.h>

#define NormalColor 15
#define HighlightColor 75

//Functions Prototypes:

void gotoxy(int x,int y);
void textattr(int i);
void PrintMenu(char *ptr,int size,int current);
struct Employee
{
    int id;
    char name[20];
    char address[25];
    int salary;
    char phone[14];
};

int main()
{
    int size =5;
    char arr[5][12]={"add","edit","display","display All","Exit"};
    char c;
    int QuitFlag=0;
    int current=0;
    struct Employee emp[5];

    do
     {
            // Function Calling

            PrintMenu(arr,size,current);
            c=getch();

            switch(c)
            {
            case -32 :
                c=getch();
                switch(c) // Extended Keys
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
           // case 27: // Esc
           //     QuitFlag=1;
            //    break;
            case 13 : // Enter
                switch(current)
                {
                    case 0 :
                        system("cls");
                        printf(" \n add \n");

                        for(int i=0;i<5;i++)
                        {
                            printf("Enter Employee %i id : ",i+1);
                            scanf("%i",&emp[i].id);
                            printf("Enter Employee %i name : ",i+1);
                            scanf("%s",emp[i].name);
                            printf("Enter Employee %i address : ",i+1);
                            scanf("%s",emp[i].address);
                            printf("Enter Employee %i salary : ",i+1);
                            scanf("%s",&emp[i].salary);
                            printf("Enter Employee %i phone : ",i+1);
                            scanf("%s",emp[i].phone);

                            printf("\n-------------------------------\n");
                            }
                        break;

                    case 1 :
                        system("cls");
                         printf(" \n edit");
                         int index;
                        printf("Enter Employee index : ");
                        scanf("%i",&index);

                        printf("Enter Employee %i id : ",index);
                        scanf("%i",&emp[index-1].id);
                        printf("Enter Employee %i name : ",index);
                        scanf("%s",emp[index-1].name);
                        printf("Enter Employee %i address : ",index);
                        scanf("%s",emp[index-1].address);
                        printf("Enter Employee %i salary : ",index);
                        scanf("%i",&emp[index-1].salary);
                        printf("Enter Employee %i phone : ",index);
                        scanf("%s",emp[index-1].phone);

                         break;
                    case 2 :
                        system("cls");
                        printf(" \n display\n");
                        int index2;
                        printf("Enter Employee index : ");
                        scanf("%i",&index2);

                        printf(" Employee %i id is -> %i",index2,emp[index2-1].id);
                        printf("\n Employee %i id is -> %s",index2,emp[index2-1].name);
                        printf("\n Employee %i id is -> %s",index2,emp[index2-1].address);
                        printf("\n Employee %i id is -> %i",index2,emp[index2-1].salary);
                        printf("\n Employee %i id is -> %s",index2,emp[index2-1].phone);
                        getch();
                        break;

                    case 3 :
                        system("cls");
                        printf(" \n display all\n");

                         for(int i=0;i<5;i++)
                            {
                                printf(" Employee %i id is -> %i",i+1,emp[i].id);
                                printf("\n Employee %i name is -> %s",i+1,emp[i].name);
                                printf("\n Employee %i address is -> %s",i+1,emp[i].address);
                                printf("\n Employee %i salay is -> %i",i+1,emp[i].salary);
                                printf("\n Employee %i phone is -> %s",i+1,emp[i].phone);

                                printf("\n-------------------------------\n");
                            }

                        getch();
                        break;
                    case 4 :
                        system("cls");
                        printf(" \n exit");
                        QuitFlag=1;

                       // getch();
                        break;
                }

                break;
            default:

                break;
            }

     }while(QuitFlag != 1);


    return 0;
}

//Functions Implementations:

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
    //Declarations :
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
