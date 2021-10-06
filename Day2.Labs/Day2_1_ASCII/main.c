#include <stdio.h>
#include <stdlib.h>

int main()
{
    printf("Please Enter Char:");
    char ch = 'a' ;

    while (ch !=27)
    {
    ch = getchar();
    printf(" The ASCII of the char %c is %i \n", ch, ch);

    }

return 0;
}
