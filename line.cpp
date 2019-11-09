pair<ii,ll> line(ii a,ii b){
    ll x=b.se-a.se,y=a.fi-b.fi;
    ll tmp=__gcd(x,y);
    x/=tmp;y/=tmp;
    if(x<0){
        x=-x;y=-y;
    }
    else if(x==0&&y<0) y=-y;
    ll z=x*a.fi+y*a.se;
    return {{x,y},z};
}
