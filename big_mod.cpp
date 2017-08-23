ll big_mod(ll a,ll b){ll s=1;
while(b){if(b&1) s*=a;b=b/2;
if(b) a=a*a;}return s;}
