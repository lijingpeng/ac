#include <cstdio>  
#include <cmath>  
  
int main(void)  
{  
    double ka, acid;  
    int m, n;  
    while (scanf("%lf%lf%d%d", &ka, &acid, &m, &n), m)  
        printf("%.3f\n", -log10((-ka + sqrt(ka * ka + (m << 2) * n * acid * ka)) / (n << 1)));  
    return 0;  
}  
