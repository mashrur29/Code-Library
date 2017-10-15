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
int n, m;
string needle, haystack;
int Z[mx];
vector<int> matches;


inline void Z_Algorithm(string s)
{
    int len = s.length();
    int L = 0, R = 0;
    for (int i=1;i<len;i++)
    {
        if (i > R)
        {
            L = R = i;
            while (R < len && s[R-L] == s[R]) R++;
            Z[i] = R-L;
            R--;
        }
        else
        {
            int k = i - L;
            if (Z[k] < R-i+1) Z[i] = Z[k];
            else
            {
                L = i;
                while (R < len && s[R-L] == s[R]) R++;
                Z[i] = R - L;
                R--;
            }
        }
        if (Z[i] == m) matches.push_back(i - m - 1);
    }
}
//z[i] equals length of prefix starting at i
int main()
{
    n = 6, m = 2;
    haystack = "abcabc";
    needle = "bc";
    Z_Algorithm(needle + "#" + haystack);
    for (int i=0;i<matches.size();i++) printf("%d ",matches[i]);
    printf("\n");
    return 0;
}

