#include <stdio.h>
#include <stdlib.h>
#include <windows.h>

#define NormalColor 15
#define HighlightColor 75
void gotoxy(int x,int y);
void textattr(int i);
void PrintMenu(char *ptr,int size,int current);

int main()
{
    int size =5;
    char arr[5][12]={"add","edit","display","display All","Exit"};
    char c;
    int QuitFlag=0;
    int current=0;
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
            //ase 27: // Esc
              //  QuitFlag=1;
                //break;
            case 13 : // Enter
                switch(current)
                {
                    case 0 :
                        system("cls");
                        printf(" \n add");
                        getch();
                        break;
                    case 1 :
                        system("cls");
                         printf(" \n edit");
                         getch();
                         break;
                    case 2 :
                        system("cls");
                        printf(" \n display");
                        getch();
                        break;
                    case 3 :
                        system("cls");
                        printf(" \n display all");
                        getch();
                        break;
                    case 4 :
                        system("cls");
                        printf(" \n exit");
                       // getch();
                        QuitFlag=1;

                        break;
                }

                break;
            default:

                break;
            }

     }while(QuitFlag != 1);


    return 0;
}
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
