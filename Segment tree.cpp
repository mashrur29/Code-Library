#include<bits/stdc++.h>
using namespace std;
#define mx 1001

int a[mx], tree[mx*3];

int query(int node, int L, int R, int left_bound, int right_bound) {
  if(L>=left_bound && R<=right_bound) return tree[node];
  if(L>right_bound || left_bound>R) return 0;

  int left = 2*node;
  int right = 2*node+1;
  int mid = (L+R)/2;
  return query(left, L, mid, left_bound, right_bound) + query(right, mid+1, R, left_bound, right_bound);
}

void update(int node, int L, int R, int ind, int val) {
  if(ind<L || ind >R) return;
  if(L>=ind && R<=ind) {
    tree[node] = val;
    return;
  }

  int left = 2*node;
  int right = 2*node+1;
  int mid = (L+R)/2;
  update(left, L, mid, ind, val);
  update(right, mid+1, R, ind, val);
  tree[node] = tree[left] + tree[right];
}

void init(int node, int L, int R) {
   if(L==R) {
    tree[node] = a[L];
    return;
   }

   int left = 2*node;
   int right = 2*node+1;
   int mid = (L+R)/2;
   init(left, L, mid);
   init(right, mid+1, R);

   tree[node] = tree[left] + tree[right];
}

int main() {
    int n;
    cin>>n;
    for(int i=0; i<n; i++) cin>>a[i];
    init(1,0,n-1);
    cout<<query(1, 0, n-1, 2, 4)<<endl;
    update(1, 0, n-1, 0, 0);
    cout<<query(1, 0, n-1, 0, 4)<<endl;
    return 0;
}


