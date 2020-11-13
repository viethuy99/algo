#include<bits/stdc++.h>
#define endl '\n'
#define LL long long

using namespace std;

typedef pair<int,int> ii;

int n,m,x,y,z,d[10004];
vector<int> a[10004],b[10004];

int prim(int u){
	int res=0;
	priority_queue<ii> Q;
	Q.push(ii(0,u));
	d[u]=0;
	while(!Q.empty()){
		ii top=Q.top();Q.pop();
		int dv=-top.first,v=top.second;
		if(dv!=d[v]) continue;
		res+=d[v];d[v]=0;
		for(int i=0;i<a[v].size();i++){
			int t=a[v][i];
			if(d[t]>b[v][i]){
				d[t]=b[v][i];
				ii hihi;
				hihi=make_pair(-d[t],t);
				Q.push(hihi);
			}
		}
	}
	return res;
}


int main(){
	ios::sync_with_stdio(false);cin.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++) d[i]=1e9;
	for(int i=1;i<=m;i++){
		cin>>x>>y>>z;
		a[x].push_back(y);
		b[x].push_back(z);
		a[y].push_back(x);
		b[y].push_back(z);
	}
	cout<<prim(1);


	return 0;
}
