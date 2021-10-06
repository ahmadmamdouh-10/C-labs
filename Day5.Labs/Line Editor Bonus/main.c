#include <stdio.h>
#include <conio.h>
#include <string.h>
#include <ctype.h>

#define RIGHT 77
#define LEFT 75
#define UP 72
#define DOWN 80
#define DELETE 83
#define BACKSPACE 8

int cx=1,cy=1,cxx=0,fchar=0,tchar=79; int nline=0; int fline=0,tline=0; int cline=0;
// cx : X-Cordinate of the cursor
// cy : Y-Cordinate of the cursor
// cxx : position of the cursor in the current line in the file
// fchar,tchar : Only a portion of the line is displayed on the screen.
//fchar gives the left position and
//tchar gives the right position in the line.
//nline: Number of lines in the file
//fline,tline : In this program,21 lines of the file are displayed at a time. These lines are from fline to tline.
//cline: It gives the line number of the line on which the cursor is placed */

static char buffer[80][121];//The file may contain maximum of 80 lines, //each line may contain maximum of 118 characters int lengthof(int cline) ;//Gives the length of a line void displine(int cline);

void dispmenu() { int i; gotoxy(1,22); printf("---------------------------------------------------------------"); gotoxy(1,23); printf("F1 — Save F3- Exit"); gotoxy(1,24); printf("---------------------------------------------------------------"); }

int spaceline(int cline) //The current line may contain only white spaces { int j; for(j=0;j<120;j++) if(buffer[cline][j]!=' ' ) return(0); return(1); }

void display() //Display contents of the screen buffer { int i,j; clrscr(); for(i=fline;i<=tline;i++ ) { gotoxy(1,i+1-fline); for(j=fchar;j<=tchar;j++) { putchar(buffer[i][j]); } } dispmenu(); gotoxy(cx,cy); }

char read() //Read the next character { char x; x=getch(); if(x==0)//Control character x=getch(); return(x); } void Delete(int cline,int pos)//Delete the current character { int j; if(pos<0) return; for(j=pos+1;buffer[cline][j]!=0;j++)//Shift characters left by 1 place buffer[cline][j-1]=buffer[cline][j]; buffer[cline][j]=' ';

}

void deleteline() //Delete the current line { int i=0,j; if(nline>1) { for(i=cline+1;i<=tline;i++) strcpy(buffer[i-1],buffer[i]); nline--; if(cline>nline) { tline--; cy=cy-1; cx=1; cline=cline-1; } } display(); }

void insertline(int cline1,char x,int pos) { int i=0,j,length,l; char buff[180]; if(x==13)//Insert a new line, it breaks the line into two lines { for(i=nline;i>cline1;i--)//Shift lines by 1 position strcpy(buffer[i+1],buffer[i]); strcpy(buffer[cline1+1],buffer[cline1]+pos);//Line after Cursor position for(i=pos;i<=119;i++)//Fill spaces in the remaining portion buffer[cline1][i]=' '; buffer[cline1][120]=0;//End of text marker for(i=strlen(buffer[cline+1]);i<120;i++) //Fill spaces in the broken line buffer[cline1+1][i]=' '; buffer[cline1+1][120]=0; nline++; //Adjust coordinate variables cline++; tline++; cy=cy+1; cxx=0; cx=1; if(cy>21)//Adjustment for the last line of the screen { fline++; cy--; }

} else { for(i=118;i>=pos ;i--)//Shift right and insert the current character buffer[cline1][i+1]=buffer[cline1][i]; buffer[cline1][i+1]=x; } display(); gotoxy(cx,cy);//Position the cursor }

void save(char filename[])//Save the file { FILE *ptr; int i,j ; ptr=fopen(filename,"w"); if(ptr==NULL) { printf("\nCould not open the file"); getch(); }

for(i=0;i<nline;i++) { buffer[i][118]='\n'; buffer[i][119]=0; for(j=0;j<=119 && buffer[i][j]!=0;j++) putc(buffer[i][j],ptr); } fclose(ptr); }

void main() { static char filename[50]; FILE *ptr; int length,i; char x; buffer[0][0]=0;//Empty buffer clrscr(); printf("\nEnter the file name : "); gets(filename); ptr=fopen(filename,"r"); if(ptr==NULL) { ptr=fopen(filename,"w"); putc(' ',ptr); fclose(ptr); ptr=fopen(filename,"r"); }

if(ptr!=NULL)
   {
    while(!feof(ptr)) //Read the file in the screen buffer
      {
       tline++;
       i=0;
       fgets(buffer[nline],120,ptr);
       while(buffer[nline][i]!='\n' && buffer[nline][i]!=0)
         i++;
       for(;i<119;i++)
         buffer[nline][i]=' ';
       buffer[nline][i]=0;
       nline++;
       }
   }
fclose(ptr);

if(tline>20)
    tline=20; //Maximum of 21 lines to be displayed
display();
gotoxy(cx,cy);
x=read(); //Read the next key
fchar=0;
tchar=lengthof(0) - 1;
if(tchar<0)
    tchar=0;
if(tchar>79)
    tchar=79;
while(x!=F3)
   {
    switch(x)
      {
       case F1:fclose(ptr);
         save(filename);
         break;
       case UP:
         if(cline>0)
          if(cy>1 )//Scroll down
             {
              cy--;
              cline--;
              gotoxy(cx,cy);
             }
          else
             {
              fline--;
              tline--;
              cline--;
              display();
              gotoxy(cx,cy);

              }
         break;
       case DOWN:
           if(cline<nline)
          if(cy<21 )//Scroll Up
              {
              cy++;
              cline++;
              gotoxy(cx,cy);
              }
          else
              {
              fline++;
              tline++;
              cline++;
              display();
              gotoxy(cx,cy);
              }
           break;

       case RIGHT:
            if(cxx<lengthof(cline))
          if(cx<80 )
            {
              cx++;
              cxx++;
              gotoxy(cx,cy);
            }
          else
            { //Scroll left
              cxx++;
              fchar++;tchar++;
              display();
            }
            break;

       case LEFT:
           if(cxx>0)
               if(cx>1)
          {
              cx--;
              cxx--;
              gotoxy(cx,cy);
          }
               else
          {  //Scroll right
              cxx--;
              fchar--;tchar--;
              display();
          }
           break;
       case DELETE:
            if(cxx>0 || ! spaceline(cline))
              {
          tchar--;
          Delete(cline,cxx);//Delete the current character
          display();
          gotoxy(cx,cy);
              }
            else
          deleteline(cline);//Delete the current line

            break;
       case BACKSPACE:
            if(cxx>0 )
              {
          tchar--;
          Delete(cline,cxx-1);//Delete the previous character
          cxx--;
          if(cx>1)
             cx--;
          display();
          gotoxy(cx,cy);
              }

            break;

       case 13://Enter is pressed
         insertline(cline,x,cxx);
         break;
       default:
         if(isalnum(x)||ispunct(x)||isspace(x))
            {
          insertline(cline,x,cxx);
          cx++;cxx++;
          gotoxy(cx,cy);
            }
         break;
     }
x=read();
 }
}

int lengthof(int cline) { return(strlen(buffer[cline])); }
