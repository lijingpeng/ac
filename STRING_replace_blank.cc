#include <stdio.h>
#include <string.h>

void ReplaceBlank(char *s, int size)
{
    if(s == NULL || size <= 0)
        return;
    
    int i, j, blankCnt = 0, len = strlen(s);
    for(i = 0; i < len; ++i)
        if(s[i] == ' ')
            ++blankCnt;

    int total = len + blankCnt*2;
    if(total > size)
        return;

    for(i = len - 1, j = total - 1; i >= 0 && j >= i; --i)
    {
        if(s[i] != ' ')
        {
            s[j--] = s[i];
        }
        else
        {
            s[j--] = '0';
            s[j--] = '2';
            s[j--] = '%';
        }
    }
}

int main()
{
    char s[100];
    scanf("%[^\n]", s);

    ReplaceBlank(s, 100);
    printf("%s\n", s);
    return 0;
}
