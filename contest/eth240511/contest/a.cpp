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
const ll MOD = 998244353;

#define rvi(a) for (int i = 0; i < a.size(); i++) scanf("%d",&a[i]);
#define rvl(a) for (int i = 0; i < a.size(); i++) scanf("%lld",&a[i]);
#define rvd(a) for (int i = 0; i < a.size(); i++) scanf("%llf",&a[i]);

vector<vector<int> > graph;

vector<int> path;
bool sa = false;

void dfs(int source, int target, int current, int parent){
    if (current == target){
        sa = true;
        path.push_back(current);
    }
}

int main() {
    int n, q; cin >> n >> q;
    

    for (int i = 0; i < n; i++){
        graph.push_back(vector<int>());
    }

    for (int i = 0; i < n - 1; i++){
        int u, v; cin >> u >> v;
        u--;v--;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    for (int i = 0; i < q; i++){
        int a, b; cin >> a >> b;
        sa = false;

        
    }
    return 0;
}