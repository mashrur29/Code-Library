ll power(ll a,ll b){
 ll s=1;
 while(b){
    if(b&1) s*=a;
    b/=2;
    if(b) a*=a;
 }
 return s;
}

int main(){
  ll n,s,i,count=1,r=9,res,p;
  sc(n);
  p=n-1;
  for(s=1;;s+=2){

    if(count>=n) break;

    count+=(r+r);
    if(p-2*r>0) p-=2*r;
    r*=10;
    if(count>=n) break;
  }

  ll t=s/2;
  if(s%2!=0) t++;

  res=(p-1)+power(10,t-1);

  cout<<res;
  if(s%2!=0) res/=10;
  while(res){
    cout<<res%10;
    res/=10;
  }

  cout<<endl;
  return 0;
}
