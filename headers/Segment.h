#include <iostream>
using namespace std;

struct SegmentTree {
    
    typedef int T;
    static constexpr T u = -1e5;
    T f(T a, T b) { return max(a,b); }
    vector<T> t; int n;
    SegmentTree(int n = 0) : t(n<<1, u), n(n) {}

    void modify(int i, T v) {
        for (t[i += n] = v; i >>= 1;)
            t[i] = f(t[i<<1], t[i<<1|1]);
    }

    T query(int l, int r) {
        T a = u, b = u;
        for (l += n, r += n; l < r; l >>= 1, r >>= 1) {
            if (l%2) a = f(a,t[l++]);
            if (r%2) b = f(t[--l],b);
        } return f(a,b);
    }

};