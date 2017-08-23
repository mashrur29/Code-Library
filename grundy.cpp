using namespace std;
#include<bits/stdc++.h>

int dp[100001];

int mex(unordered_set<int>s) {
   int mx=0;

   while(s.find(mx)!=s.end()) mx++;
   return mx;
}

int grundy(int n) {
  if(n==0) return 0;
  if(n==1) return 1;

  if(dp[n]!=-1) return dp[n];

  unordered_set<int>s;

  for(int i=1; i<=n/2; i++) {
    s.insert(grundy(n-i));
  }

  return dp[n] = mex(s);
}

int main() {
  memset(dp, -1, sizeof(dp));

  for(int i=1; i<=60; i+=2) cout<<grundy(i)<<endl;
}

