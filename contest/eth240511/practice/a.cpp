#include <iostream>
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector<ll> vll;
typedef vector<vll> vvll;
typedef pair<int, int> ii;
typedef vector<ii> vii;

#define INF = 1e9;
#define MINF = -1e9;
#define EPS = 1e-9;
#define MOD = 1e9+7;

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
    return res;
}

void solve() {
    ll a,b; cin >> a >> b;
    ll r = a * binpow(b,1e9+5,1e9+7);
    r %= 1000000007;
    printf("%lld\n",r);
}

int main() {
    int k; cin >> k;
    while (k--) {
        solve();
    }
}