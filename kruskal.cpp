#include<bits/stdc++.h>
using namespace std;

const int maxi = 1111;
int id[maxi], sz[maxi], n;
vector<pair<int, int>> adj[maxi];

inline void reset() {
    for(int i=0; i<maxi; i++) {
        id[i] = i;
        sz[i] = 1;
        adj[i].clear();
    }
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

bool connected(int x, int y) {
    return find(x)==find(y);
}

void merge(int x, int y) {
    int i = find(x);
    int j = find(y);

    if(i==j) return;

    if(sz[i]<sz[j]) {
        id[i] = j;
        sz[j]+=sz[i];
    } else {
        id[j] = i;
        sz[i]+=sz[j];
    }
}

void kruskal() {
    priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>> >, greater<pair<int, pair<int, int>> >> q;
    for(int i=1; i<=n; i++) {
        for(int j=0; j<adj[i].size(); j++) q.push(make_pair(adj[i][j].second, make_pair(i, adj[i][j].first)));
    }

    cout<<endl<<endl;
    while(!q.empty()) {
        int u = q.top().second.first;
        int v = q.top().second.second;
        int w = q.top().first;
        q.pop();
        if(!connected(u, v)) {
            merge(u, v);
            cout<<u<<" "<<v<<" "<<w<<endl;
        }
    }
}

int main() {
    reset();
    int m;
    scanf("%d %d", &n, &m);

    for(int i=0; i<m; i++) {
        int u, v, w;
        scanf("%d %d %d", &u, &v, &w);
        adj[u].push_back(make_pair(v, w));
        adj[v].push_back(make_pair(u, w));
    }

    kruskal();
}

