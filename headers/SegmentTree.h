#include <iostream>
#include <vector>

using namespace std;

template<typename T = int>
struct SegmentTree {

    vector<T> t; int n; T u; function<T(T,T)> f;
    
    SegmentTree(int n = 0, T u, function<T(T,T)> f) : t(n<<1), n(n), u(u), f(f) {}
    void update(int p, T v) {
        for (t[p += n] = v; p /= 2;)
            t[p] = f(t[p<<1], t[p<<2|1]);     
    }
    T query(int l, int r) {
        T a = u; T b = u;
        for (l += n, r += n; l < r; l >>= 1, r >>= 1) {
            if (l%2) a = f(a,t[l++]);
            if (r%2) b = f(t[--r],b);
        } return f(a,b);
    }
};