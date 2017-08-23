void sieve(){
 ll n=1000000,i,j;
 bool a[n+1];
 memset(a,true,sizeof(a));

 for(i=2;i<=sqrt(n);i++)
 {
     if(a[i]){
        for(j=2*i;j<=n;j+=i) a[j]=false;
     }
 }

 for(i=2;i<=n;i++)
 {
     if(a[i]) p.push_back(i);
 }

}