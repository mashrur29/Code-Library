#include<bits/stdc++.h>
using namespace std;
const int maxstate=500*500+100;
const int maxchar=30;
bitset<500>output[maxstate];
int go[maxstate][maxchar];
int f[maxstate];
char highestchar='z';
char lowestchar='a';
string keywords[510];
string searchspace;
int ans[510],n;
 
void build()
{
    for(int  i = 0 ; i<maxstate; ++i)output[i].reset();
    memset(f, -1, sizeof f);
    memset(go, -1, sizeof go);
    int states = 1;
    for (int i = 0; i <n; ++i)
    {
        int current=0;
        for (int j = 0; j < keywords[i].size(); ++j)
        {
            int c = keywords[i][j] - lowestchar;
            if (go[current][c] == -1) {
                go[current][c] = states++;
            }
            current=go[current][c];
        }
        output[current].set(i);
    }
   
    for (int c = 0; c < maxchar; ++c)if (go[0][c] == -1)go[0][c] = 0;
    queue<int> q;
    for (int c = 0; c < maxchar; ++c)
    {
        if (go[0][c] != 0)
        {
            f[go[0][c]] = 0;
            q.push(go[0][c]);
        }
    }
    while (!q.empty())
    {
        int state = q.front();q.pop();
       
        for (int c = 0; c <= highestchar - lowestchar; ++c)
        {
            if (go[state][c] != -1)
            {
                int failure = f[state];
                while (go[failure][c] == -1) failure = f[failure];
                failure = go[failure][c];
                f[go[state][c]] = failure;
                output[go[state][c]] |= output[failure];
                q.push(go[state][c]);
            }
        }
    }
}
int findNextState(int currentState, char nextInput) {
    int answer = currentState;
    int c = nextInput - lowestchar;
    while (go[answer][c] == -1) answer = f[answer];
    return go[answer][c];
}
 
void solve()
{
    build();
    int currentState = 0;
        for (int i = 0; i < searchspace.size(); ++i)
        {
           currentState = findNextState(currentState, searchspace[i]);
           if (output[currentState] == 0) continue;
           for (int j = 0; j < n; ++j)if (output[currentState].test(j)) ans[j]++;
       }
}
int main()
{
    ios_base::sync_with_stdio(false);cin.tie(NULL);
    int t,cas=0;
    cin>>t;
    while(t--)
    {
        memset(ans,0,sizeof ans);
        cin>>n;
        cin>>searchspace;
        for(int i=0;i<n;i++)cin>>keywords[i];
        solve();
        cout<<"Case "<<++cas<<":"<<endl;
        for(int i=0;i<n;i++)cout<<ans[i]<<endl;
    }
    return 0;
}
//prob+aho
double getProb (int u, int dep) {
    if (dep == 0)
        return 1.0;

    if (vis[u][dep])
        return dp[u][dep];

    vis[u][dep] = 1;

    double& ans = dp[u][dep];
    ans = 0;

    for (int i = 0; i < sigma_size; i++) {
        if (last[ac[u][i]] == 0)
            ans += pi[i] * getProb(ac[u][i], dep - 1);
    }
    return ans;
}
//////
void dfs(Node *p, Node *q) {
        for (int i = 0; i < MAXCHAR; i++) {
            if (q->next[i]) {
                Node *u = p->next[i], *v = q->next[i];
                if (u == NULL)
                    p->next[i] = getNode(), u = p->next[i];
                u->cnt |= v->cnt;
                dfs(u, v);
            }
        }
    }
    void merge(const ACmachine &other) {
        dfs(root, other.root);
    }
