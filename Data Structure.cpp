// TRIE

struct node{
  bool endmark;
  node *next[26+1];
  node() {
   endmark = false;
   for(int i = 0; i<26; i++) next[i] = NULL;
  }
};

struct TRIE {
  node *root;
  bool pre;

  TRIE() {
   root = new node();
   pre = false;
  }

  void insert(string str) {
   node *curr = root;
   int cnt = 0;

   int len = str.size();
   for(int i=0; i<len; i++) {
    int id = str[i] - 'a';
    if(curr->next[id]==NULL) {
            curr->next[id] = new node();
    }
    else cnt++;

    if(curr->endmark) pre = true;
    curr = curr->next[id];
   }

   if(cnt==len) pre = true;
   curr->endmark = true;
  }

  bool search(string str) {
   node *curr = root;
   int len = str.size();

   for(int i=0; i<len; i++) {
    int id = str[i] - 'a';
    if(curr->next[id]==NULL) return false;
    curr = curr->next[id];
   }


   return curr->endmark;
  }

  void del(node *curr) {
   for(int i=0; i<26; i++) {
    if(curr->next[i]) del(curr->next[i]);
   }
   delete(curr);
  }

  bool prefix() {
   return pre;
  }

};

// Segement Tree

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

// Lazy

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

// RMQ

#include<bits/stdc++.h>
using namespace std;
#define pii pair<int, int>

int main(){
  priority_queue<pii, vector<pii>, greater<pii>> p;
  deque<pii> q;
  vector<int> res;
  pii temp;
  int qu, i, n, a[100], m;

  cin>>n>>qu;
  for(i=0; i<n; i++) cin>>a[i];

  for(i=0; i<qu; i++){
    cin>>temp.second>>temp.first;
    p.push(temp);
  }


  for(i=0; i<n; i++) {
    if(p.empty()) break;

    while(!q.empty() && q.front().second<p.top().second) q.pop_front();

    if(i==p.top().first) {
        res.push_back(q.front().first);
        p.pop();
        while(!q.empty() && q.front().second<p.top().second) q.pop_front();
    }

    while(!q.empty() && q.back().first>=a[i]) q.pop_back();
    q.push_back(pii(a[i],i));

  }

  for(i=0; i<res.size(); i++) cout<<res[i]<<" ";
  cout<<endl;
  return 0;

}

// Sliding RMQ

#include<bits/stdc++.h>
using namespace std;
#define pii pair<int,int>
vector<int>res;

void sliding_rmq(int a[], int n, int m) {
  deque<pii>q;
  res.clear();

  for(int i=0; i<n; i++) {

    while(!q.empty() && q.back().first>=a[i]) q.pop_back();
    q.push_back(pii(a[i],i));
    while(!q.empty() && q.front().second<=i-m) q.pop_front();
    if(i>=m-1) res.push_back(q.front().first);

  }

}

int main() {
  int n, m, a[100], i;

  cin>>n>>m;
  for(i=0; i<n ;i++) cin>>a[i];
  sliding_rmq(a, n, m);
  for(i=0; i<res.size(); i++) cout<<res[i]<<" ";
  cout<<endl;
  return 0;
}


// Returning vector

#include<bits/stdc++.h>
using namespace std;
#define pii pair<int,int>

vector<int> sliding_rmq(int a[], int n, int m) {
  deque<pii>q;
  vector<int>res;

  for(int i=0; i<n; i++) {

    while(!q.empty() && q.back().first>=a[i]) q.pop_back();
    q.push_back(pii(a[i],i));
    while(!q.empty() && q.front().second<=i-m) q.pop_front();
    if(i>=m-1) res.push_back(q.front().first);

  }
  return res;
}

int main() {
  int n, m, a[100], i;
  vector<int>res;

  cin>>n>>m;
  for(i=0; i<n ;i++) cin>>a[i];
  res = sliding_rmq(a, n, m);
  
  for(i=0; i<res.size(); i++) cout<<res[i]<<" ";
  cout<<endl;
  return 0;
}

// Union finding

#include<bits/stdc++.h>
using namespace std;

class UF {
  int *id, cnt, *sz;

  public:

  UF(int N) {
    cnt = N;
    id = new int[N];
    sz = new int[N];
    for(int i=0; i<N; i++) {
        id[i] = i;
        sz[i] = 1;
    }
  }

  ~UF() {
   delete [] id;
   delete [] sz;
  }

  int find(int p) {
   int root = p;

   while(root!=id[root]) root = id[root];

   while(p!=root) {
    int temp = id[p];
    id[p] = root;
    p = id[p];
   }

   return root;
  }

  void merge(int x, int y) {
    int i = find(x);
    int j = find(y);

    if(i==j) return;

    if(sz[i]<sz[j]) {
        id[i] = j;
        sz[j]+=sz[i];
    }
    else {
        id[j] = i;
        sz[i]+=sz[j];
    }

    cnt--;
  }

  bool connected(int x, int y) {
   return find(x)==find(y);
  }

  int count() {
   return cnt;
  }

};

int main() {
   UF L(7);
   cout<<L.count()<<endl;
}
