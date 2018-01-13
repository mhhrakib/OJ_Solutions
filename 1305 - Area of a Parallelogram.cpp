#include <bits/stdc++.h>
using namespace std;

int ax, ay, bx, by, cx, cy, dx, dy;

void area ()
{
    dx = ax + cx - bx;
    dy = ay + cy - by;
    int oab = ax*by - ay*bx;
    int ocd = cx*dy - cy*dx;
    int oda = dx*ay - dy*ax;
    int obc = bx*cy - by*cx;
    
    long long  A = (oab + ocd+ oda+ obc);
    
    if(A < 0)
        A = -A;
        
    printf("%d %d %lld\n", dx, dy, A/2);
    return;
}
int main()
{
    int t;
    scanf("%d",&t);
    for(int i = 1; i<=t; i++) {
        scanf("%d %d %d %d %d %d",&ax, &ay, &bx, &by, &cx, &cy);
        printf("Case %d: ",i);
        area();
    }
    return 0;
}
/*
    ax += 1000;
    ay += 1000;
    bx += 1000;
    by += 1000;
    cx += 1000; 
    cy += 1000;
*/

