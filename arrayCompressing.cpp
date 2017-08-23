#include<bits/stdc++.h>
using namespace std;

int res[100];

void compress(int item[], int n) {
   map<int, int> mp;
   int i, com=0;
   for(i=0; i<n; i++) {
    if(mp.find(item[i])==mp.end()) {
        mp[item[i]]=com++;
    }
    res[i]=mp[item[i]];
   }

}

int main() {
   int item[12]={-102,1,134565589,134565589,-102,66666668,134565589,66666668,-102,1,-2};
   int n=12;
   compress(item, n);

   for(int i=0; i<n; i++) cout<<res[i]<<" ";
   puts("");
   return 0;
}

