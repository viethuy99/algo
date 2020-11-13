#include <bits/stdc++.h>

using namespace std;

const int maxn = 505;

long long a[505][505], res[505][505];
long long n, m, k;
long long l;


long long tinh_tong(int tren, int trai, int duoi, int phai) {
  return a[duoi][phai] - a[tren - 1] [phai] - a[duoi][trai - 1] + a[tren - 1][trai - 1];
}

long long calc(int x, int y)
{
  res[x][y] = tinh_tong(x-k, y-k, x+k, y+k);
}

void solve()
{
  for (int i = k+1; i <= n-k; i++)
    {
      for (int j=k+1; j <= m-k; j++)
      {
        calc(i, j);
      }
    }
}

int main()
{
  //freopen("inp.txt", "r", stdin);
  freopen("1.inp","r",stdin);
  freopen("1.sai","w",stdout);
//  ios_base::sync_with_stdio(false);
  int test;
  cin >> test;
  while (test --)
  {
    memset(a, 0, sizeof(a));
    memset(res, 0, sizeof(res));
    cin >> n >> m >> l;
    for (int i = 1; i <= n; i++)
    {
      for (int j = 1; j <= m; j++)
      {
        cin >> a[i][j];
        a[i][j] += a[i-1][j] + a[i][j-1] - a[i-1][j-1];
      }
    }
    k = (l-1)/2;
    solve();
    long long soChia = l*l;
   for (int i = k+1; i <= n-k; i++)
    {
      for (int j = k+1; j <= m-k; j++)
      {
        long long kq = res[i][j]/soChia;
        cout << kq << " ";
      }
      cout << endl;
    }
//    cout << n << " " << m << " " << l << " " << k << endl;
  }
  return 0;
}
