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

void solve() {
}

int main() {
    string str; cin >> str;
    bool v = false;
    bool i = false;
    for (char c : str) {
        if (c == 'v')
            v = true;
        if (v && c == 'i')
            i = true;
        if (v && i && c=='s') {
            printf("YES\n");
            return 0;
        }
        
    }
    printf("NO\n");
        return 0;
}