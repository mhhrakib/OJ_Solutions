#include<math.h>
#include<stdio.h>
int main()
{
    int t,i;
    scanf("%d",&t);
    double r1,r2,r3,a,b,c,A,B,C,area,x,y,z,pi = 2.0*acos(0.0),A1,A2,A3;
    for(i = 1; i<=t; i++) {
        scanf("%lf %lf %lf",&r1,&r2,&r3);
        a = r1 + r2;
        b = r2 + r3;
        c = r3 + r1;
        x = a*a; y = b*b; z = c*c;
        //printf("%lf %lf %lf\n",x,y,z);
        A = acos((y + z - x)/ (2*b*c));
        B = acos((z + x - y)/(2*c*a));
        C =  pi - (A+B);
        //printf("%lf %lf %lf\n",A,B,C);
        double areaOfTriangle = 0.5*b*c*sin(A);
        //printf("%lf\n",areaOfTriangle);
        A1 = 0.5*r1*r1*B, A2 = 0.5*r3*r3*A, A3 = 0.5*r2*r2*C;
        //printf("%lf %lf %lf\n",A1,A2,A3);
        double areaOfSectors = A1 + A2 + A3;
        //printf("%lf\n",areaOfSectors );
        area = areaOfTriangle - areaOfSectors;
        printf("Case %d: %.7f\n",i, area);
    }
}
