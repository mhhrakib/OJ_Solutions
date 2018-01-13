#include <cstdio>
#include <cmath>
#include <algorithm>  
using namespace std;

int main()
{
    //freopen("out.txt","w",stdout);
    long long int t,x1,y1,x2,y2,i,a,b;
    scanf("%lld",&t);
    for(i = 0; i<t; i++) {
        scanf("%lld %lld %lld %lld",&x1,&y1,&x2,&y2);
        a = abs(x1-x2);
        b = abs(y1-y2);
        printf("Case %lld: %lld\n",i+1,__gcd(a, b)+1);
    }
}
