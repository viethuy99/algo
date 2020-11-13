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

LL n,m,u,v,bac[10004],goc[10004],hi,res;
VI ke[10004];
stack<LL> S;

void dfs(LL u){
	S.push(u);
	bac[u]=goc[u]=++hi;
	FT(i,0,ke[u].size()){
		int v=ke[u][i];
		if(bac[v]){
			goc[u]=min(goc[u],bac[v]);
		}
		else{
			dfs(v);
			goc[u]=min(goc[u],goc[v]);
		}
	}
	if(bac[u]==goc[u]){
		res++;
		do{
			v=S.top();S.pop();
			bac[v]=goc[v]=2e9;
		}while(v!=u);
	}
}





int main(){
    ios::sync_with_stdio(false);cin.tie(0);
//	freopen("input.txt","r",stdin);
//  freopen("output.txt","w",stdout);
	cin>>n>>m;
	FTB(i,1,m){
		cin>>u>>v;
		ke[u].PB(v);
	}
	FTB(i,1,n){
		if(!goc[i]) dfs(i);
	}
	cout<<res;




	return 0;
}



