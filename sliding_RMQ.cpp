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

