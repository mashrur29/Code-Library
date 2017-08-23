// if x>y (x+y is minimum)

ll egcd(ll a,ll b,ll &x,ll &y){
 if(a==0){
    x=0;y=1;
    return b;
 }
 ll x1,y1;
 ll d=egcd(b%a,a,x1,y1);
 x=y1-(b/a)*x1;
 y=x1;
 return d;
}

// if x<y (x+y is minimum)

ll egcd(ll a,ll b,ll &x,ll &y){
 if(b==0){
    x=1;y=0;
    return a;
 }
 ll x1,y1;
 ll d=egcd(b,a%b,x1,y1);
 x=y1;
 y=x1-(a/b)*y1;
 return d;
}
