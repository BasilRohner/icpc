#include <iostream>
#include <bits/stdc++.h>
using namespace std;

bool connected(vector<vector<int>> g) {
    queue<int> q; q.push(0);
    vector<bool> s; s[0] = true; int r = 1;
    while (!q.empty()) {
        int c = q.front(); q.pop();
        for (int v : g[c]) 
            if (!s[c]) {
                s[c] = true;
                q.push(c); r++;
            }
    } return r = g.size();
}