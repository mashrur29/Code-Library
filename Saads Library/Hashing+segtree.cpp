#include<bits/stdc++.h>
using namespace std;
#define loop(i,L,R) for(int i=(L);i<=(R);i++)
#define rept(i,L,R) for(int i=(L);i<(R);i++)
#define isc(n) scanf("%d",&n)
#define llsc(n) scanf("%lld",&n)
#define dsc(n) scanf("%lf",&n)
#define enl cout<<endl
#define PB(x) push_back(x)
#define MP(x,y) make_pair(x,y)
#define xx first
#define yy second
typedef long long ll;
typedef pair<int,int>PI;
typedef pair<pair<int,int>,int>PII;

string s;
const int mx=1e5+10;
struct Lt
{
    int sz;
    long long h1,h2;
    Lt() {}
    Lt(int _sz, long long _h1, long long _h2)
    {
        sz=_sz;
        h1=_h1;
        h2=_h2;
    }
} Q[4*mx+3],Q2[4*mx+3];
ll B2 = 347, M2 = 1000000000+7;
ll B1 = 257, M1 = 402653189;
ll P1[mx],P2[mx];
void Edit(int w,int l,int r,int x)
{
    if (l==r)
    {
        Q[w].sz=1;
        Q[w].h1=(s[x-1]);
        Q[w].h2=(s[x-1]);
        //cout<<x<<Q[w].h1<<" "<<Q[w].h2<<endl;
        return;
    }
    int mid=(l+r)>>1;
    if (x<=mid) Edit(w<<1,l,mid,x);
    else Edit(w<<1|1,mid+1,r,x);
    Q[w].sz=Q[w<<1].sz+Q[w<<1|1].sz;
    {
        ll pow1=P1[Q[w<<1|1].sz],pow2=P2[Q[w<<1|1].sz];
        Q[w].h1=Q[w<<1].h1*pow1+Q[w<<1|1].h1;
        Q[w].h2=Q[w<<1].h2*pow2+Q[w<<1|1].h2;
        Q[w].h1%=M1;
        Q[w].h2%=M2;
        //cout<<x<<Q[w].h1<<" "<<Q[w].h2<<endl;
    }
}



Lt Get(int w,int l,int r,int Lx,int RX)
{
    if (r<Lx||l>RX) return Lt(0,0,0);
    if (Lx<=l&&r<=RX) return Q[w];
    int mid=(l+r)>>1;
    {
        Lt ret;
        Lt lef=Get(w<<1,l,mid,Lx,RX);
        Lt rit=Get(w<<1|1,mid+1,r,Lx,RX);
        ret.sz=lef.sz+rit.sz;
        {
            ll pow1=P1[rit.sz],pow2=P2[rit.sz];
            ret.h1=(lef.h1*pow1)%M1+rit.h1;
            ret.h2=(lef.h2*pow2)%M2+rit.h2;
            ret.h1%=M1;
            ret.h2%=M2;
        }
        return ret;
    }
}

char in[mx];
int main()
{
	P1[0]=1,P2[0]=1;
    for(int i=1; i<mx; i++)
    {
        P1[i]=(P1[i-1]*B1)%M1;
        P2[i]=(P2[i-1]*B2)%M2;
    }
	int q;
    scanf("%s",&in);
    isc(q);
    s=string(in);
    int len=s.size();
    for(int i=0; i<len; i++)Edit(1,1,len,i+1);
    char type[11];
    while(q--)
    {
		scanf("%s",&type);
		if(type[0]=='c')
		{
			int i;
			char b[2];
			scanf("%d %s",&i,&b);
			//cout<<b[0]<<endl;
			s[i-1]=b[0];
			rs[len-i]=b[0];
			Edit(1,1,len,i);
		}
		
	}
    return 0;
}
