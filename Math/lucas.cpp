
ll mod1=29,mod2=34483,tu1[40],mau1[40],tu2[40000],mau2[40000];

void precompute(){
    tu1[0]=tu2[0]=1;
    FT(i,1,mod1){
        tu1[i]=tu1[i-1]*i%mod1;
    }
    mau1[mod1-1]=pow(tu1[mod1-1],mod1-2,mod1);
    FGB(i,mod1-2,0){
        mau1[i]=mau1[i+1]*(i+1)%mod1;
    }
    FT(i,1,mod2){
        tu2[i]=tu2[i-1]*i%mod2;
    }
    mau2[mod2-1]=pow(tu2[mod2-1],mod2-2,mod2);
    FGB(i,mod2-2,0){
        mau2[i]=mau2[i+1]*(i+1)%mod2;
    }
}


ll cal_lucas(ll n,ll k,ll mod,ll type){
    vi v1,v2;
    ll res=1;
    while(n){
        v1.pb(n%mod);n/=mod;
    }
    while(k){
        v2.pb(k%mod);k/=mod;
    }
    while(v1.size()<v2.size()) v1.pb(0);
    while(v1.size()>v2.size()) v2.pb(0);
    FT(i,0,v1.size()){
        ll tmp,n=v1[i],k=v2[i];
        if(n<k) tmp=0;
        else if(type==1) tmp=tu1[n]*mau1[k]%mod*mau1[n-k]%mod;
        else if(type==1) tmp=tu1[n]*mau1[k]%mod*mau1[n-k]%mod;
        else tmp=tu2[n]*mau2[k]%mod*mau2[n-k]%mod;
        res=(res*tmp)%mod;
    }
    return res;
}
