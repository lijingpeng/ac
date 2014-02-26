#include <cstdio>
#include <cstdlib>
#include <cstring>

double arr[11000];

int main(void){
    int m, n, k;
    int i, j;
    double pm, pn;
    int flag; // 1 bullish trend ; 0 bearish trend

    while (scanf("%d%d%d", &m, &n, &k) != EOF){
        flag = -1;
        memset(arr, 0, sizeof(arr));
        pm = pn = 0;
        for (i = 0; i < k; i++){
            scanf("%lf", &arr[i]);
            if (i < m - 1){
                pm += arr[i];
            }
            else{
                pm -= arr[i - m];
                pm += arr[i];
            }
            if (i < n - 1){
                pn += arr[i];
            }
            else{
                pn -= arr[i - n];
                pn += arr[i];
                if (pm / m > pn / n && flag != 1){
                    printf("BUY ON DAY %d\n", i + 1);
                    flag = 1;
                }
                if (pm / m < pn / n && flag != 0){
                    printf("SELL ON DAY %d\n", i + 1);
                    flag = 0;
                }
            }
        }
    }
    return 0;
}

