#include<bits/stdc++.h>
using namespace std;

const int INF=2e9;
const int N=1e5;
const int L=20;

int n,q;
int h[N],p[N][L];
int mn[N][L];
vector<pair<int,int>> g[N];

void dfs(int v,int par=-1){
    for (auto x: g[v]){
        int to=x.first,c=x.second;
        if (to==par) continue;
        p[to][0]=v;
        mn[to][0]=c;
        h[to]=h[v]+1;
        dfs(to,v);
    }
}

int up(int &v,int len){
    int res=INF;
    for (int i=L-1; i>=0; i--){
        if ((1<<i)<=len){
            res=min(res,mn[v][i]);
            v=p[v][i];
            len-=(1<<i);
        }
    }
    return res;
}

int get(int v,int u){
    int res=INF;
    if (h[v]>h[u]) res=min(res,up(v,h[v]-h[u]));
    else if (h[u]>h[v]) res=min(res,up(u,h[u]-h[v]));
    if (v==u) return res;
    for (int i=L-1; i>=0; i--){
        if (p[v][i]!=p[u][i]){
            res=min(res,mn[v][i]);
            v=p[v][i];
            res=min(res,mn[u][i]);
            u=p[u][i];

        }
    }
    res=min(res,mn[v][0]);
    res=min(res,mn[u][0]);
    return res;
}

int main(){
    cin >> n;
    for (int i=1; i<n; i++){
        int v,u,c;
        cin >> v >> u >> c;
        v--; u--;
        g[v].push_back(make_pair(u,c));
        g[u].push_back(make_pair(v,c));
    }
    dfs(0);
    for (int i=1; i<L; i++){
        for (int v=0; v<n; v++){
            p[v][i]=p[p[v][i-1]][i-1];
            mn[v][i]=min(mn[v][i-1],mn[p[v][i-1]][i-1]);
        }
    }
    cin >> q;
    int v=7-1;
    cout << up(v,1) << ' ';
    cout << v+1;
    while(q--){
        int v,u;
        cin >> v >> u;
        v--; u--;
        cout << get(v,u) << '\n';
    }
    return 0;
}
