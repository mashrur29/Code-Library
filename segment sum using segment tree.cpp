#include<bits/stdc++.h>
using namespace std;

struct info {
    int best_left, best_right, seg_sum, total;
};

const int maxi = 50011;
info tree[3*maxi];
int a[maxi];

info set_(int val) {
    info ret;
    ret.total = val;
    ret.best_left = ret.best_right = ret.seg_sum = max(-100001, val);
    return ret;
}

info comb(info L, info R) {
    info ret;
    ret.total = L.total + R.total;
    ret.best_left = max(max(L.best_left, L.total), L.total + R.best_left);
    ret.best_right = max(max(R.best_right, R.total), R.total + L.best_right);
    ret.seg_sum = max(max(L.seg_sum, R.seg_sum), R.best_left + L.best_right);
    return  ret;
}

info query(int node, int L, int R, int LL, int RR) {
    if(RR<L || LL>R) return set_(-100001);
    if(L>=LL && R<=RR) return tree[node];
    int left = 2*node;
    int right = left + 1;
    int mid = (L + R) / 2;

    if(RR<=mid) return query(left, L, mid, LL, RR);
    else if(LL>mid) return query(right, mid+1, R, LL, RR);
    return comb(query(left, L, mid, LL, RR), query(right, mid+1, R, LL, RR));
}

void update(int node, int L, int R, int ind, int val) {
    if(L==R && ind==L) {
        tree[node] = set_(val);
        return;
    }
    int left = 2*node;
    int right = left + 1;
    int mid = (L + R) / 2;

    if(ind<=mid) update(left, L, mid, ind, val);
    else update(right, mid+1, R, ind, val);
    tree[node] = comb(tree[left], tree[right]);
}

void init(int node, int L, int R) {
    if(L==R) {
        tree[node] = set_(a[L]);
        return;
    }

    int left = 2*node;
    int right = left + 1;
    int mid = (L + R) / 2;
    init(left, L, mid);
    init(right, mid+1, R);
    tree[node] = comb(tree[left], tree[right]);
}

int main() {
    int n, q;
    scanf("%d", &n);
    for(int i=1; i<=n; i++) scanf("%d", &a[i]);
    init(1, 1, n);

    scanf("%d", &q);
    for(int i=1; i<=q; i++) {
        int tp, l, r;
        scanf("%d %d %d", &tp, &l, &r);
        if(tp) printf("%d\n", query(1, 1, n, l, r).seg_sum);
        else update(1, 1, n, l, r);
    }

    return 0;
}

