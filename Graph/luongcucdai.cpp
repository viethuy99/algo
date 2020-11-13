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


LL n,m,s,t,a,b,cost,c[1002][1002],res,cha[1002];
VI ke[1004];
bool bfs(){
	queue<LL> Q;
	int i,u,v;
	memset(cha,0,sizeof(cha));
	Q.push(s);
	cha[s]=s;
	while(Q.size()){
		u=Q.front();Q.pop();
		for (i=0; v=ke[u][i]; i++)
			if(c[u][v]&&!cha[v]){
				cha[v]=u;
				if(v==t) return true;
				Q.push(v);
			}
	}
	return false;
}


int main(){
    ios::sync_with_stdio(false);cin.tie(0);
	cin>>n>>m>>s>>t;
	FT(i,0,m){
		cin>>a>>b>>cost;
		ke[a].PB(b);
		ke[b].PB(a);
		c[a][b]=cost;
	}
	FTB(i,1,n) ke[i].PB(0);
	while(bfs()){
		LL tmp=1e18;
		for(LL v=t;v!=s;v=cha[v]){
			tmp=min(tmp,c[cha[v]][v]);
		}
		for(LL v=t;v!=s;v=cha[v]){
			c[cha[v]][v]-=tmp;
			c[v][cha[v]]+=tmp;
		}
		res+=tmp;
	}
	cout<<res;



	return 0;
}



