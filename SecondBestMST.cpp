#include<bits/stdc++.h>
#define INF INT_MAX
using namespace std;


const int maxi = 100011;
int inf = INT_MAX;
vector<int>llst;
int nod, edg, parent[maxi], take[maxi];


struct node {
    int u, v, w;
};

vector<node> adj;
struct node temp,tp;

bool comp(const node l, const node r) {
    return l.w < r.w;
}

inline void reset() {
    llst.clear();
    adj.clear();
    memset(take, 0, sizeof(take));
}

int find(int n) {
    if(parent[n]== n) {
        return n;
    } else {
        return parent[n]=find(parent[n]);
    }
}

int kruskal() {
    int u,v,cnt=0;
    int ret=0;


    for(int i=0; i<=nod; i++) {
        parent[i]=i;
    }

    for(int i=0; i<adj.size(); i++) {
        u = find(adj[i].u);
        v = find(adj[i].v);
        if(u!=v) {
            parent[v]=u;
            ret += adj[i].w;
            cnt++;
            llst.push_back(i);

        }

        if(cnt==(nod-1)) {
            return ret;
        }
    }


    return inf;
}


int kruskal_second() {
    int u, v, cnt=0;
    int ret=0;

    for(int i=0; i<=nod; i++) {
        parent[i]=i;
    }

    for(int i=0; i<adj.size(); i++) {
        u = find(adj[i].u);
        v = find(adj[i].v);
        if(u!=v && take[i]==0) {
            parent[v]=u;
            ret += adj[i].w;
            cnt++;
        }
        if(cnt==(nod-1)) {
            return ret;
        }
    }

    return inf;
}


int main() {
    int m, i;
    cin>>nod>>m;

    for(i=0; i<m; i++) {
        int x, y, c;
        cin>>x>>y>>c;
        temp.u=x;
        temp.v=y;
        temp.w=c;
        adj.push_back(temp);
    }



    if(m<=nod-1) {
        cout<<"No Second Best MST"<<endl;
    } else {
        sort(adj.begin(), adj.end(), comp);

        kruskal();
        int res = inf;

        for(int i=0; i<llst.size(); i++) {
            take[llst[i]]=1;
            res = min(res, kruskal_second());
            take[llst[i]]=0;
        }

        cout<<res<<endl;
    }


    return 0;
}
