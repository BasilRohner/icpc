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

    int n; scanf("%d",&n);
    stack<int> a;
    stack<int> b;
    stack<int> c;
    for (int i = 0; i < n; i++) {
        int x; scanf("%d",&x);
        a.push(x);
    }

    vector<string> str;

    while (!a.empty()) {
        if (b.empty() && a.top() == 1) {
            str.push_back("A C");
            b.push(a.top());
            a.pop();
        } 
        else if (b.empty()) {
            str.push_back("A B");
            c.push(a.top());
            a.pop();
        }
        else if (a.top() != b.top() + 1) {
            str.push_back("A B");
            c.push(a.top());
            a.pop();
        }
        else {
            str.push_back("A C");
            b.push(a.top());
            a.pop();
        }
    }

    while (!c.empty()) {
        if (c.top() != b.top()+1) {
            printf("-1\n");
            return 0;
        }
        else {
            str.push_back("B C");
            b.push(c.top());
            b.pop();
        }
    }

    for (string s : str) {
        cout << s << '\n';
    }
}