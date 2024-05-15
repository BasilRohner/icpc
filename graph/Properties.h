#include <iostream>
#include <bits/stdc++.h>
using namespace std;

typedef vector<int> vi;
typedef vector<vi> vvi;

bool connected(vvi g) {
    queue<int> q; vector<bool> s(g.size()); int r = 1;
    q.push(0); s[0] = true;
    while (!q.empty()) {
        int c = q.front(); q.pop();
        for (int n : g.at(c)) 
            if (!s[n]) {
                s[n] = true;
                q.push(c); r++;
            }
    } return r == g.size();
}

int depth(vvi g) {
    queue<int> q; vector<bool> s(g.size()); int d = 0;
    q.push(0); s[0] = true;
    while (!q.empty()) {
        int sz = q.size(); d++;
        for (int i = 0; i < sz; i++) {
            int c = q.front(); q.pop();
            for (int n : g.at(c))
                if (!s[n]) {
                    s[n] = true;
                    q.push(c);
                }
        }
    } return d;
}

bool bipartite(vvi g) {
    queue<int> q; vector<int> s(g.size(), 0); int p = 1;
    q.push(0); s[0] = 1;
    while (!q.empty()) {
        int sz = q.size(); p *= -1;
        for (int i = 0; i < sz; i++) {
            int c = q.front(); q.pop();
            for (int n : g.at(c)) {
                if (!s[n]) {
                    s[n] = p;
                    q.push(n);
                } else if (s[n] != p) {
                    return false;
                }
            }
        }
    } return true;
} 

bool eulerian(vvi g) {
    int od = 0;
    for (vi v : g) od += v.size()&1;
    return connected(g) && (od <= 2);
}