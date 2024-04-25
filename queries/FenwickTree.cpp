#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<ll> vll;
typedef vector<vll> vvll;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int, int> ii;
typedef vector<ii> vii;

/*
 * Efficient range queries over arbitrary 2d indexed structures 
 * Operator for the range queries needs to be associative
 * Runtime bounds are as follows:
 * 
 * Generation:     n
 * Queries:        log n
 * Updates:        log n    
 */

struct Fenwick1d {

    public:

        vll bit; int n;

        Fenwick1d(vll &a) {
            n = a.size()+1;
            bit.assign(n+1, 0);
            for (int i = 0; i < n; i++) 
                insert(i, a[i]);
        }

        ll query(int idx) {
            ll res = 0;
            for (++idx; idx > 0; idx -= idx & -idx)
                res += bit[idx];
            return res;
        }

        void insert(int idx, ll delta) {
            for (++idx; idx < n; idx += idx & -idx)
                bit[idx] += delta;
        }

};

/*
 * Efficient range queries over arbitrary 2d indexed structures
 * Operator for the range queries needs to be associative
 * Runtime bounds are as follows:
 * 
 * Generation:     n^2
 * Queries:        log^2 n
 * Updates:        log^2 n
 */

struct Fenwick2d {

    public:

        vvll bit; int n,m;

        Fenwick2d(vvll &a) {
            n = a.size()+1;
            m = a.at(0).size()+1;
            bit.assign(n+1, vll(m+1, 0));
            for (int i = 0; i < n; i++) 
                for (int j = 0; j < m; j++)
                    insert(i,j,a[i][j]);
        }

        ll query(int i, int j) {
            ll res = 0;
            for (++i; i > 0; i -= i & -i)
                for (++j; j > 0; j -= j & -j)
                    res += bit[i][j];
            return res;
        }

        void insert(int i, int j, ll delta) {
            for (++i; i < n; i += i & -i)
                for (++j; j < m; j += j & -j)
                    bit[i][j] += delta;
        }

};