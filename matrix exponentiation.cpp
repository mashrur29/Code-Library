void multiply(ll a[][3],ll b[][3]){
  ll i,j,k;
  for(k=0;k<3;k++){
    for(i=0;i<3;i++){
        ll sum=0;
        for(j=0;j<3;j++){
          sum=(sum%mod+(a[i][j]*b[j][k])%mod)%mod;
        }
    c[i][k]=sum%mod;
    }
  }
  for(i=0;i<3;i++){
    for(j=0;j<3;j++) a[i][j]=c[i][j];
  }
}

void mat_to(ll mat[][3],ll n,ll res[][3]){
    for(ll i=0;i<3;i++) res[i][i]=1;

    while(n){
        if(n&1) multiply(res,mat);
        n/=2;
        if(n) multiply(mat,mat);
    }
}

