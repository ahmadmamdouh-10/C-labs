#include <curses.h>

int main(int argc, char ** argv)
{
    char*q = 0;
    char t[999] = {0};
    int j = 0, k = 0;
    int i = 0; // cursor before first char
    int s = 0; // current size
    int c = 0; // current input
    int p = 0;

    // copy first command-line argument
    if(argc>0 && (q=argv[1]))while(*q)t[s++]=*q++; i=s;

    initscr(); // initiate NCURSES
    noecho(); // input does not echo on entry
    keypad(stdscr,TRUE); // handle all input

    do
    {
        // print current content with cursor
        for(j=0;j<i;j++) addch(t[j]);
        addch('|'); for(j=i;t[j];j++) addch(t[j]);

//      printw("\n\n> key %d pressed",c); // debug

        c = getch(); // read next char

        switch(c)
        {
            case KEY_LEFT: // left arrow; cursor left
            if(i > 0) i--;
            break;

            case KEY_RIGHT: // right arrow; cursor right
            if(i < s) i++;
            break;

            case 8: // backspace; remove previous char
            case 127:
            case KEY_BACKSPACE:
            if(i > 0)
            {
                for(k=i-1; k<s; k++) t[k]=t[k+1];
                i--;s--;
            }
            break;

            case KEY_DC: // delete; remove next char
            if(i < s)
            {
                for(k=i; k<s; k++) t[k]=t[k+1];
                s--;
            }
            break;

            default: // none of the above

            if(c > 31 && c < 127) // printable char
            {
                for(k=s; k>i; k--) t[k]=t[k-1];
                t[i] = c;i++;s++;
            }
        }

        clear(); // clear screen
        if(c == 10) break;
    }
    while(c);

    addch('\n');
    printw(t); // print final result
    getch(); // wait for any input
    endwin();
    return 0;
}
