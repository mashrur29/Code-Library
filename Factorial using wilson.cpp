// Factorial using wilson

#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

void extendeed(ll a, ll b, ll &x, ll &y) {
    if(a%b==0) {
        x = 0;
        y = 1;
        return;
    }

    extendeed(b, a%b, x, y);
    ll temp = x;
    x = y;
    y = temp - y*(a/b);
}

ll modINV(ll a, ll m) {
    ll x, y;
    extendeed(a, m, x, y);

    return ((x%m)+m)%m;
}

ll fact(ll n, ll mod) {
    ll ans = 1;

    if(n>=mod) {
        ans = 0;
    } else {
        for(ll i=n+1; i<mod; i++) {
            ans = (ans*i)%mod;
        }

        ans = modINV(ans, mod);
        ans = -1*ans + mod;
    }

    return ans%mod;
}

int main() {
    int T;
    scanf("%d", &T);

    while(T--) {
        ll n, m;
        cin>>n>>m;
        cout<<fact(n, m)<<endl;
    }

    return 0;
}

