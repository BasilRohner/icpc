#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<ll> vll;
typedef vector<int> vi;
typedef vector<vll> vvll;
typedef vector<vi> vvi;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<bool> vb;
typedef vector<vb> vvb;
typedef vector<double> vd;
typedef vector<vd> vvd;

template<typename A, typename B> inline ostream& operator<< (ostream& out, const pair<A, B>& p) { return out << p.first << " " << p.second << "\n"; }
template<typename T> inline ostream& operator<< (ostream& out, const vector<T>& a) { for (int i = 0; i < a.size(); i++) out << a[i] << ' '; return out; }
template<typename T> inline ostream& operator<< (ostream& out, const vector<vector<T> >& a) { for (int i = 0 ; i < a.size(); i++) out << a[i] << '\n'; return out; }

template<typename A, typename B> inline istream& operator>> (istream& in, const pair<A, B>& a) { cin >> a.first >> a.second; }
template<typename T> inline istream& operator>> (istream& in, const vector<T>& a) { for (int i = 0; i < a.size(); i++) cin >> a[i]; }
template<typename T> inline istream& operator>> (istream& in, const vector<vector<T> >& a) { for (int i = 0; i < a.size(); i++) cin >> a[i]; }

template<typename T> inline T gcd(T a, T b) { return b ? gcd(b,a%b) : a; }
template<typename T> inline T lcm(T a, T b) { return a * b / gcd(a,b); }
template<typename T> inline T binpow(T b, T e) { T r = 1; for (; e; e >>= 1) { if (e&1) r *= b; b *= b; } return r; }
template<typename T> inline T modpow(T b, T e, ll m) { T r = 1; for (; e; e >>=1 ) { if (e&1) r = r * b % m; b = b * b % m; } return r; }
template<typename T> inline T modinv(T a, ll m) { return modpow(a, m-2, m); }

void solve() {
    int n;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while (t--)
        solve();
}
