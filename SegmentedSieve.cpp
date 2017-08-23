#include<bits/stdc++.h>
using namespace std;

const int maxi = 2000001;
bool is[maxi];
vector<long long> p;

void sieve() {
    memset(is, 0, sizeof(is));
    int lim, n = maxi-1;
    lim = sqrt(n);
    is[1] = true;
    for(int i=3; i<=lim; i+=2) {
        if(!is[i]) {
            for(int j = i*i; j<=n; j+=2*i) is[j] = 1;
        }
    }

    p.push_back(2);
    for(int i=3; i<=n; i+=2) {
        if(!is[i]) p.push_back(i);
    }
}

int segmented_sieve(int L, int R) {
    int range = R - L, cnt = 0;
    vector<long long> prime_in_range;

    bool ok[maxi-1];
    memset(ok, 0, sizeof(ok));

    for(int i=0; i<p.size(); i++) {
        long long prime = p[i];
        long long inc = prime + prime;

        long long start = max(((L + prime - 1)/prime)*prime, prime*prime);
        if((start&1)==0) {
            start += prime;
        }

        start -= L;
        for(long long j=start; j<=range; j+=inc) ok[j] = 1;
    }

    if(L<=2 && R>=2) prime_in_range.push_back(2);
    for(long long k = (L & 1) ? 0 : 1; k<=range; k+=2) {
        if(!ok[k]) prime_in_range.push_back(L + k);
    }

    return prime_in_range.size();
}

int main() {
    sieve();
    int l, r;

    while(scanf("%d %d", &l, &r)==2) {
        if(l==1) l++;
        cout<<segmented_sieve(l, r)<<endl;
    }

    return 0;
}

