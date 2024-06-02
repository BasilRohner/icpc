#include <bits/stdc++.h>
using namespace std;
typedef vector<int> vi;

const int N = 10000000;
vi lp(N+1);
vi pr;

void sieve() {
    for (int i=2; i <= N; ++i) {
        if (lp[i] == 0) {
            lp[i] = i;
            pr.push_back(i);
        }
        for (int j = 0; i * pr[j] <= N; ++j) {
            lp[i * pr[j]] = pr[j];
            if (pr[j] == lp[i]) 
                break;
        }
    }
}
