#include<bits/stdc++.h>
using namespace std;
 
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef pair<ll,ll> ii;
typedef vector<ll> vi;
typedef vector<ii> vii;
typedef map<ll,ll> mll;
typedef vector<bool> vb;
 
#define y0 sdkfaslhagaklsldk
#define y1 aasdfasdfasdf
#define yn askfhwqriuperikldjk
#define j1 assdgsdgasghsf
#define tm sdfjahlfasfh
#define lr asgasgash
#define endl "\n"
#define prina(arr,dau,cuoi) FTB(mmczmp,dau,cuoi)cout<<arr[mmczmp]<<" ";cout<<endl;
#define debug cout<<"debug\n"
#define DEBUG(x) { cout << #x << " = "; cout << (x) << endl; }
#define pb push_back
#define pbg(ke,u,v) ke[u].pb(v);ke[v].pb(u);
#define X first
#define Y second
#define pi acos(-1.0)
#define lbnd(f,s,gt) lower_bound(f,s,gt)
#define ubnd(f,s,gt) upper_bound(f,s,gt)
#define all(s) s.begin(),s.end()
#define bitcount(n) __builtin_popcountll(n)
#define FTB(i,a,b) for(ll i=a,_b=b;i<=_b;i++)
#define FT(i,a,b) for(ll i=a,_b=b;i<_b;i++)
#define FGB(i,a,b) for(ll i=a,_b=b;i>=_b;i--)
#define FG(i,a,b) for(ll i=a,_b=b;i>_b;i--)
/////////////////////////////////////////////
 
 
 
 
ll n,m,con[100005],par[100005],fa[100005][22],res[100005],depth[100005];
vi ke[100005];
//par: luu cha trong cay centroid
//fa: luu cha trong cay ban dau
 
void dfs(ll u,ll p=0){
    con[u]=1;
    for(auto v:ke[u]){
        if(v==p) continue;
        fa[v][0]=u;
        depth[v]=depth[u]+1;
        dfs(v,u);
        con[u]+=con[v];
    }
}
 
 
 
ll LCA(ll x,ll y){
    FGB(deg,20,0){
        if(depth[fa[x][deg]]>=depth[y]) x=fa[x][deg];
    }
    FGB(deg,20,0){
        if(depth[fa[y][deg]]>=depth[x]) y=fa[y][deg];
    }
    if(x==y) return x;
    FGB(deg,20,0){
        if(fa[x][deg]!=fa[y][deg]){
            x=fa[x][deg];
            y=fa[y][deg];
        }
    }
    while(x!=y) x=fa[x][0],y=fa[y][0];
    return x;
}
 
ll dist(ll x,ll y){
    return depth[x]+depth[y]-2*depth[LCA(x,y)];
}
 
void centroid(ll i,ll p,ll s) {
    for (auto it:ke[i]) {
        if (con[it]>(s/2) && par[it]<0) {
            con[i]=s-con[it];
            centroid(it,p,s);
            return;
        }
    }
    par[i]=p;
    for (auto it:ke[i]) {
        if (par[it]<0) centroid(it,i,con[it]);
    }
}
void upd(int i) {
    res[i]=0;
    int j=i;
    while (par[j]) {
        res[par[j]]=min(res[par[j]],dist(i,par[j]));
        j=par[j];
    }
}
ll get(int i) {
    ll ans=res[i];
    ll j=i;
    while (par[j]) {
        ans=min(ans,res[par[j]]+dist(i,par[j]));
        j=par[j];
    }
    return ans;
}
 
void Solve(){
    memset(par,-1,sizeof par);
    cin>>n>>m;
    FT(i,1,n){
        ll a,b;cin>>a>>b;
        pbg(ke,a,b);
    }
    dfs(1);
    FTB(deg,1,20){
        FTB(i,1,n){
            fa[i][deg]=fa[fa[i][deg-1]][deg-1];
        }
    }
    centroid(1,0,n);
    FTB(i,1,n) res[i]=1e15;
    upd(1);
    while (m--) {
        ll a,b; cin>>a>>b;
        if (a==1) upd(b);
        else cout<<get(b)<<endl;
    }
}
 
int main(){
    ios::sync_with_stdio(0);cin.tie(0);
 
    //freopen("1.in","r",stdin);
    //freopen("1.out","w",stdout);
 
 
    int Test_numbers=1;
    //int Test_numbers;cin>>Test_numbers;
 
    while(Test_numbers--) Solve();
 
    //cerr << "\nTime run: " << 1000 * clock() / CLOCKS_PER_SEC << "ms\n";
 
	return 0;
}