#include<bits/stdc++.h>
using namespace std;

const int maxi = 111;
int dp[2][maxi];
string a, b;

int main() {
    while(cin>>a>>b) {
        memset(dp, 0, sizeof(dp));

        for(int i=1; i<=a.size(); i++) {
            for(int j=1; j<=b.size(); j++) {
                if(a[i-1] == b[j-1]) dp[1][j] = 1 + dp[0][j-1];
                else dp[1][j] = max(dp[1][j-1], dp[0][j]);
            }

            for(int j=1; j<=b.size(); j++) dp[0][j] = dp[1][j];
        }

        cout<<dp[0][b.size()]<<endl;
    }

    return 0;
}

/*

ABCBDAB
BDCABA

*/
