#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl "\n"

ll a[505][505], n, m, l, pr[505][505];

ll get_seg(int tren, int trai, int duoi, int phai) {
  return pr[duoi][phai] - pr[tren - 1] [phai] - pr[duoi][trai - 1] + pr[tren - 1][trai - 1];
}

void Solve() {
  cin >> n >> m >> l;
  int k = (l - 1) / 2;
  for (int i = 1; i <= n; i++) for (int j = 1; j <= m; j++) {
    cin >> a[i][j];
    pr[i][j] = a[i][j] + pr[i - 1][j] + pr[i][j - 1] - pr[i - 1][j - 1];
  }
  for (int i = k + 1; i <= n - k; i++) {
    for (int j = k + 1; j <= m - k; j++) {
      ll res = get_seg(i - k, j - k, i + k, j + k) / (l * l);
      cout << res << " ";
    }

    cout << endl;
  }
//  cout << n << " " << m << " " << l << " " << k << endl;
}


int main() {
//  ios::sync_with_stdio(false); cin.tie(0);
//  freopen("1.txt", "r", stdin);
  freopen("1.inp", "r", stdin);
  freopen("1.dung", "w", stdout);
  int T = 1;
  cin >> T;
  while (T--) {
    Solve();
  }

  return 0;
}
