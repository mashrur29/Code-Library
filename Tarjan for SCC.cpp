#include<bits/stdc++.h>
using namespace std;

const int mx = 1000;
vector<int> adj[mx];
int n, m, scc, tick;
bool vis[mx], stacked[mx];
int d[mx], low[mx], belong[mx];
stack<int> q;

void tarjan(int u) {
  d[u] = low[u] = tick++;
  q.push(u);
  stacked[u]=true;

  for(int i=0; i<adj[u].size(); i++) {
    int v = adj[u][i];

    if(d[v]==-1) {
        tarjan(v);
        low[u] = min(low[u], low[v]);
    }
    else if(stacked[v]) low[u] = min(low[u], low[v]);
  }

  if(d[u]==low[u]) {
    int v;
    scc++;

    do {
      v=q.top();
      q.pop();
      stacked[v] = false;
      belong[v] = scc;
    } while(u != v);

  }

}

int main() {
  memset(d, -1, sizeof(d));
  int edge;
  scc=0;
  tick=1;
  scanf("%d %d", &n, &edge);

  for(int i=1; i<=m; i++) {
    int u, v;
    scanf("%d %d", &u, &v);
    adj[u].push_back(v);
  }

  for(int i=1; i<=n; i++) {
    if(d[i]==-1) tarjan(i);
  }


  return 0;
}

