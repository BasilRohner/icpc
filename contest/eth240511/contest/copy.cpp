// C++ implementation
#include <bits/stdc++.h>
using namespace std;
 
// An utility function to add an edge in an
// undirected graph.
void addEdge(vector<int> v[],
             int x,
             int y)
{
    v[x].push_back(y);
    v[y].push_back(x);
}
 
// A function to print the path between
// the given pair of nodes.
// void printPath(vector<int> stack)
// {
//     int i;
//     for (i = 0; i < (int)stack.size() - 1;
//          i++) {
//         cout << stack[i] << " -> ";
//     }
//     cout << stack[i];
// }
 
// An utility function to do
// DFS of graph recursively
// from a given vertex x.
void DFS(vector<int> v[],
         bool vis[],
         int x,
         int y,
         vector<int> stack)
{
    stack.push_back(x);
    if (x == y) {
 
        // print the path and return on
        // reaching the destination node
        // printPath(stack);
        return;
    }
    vis[x] = true;
 
    // if backtracking is taking place
    if (!v[x].empty()) {
        for (int j = 0; j < v[x].size(); j++) {
            // if the node is not visited
            if (vis[v[x][j]] == false)
                DFS(v, vis, v[x][j], y, stack);
        }
    }
 
    stack.pop_back();
}
 
// A utility function to initialise
// visited for the node and call
// DFS function for a given vertex x.
void DFSCall(int x,
             int y,
             vector<int> v[],
             int n,
             vector<int> stack)
{
    // visited array
    bool vis[n + 1];
 
    memset(vis, false, sizeof(vis));
 
    // DFS function call
    DFS(v, vis, x, y, stack);
}
 
// Driver Code
int main()
{
    int mod = 998244353;
    int n; cin >> n; n++;
    int q; cin >> q;
    vector<int> v[n], stack;

    for (int i = 0; i < n - 1; i++){
        int u, r; cin >> u >> r;
        addEdge(v, u, r);
    }

    for (int i = 0; i < q; i++){
        int a, b; cin >> a >> b;
        DFSCall(a, b, v, n, stack);

        int res = stack[0] % mod;

        for (i = 1; i < (int)stack.size() - 1; i++) {

            res = (res * (stack[i] % mod)) % mod;
        }
        cout << res << "\n";
    }
 
    return 0;
}