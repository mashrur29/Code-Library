#include<bits/stdc++.h>
using namespace std;

const int maxi = 1111;
vector<pair<int, int>> adj[maxi];
int n;

void MST(int src) {
    int d[maxi], taken[maxi], par[maxi];
    priority_queue<pair<int, int>, vector<pair<int, int> >, greater<pair<int, int>> > q;

    for(int i=0; i<maxi; i++) {
        d[i] = INT_MAX;
        taken[i] = 0;
        par[i] = -1;
    }

    q.push(make_pair(0, src));

    while(!q.empty()) {
        int pp = q.top().second;
        q.pop();
        taken[pp] = 1;

        for(int i=0; i<adj[pp].size(); i++) {
            int u = adj[pp][i].first;
            int w = adj[pp][i].second;
            if(!taken[u] && d[u]>w) {
                d[u] = w;
                q.push(make_pair(d[u], u));
                par[u] = pp;
            }
        }
    }

    cout<<endl<<endl<<"The required graph"<<endl;
    for(int i=src+1; i<=n; i++) cout<<par[i]<<" "<<i<<" "<<d[i]<<endl;

}

int main() {
    int m;

    scanf("%d %d", &n, &m);
    for(int i=0; i<m; i++) {
        int u, v, w;
        scanf("%d %d %d", &u, &v, &w);
        adj[u].push_back(make_pair(v, w));
        adj[v].push_back(make_pair(u, w));
    }

    MST(1);
}

/*

8 11
1 5 2
1 2 4
1 4 10
2 4 8
4 5 5
2 3 18
3 4 11
4 8 9
4 7 11
6 8 2
6 7 1

*/

