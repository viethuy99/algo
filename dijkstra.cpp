#pragma comment(linker, "/stack:200000000")
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#include<bits/stdc++.h>

using namespace std;

#define FTB(i,a,b) for(LL i=a;i<=b;i++)
#define FT(i,a,b) for(LL i=a;i<b;i++)
#define FGB(i,a,b) for(LL i=a;i>=b;i--)
#define FG(i,a,b) for(LL i=a;i>b;i--)
#define endl "\n"
#define PB push_back
#define mp make_pair
#define fi first
#define se second
#define PI 3.1415926535897
/*cac ham bin 1 nua, neu khong tim thay thi tra ve cuoi+1 */
#define lbnd(dau,cuoi,giatri) lower_bound(dau,cuoi,giatri) //tra ve vi tri dau tien lon hon hoac bang gia tri
#define ubnd(dau,cuoi,giatri) upper_bound(dau,cuoi,giatri) //tra ve vi tri dau tien lon hon gia tri
/* vd:q = lower_bound(a, a+n, p) - a; // a[0..n-1], a[q]>=p */
typedef double DB;
typedef long long LL;
typedef unsigned long long UL;
typedef long double LD;
typedef pair<LL,LL> II;
typedef vector<LL> VI;
typedef vector<bool> VB;

LL n,m,q,x,u,v,d[101],dai[101][101],truoc[101];

priority_queue<II> Q;

void dijkstra(LL u){
	FTB(i,1,n){
		d[i]=1e9;
		truoc[i]=0;
	}
	Q.push(II(0,u));
	d[u]=0;
	while(Q.size()){
		II z=Q.top();Q.pop();
		u=z.se;
		LL du=-z.fi;
		if(du!=d[u]) continue;
		FTB(v,1,100){
			if(d[v]>d[u]+dai[u][v]){
				d[v]=d[u]+dai[u][v];
				Q.push(II(-d[v],v));
				truoc[v]=u;
			}
		}
	}
}





int main(){
    ios::sync_with_stdio(false);cin.tie(0);
	cin>>n>>m>>q;
	FTB(i,1,n) FTB(j,1,n){
		if(i==j){
			dai[i][j]=0;
			continue;
		}
		dai[i][j]=1e9;
	}
	FTB(i,1,m){
		cin>>u>>v>>x;
		dai[u][v]=x;
		dai[v][u]=x;
	}
	while(q--){
		cin>>x>>u>>v;
		dijkstra(u);
		if(x==1){
			VI hi;
			do{
				hi.PB(v);
				v=truoc[v];
			}while(hi.back()!=u);
			cout<<hi.size();
			FGB(i,hi.size()-1,0) cout<<" "<<hi[i];
		}
		else{
			cout<<d[v];
		}
		cout<<endl;
	}


	return 0;
}


