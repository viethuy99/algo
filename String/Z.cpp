#include<bits/stdc++.h>
using namespace std;

string a,b,s;
int l,r,g;
int z[2000006];
#define endl "\n"
int main(){
	ios::sync_with_stdio(false);cin.tie(0);
	cin>>a>>b;
	s+=b;s+='.';s+=a;
	int n=s.length(),g=b.length();
	for(int i=1;i<n-g+1;i++){
		if(i>r){
			l=i;r=i;
			while(r<n&&s[r-l]==s[r]) r++;
			z[i]=r-l;r--;
		}
		else{
			if(z[i-l]<r-i+1) z[i]=z[i-l];
			else if(z[i-l]>=r-i+1){
				l=i;
				while(r<n&&s[r-l]==s[r]) r++;
				z[i]=r-l;r--;
			}
		}
		if(z[i]==g) cout<<i-g<<" ";
	}
	return 0;
}
