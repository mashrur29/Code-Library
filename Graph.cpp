/************************** all possible topsort problem ***********************/

#include<bits/stdc++.h>
using namespace std;

const int maxi = 60;
vector<int> adj[maxi];
int tick, n, po[maxi][maxi];
char vis[maxi];
map<char, int> mp;
map<int, char> mp_res;
bool cycle, ok;

inline void reset() {
    ok = false;
    cycle = false;
    tick = 1;
    for (int i = 0; i < maxi; i++) {
        adj[i].clear();
        vis[i] = 'W';
    }
    memset(po, 0, sizeof(po));
    mp.clear();
    mp_res.clear();
}

void dfs(int node) {
    vis[node] = 'G';

    for (int i = 0; i < adj[node].size(); i++) {
        int u = adj[node][i];
        if (vis[u] == 'W') dfs(u);
        else if (vis[u] == 'G') cycle = true;
    }

    vis[node] = 'B';
}

void lol(int pos, int taken[], int res[]) {
    if (pos > n) {
        bool f = true;

        for (int i = 1; i <= n; i++) {
            for (int j = i + 1; j <= n; j++) {
                int u = res[j], v = res[i];
                if (po[u][v] == 1) {
                    f = false;
                    break;
                }
            }
            if (!f) break;
        }

        if (f) {
            ok = true;
            for (int i = 1; i <= n; i++) {
                if (i > 1) printf(" ");
                printf("%c", mp_res[res[i]]);
            }
            printf("\n");
        }
        return;
    }

    for (int i = 1; i <= n; i++) {
        if (!taken[i]) {
            taken[i] = 1;
            res[pos] = i;
            lol(pos + 1, taken, res);
            taken[i] = 0;
        }
    }
}

int main() {
    string s, s1;
    int T, caseno = 1;

    cin >> T;
    cin.ignore();

    while (T--) {
        reset();
        //if(caseno) cout<<endl;
        getline(cin, s);
        getline(cin, s1);

        for (int i = 0; i < s.size(); i += 2) {
            char ch = s[i];
            if (!mp[ch]) {
                mp[ch] = tick;
                mp_res[tick] = ch;
                tick++;
            }
        }

        n = tick - 1;

        for (int i = 0; i < s1.size(); i += 4) {
            int u = mp[s1[i]], v = mp[s1[i + 2]];
            //cout<<u<<" "<<v<<endl;
            if (s1[i + 1] == '<') adj[u].push_back(v), po[u][v] = 1;
            else adj[v].push_back(u), po[v][u] = 1;
        }

        for (int i = 1; i <= n; i++) {
            if (vis[i]=='W') {
                dfs(i);
            }
        }

        //cout << cycle << endl;
        if (cycle) printf("NO\n");
        else {
            int taken[maxi], res[maxi];
            memset(taken, 0, sizeof(taken));
            lol(1, taken, res);
        }

        //if(!ok) printf("NO\n");
        caseno++;
    }

    return 0;
}

/****************************** kruskal ***************************/

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

/**************************** Tarjan for scc ****************************/

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

/*************************** prims MST ***************************/

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

/****************************** Lexicographical topsort **********************/

const int maxi = 111;
vector<int> adj[maxi];
int in[maxi], n, tick, taken[maxi];
map<string, int> mp;
map<int, string> mp_res;

inline void reset() {
    mp.clear();
    mp_res.clear();
    tick = 1;
    for(int i=0; i<maxi; i++) {
        adj[i].clear();
        in[i] = 0;
        taken[i] = 0;
    }
}

int main() {
    int caseno = 1;

    while(scanf("%d", &n)==1) {
        reset();

        for(int i=1; i<=n; i++) {
            string u;
            cin>>u;
            if(!mp[u]) {
                mp[u] = tick;
                mp_res[tick] = u;
                tick++;
            }
        }

        int m;
        scanf("%d", &m);

        for(int i=1; i<=m; i++) {
            string u, v;
            cin>>u>>v;
            int u_ = mp[u], v_ = mp[v];
            adj[u_].push_back(v_);
            in[v_]++;
        }

        printf("Case #%d: Dilbert should drink beverages in this order:", caseno++);
        for(int k=1; k<=n; k++) {
            for(int i=1; i<=n; i++) {
                if(!in[i] && !taken[i]) {
                    cout<<" "<<mp_res[i];

                    for(int j=0; j<adj[i].size(); j++) {
                        in[adj[i][j]]--;
                    }
                    taken[i] = 1;
                    break;
                }
            }
        }
        printf(".\n\n");
    }

    return 0;
}

/******************************** dijkstra ************************/

while(!q.empty()){
           x=q.top().second;
           lim=a[x].size();
           q.pop();

                for(i=0;i<lim;i++){
                    pp=a[x][i].first; ppw=a[x][i].second;
                    if(ppw+d[x]<d[pp]){
                        p[pp]=x;
                        ll t=d[x]+ppw;
                        q.push(pii(-(d[pp]=t),pp));
                    }
                }
  }

/*************************** DFS *********************/

void visit(int x){
   color[x]='G';

   for(i=1; i<=N; i++){
             
       if(adj[x][i]){
          
          if(color[i]=='W'){
            
            visit(i);
            
          }  
       }
     }
    
  color[x]='B';  
}

/**************************** Floyd-Warshall *************************/

#include <iostream>
#include <conio.h>
using namespace std;
void floyds(int b[][7])
{
    int i, j, k;
    for (k = 0; k < 7; k++)
    {
        for (i = 0; i < 7; i++)
        {
            for (j = 0; j < 7; j++)
            {
                if ((b[i][k] * b[k][j] != 0) && (i != j))
                {
                    if ((b[i][k] + b[k][j] < b[i][j]) || (b[i][j] == 0))
                    {
                        b[i][j] = b[i][k] + b[k][j];
                    }
                }
            }
        }
    }
    for (i = 0; i < 7; i++)
    {
        cout<<"\nMinimum Cost With Respect to Node:"<<i<<endl;
        for (j = 0; j < 7; j++)
        {
            cout<<b[i][j]<<"\t";
        }
 
    }
}

int main()
{
    int b[7][7];
    cout<<"ENTER VALUES OF ADJACENCY MATRIX\n\n";
    for (int i = 0; i < 7; i++)
    {
        cout<<"enter values for "<<(i+1)<<" row"<<endl;
        for (int j = 0; j < 7; j++)
        {
            cin>>b[i][j];
        }
    }
    floyds(b);
}

/**************************  Bellmanford Algorithm ************************/

#include<bits/stdc++.h>
using namespace std;
#define mp(a, b, c) make_pair(make_pair(a, b), c)

const int maxi = 1001;
vector<pair<pair<int, int>, int> > adj;
int n, inf = 10000001, d[maxi];
bool neg_cycle;

inline void reset() {
    for(int i=0; i<maxi; i++) {
        d[i] = inf;
    }
    adj.clear();
    neg_cycle = false;
}

void bellman(int src) {
    d[src] = 0;

    for(int k = 1; k<=n-1; k++) {
        for(int i=0; i<adj.size(); i++) {
            int u = adj[i].first.first;
            int v = adj[i].first.second;
            int w = adj[i].second;
            if(d[u] + w < d[v]) {
                d[v] = d[u] + w;
            }
        }
    }

    for(int i=0; i<adj.size(); i++) {
        int u = adj[i].first.first;
        int v = adj[i].first.second;
        int w = adj[i].second;
        if(d[u] + w < d[v]) {
            neg_cycle = true;
            return;
        }
    }

    return;
}

int main() {
    reset();
    int n, m;
    scanf("%d %d", &n, &m);

    for(int i=1; i<=m; i++) {
        int u, v, w;
        scanf("%d %d %d", &u, &v, &w);
        adj.push_back(mp(u, v, w));
    }

    for(int i=0; i<n; i++) {
        if(d[i]==inf) bellman(i);
        if(neg_cycle) break;
    }

    return 0;
}


/***************************** Articulation Point ********************/

int d[maxi], low[maxi], par[maxi], tick;
void dfs(int node, int root) {
    d[node] = tick;
    low[node] = tick;
    tick++;
    int child = 0;

    for(int i=0; i<adj[node].size(); i++) {
        int u = adj[node][i];
        if(u==par[node]) continue;

        if(d[u]==-1) {
            child++;
			par[u] = node;
            dfs(u, root);
            low[node] = min(low[node], low[u]);

            if(d[node]<=low[u] && node!=root) {
               // node is an articulation point
            }

            if(node==root && child>1) {
                // node is an articulation point
            }

        } else if(u!=par[node]) low[node] = min(low[node], d[u]);

    }

}

/********************** Bridge ************************/

void dfs(int node, int root) {
    d[node] = ++tm_;
    low[node] = d[node];
    int child = 0;
 
    for(int i=0; i<adj[node].size(); i++) {
        int u = adj[node][i];
        if(d[u]==-1) {
            dfs(u, node);
            ++child;
            low[node] = min(low[node], low[u]);
            if(d[u]==low[u]) {
                // u, node is a bridge
            }
 
        } else if(u!=root) low[node] = min(d[u], low[node]);
 
    }
 
}

/*************** Tarjan's algorithm for finding bridges in an undirected graph ********************/

void dfs(int node, int root) {
    d[node] = ++tm_;
    low[node] = d[node];
    int child = 0;

    for(int i=0; i<adj[node].size(); i++) {
        int u = adj[node][i];
        if(!d[u]) {
            dfs(u, node);
            ++child;
            low[node] = min(low[node], low[u]);
            if(d[u]==low[u]) {
                int ta, tb;
                ta = min(u, node);
                tb = max(u, node);
                res.push_back(mp(ta, tb));
            }

        } else if(u!=root) low[node] = min(d[u], low[node]);

    }

}

/****************** Biconnected Component **********************/

#include<bits/stdc++.h>
using namespace std;

const int maxi = 1111;
vector<int> adj[maxi];
stack<pair<int, int> > st;
int d[maxi], low[maxi], par[maxi], tick;

inline void reset() {
    for(int i=0; i<maxi; i++) {
        adj[i].clear();
        d[i] = -1;
        par[i] = -1;
    }
    tick = 1;
}

void outputBCC(int u, int v) {
	// Biconnected component found

    while(1) {
        int p1 = st.top().first, p2 = st.top().second;
        st.pop();
        //cout<<p1<<" "<<p2<<endl;
        if((p1==u && p2==v) || (p1==v && p2==u)) break;
    }
}

void dfs(int node) {
    d[node] = low[node] = tick++;

    for(int i=0; i<adj[node].size(); i++) {
        int u = adj[node][i];
        if(d[u]==-1) {
            st.push(make_pair(node, u));
            par[u] = node;
            dfs(u);
            if(d[node]<=low[u]) {
                outputBCC(node, u);
            }
			low[node] = min(low[node], low[u]);
        } else if(par[node]!=u && d[u]<d[node]) {
            st.push(make_pair(node, u));
            low[node] = min(low[node], d[u]);
        }
    }

}

int main() {
    reset();
    int n, m;

    scanf("%d %d", &n, &m);

    for(int i=0; i<m; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    for(int i=0; i<n; i++) {
        if(d[i]==-1) dfs(i);
     }

     return 0;
}

/******************  Biconnected component odd and even length ************************/

#include<bits/stdc++.h>
using namespace std;
#define pb(a) push_back(a)
#define mp(a,g) make_pair(a,g)
const int MAX = 10005;

int par[MAX] = {0},child[MAX]= {0},low[MAX] = {0},tym[MAX]= {0};
bool visit[MAX]= {0},isCut= {0};
static int t=0;
stack <pair <int,int> > bc;
vector <int> a[MAX];
int odd=0,even=0;


void BCdfs(int s) {
    visit[s] = true;
    low[s]=tym[s]=t++;
    for(int i=0; i<a[s].size(); i++) {
        int v = a[s][i];
        if(!visit[v]) {
            par[v] = s;
            child[s]++;
            bc.push(mp(s,v));
            BCdfs(v);

            low[s] = min(low[s],low[v]);
            if((tym[s]==1 and child[s]>1)||( low[v]>=tym[s])) {
                set<int> nodes;
                while(bc.top().first !=s || bc.top().second !=v) {
                    nodes.insert(bc.top().first);
                    nodes.insert(bc.top().second);
                    bc.pop();
                }
                nodes.insert(bc.top().first);
                nodes.insert(bc.top().second);
                bc.pop();
                if(nodes.size()!=0 and nodes.size()&1)odd++;
                else even++;
            }
        } else if(v!=par[s] && tym[v]<low[s]) {
            low[s] = min(low[s],tym[v]);
            bc.push(mp(s,v));
        }
    }
}


int main() {
    int n,m,x,y;
    cin>>n>>m;
    while(m--) {
        cin>>x>>y;
        a[x+1].pb(y+1);
        a[y+1].pb(x+1);
    }
    par[1] = -1;
    for(int i=1; i<=n; i++) {
        if(!visit[i])
            BCdfs(i);
    }
    set <int> nodes;
    while(!bc.empty()) {
        cout<<bc.top().first<<" "<<bc.top().second<<"\n";
        nodes.insert(bc.top().first);
        nodes.insert(bc.top().second);
        bc.pop();
    }

    if(nodes.size()!=0 and nodes.size()&1)odd++;
    else if(nodes.size()!=0 ) even++;

    cout<<odd<<" "<<even;

    return 0;
}

/***************** sort edges after finding BCC ***************/

#include<bits/stdc++.h>
using namespace std;

const int maxi = 100001;
vector<int> adj[maxi];
priority_queue<pair<int, int>, vector<pair<int, int> >, greater<pair<int, int> > > res[maxi], res1[maxi];
vector<pair<int, pair<int, int> > > give;
int d[maxi], low[maxi], tick, cmp, par[maxi], taken[maxi];
stack<pair<int, int> > q;
vector<pair<int, int> > gv[maxi];

inline void reset() {
    for(int i=0; i<maxi; i++) {
        adj[i].clear();
        d[i] = -1;
        par[i] = -1;
        taken[i] = 0;
        gv[i].clear();
    }
    while(!q.empty()) q.pop();
    tick = 1;
    cmp = 1;
    give.clear();
}

void BCC(int u, int v) {
    while(1) {
        int u1 = q.top().first, v1 = q.top().second;
        res[cmp].push(make_pair(min(u1, v1), max(u1, v1)));
        res1[cmp].push(make_pair(min(u1, v1), max(u1, v1)));
        q.pop();
        if((u1==u && v1==v) || (u1==v && v1==u)) break;
    }
    cmp++;
}

void dfs(int node) {
    d[node] = low[node] = tick++;

    for(int i=0; i<adj[node].size(); i++) {
        int u = adj[node][i];
        if(d[u]==-1) {
            par[u] = node;
            q.push(make_pair(node, u));
            dfs(u);

            if(d[node]<=low[u]) {
                BCC(node, u);
            }

            low[node] = min(low[node], low[u]);
        } else if(u!=par[node] && d[u]<d[node]) {
            q.push(make_pair(node, u));
            low[node] = min(low[node], d[u]);
        }
    }

}

int main() {
    reset();
    int n, m;
    scanf("%d %d", &n, &m);

    for(int i=0; i<m; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    for(int i=0; i<n; i++) {
        if(d[i]==-1) dfs(i);
    }


    for(int i=1; i<cmp; i++) {
        while(!res[i].empty()) {
            int u = res[i].top().first, v = res[i].top().second;
            res[i].pop();
            give.push_back(make_pair(u, make_pair(v, i)));
        }
    }

    sort(give.begin(), give.end());
    int p = 1;

    for(int i=0; i<give.size(); i++) {
        int id = give[i].second.second;

        if(taken[id]) continue;
        taken[id] = 1;
        while(!res1[id].empty()) {
            gv[p].push_back(make_pair(res1[id].top().first, res1[id].top().second));
            res1[id].pop();
        }
        p++;
    }

    for(int i=1; i<p; i++) {
        for(int j=0; j<gv[i].size(); j++) {
            printf("%d %d\n", gv[i][j].first, gv[i][j].second);
        }
        if(i!=p-1) printf("---\n");
    }

}

/*

5
4
0 1 10
1 2 1073741824
0 3 20
3 4 1073741824
2

*/

