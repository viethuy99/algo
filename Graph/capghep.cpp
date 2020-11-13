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
#define y1 aghksdmlsjdfjavljvlckdfmg
typedef double DB;
typedef long long LL;
typedef unsigned long long UL;
typedef long double LD;
typedef pair<LL,LL> II;
typedef vector<LL> VI;
typedef vector<II> VII;
typedef vector<bool> VB;


LL m,n,x[1004],y[1003],ok[1003],res,d;
VI ke[1004];

bool fin(LL i){
    if(ok[i]) return false;
    ok[i]=true;
    FT(j,0,ke[i].size()){
        LL v=ke[i][j];
        if(y[v]==0){
            x[i]=v;
            y[v]=i;
            return true;
        }
        if(fin(y[v])){
            // quay lui ve cai lai tat ca cac canh da di qua va xoa cac canh truoc
            x[i]=v;
            y[v]=i;
            return true;
        }
    }
    return false;
}




int main(){
    ios::sync_with_stdio(false);cin.tie(0);
//	freopen("input.txt","r",stdin);
//  freopen("output.txt","w",stdout);
    cin>>m>>n>>d;
    LL u,v;
    FTB(i,1,d){
        cin>>u>>v;
        ke[u].PB(v);
    }
    FTB(i,1,m){
        memset(ok,0,sizeof(ok));
        if(fin(i)) res++;

    }
    cout<<res<<endl;


	return 0;
}
