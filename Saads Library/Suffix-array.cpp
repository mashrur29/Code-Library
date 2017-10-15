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

const int mx=10000+100;
char str[mx];
 
int n, stp, mv, suffix[mx], tmp[mx];
int sum[mx], cnt[mx], rnk[20][mx];
int invsuff[mx],lcp[mx];

inline bool equal(const int &u, const int &v){
    if(!stp) return str[u] == str[v];
    if(rnk[stp-1][u] != rnk[stp-1][v]) return false;
    int a = u + mv < n ? rnk[stp-1][u+mv] : -1;
    int b = v + mv < n ? rnk[stp-1][v+mv] : -1;
    return a == b;
}
 
void update(){
    int i, rk;
    for(i = 0; i < n; i++) sum[i] = 0;
    for(i = rk = 0; i < n; i++) {
        suffix[i] = tmp[i];
        if(i && !equal(suffix[i], suffix[i-1])) {
            rnk[stp][suffix[i]] = ++rk;
            sum[rk+1] = sum[rk];
        }
        else rnk[stp][suffix[i]] = rk;
        sum[rk+1]++;
    }
}
 
void Sort() {
    int i;
    for(i = 0; i < n; i++) cnt[i] = 0;
    memset(tmp, -1, sizeof tmp);
    for(i = 0; i < mv; i++){
        int idx = rnk[stp - 1][n - i - 1];
        int x = sum[idx];
        tmp[x + cnt[idx]] = n - i - 1;
        cnt[idx]++;
    }
    for(i = 0; i < n; i++){
        int idx = suffix[i] - mv;
        if(idx < 0)continue;
        idx = rnk[stp-1][idx];
        int x = sum[idx];
        tmp[x + cnt[idx]] = suffix[i] - mv;
        cnt[idx]++;
    }
    update();
    return;
}
 
inline bool cmp(const int &a, const int &b){
    if(str[a]!=str[b]) return str[a]<str[b];
    return false;
}
 
void SortSuffix() {
    int i;
    for(i = 0; i < n; i++) tmp[i] = i;
    sort(tmp, tmp + n, cmp);
    stp = 0;
    update();
    ++stp;
    for(mv = 1; mv < n; mv <<= 1) {
        Sort();
        stp++;
    }
    stp--;
    for(i = 0; i <= stp; i++) rnk[i][n] = -1;
}

void kasai()
{
    for (int i=0; i < n; i++)invsuff[suffix[i]] = i;
    int k = 0;
    for (int i=0; i<n; i++)
    {
        if (invsuff[i] == n-1)
        {
            k = 0;
            continue;
        }
        int j = suffix[invsuff[i]+1];
        while (i+k<n && j+k<n && str[i+k]==str[j+k])
            k++;
        lcp[invsuff[i]+1] = k;
        if (k>0)
            k--;
    }
}

/*int RMQ[MAX_LEN][LOG2_LEN + 1];

void initialize_rmq(){
    for(int i = 0;i<N;++i) RMQ[i][0] = lcp[i];
    
    for(int j = 1;(1<<j)<=N;++j){
        for(int i = 0;i+(1<<j)-1<N;++i){
            if(RMQ[i][j-1]<=RMQ[i+(1<<(j-1))][j-1])
                RMQ[i][j] = RMQ[i][j-1];
            else
                RMQ[i][j] = RMQ[i+(1<<(j-1))][j-1];
        }
    }
}

// lcp(pos[x],pos[y])
int rlcp(int x, int y){
    if(x == y) return N-rank[x];
    if(x > y) swap(x,y);
    
    int log = 0;
    while((1<<log)<=(y-x)) ++log;
    --log;
    
    return min(RMQ[x+1][log],RMQ[y-(1<<log)+1][log]);
    
}*/
int main()
{
	int t,cas=0;
	isc(t);
	while(t--)
	{
		scanf("%s",str);
		n=strlen(str);
		int p,q;
		isc(p),isc(q);
		SortSuffix();
		kasai();
		int ans=0;
		rept(i,0,n)ans+=max(0,(min(n-suffix[i],q)-max(lcp[i],p-1)));//n-suffix[i]-lcp[i];
		printf("Case %d: %d\n", ++cas,ans);
	}
	return 0;
}

/*
Generates suffix array in O(n (lg n)^2). Finds LCP in O(lg n)
A[] is the target string with N length. base is the lowest character in A[].
S[i] holds the index of ith suffix when sorted lexicographically.
Change base as necessary and MAXLOG = log2(MAXLEN).
*/
 
int N, stp, P[MAXLOG][MAXLEN], S[MAXLEN];
char A[MAXLEN], base = 'a';
struct entry { int nr[2], p; } L[MAXLEN];
 
inline bool cmp(const entry &a, const entry &b) {
    return a.nr[0] == b.nr[0] ? (a.nr[1] < b.nr[1] ? 1 : 0) : (a.nr[0] < b.nr[0] ? 1 : 0);
}
 
void generateSuffix() {
    register int i, cnt;
    for(i=0; i<N; i++) P[0][i] = A[i]-base;
    for(stp = cnt = 1; cnt>>1 < N; stp++, cnt<<=1) {
        for(i=0; i<N; i++) {
            L[i].nr[0] = P[stp-1][i];
            L[i].nr[1] = i+cnt<N ? P[stp-1][i+cnt] : -1;
            L[i].p = i;
        }
        sort(L, L+N, cmp);
        for(i=0; i<N; i++) {
            if(i > 0 && L[i].nr[0] == L[i - 1].nr[0] && L[i].nr[1] == L[i - 1].nr[1]) P[stp][L[i].p] = P[stp][L[i - 1].p];
            else P[stp][L[i].p] = i;
        }
    }
    for(i=0; i<N; i++) S[P[stp-1][i]] = i;
}
 
int lcp(int x, int y) {
    int k, ret = 0;
    if(x == y) return N - x;
    for(k = stp - 1; k >= 0 && x < N && y < N; k --)
        if(P[k][x] == P[k][y])
            x += 1 << k, y += 1 << k, ret += 1 << k;
    return ret;
}
