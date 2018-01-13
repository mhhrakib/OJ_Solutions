#include<cmath>
#include<cstdio>
int main()
{
    double c = 4.0 - acos(-1.0),r;
    int t,i;
    scanf("%d",&t);
    for(i = 1; i<=t; i++) {
        scanf("%lf",&r);
        printf("Case %d: %.2f\n",i, r*r*c + 0.000000001);
    }
}
