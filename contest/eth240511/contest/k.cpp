#include <iostream>
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector<ll> vll;
typedef vector<vll> vvll;
typedef pair<int, int> ii;
typedef vector<ii> vii;

const ll INF = 1e9;
const ll MINF = -1e9;
const ll EPS = 1e-9;
const ll MOD = 1000000007;

#define rvi(a) for (int i = 0; i < a.size(); i++) scanf("%d",&a[i]);
#define rvl(a) for (int i = 0; i < a.size(); i++) scanf("%lld",&a[i]);
#define rvd(a) for (int i = 0; i < a.size(); i++) scanf("%llf",&a[i]);

long long binpow(long long a, long long b, long long m) {
    a %= m;
    long long res = 1;
    while (b > 0) {
        if (b & 1)
            res = res * a % m;
        a = a * a % m;
        b >>= 1;
    }
    return res%m;
}

ll gcd(ll a, ll b)
{
    if (b==0)return a;
    return gcd(b, a % b);   
}

int main() {
    ll k,n; cin >> n >> k;
    ll a,b; cin >> a >> b;
    a %= MOD; b %= MOD;
    ll c = b - a;

    ll ck = binpow(c, k, MOD)%MOD;
    ll cn = binpow(c, n, MOD)%MOD;
    ll bn = binpow(b, n, MOD)%MOD;
    ll bk = binpow(b, k, MOD)%MOD;
    ll bnmincn = bn - cn;

    ll top = ck * bn % MOD;
    ll bot = (bk * bnmincn) % MOD;
    ll gcdd = gcd(bot, top);

    ll sol = ((top / gcdd)%MOD * binpow((bot / gcdd), MOD - 2, MOD))%MOD;
    // ll sol = (top * binpow(bot, MOD - 2, MOD))%MOD;
    // Geometrisch Verteilt
    cout << sol << endl;
    return 0;
}