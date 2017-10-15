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

const int mx=1e5+10;
int nlen, hlen;
string needle, haystack;
int P[mx];
vector<int> matches;

inline void KMP()
{
    for (int i=0;i<nlen;i++) P[i] = -1;
    for (int i=0, j=-1;i<nlen;)
    {
        while (j > -1 && needle[i] != needle[j]) j = P[j];
        i++;
        j++;
        P[i] = j;
    }
    //p[i] for the string 0..i-1 longest prefix that is also a proper suffix
    for (int i=0, j=0;i<n;)
    {
        while (j > -1 && haystack[i] != needle[j]) j = P[j];
        i++;
        j++;
        if (j == m)
        {
            matches.push_back(i - m);
            j = P[j];
        }
    }
}

int main()
{
    haystack = "abcabc";
    needle = "bc";
    nlen=needle.size();
    hlen=haystack.size();
    KMP();
    for (int i=0;i<matches.size();i++) printf("%d ",matches[i]);
    printf("\n");
    return 0;
}

//cycle 0..i-1 has cycle if(p[i]>0 && (i)%(i-f[k])==0 cnt=(i)/(i-f[k]))
