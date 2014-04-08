#include <stdio.h>
int main()
{
    char c;
    int sum = 0,pos = 1;
    while(1)
    {
        c = getchar();
        if(c == '#')
            break;
        else if (c == '\n')
        {
            printf("%d\n",sum);
            sum = 0;
            pos = 1;
            continue;
        }
        else
        {
            sum += (c == ' ') ? 0 : pos*(c - 'A' + 1);
            pos++;
        }
    }
    return 0;
}

