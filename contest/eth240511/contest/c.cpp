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

void solve() {
    int k; scanf("%d",&k);
}

int main() {
    int n,m; scanf("%d %d",&n,&m);
    ll result = 0;
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            for (int k = i+1; k < m; k++) {
                for (int l = j+1; l < n; l++) {
                    result++;
                }
            }
        }
    }

    printf("%lld\n",result);
}