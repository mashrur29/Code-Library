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
 
const int mx=5e3+10;
char stri[3][mx],str[3*mx];
int len[3],length;
 
int n, stp, mv, suffix[3*mx], tmp[3*mx];
int sum[3*mx], cnt[3*mx], rnk[16][3*mx];
int invsuff[3*mx],lcp[3*mx];
 
inline bool equal(const int &u, const int &v){
    if(!stp) return str[u] == str[v];
    if(rnk[stp-1][u] != rnk[stp-1][v]) return false;
    length = (u >= len[1] ? len[2] : (u >= len[0] ? len[1] : len[0]));
    int a = u + mv < length ? rnk[stp-1][u+mv] : -1;
    length = (v >= len[1] ? len[2] : (v >= len[0] ? len[1] : len[0]));
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
inline int cal_lcp(int u, int v) {
    if(u == v) return n - u;
    int ret, i;
    for(ret = 0, i = stp; i >= 0; i--) {
        if(rnk[i][u] == rnk[i][v]) {
            ret += 1<<i;
            u += 1<<i;
            v += 1<<i;
        }
    }
    return ret;
}

int findRes() {
    int res = 0;
    int la = -1, lb = -1, lc = -1;
    int save[3][3] = {0};
    for( int i = 0; i < n; i++ ) {
        if( suffix[i] < len[0]-1 ) { // part of first string
            //cout<<"1 "<<suffix[i]<<endl;
            la = suffix[i];
            if( lb != -1 ) save[0][1] = cal_lcp( la, lb );
            if( lc != -1 ) save[0][2] = cal_lcp( la, lc );
            res = max( res, min( save[0][1], min( save[0][2], save[1][2] ) ) );
        }
        else if( len[0]-1 < suffix[i] && suffix[i] < len[1]-1) { // part of second string
            //cout<<"2 "<<suffix[i]<<endl;
            lb = suffix[i];
            if( la != -1 ) save[0][1] = cal_lcp( la, lb );
            if( lc != -1 ) save[1][2] = cal_lcp( lb, lc );
            res = max( res, min( save[0][1], min( save[0][2], save[1][2] ) ) );
        }
        else if( len[1]-1 < suffix[i] && suffix[i] < len[2]-1) { // part of third string
            //cout<<"3 "<<suffix[i]<<endl;
            lc = suffix[i];
            if( la != -1 ) save[0][2] = cal_lcp( la, lc );
            if( lb != -1 ) save[1][2] = cal_lcp( lb, lc );
            res = max( res, min( save[0][1], min( save[0][2], save[1][2] ) ) );
        }
        //cout<<save[0][1]<<" "<<save[0][2]<<" "<<save[1][2]<<endl;
    }
    return res;
}
int main()
{
    int t,cas=0;
    isc(t);
    while(t--)
    {
        scanf("%s", stri[0]);
        len[0] = strlen(stri[0]) + 1;
        scanf("%s", stri[1]);
        len[1] = strlen(stri[1]) + 1 + len[0];
        scanf("%s", stri[2]);
        len[2] = strlen(stri[2]) + 1 + len[1];
        strcpy(str,stri[0]);
        strcat(str,"0");
        strcat(str,stri[1]);
        strcat(str,"1");
        strcat(str,stri[2]);
        strcat(str,"3");
        n=len[2];
        SortSuffix();
        printf("Case %d: %d\n", ++cas,findRes());
    }
    return 0;
}
 
