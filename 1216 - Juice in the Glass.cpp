#include<cstdio>
#include<cmath>
const double pi =  3.14159265359;
int main()
{
    int r1,r2,h,p,t,i;
    double nr1,A;
    scanf("%d",&t);
    for(i = 1; i<=t; i++) {
        scanf("%d %d %d %d",&r1,&r2,&h,&p);
        nr1 = (((r1-r2+0.0)/h)*p)+r2;
        A = (p*pi*(nr1*nr1 + nr1*r2 + r2*r2)/3);
        printf("Case %d: %.7f\n",i,A);
    }
}
