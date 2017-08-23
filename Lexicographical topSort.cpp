// uva 11060

#include<bits/stdc++.h>
using namespace std;

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

