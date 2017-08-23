// uva 872

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

