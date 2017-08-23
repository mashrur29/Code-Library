#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int n;
pair<int, int> a[10001];

ll cost(int pos) {
    int h = a[pos].first;
    ll ret = 0;
    for(int i=0; i<n; i++) {
        int diff = fabs(a[i].first - h);
        ret += a[i].second*diff;
    }
    //cout<<ret<<endl;
    return ret;
}

int main() {
    int T;
    scanf("%d", &T);

    while(T--) {
        ll res = 10000000;
        scanf("%d", &n);

        for(int i=0; i<n; i++) scanf("%d", &a[i].first);
        for(int i=0; i<n; i++) scanf("%d", &a[i].second);

       // cout<<endl;

        sort(a, a+n);
       // for(int i=0; i<n; i++) printf("%d %d\n", a[i].first, a[i].second);
       //reverse(a, a+n);

        int lo = 0, hi = n-1, mid1, mid2;

        while((hi-lo+1)>3) {
            int x = (hi - lo + 1)/3;
            mid1 = (lo * 2 + hi) / 3;
            mid2 = (lo + hi * 2) / 3;
            ll res1 = cost(mid1), res2 = cost(mid2);
            // cout<<res1<<" "<<res2<<endl;

            if(res1<res2) {
                hi = mid2;
            } else {
                lo = mid1;
            }
        }

        res = cost(lo);
        for(int i = lo; i<=hi; i++) {
            res = min(res, cost(i));
        }

        printf("%lld\n", res);

    }

    return 0;
}

