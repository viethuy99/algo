#include<bits/stdc++.h>

using namespace std;
#define FTB(i,a,b) for(ll i=a,_b=b;i<=_b;i++)
#define FT(i,a,b) for(ll i=a,_b=b;i<_b;i++)
#define FGB(i,a,b) for(ll i=a,_b=b;i>=_b;i--)
#define FG(i,a,b) for(ll i=a,_b=b;i>_b;i--)
#define endl "\n"
#define debug cout<<"debug\n"
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define PI 3.1415926535897
#define lbnd(f,s,gt) lower_bound(f,s,gt)
#define ubnd(f,s,gt) upper_bound(f,s,gt)
#define y1 aghksdmlsjdfjavljvlckdfmg
#define lamtron(n) fixed<<setprecision(n)
#define ALL(s) s.begin(),s.end()
#define ONLINE_JUDGE gshysrthrrthbd

template<class T> int getbit(T s, int i) { return (s >> i) & 1; }
template<class T> T onbit(T s, int i) { return s | (T(1) << i); }
template<class T> T offbit(T s, int i) { return s & (~(T(1) << i)); }
template<class T> int cntbit(T s) { return __builtin_popcount(s);}
template<class T> inline T gcd(T a, T b) { T r; while (b != 0) { r = a % b; a = b; b = r; } return a;}

typedef double db;
typedef long long ll;
typedef unsigned long long ul;
typedef long double ld;
typedef pair<ll, ll> ii;
typedef vector<ll> vi;
typedef vector<ii> vii;
typedef vector<bool> vb;

const int MINN = 2, MAXN =  20, MINM = 1, MAXM = 10, MINV = 0, MAXV = 10, MINT = 1, MAXT = 20, f = 100;
int maxn = 100;
mt19937 mt_rand(time(0));
ll Rand(ll l, ll r) {
  return l + ((ll)rand() * (RAND_MAX + 1) * (RAND_MAX + 1) * (RAND_MAX + 1)
              + (ll)rand() * (RAND_MAX + 1) * (RAND_MAX + 1)
              + (ll)rand() * (RAND_MAX + 1)
              + (ll)rand()) % (r - l + 1);
}


// Có 2 solve(1 solve sai và 1 solve đúng), bỏ vào cùng 1 folder với file chấm này
// Solve đúng lưu tên file là solvedung.cpp, solve sai lưu tên file là solvesai.cpp
// Cả 2 solve đều đọc file "prob.inp", solve sai ghi ra file "prob.out", solve đúng ghi ra file "prob.ans"



int main()
{
//    ios::sync_with_stdio(0);cin.tie(0);
  srand(time(NULL));
  for (int iTest = 1; iTest <= 1000; iTest++)
  {
    ofstream inp("1.inp");
    ll T = 1;
    T = Rand(1, 10);
    inp << T << endl;
    while (T--) {
//*****************************Viet test sinh tai day********************************************
      int n = Rand(3, 10);
      int m = Rand(3, 10);
      cout << n << " " << m << endl;
      // int l=Rand(1,min(n, m) / 2) * 2 + 1;
      int l = Rand(1, min(n, m));
      if (l % 2 == 0) l--;
      inp << n << " " << m << " " << l << endl;
      FTB(i, 1, n) {
        FTB(j, 1, m) {
          int c = Rand(0, 255);
          inp << c << " ";
        }
        inp << endl;
      }

//******************************************************************************************
//                inp<<endl;
    }

    inp.close();
    system("solvesai.exe");
    system("solvedung.exe");
    if (system("fc 1.sai 1.dung") != 0)
    {
      cout << "Test " << iTest << ": WRONG!\n";
      return 0;
    }
    cout << "Test " << iTest << ": CORRECT!\n";
  }
  return 0;
}
