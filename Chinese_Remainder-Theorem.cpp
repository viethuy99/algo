
// truyen vao vector _a[] la so du va vector _Mod[] la mod
struct CRT{
    ll a[105],M[105],Mod[105],y[105],big_mod,n,res;

    ll qp(ll a,ll b,ll mod){
        if(b==0) return 1;
        if(b&1) return a*qp(a,b-1,mod)%mod;
        return qp(a*a%mod,b>>1,mod)%mod;
    }
    CRT(){}
    CRT(vi _a,vi _Mod){
        big_mod=1;
        n=_a.size();
        FTB(i,1,n){
            a[i]=_a[i-1];
            Mod[i]=_Mod[i-1];
            big_mod*=Mod[i];
        }
        FTB(i,1,n) M[i]=big_mod/Mod[i];
        FTB(i,1,n){
            y[i]=qp(M[i],Mod[i]-2,Mod[i])*a[i]%Mod[i];
        }
    }
    void Set(vi _a,vi _Mod){
        big_mod=1;
        n=_a.size();
        FTB(i,1,n){
            a[i]=_a[i-1];
            Mod[i]=_Mod[i-1];
            big_mod*=Mod[i];
        }
        FTB(i,1,n) M[i]=big_mod/Mod[i];
        FTB(i,1,n){
            y[i]=qp(M[i],Mod[i]-2,Mod[i])*a[i]%Mod[i];
        }
    }
    ll get(){
        res=0;
        FTB(i,1,n){
            res=(res+y[i]*M[i]%big_mod)%big_mod;
        }
        return res;
    }

} China;
