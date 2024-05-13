#include <iostream>
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector<ll> vll;
typedef vector<vll> vvll;
typedef pair<int, int> ii;
typedef vector<ii> vii;

bool cmp(pair<ll, ll> a, pair<ll, ll> b) {
    if (a.first == b.first) {
        return a.second < b.second;
    } else {
        return a.first < b.first;
    }
}

void solve() {
    int n,m; scanf("%d %d",&n,&m);
    vll a(n); for (int i = 0; i < a.size(); i++) scanf("%lld",&a[i]);
    vll b(n); for (int i = 0; i < a.size(); i++) scanf("%lld",&b[i]);
    vector<pair<long, long> > p(n);
    for (int i = 0; i < n; i++) {
        p[i] = make_pair(a[i], b[i]);
    } sort(p.begin(), p.end(), cmp);

    set<ll> seen;
    int count = 0;
    while (true) {
        for (int i = 1; i <= m; i++) {
            int idx = lower_bound(p.begin(), p.end(), i) - p.begin();
            bool found = false;
            while (idx < n && p[idx].first == i) {
                if (seen.find(p[idx].second) != seen.end()) {
                    seen.insert(p[idx].second);
                    found = true;
                    break;
                }
            }
            if (!found) {
                printf("%d\n", count);
                return;
            }
        } count++;
    }
}

int main() {
    int n; scanf("%d",&n);
    for (int i = 0; i < n; i++)
        solve();
}