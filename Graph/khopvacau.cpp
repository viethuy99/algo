#pragma comment(linker, "/stack:200000000")
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#include <algorithm>
#include <bitset>
#include <cassert>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <ctime>
#include <deque>
#include <functional>
#include <iomanip>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <sstream>
#include <string>
#include <vector>
#include <stack>

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
#define debug cout<<"VL\n";
#define PI 3.1415926535897
#define lbnd(dau,cuoi,giatri) lower_bound(dau,cuoi,giatri)
#define ubnd(dau,cuoi,giatri) upper_bound(dau,cuoi,giatri)
typedef double DB;
typedef long long LL;
typedef unsigned long long UL;
typedef long double LD;
typedef pair<LL,LL> II;
typedef vector<LL> VI;
typedef vector<bool> VB;


LL n,m,low[10004],num[10004],tmp,x,y,node,edge;
VI ke[10004];
bool ok[10004];

void tarjan(LL u,LL t){
	LL con=0;
	low[u]=num[u]=++tmp;
	for(auto v:ke[u]){
		if(v==t) continue;
		if(num[v]){
			low[u]=min(low[u],num[v]);
		}
		else{
			tarjan(v,u);
			con++;
			low[u]=min(low[u],low[v]);
			if(low[v]>num[u]) edge++;
			if(u==t){
				if(con>=2) ok[u]=true;
			}
			else{
				if(low[v]>=num[u]) ok[u]=true;
			}
		}
	}
}




int main(){
    ios::sync_with_stdio(false);cin.tie(0);
//	freopen("input.txt","r",stdin);
//  freopen("output.txt","w",stdout);
	cin>>n>>m;
	FTB(i,1,m){
		cin>>x>>y;
		ke[x].PB(y);
		ke[y].PB(x);
	}
	FTB(i,1,n){
		if(!num[i]) tarjan(i,i);
	}
	FTB(i,1,n) node+=ok[i];
	cout<<node<<" "<<edge;





	return 0;
}



