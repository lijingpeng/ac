#include <stdio.h>
int main ()
{
    int place, sum = 0, ans = -1, i;
    char ar[11];
    scanf("%s", ar);
    for (i = 0; i < 10; i++)
    {
        if (ar[i] == '?') place = i;
        else if (ar[i] == 'X') sum += 10 * (10 - i);
        else sum += (ar[i] - 48) * (10 - i);
    }
    for (i = 0; i <= (place == 9 ? 10 : 9); i++)
    {
        if ((sum + i * (10 - place)) % 11 == 0)
        {
            ans = i;
            break;
        }
    }
    if (ans == 10) printf("X\n");
    else printf("%d\n", ans);
    return 0;
}
