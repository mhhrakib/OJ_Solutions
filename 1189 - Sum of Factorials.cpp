#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll fact [] = {1, 1, 2, 6, 24, 120, 720, 5040, 40320, 362880, 3628800, 39916800, 479001600,6227020800,
      87178291200,1307674368000, 20922789888000, 355687428096000,6402373705728000, 121645100408832000};
void foo(ll n)
{
    int cnt = 19, flag = 0;
    stack < int > stk;
    while (cnt >= 0) {
        if(n >= fact[cnt]) {
            n -= fact[cnt];
            stk.push(cnt);
        }
        if(n == 0) {
            flag = 1;
            break;
        }
        cnt--;
    }
    
    if(!flag) {
        printf("impossible\n");
        return;
    }
    
    while(stk.size()>1) {
        int f = stk.top();
        printf("%d!+",f);
        stk.pop();
    }
    printf("%d!\n",stk.top());
}

int main()
{
    int t;
    ll n;
    scanf("%d",&t);
    for(int i = 1; i<=t; i++) {
        scanf("%lld",&n);
        printf("Case %d: ",i);
        foo(n);        
    }
}
