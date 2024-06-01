//templ__b
//templ__str: Template
//templ__pref: templ
//templ__desc: std template
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

template<typename A, typename B> inline ostream& operator<< (ostream& out, const pair<A, B>& p) { return out << p.first << " " << p.second << "\n"; }
template<typename T> inline ostream& operator<< (ostream& out, const vector<T>& a) { for (int i = 0; i < a.size(); i++) { out << a[i] << ' '; } return out; }
template<typename A, typename B> inline ostream& operator>> (ostream& in, const pair<A, B>& a) { cin >> a.first >> a.second; }
template<typename T> inline ostream& operator>> (ostream& in, const vector<T>& a) { for (int i = 0; i < a.size(); i++) cin >> a[i]; }
template<typename T> inline ostream& operator>> (ostream& in, const vector<vector<T> >& a) { for (int i = 0; i < a.size(); i++) cin >> a[i]; }

template<typename T>
T gcd(T a, T b) { return (b ? gcd(b,a%b) : a); }
template<typename T>
T lcm(T a, T b) { return a*b/gcd(a,b); }


void solve() {
    int m, d; cin >> m >> d;
    if (d == 1 && m == 4)
        cout << "YES";
    else cout << "NO";
}  

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
}
//templ__e

//templ__b
//templ__str: DFS-Function
//templ__pref: dfs
//templ__desc: dfs implementation
struct DFS {

    vvi adj;

};
//templ__e

//templ__b
//templ__str: BFS-Function
//templ__pref: bfs
//templ__desc: bfs implementation
struct BFS {

    vvi adj;

};
//templ__e

//templ__b
//templ__str: LCA-Function
//templ__pref: lca
//templ__desc: lca implementation
struct LCA {

    vvi adj;

};
//templ__e

//templ__b
//templ__str: HLD-Function
//templ__pref: hld
//templ__desc: hld implementation
struct HLD {

    vvi adj;

};
//templ__e

//templ__b
//templ__str: Segment Tree
//templ__pref: segment
//templ__desc: Segment Tree implementation
struct SegmentTree {

    vvi adj;

};
//templ__e

//templ__b
//templ__str: Lazy Segment Tree
//templ__pref: lazysegment
//templ__desc: Lazy Segment Tree implementation
struct LazySegmentTree {

    vvi adj;

};
//templ__e

//templ__b
//templ__str: Fenwick Tree
//templ__pref: fenwick
//templ__desc: Fenwick Tree implementation
struct FenwickTree {

    vvi adj;

};
//templ__e

//templ__b
//templ__str: Trie
//templ__pref: trie
//templ__desc: Trie implementation
struct Trie {

    vvi adj;

};
//templ__e

//templ__b
//templ__str: Corasick
//templ__pref: corasick
//templ__desc: Corasick implementation
struct Corasick {

    vvi adj;

};
//templ__e


//templ__b
//templ__str: Z-Function
//templ__pref: zfunc
//templ__desc: Z-Function implementation
struct ZFunction {

    vvi adj;

};
//templ__e

//templ__b
//templ__str: String Hashing
//templ__pref: strhash
//templ__desc: String Hashing Implementation
struct StringHashing {

    vvi adj;

};
//templ__e

//templ__b
//templ__str: Hopcroft Karp
//templ__pref: hopcroft
//templ__desc: Hopcroft Karp Matching Implementation
struct HopcroftKarp {

    vvi adj;

};
//templ__e

//templ__b
//templ__str: Minimum Spanning Tree
//templ__pref: mst
//templ__desc: ...
struct MST {

    vvi adj;

};
//templ__e