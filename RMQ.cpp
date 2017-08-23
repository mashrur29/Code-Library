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


/*

8 3
10 15 3 8 11 13 18 19
5 7
3 6
1 3

*/

