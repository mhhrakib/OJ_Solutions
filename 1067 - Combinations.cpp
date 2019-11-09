#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod = 1000003, maxn = 1e6;
ll fact[maxn];

void init() {
    fact[0] = 1;
    for(int i = 1; i <= maxn; i++)
        fact[i] = fact[i-1] * i % mod;
}

ll egcd(ll a, ll b, ll &x, ll &y) {
    if(a == 0) {
        x = 0, y = 1;
        return b;
    }

    ll x1, y1;
    ll d = egcd(b%a, a, x1, y1);
    x = y1 - (b/a) * x1;
    y = x1;
    return d;
}

ll inverse(ll a) {
    ll x, y;
    ll gcd = egcd(a, mod, x, y);
    if (gcd != 1)
        return -1; // No solution
    else {
        x = (x % mod + mod) % mod;
        return x;
    }
}

ll binpow(ll a, ll b, ll m) {
    a %= m;
    ll res = 1;
    while (b > 0) {
        if (b & 1)
            res = res * a % m;
        a = a * a % m;
        b >>= 1;
    }
    return res;
}

ll inverse2(ll b) {
    return binpow(b, mod-2, mod);
}

ll nckmod(ll n, ll k) {
    return fact[n] * inverse2(fact[k]) % mod * inverse2(fact[n - k]) % mod;
}


int main() {
    init();
    int t, cs = 0;
    ll n, k;
    scanf("%d", &t);
    while(t--) {
        scanf("%lld %lld", &n, &k);
        printf("Case %d: %lld\n", ++cs, nckmod(n, k));
    }
    return 0;
}
