ll big_mod(ll a,ll b){
    if(!b) return 1;
    if(b&1) return ((a%m)*(big_mod(a,b-1)%m))%m;
    else{
        ll temp=big_mod(a,b/2)%m;
        return ((temp%m)*(temp%m))%m;
    }
}
