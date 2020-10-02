// convex_hull_trick_min
struct convex_hull_trick {
  ll top = 0;
  ii z[maxn];
  bool del(ll i, ll j, ll k) {
    return 1.*(z[j].fi - z[i].fi) * (z[k].se - z[i].se) >= 1.*(z[k].fi - z[i].fi) * (z[j].se - z[i].se);
  }
  void add(ll a, ll b) {
    z[++top] = {a, b};
    while (top >= 3 && del(top - 2, top - 1, top)) {
      z[top - 1] = z[top];
      top--;
    }
  }
  ll query(ll x) {
    ll ans, l = 1, r = top;
    while (l < r) {
      ll mid = (l + r) / 2;
      ll p1 = z[mid].fi * x + z[mid].se;
      ll p2 = z[mid + 1].fi * x + z[mid + 1].se;
      if (p1 > p2) {
        l = mid + 1;
      }
      else {
        r = mid;
      }
    }
    return z[l].fi * x + z[l].se;
  }
} cht;