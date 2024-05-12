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
const ll MOD = 1e7+7;

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

int main() {
    int n; scanf("%d",&n);
    vector<vector<int> > graph(n);
    for (int i = 0; i < n-1; i++) {
        int a,b; scanf("%d %d",&a,&b);
        graph[b-1].push_back(a-1);
        graph[a-1].push_back(b-1);
    }

    ll result = n-1;
    result %= 1000000007;
    for (int i = 0; i < n; i++) {
        result += binpow(2,graph[i].size(),1000000007)-graph[i].size()-1;
        result %= 1000000007;
    } result %= 1000000007;
    printf("%lld\n",result);

}