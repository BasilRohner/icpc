#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<ll> vll;
typedef vector<vll> vvll;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int, int> ii;
typedef vector<ii> vii;

#define rvi(v) for (int &i : v) scanf("%d",i);
#define rvl(v) for (ll &i : v) scanf("%d",i); 

template<typename T>
void karp(vector<vector<T>> g) {

}

template<typename T>
void scc(vector<vector<T>> g) {

}

template<typename T>
void art(vector<vector<T>> g) {

}

template<typename T>
void lca(vector<vector<T>> g) {

}

template<typename T, typename C>
void maxflow(vector<vector<T>> g, vector<vector<C>> c) {

}

template<typename T, typename C>
void mincut(vector<vector<T>> g, vector<vector<C>> c) {

}

template<typename T, typename C>
void hld(vector<vector<T>> g) {
    
}

void dfs_pss(int v = 0) {
    sz[v] = 1;
    for(auto &u: g[v]) {
        dfs_pss(u);
        sz[v] += sz[u];
        if(sz[u] > sz[g[v][0]]) {
            swap(u, g[v][0]);
        }
    }
}

void dfs_hld(int v = 0) {
    in[v] = t++;
    for(auto u: g[v]) {
        nxt[u] = (u == g[v][0] ? nxt[v] : u);
        dfs_hld(u);
    }
    out[v] = t;
}s