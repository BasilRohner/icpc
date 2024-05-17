#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector<ll> vll;
typedef vector<vll> vvll;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int, int> ii;
typedef vector<ii> vii;

const ll inf = 1e9;
const ll fni = -1e9;
const ll eps = 1e-9;

#define wb(b) printf(b?"yes\n":"no\n");
#define rvi(a) for (int i = 0; i < a.size(); i++) scanf("%d",&a[i]);
#define rvl(a) for (int i = 0; i < a.size(); i++) scanf("%lld",&a[i]);
#define rvd(a) for (int i = 0; i < a.size(); i++) scanf("%llf",&a[i]);
#define all(a) a.begin(), a.end();

ll bin(ll a, ll b) { ll r = 1; for (;b;a*=a,b>>=1) if (b&1) r*=a; return r; }
ll mod(ll a, ll b, ll m = 1e9+7) { ll r = 1; for (a%=m;b;a=a*a%m,b>>=1) if (b&1) r=r*a%m; return r; }
ll inv(ll a, ll m = 1e9+7) { return mod(a,m-2,m); }

void solve() {

}

int main() {
    int n; scanf("%d",&n);
    while (n--) solve();
}