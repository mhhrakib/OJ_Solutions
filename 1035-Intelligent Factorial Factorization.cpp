#include<bits/stdc++.h>
using namespace std;

int primes[] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29,
                31, 37, 41, 43, 47, 53, 59, 61, 67,
                71, 73, 79, 83, 89, 97};

void solve (int n) {
    vector <pair <int, int> > base_exp;
    for(int i = 0; i < 25; i++) {
        int base = primes[i], exp = 0, num;
        if(base > n)
            break;
        for(int j = base; j <= n; j += base) {
            num = j;
            while(num % base == 0) {
                num /= base;
                exp++;
            }
        }
        if(exp)
            base_exp.push_back(make_pair(base, exp));
    }

    int sz = base_exp.size();
    printf("%d = %d (%d)", n, base_exp[0].first, base_exp[0].second);

    for(int i = 1; i < sz; i++) {
        printf(" * %d (%d)", base_exp[i].first, base_exp[i].second);
    }
    puts("");

}

int main()
{
    int t, n, cs = 0;
    scanf("%d", &t);
    while(t--) {
        scanf("%d", &n);
        printf("Case %d: ", ++cs);
        solve(n);
    }
    return 0;
}
