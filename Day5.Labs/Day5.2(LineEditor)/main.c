#include <stdio.h>
#include <windows.h>
#include <stdlib.h>



#define Left 75
#define Right 77
#define Home 71
#define End 79
#define DELETE 83
#define BACKSPACE 8


//define Up 72
//#define Down 80
//#define PgUp 73
//#define PgDn 81





void deleteline();
void display();
void gotoxy(int x,int y);




int main()
{

     printf("Line Editor \n");


     // Declarations :


    int StartCol=1, LastCol=1, CurrentCol=0, StartRow, Size;
    StartCol=LastCol=CurrentCol=30;
    StartRow=1;
    Size=21;
    int QuitFlag=0;

    char name[21];
    char *Current_ptr;
    char *last_ptr;
    Current_ptr= last_ptr= name;
    char c;

     int nline=0;
     int fline=0,tline=0;
     int cline=0;





    do
    {
        gotoxy(CurrentCol,StartRow);
        c=getch();
        switch(c)
        {
        case -32:  //Extended Key
            c=getch();
            switch(c) // To know which Extended Key
            {
            case Left: //Left
                if (CurrentCol>StartCol)
            {
                    CurrentCol++; //screen
                    Current_ptr++; //memory
            }

            break;

            case Right: //Right
                if(CurrentCol<LastCol)
                {
                    CurrentCol--; //Screen
                    Current_ptr--; //memory
                }
                break;

                case 71 : Home;
                       CurrentCol=StartCol;
                       Current_ptr=name;
                break;

                case 79 : End ;
                       CurrentCol=LastCol;
                       Current_ptr=last_ptr;
                break;
                     printf("%i", c);
            }

        break;




                case DELETE: // Delete
                 if(StartCol>0)
                 {
                     Size--;
                     Delete( cline ,StartCol);
                     Display();
                     gotoxy(CurrentCol, StartRow);
                 }

                break;

                case BACKSPACE: //backspace
                    if(StartCol>0)
                    {
                        Size--;
                        Delete( cline , StartCol);
                        StartCol--;
                        if(CurrentCol>1)
                        {
                            StartCol--;
                            display();
                            gotoxy(CurrentCol, StartRow);
                        }
                    }
                    break;

            case 27: //Esc
                QuitFlag=1;
            break;

            case 13: //Enter
                *last_ptr=0;
                gotoxy(StartCol, StartRow +2);
                printf("%s", name);
                QuitFlag=1;
            break;

            default:  // All other Characters

                if(CurrentCol<StartCol+Size)
                {   if (CurrentCol==LastCol)
                {
                        //Screen
                         LastCol++;
                        //Memory
                        last_ptr++;

                }
                    //Screen
                    printf("%c", c);
                    CurrentCol++;


                    //Memory
                    *Current_ptr= c;
                    Current_ptr++;

                }



        }


    }while(!QuitFlag);

    return 0;
}


//Implementation :

 void deleteline()
    {
        //Delete the current line

       int i=0,j;
       int nline;
        if(nline>1)
        {
            int cline;
            int tline;
            int buffer;

            for(i=cline+1;i<=tline;i++)
                strcpy(buffer[i-1],buffer[i]);
            nline--;
             if(cline>nline)
             {

                 tline--; cy=cy-1; cx=1; cline=cline-1;
             }

        }








  void display()
 {
     //Display contents of the screen buffer
      int i,j;
      clrscr();
       for(i=fline;i<=tline;i++ )
       {
            gotoxy(1,i+1-fline);
        for(j=StartRow;j<=Size;j++)
        {
           putchar(buffer[i][j]);
        }
       }

       dispmenu(); gotoxy( CurrentCol, StartRow);
 }



 void gotoxy(int x,int y)
 {
   COORD coord={0,0};
   coord.X=x;
   coord.Y=y;
   SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),coord);
 }
