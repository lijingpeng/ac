#include <stdio.h>

int main()
{
    char ss[12][13] = {
    "",
    " ",
    "  ",
    "   ",
    "    ",
    "     ",
    "      ",
    "       ",
    "        ",
    "         ",
    "          ",
    "            "
    };
    char str[100000][21];
    scanf("%s", str[0]);
    printf("%s\n", str[0]);
    int i, com = 1, k = 1;
    while(scanf("%s", str[k++]) != EOF)
    {
        for(i = 0; i < com; i++)
        {
            if(str[k - 2][i] != str[k - 1][i])
            {
                com = i;
                break;
            }
        }

        com++;
               
        printf("%s%s\n", ss[com - 1], str[k - 1]);
    }

    return 0;
}
