#include <bits/stdc++.h>
using namespace std;

template<typename T>
struct FenwickTree {

    vector<T> bit; 
    int n;
    const T ne = 0;
    function op = [] (T a, T b) { return a+b; };

    FenwickTree(int n) {
        this->n = n;
        bit.assign(n, ne);
    }

    FenwickTree(vector<T> const &a) : FenwickTree(a.size()) {
            modify(i, a[i]);
    }

    T query(int idx) {
        int ret = 0;
        for (++idx; idx > 0; idx -= idx & -idx)
            ret = op(ret, bit[idx]);
        return ret;
    }

    T query(int l, int r) {
        return query(r) - query(l - 1);
    }

    void modify(int idx, int delta) {
        for (++idx; idx < n; idx += idx & -idx)
            bit[idx] = op(bit[idx], delta);
    }

};