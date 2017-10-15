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


inline int minimumExpression(char *s) {
    int i, j, k, n, len, p, q;
    len = n = strlen(s), n <<= 1, i = 0, j = 1, k = 0;
    while(i + k < n && j + k < n) {
        p = i+k >= len ? s[i+k-len] : s[i+k];
        q = j+k >= len ? s[j+k-len] : s[j+k];
        if(p == q) k++;
        else if(p > q) { i = i+k+1; if(i <= j) i = j+1; k = 0; }
        else if(p < q) { j = j+k+1; if(j <= i) j = i+1; k = 0; }
    }
    return i < j ? i : j;
}
 

void printSmallestSequence(char S[], int n)
{
    int starting_index = minimumExpression(S);
    for (int i=0;i<n;i++)
        cout << S[(starting_index+i)%n];
}
 

int main()
{
    char S[] = "DCACBCAA";
    int n = 8;
    printSmallestSequence(S, n);
    return 0;
}
