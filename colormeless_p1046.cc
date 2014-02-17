#include <iostream>
#include <cstdio>
#include <climits>
#include <cmath>
#include <vector>
using namespace std;

struct Point
{
    int x;
    int y;
    int z;
};

int main()
{
    vector<struct Point> points;
    struct Point pt;
    int i = 0;
    while(i < 16)
    {
        i++;
        cin >> pt.x;
        cin >> pt.y;
        cin >> pt.z;
        points.push_back(pt);
    }
    while(1)
    {
        cin >> pt.x;
        cin >> pt.y;
        cin >> pt.z;
        if(pt.x == -1) break;
        int dist = 0, minDist = INT_MAX, cnt = 0;
        vector<struct Point>::const_iterator pts_itr = points.begin();
        for(int i = 0 ; pts_itr != points.end(); pts_itr++, i++)
        {
            dist = (pt.x-(*pts_itr).x) * (pt.x-(*pts_itr).x) + (pt.y-(*pts_itr).y) * (pt.y-(*pts_itr).y) + (pt.z-(*pts_itr).z) * (pt.z-(*pts_itr).z);
            if(dist < minDist)
            {
                cnt = i;
                minDist = dist;
            }
        }
            cout << "("<<pt.x<<","<<pt.y<<","<<pt.z<<") maps to ("<< points[cnt].x << "," << points[cnt].y << "," << points[cnt].z <<")"<< endl;
    }
    return 0;
}
