#include<bits/stdc++.h>
using namespace std;

#define ll long long

ll n, mid1[500005], mid2[500005], res, openp[500005], closep[500005];
string s;

struct pairto() {
  ll vt,
};

struct HashSolve{
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

bool check_mid2(int st, int mid) {
  return p[0].getHas(st - mid + 1, st) == p[0].getHasRev(st + 1, st + mid)
  && p[1].getHas(st - mid + 1, st) == p[1].getHasRev(st + 1, st + mid) ;
}

bool check_mid1(int st, int mid) {
  return p[0].getHas(for (ll st = 1; st <= n; st++) {
    int l = 1, r = min(st, n - st + 1), tmp = 1;
    while (l <= r) {
      ll mid = (l + r) >> 1;
      if (check_mid1(st, mid)) {
        tmp = mid;
        l = mid + 1;
      }
      else r = mid - 1;
    }
    mid1[st] = tmp;
  }st - mid + 1, st) == p[0].getHasRev(st, st + mid - 1)
  && p[1].getHas(st - mid + 1, st) == p[1].getHasRev(st, st + mid - 1) ;
}

void init_mid() {
  p[0].init(n, s, 311, 1e9 + 7);
//  p[1].init(n, s,
  for (ll st = 1; st <= n; st++) {
    int l = 1, r = min(st, n - st + 1), tmp = 1;
    while (l <= r) {
      ll mid = (l + r) >> 1;
      if (check_mid1(st, mid)) {
        tmp = mid;
        l = mid + 1;
      }
      else r = mid - 1;
    }
    mid1[st] = tmp;
  }401, 1e9 + 103);

  for (ll st = 1; st <= n; st++) {
    int l = 1, r = min(st, n - st + 1), tmp = 1;
    while (l <= r) {
      ll mid = (l + r) >> 1;
      if (check_mid1(st, mid)) {
        tmp = mid;
        l = mid + 1;
      }
      else r = mid - 1;
    }
    mid1[st] = tmp;
  }

  for (ll st = 1 ; st < n; st++) {
    int l = 1, r = min(st, n - st), tmp = 0;
    while (l <= r) {
      ll mid = (l + r) >> 1;
      if (check_mid2(st, mid)) {
        tmp = mid;
        l = mid + 1;
      }
      else r = mid - 1;
    }
    mid2[st] = tmp;
  }
}


void init_arr() {
  for (int i = 1; i <= n; i++) {
    openp[i - mid1[i] + 1] = {mid1[i] , 1}
  }
}



void Solve(){
  cin >> n >> s;
  s = " " + s;
  init_mid();
  init_tree();
  for (int i = 1; i <= n; i++) cout << tree_open.get(1, 1, n, i, i) << " "; cout << endl;
  for (int i = 1; i <= n; i++) cout << tree_close.get(1, 1, n, i, i) << " "; cout << endl;
  for (int i = 1; i < n; i++) {
    ll  a = min(tree_close.get(1, 1, n, i, i), tree_open.get(1, 1, n, i + 1, i + 1));
    res += a;
    cout << tree_close.get(1, 1, n, i, i) <<" " << tree_open.get(1, 1, n, i + 1, i + 1) << " " << a << endl;
  }
  cout << res;
}


int main(){
    ios::sync_with_stdio(0);cin.tie(0);

    freopen("1.txt","r",stdin);
//    freopen("1.out","w",stdout);

    int Test_numbers=1;
//    cin>>Test_numbers;

    while(Test_numbers--) Solve();

	return 0;
}
