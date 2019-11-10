#include<bits/stdc++.h>
using namespace std;

double x, y, c;

double foo(double w) {
    double h1, h2;
    h1 = sqrt(x * x - w * w);
    h2 = sqrt(y * y - w * w);
    return (h1 * h2)/(h1 + h2);
}

double solve(int cs) {
    int cnt = 100;
    double lo, hi, mid;
    lo = 0.0, hi = min(x,y);

    while(cnt--) {
        mid = (lo + hi)/2;
        if(foo(mid) <= c)
            hi = mid;
        else
            lo = mid;
    }

    printf("Case %d: %.10lf\n", cs, mid);
}

int main() {
    int t;
    scanf("%d", &t);
    for(int i = 1; i<=t; i++) {
        scanf("%lf %lf %lf", &x, &y, &c);
        solve(i);
    }
}
