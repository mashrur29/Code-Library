int primefactors(int n)
{
    int k=0,flag=1;
    while(n%2==0)
    {
        if(flag){
        a[k++]=2;
        flag=0;
        }
        n=n/2;
    }
    for(int i=3;i<=sqrt(n);i+=2)
    {
        while(n%i==0){
            if(i!=a[k-1]) a[k++]=i;
            n=n/i;
        }
    }
   if(n>2) a[k++]=n;
   return k;
}

int main()
{
    int n,r;
    sc(n);
    clr(a);
    r=primefactors(n);
    for(int i=0;i<r;i++) pr(a[i]);
    return 0;
}
