#include<bits/stdc++.h>
using namespace std;

#define ll long long

struct HashSolve {
  ll n, base, mod, pow[500005], hs[500005], hs_rev[500005];
  string s;

  void init(ll _n, string _s, ll _base, ll _mod) {
    n = _n;
    s = _s;
    base = _base;
    mod = _mod;
    memset(hs, 0, sizeof hs);
    memset(hs_rev, 0, sizeof hs_rev);
    memset(pow, 0, sizeof pow);
    pow[0] = 1;
    for (int i = 1; i <= n; i++) {
      pow[i] = pow[i - 1] * base % mod;
    }
    for (int i = 1; i <= n; i++) {
      hs[i] = (hs[i - 1] * base + s[i]) % mod;
    }
    for (int i = n; i >= 1; i--) {
      hs_rev[i] = (hs_rev[i + 1] * base + s[i]) % mod;
    }
  }

  ll getHas(int l, int r) {
    return (hs[r] - hs[l - 1] * pow[r - l + 1] + mod * mod) % mod;
  }

  ll getHasRev(int l, int r) {
    return (hs_rev[l] - hs_rev[r + 1] * pow[r - l + 1] + mod * mod) % mod;
  }
} p[2];


int main() {
  int n = 1;
  string s = " a";
  p[0].init(n, s, 311, 1e9 + 7);
//   401 409 419 421 431 433 439 443 449 457
// 1000000007 1000000009 1000000021 1000000033 1000000087 1000000093 1000000097 1000000103 1000000123 1000000181
  return 0;
}
