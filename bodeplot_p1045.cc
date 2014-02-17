#include <iostream>
#include <cstdio>
#include <cmath>
using namespace std;

int main()
{
    int n;
    double r,c,w,vs;
    scanf("%lf%lf%lf%d", &vs, &r, &c, &n);
    while(n--)
    {
        scanf("%lf", &w);
        printf("%.3f\n", r*c*w*vs*sqrt( 1/(r*r*c*c*w*w+1) ));
    }

    return 0;
}
