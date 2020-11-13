#include<bits/stdc++.h>
using namespace std;

vector<int> v;
int k=0,h,p[1000006];
main(){
	ios::sync_with_stdio(false);cin.tie(0);
	string a="!",b="?",aa,bb;cin>>aa>>bb;
	a+=aa;b+=bb;
	int n=a.length()-1,m=b.length()-1;
	p[1]=0;
	for(int i=2;i<=m;i++){
		while(b[k+1]!=b[i]&&k>0){
			k=p[k];
		}
		if(b[k+1]==b[i]) k++;
		p[i]=k;
	}
	k=0;
	for(int i=1;i<=n;i++){
		while(b[k+1]!=a[i]&&k>0) k=p[k];
		if(b[k+1]==a[i]) k++;
		if(k==m){
			v.push_back(i-m+1);
		}
	}
	for(int i=0;i<v.size();i++) cout<<v[i]<<" ";
}
