#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector<ll> vll;
typedef vector<vll> vvll;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int, int> ii;
typedef vector<ii> vii;

template<typename T> T gcd(T a, T b) { return b?gcd(b,a%b):a; }
template<typename T> T lcm(T a, T b) { return a*b/gcd(a,b); }

#define rvi(a) for (int i = 0; i < a.size(); i++) scanf("%d",&a[i]);
#define rvl(a) for (int i = 0; i < a.size(); i++) scanf("%lld",&a[i]);
#define rvd(a) for (int i = 0; i < a.size(); i++) scanf("%llf",&a[i]);
#define all(a) a.begin(), a.end();

#define wy printf("YES\n");
#define wn printf("NO\n");

template<typename T> T binexp(T b, T e, ll m = 100000007) {
    T res=1; for (;e;b=b*b%m,e/=2)
        if (e&1) res = res*b%m;
    return res;
}

template<typename T> T modinv(T b, ll m = 100000007) { return binexp(b,m-2,m); }

/* Template End Here */

void solve() {

}

int main() {
    int n; scanf("%d",&n);
    while (n--) solve();
}