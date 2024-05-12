#include <bits/stdc++.h>

using namespace std;

vector<vector<int> > graph;
stack<int> pa;
bool change = true;

void dfs(int target, int current, int parent){
    if (change){
        pa.push(current);
    }
    if (current == target){
        change = false;
        return;
    }
    else {
        vector<int> neighbors = graph[current];
        for (int neighbor : neighbors){
            if (neighbor != parent){
                dfs(target, neighbor, current);
            }
        }
    }
    if (change){
        pa.pop();
    }
}

int main(){
    int mod = 998244353;
    int n, q; cin >> n >> q;
    for (int i = 0; i < n; i++){
        graph.push_back(vector<int>());
    }

    for (int i = 0; i < n - 1; i++){
        int u, v; cin >> u >> v;
        u--; v--;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    for (int i = 0; i < q; i++){
        int a, b; cin >> a >> b; a--; b--;
        change = true;
        dfs(b, a, -1);
        int res = -1;
        while (!pa.empty()){
            int t = pa.top();
            // cout << "node: " << t << "\n";
            pa.pop();
            if (t == b){
                continue;
            }
            else if (t == a) {
                if (res == -1){
                    res = graph[a].size() % mod;
                }
                else {
                    res = (res * (graph[a].size() % mod)) % mod;
                }
            }
            else {
                if (res == -1){
                    res = (graph[t].size() - 1) % mod;
                }
                else {
                    res = (res * ((graph[t].size() - 1) % mod)) % mod;
                }
            }
        }

        cout << res << "\n";
    }
    return 0;

}