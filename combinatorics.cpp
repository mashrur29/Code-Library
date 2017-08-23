// number of trailing Zeros

ll numberofZero(ll n){
 ll count=0;
 for(ll i=5;n/i>0;i*=5) count+=n/i;
 return count;
}

// number of digits in factorial representation

ll numberofDigit(ll n){
 double c=0;
 for(double i=1.0;i<=n;i+=1.0){
    c+=(log10(i));
 }
 c=floor(c);
 c+=1.0;
 return (ll)c;
}

// combination

ll c[1001][1001];

void combinaton(){
 ll i,j,lim=1000;
 c[0][0]=1;
 for(i=1;i<=lim;i++){
    for(j=0;j<=lim;j++){
     if(j>i) c[i][j]=0;
     else if(j==0||i==j) c[i][j]=1;
     else c[i][j]=c[i-1][j]+c[i-1][j-1];
    }
 }
}

// dearrangement

ll a[1000001];

ll d(ll n){
  clr(a);
  if(n==1) return 0;
  if(n==2) return 1;
  else{
    if(!a[n]) a[n]=(n-1)*(d(n-1)+d(n-2));
    else return a[n];
  }
  return a[n];
}

// catalan number ex: XXXYYY, XYXXYY, XYXYXY, XXYYXY, XXYXYY (N=3) || ((())), ()(()), ()()(), (())(), (()()) || triangulation of polygon || for n leaf how many complete binary tree

ll c[1001][1001];
void combination(){
 ll i,j;
 c[0][0]=1;
 for(i=1;i<=1000;i++){
    for(j=0;j<=1000;j++){
        if(j>i) c[i][j]=0;
        else if(j==i||j==0) c[i][j]=1;
        else c[i][j]=c[i-1][j]+c[i-1][j-1];
    }
 }
}

ll catalan_number(ll n){
 combination();
 return c[2*n][n]-c[2*n][n+1];  // (1/(n+1))*c[2*n][n]
}

// stirling number of second type ex: dividing n elements into k groups

ll str2[10001][10001];
ll stirling2(ll n,ll k){
 if(k==1||n==k) return 1;
 else{
    if(!str2[n][k]) str2[n][k]=stirling2(n-1,k-1)+k*stirling2(n-1,k);
    else return str2[n][k];
 }
 return str2[n][k]; // clear str2[][] in main function 
}

// stirling number of first type ex: dividing n elements into k cyclic groups

ll str[1001][1001],f[100];

void fact(){
 clr(f);
 f[0]=1;f[1]=1;
 ll i;
 for(i=1;i<=50;i++) f[i]=f[i-1]*i;
}

ll stirling1(ll n,ll k){
 if(k==1) str[n][k]=f[n-1];
 else if(n==k) str[n][k]=1;
 else{
    if(!str[n][k]) str[n][k]=stirling1(n-1,k-1)+(n-1)*stirling1(n-1,k);
    else return str[n][k];
 }
 return str[n][k];  // clear str[][] in main()
}

 	
