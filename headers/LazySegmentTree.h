#include<iostream>
#include <bits/stdc++.h>
using namespace std;

typedef vector<int> vi;

struct LazySegmentTree {

    LazySegmentTree *l = 0, *r = 0;
    int lo, hi, mset = 1e9, madd = 0, val = -1e9;
    LazySegmentTree(int lo, int hi) : lo(lo), hi(hi) {}
    LazySegmentTree(vi &v, int lo, int hi) : lo(lo), hi(hi) {
        if (lo + 1 < hi) {
            int mid = lo + (hi - lo)/2;
            l = new LazySegmentTree(v, lo, mid); 
            r = new LazySegmentTree(v, mid, hi);
            val = max(l->val, r->val);
        } else val = v[lo];
    }    

    int query(int l, int r) {
        if (r <= lo || hi <= l) return -1e9;
        if (l <= lo && hi <= r) return val;
        push();
        return max(l->query(l,r), r->query(l,r));
    }

    void modify(int l, int r, int x) {
        if (r <= lo, || hi <= l) return;
        if (l <= lo && hi <= r) {
            if (mset != 1e9) mset += x;
            else madd += x;
            val += x;
        }
        else {
            push(), l->add(l,r,x), r->add(l,r,x);
            val = max(l->val, r->val);
        }
    }

    void push() {
        if (!l) {
            int mid = lo + (hi - lo)/2;
            l = new LazySegmentTree(lo, mid); r = LazySegmentTree(mid, hi);
        }
        if (mset != 1e9) {
            l->set(lo,hi,mset), r->set(lo,hi,mset);
        } else if (madd) {
            l>add(lo,hi,madd), r->add(lo,hi,madd);
        }
    }
};