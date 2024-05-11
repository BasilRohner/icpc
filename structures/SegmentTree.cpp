#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<ll> vll;
typedef vector<vll> vvll;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int, int> ii;
typedef vector<ii> vii;

struct SegmentTree {
  int n;
  vector<Value> tree;

  SegmentTree(int min_n)
    : n(next_power_of_two(min_n)),
      tree(2*n, identity_value()) {}

  Value query(int l, int r) {
    assert(0 <= l && l < r && r <= n);
    return query_(l, r, 1, 0, n);
  }

  void update(int l, int r, Update a) {
    assert(r - l == 1); // only allow element updates (for now)
    assert(0 <= l && l < r && r <= n);
    return update_(a, l, r, 1, 0, n);
  }

private:

  void apply(int pos, Update a) {
    tree[pos] = apply_update(a, tree[pos]);
  }

  void recompute(int pos) {
    tree[pos] = combine(tree[2*pos], tree[2*pos+1]);
  }

  Value query_(int ql, int qr, int pos, int l, int r) {
    if (ql <= l && r <= qr) { return tree[pos]; }
    if (qr <= l || r <= ql) { return identity_value(); }
    int m = (l+r)/2;
    Value ans_l = query_(ql, qr, 2*pos, l, m);
    Value ans_r = query_(ql, qr, 2*pos+1, m, r);
    return combine(ans_l, ans_r);
  }

  void update_(Update a, int ql, int qr, int pos, int l, int r) {
    if (ql <= l && r <= qr) { apply(pos, a); return; }
    if (qr <= l || r <= ql) { return; }
    int m = (l+r)/2;
    update_(a, ql, qr, 2*pos, l, m);
    update_(a, ql, qr, 2*pos+1, m, r);
    recompute(pos); 
  }
};

struct LazySegment {

  int n;
  vector<Value> tree;
  vector<Update> lazy;

  LazySegment(int min_n)
    : n(next_power_of_two(min_n)),
      tree(2*n, identity_value()),
      lazy(2*n, identity_update()) {}

  LazySegment(vector<Value> const& base)
    : n(next_power_of_two(base.size())),
      tree(2*n, identity_value()),
      lazy(2*n, identity_update()) {
    for (int i=0; i< base.size(); ++i)
      tree[n+i] = base[i];
    build(1, 0, n);
  }

  Value query(int l, int r) {
    if (ql <= l && r <= qr) { return t[pos]; }
    if (qr <= l || r <= ql) { return identity_value(); }
    propagate(pos);
    int m = (l+r)/2;
    Value ans_l = query_(ql, qr, 2*pos, l, m);
    Value ans_r = query_(ql, qr, 2*pos+1, m, r);
    return combine(ans_l, ans_r);
  }

  void update(int l, int r, Update a) {
    assert(0 <= l && l < r && r <= n);
    return update_(a, l, r, 1, 0, n);
  }

private:

  void apply(int pos, Update a) {
    tree[pos] = apply_update(a, tree[pos]);
    lazy[pos] = combine_updates(a, lazy[pos]);
  }

  void recompute(int pos) {
    tree[pos] = combine(tree[2*pos], tree[2*pos+1]);
  }

  void propagate(int pos) {
    apply(2*pos, lazy[pos]);
    apply(2*pos+1, lazy[pos]);
    lazy[pos] = identity_update();
  }

  void build(int pos, int l, int r){
    if (r - l == 1) return;
    int m = (l+r)/2;
    build(2*pos, l, m);
    build(2*pos+1, m, r);
    recompute(pos);
  }

  Value query_(int ql, int qr, int pos, int l, int r) {
    if (ql <= l && r <= qr) { return tree[pos]; }
    if (qr <= l || r <= ql) { return identity_value(); }
    propagate(pos);
    int m = (l+r)/2;
    Value ans_l = query_(ql, qr, 2*pos, l, m);
    Value ans_r = query_(ql, qr, 2*pos+1, m, r);
    return combine(ans_l, ans_r);
  }

  void update_(Update a, int ql, int qr, int pos, int l, int r) {
    if (ql <= l && r <= qr) { apply(pos, a); return; }
    if (qr <= l || r <= ql) { return; }
    propagate(pos);
    int m = (l+r)/2;
    update_(a, ql, qr, 2*pos, l, m);
    update_(a, ql, qr, 2*pos+1, m, r);
    recompute(pos);
  }
};

class PersistentSegment {

}

class SparseSegment {

}

class SegmentBeats {
    
}