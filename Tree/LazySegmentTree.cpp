struct SegMentTreeLazy { //sum
  ll n, a[100005], seg[4 * 100005], lazy[4 * 100005];

  void init(int _n) {
    n = _n;
  }

  void down(int id){
    lazy[id << 1] += lazy[id];
    lazy[id << 1 | 1] += lazy[id];
    lazy[id] = 0;
  }

  void upd(int id, int l, int r, int u, int v, int k){
    seg[id] += (r - l + 1) * lazy[id];
    down(id);
    if(l > v || r < u) return;
    if(u <= l && r <= v){
      seg[id] += (r - l + 1) * k;
      lazy[id << 1] += k;
      lazy[id << 1 | 1] += k;
      return;
    }

    int mid = (l + r) >> 1;
    upd(id << 1, l, mid, u, v, k);
    upd(id << 1 | 1, mid + 1, r, u, v, k);
    seg[id] = seg[id << 1] + seg[id << 1 | 1];

  }
  ll get(int id, int l, int r, int u, int v){
    seg[id] += (r - l + 1) * lazy[id];
    down(id);
    if (l > v || r < u) return 0;
    if(u <= l && r <= v){
        return seg[id];
    }
    ll mid=(l+r)>>1;
    return get(id << 1, l, mid, u, v) + get(id << 1 | 1, mid + 1, r, u, v);
  }
} tree;
