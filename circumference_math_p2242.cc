#include <iostream>
#include <cstdio>
#include <cmath>
using namespace std;
const double PI = 3.141592653589793;

double get_side_length(double x1, double y1, double x2, double y2)
{
    return sqrt( (x1-x2)*(x1-x2) + (y1-y2)*(y1-y2) );
}

//Helan formular S = sqrt(p*(p-a)*(p-b)*(p-c))  p=(a+b+c)/2;
double get_triangel_area(double a, double b, double c)
{
    double m = (a + b + c) / 2;
    return sqrt( m*(m - a)*(m - b)*(m - c) );
}

double get_triangel_diameter(double a, double b, double c, double area)
{
    return a*b*c/2/area;
}

int main()
{
    double x1,y1, x2,y2, x3,y3, a, b, c, area, dia;
    while(cin >>x1>>y1>>x2>>y2>>x3>>y3)
    {
        a = get_side_length(x1, y1, x2, y2);
        b = get_side_length(x2, y2, x3, y3);
        c = get_side_length(x1, y1, x3, y3);
        area = get_triangel_area(a, b, c);
        dia = get_triangel_diameter(a, b, c, area);
        printf("%.2lf\n", PI*dia);
    }
    return 0;
}
