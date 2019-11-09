#include<bits/stdc++.h>

using namespace std;
#define FTB(i,a,b) for(ll i=a,_b=b;i<=_b;i++)
#define FT(i,a,b) for(ll i=a,_b=b;i<_b;i++)
#define FGB(i,a,b) for(ll i=a,_b=b;i>=_b;i--)
#define FG(i,a,b) for(ll i=a,_b=b;i>_b;i--)
#define endl "\n"
#define debug cout<<"debug\n"
#define PB push_back
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


typedef double db;
typedef long long ll;
typedef unsigned long long ul;
typedef long double ld;
typedef pair<ll,ll> ii;
typedef vector<ll> vi;
typedef vector<ii> vii;
typedef vector<bool> vb;

template<class T> ll getbit(T s, ll i) { return (s >> i) & 1; }
template<class T> T onbit(T s, ll i) { return s | (T(1) << i); }
template<class T> T offbit(T s, ll i) { return s & (~(T(1) << i)); }
template<class T> ll cntbit(T s) { return __builtin_popcount(s);}
template<class T> inline T gcd(T a, T b){ T r; while (b != 0) { r = a % b; a = b; b = r; } return a;}


const ll MINN = 2, MAXN =  20, MINM = 1, MAXM = 10, MINV = 0, MAXV = 10,MINT=1,MAXT=20,f=100;
ll dd[1000];
ll a[107][107];
ll maxn=1000;
ll timcha(ll x){
    if (dd[x] < 0) return x;
    else dd[x] = timcha(dd[x]);
}
long long Rand(long long l, long long h)
{
    return l + ((long long)rand() * (RAND_MAX + 1) * (RAND_MAX + 1) * (RAND_MAX + 1) +
                (long long)rand() * (RAND_MAX + 1) * (RAND_MAX + 1) +
                (long long)rand() * (RAND_MAX + 1) +
                rand()) % (h - l + 1);
}


int main()
{
    srand(time(NULL));
    for(ll iTest = 1; iTest <= 1; iTest++)
    {
        ofstream inp("1.inp");
        ll n = Rand(1,100);
        inp << n << endl;
        ll dem = 0;
        for(ll i = 1;i <= n;i++)
            dd[i] = -1;
        while(dem < n - 1){
            ll x = Rand(1,n);
            ll y = Rand(1,n);
            if (a[x][y]) continue;
            ll chaX = timcha(x);
            ll chaY = timcha(y);
            if (chaX != chaY){
                inp << x << " " << y << endl;
                a[x][y] = a[y][x] = 1;
                dem++;
                if (dd[chaX] < dd[chaY]){
                    dd[chaX] += dd[chaY];
                    dd[chaY] = chaX;
                } else {
                    dd[chaY] += dd[chaX];
                    dd[chaX] = chaY;
                }
            }
        }
//        inp.close();
//        system("solvesai.exe");
//        system("solvedung.exe");
//        if(system("fc 1.dung 1.sai") != 0)
//        {
//            cout << "Test " << iTest << ": WRONG!\n";
//            return 0;
//        }
//        cout << "Test " << iTest << ": CORRECT!\n";
    }
    return 0;
}
