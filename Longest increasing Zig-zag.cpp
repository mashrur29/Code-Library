ll LIZ(ll n){
  ll i,j,mx=1;

  for(i=0;i<n;i++){
    for(j=0;j<i;j++){
        if(a[i]>a[j]) dp[i][0]=max(dp[i][0],dp[j][1]+1);
    }

    for(j=0;j<i;j++){
        if(a[i]<a[j]) dp[i][1]=max(dp[i][1],dp[j][0]+1);
    }
  }

  return max(mx,max(dp[n-1][0],dp[n-1][1]));
}
