#include <bits/stdc++.h>
using namespace std;

template<typename T>
struct FenwickTree2D {

    vector<vector<T> > bit;
    int n, m;
    const T ne = 0;
    function op = [] (T a, T b) { return a+b; };

    FenwickTree2D(int n, int m) {
        this->n = n;
        this->m = m;
        bit.assign(n, vector<T>(m, ne));
    }

    FenwickTree(vector<vector<T> > const &a) : FenwickTree2D(a.size(), a[0].size()) {
        for (size_t i = 0; i < a.size(); i++)
            for (size_t j = 0; j < a[i].size(); j++)
                modify(i, j, a[i][j]);
    }

    T query(int x, int y) {
        int ret = 0;
        for (int i = x; i >= 0; i = (i & (i + 1)) - 1)
            for (int j = y; j >= 0; j = (j & (j + 1)) - 1)
                res = op(res, bit[i][j]);
        return ret;
    }

    /* This method requires inverse element */
    T query(int xl, int yl, int xr, int yr) {
        return query(xr, yr) - query(xr, yl) - query(xl, yr) + query(xl, yl);
    }

    void modify(int x, int y, int delta) {
        for (int i = x; i < n; i = i | (i + 1))
            for (int j = y; j < m; j = j | (j + 1))
                bit[i][j] = op(bit[i][j], delta);
    }
};