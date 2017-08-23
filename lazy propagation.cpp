#include<bits/stdc++.h>
using namespace std;
#define mx 1001

struct info{
 int prop, sum;
 info() {
  prop = 0;
  sum = 0;
 }
};

int a[mx];
info tree[mx*3];

void update(int node, int L, int R, int LL, int RR, int val) {
 if(LL>R || RR<L) return;
 if(L>=LL && R<=RR) {
    tree[node].sum+=(R-L+1)*val;
    tree[node].prop+=val;
    return;
 }

 int left = 2*node;
 int right = 2*node+1;
 int mid = (L+R)/2;
 update(left, L, mid, LL, RR, val);
 update(right, mid+1, R, LL, RR, val);
 tree[node].sum = tree[left].sum + tree[right].sum + ((R-L+1)*tree[node].prop);
}

int query(int node, int L, int R, int LL, int RR, int carry) {
 if(LL>R || RR<L) return 0;
 if(L>=LL && R<=RR) return tree[node].sum + (R-L+1)*carry;

 int left = 2*node;
 int right = 2*node+1;
 int mid = (L+R)/2;
 int p1 = query(left, L, mid, LL, RR, carry+tree[node].prop);
 int p2 = query(right, mid+1, R, LL, RR, carry+tree[node].prop);
 return p1+p2;
}

void init(int node, int L, int R) {
 if(L==R){
    tree[node].sum = a[L];
    return;
 }

 int left = 2*node;
 int right = 2*node+1;
 int mid = (L+R)/2;
 init(left, L, mid);
 init(right, mid+1, R);
 tree[node].sum = tree[left].sum + tree[right].sum;
}

int main() {
 int n, i;
 cin>>n;
 for(i=0; i<n; i++) cin>>a[i];
 init(1, 0, n-1);
 cout<<query(1, 0, n-1, 0, 2, 0)<<endl;
 update(1, 0, n-1, 0, 2, 12);
 cout<<query(1, 0, n-1, 2, 3, 0)<<endl;
}

