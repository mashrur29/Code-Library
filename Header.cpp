/***************************************************************
*    __    _____________      _______  _    ______             *
*     |\  /||    | |     |    | |   |  |    | |   |            *
*     | \/ ||____| |---| |____| |---|  |    | |---| -          *
*     |    ||    |     | |    | |   \  |____| |   \ |          *
*    --    --    --|------    ---   ----------------|          *
*                                                              *
*                Name: Mashrur Rashik                          *
*              Inst: University of Dhaka                       *
*                Country : Bangladesh                          *
***************************************************************/

#include<bits/stdc++.h>
using namespace std;
#define MAX 300300
#define clr(ar)              memset(ar, 0, sizeof(ar))
#define mem(a,b)             memset(a, b, sizeof(a))
#define fr(i,n)              for(i=0;i<n;i++)
#define sci(a)               scanf("%d",&a)
#define ssci(a,b)            scanf("%d %d",&a,&b)
#define pri(a)               printf("%d",a)
#define scl(a)               scanf("%lld",&a)
#define sscl(a,b)            scanf("%lld %lld",&a,&b)
#define prl(a)               printf("%lld\n",a)
#define Debug(a)             cout<<"LOL : "<<a<<endl
#define FILL(a,n,t)          for(int i=0;i<n;i++) a[i]=t
#define FILL_2D(a,n,m,t)     for(int i=0;i<n;i++)for(int j=0;j<m;j++) a[i][j]=t
#define inf                  (ll) 9e18
#define eps                  1e-9
#define pii                  pair <ll,ll>
#define TimeErMayReBaal(x)   ios_base::sync_with_stdio(x)
typedef long long ll;
typedef unsigned long long ull;

/************************************  Templates  *****************************************/

template <typename T> T mmul(T a,T b,T m){a%=m;T s=0;while(b){if(b&1) s=(s+a)%m;a=(a+a)%m;b>>=1;}return s;}
template <typename T> T big_mod(T a,T b,T m){a%=m;T s=1;while(b){if(b&1) s=mmul(s,a,m);b>>=1;a=mmul(a,a,m);}return s;}
template <typename T> T big_sum(T first,T com,T n,T m){T s=1,t;if(com==1) return mmul(n,first,m);s=(s*first)%m;t=((big_mod(com,n,m)-1)+m)%m;s=(s*t)%m;t=big_mod(com-1,m-2,m);s=(s*t)%m;return s;}
template <typename T> T gcd(T a,T b){if(a<0)a=-a;if(b<0)b=-b;while(b!=0){a%=b;if(a==0)return b;b%=a;}return a;}
template <typename T> T lcm(T a,T b){return (a/gcd(a,b))*b;}
template <typename T> T power(T a,T b){T s=1;while(b){if(b&1)s*=a;b>>=1;a*=a;}return s;}
template <typename T> T orientation(T ax,T ay,T bx,T by,T cx,T cy){return ax*(by-cy)+bx*(cy-ay)+cx*(ay-by);}

/******************************************************************************************/

int Set(int N,int pos){return N=N | (1<<pos);}
int reset(int N,int pos){return N= N & ~(1<<pos);}
bool check(int N,int pos){return (bool)(N & (1<<pos));}

/*******************************************************************************************/
