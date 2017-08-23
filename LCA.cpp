#include<bits/stdc++.h>
using namespace std;
#define pii pair<int, int>

const int maxi = 20000;
vector<pii> adj[maxi];
int sparse[maxi][22], par[maxi], dis[maxi], d[maxi], n;

inline void reset() {
    for(int i=0; i<maxi; i++) adj[i].clear();
    memset(d, 0, sizeof(d));
    memset(dis, 0, sizeof(dis));
    memset(sparse, -1, sizeof(sparse));
}

void dfs(int from, int node, int depth) {
    par[node] = from;
    d[node] = depth;

    for(int i=0; i<adj[node].size(); i++) {
        pii x = adj[node][i];
        if(x.first==from) continue;
        dis[x.first] = dis[node] + x.second;
        dfs(node, x.first, depth + 1);
    }

}

int lca(int u, int v) {
    if(d[u]<d[v]) swap(u, v);

    int log = 1;
    while(1) {
        if(1<<(log+1)>d[u]) break;
        log++;
    }

    for(int i = log; i>=0; i--) {
        if(d[u] - (1<<i) >= d[v]) u = sparse[u][i];
    }

    if(u==v) return u;

    for(int i = log; i >= 0; i--) {
        if(sparse[u][i] != -1 && sparse[u][i] != sparse[v][i]) {
            u = sparse[u][i];
            v = sparse[v][i];
        }
    }

    return par[u];
}

void init() {
    for(int i = 0; i < n; i++) sparse[i][0] = par[i];

    for(int j = 1; (1<<j)<n; j++) {
        for(int i=0; i<n; i++) {
            if(sparse[i][j-1]!=-1) {
                sparse[i][j] = sparse[sparse[i][j-1]][j-1];
            }
        }
    }

}
