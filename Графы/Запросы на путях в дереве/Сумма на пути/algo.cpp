#include<bits/stdc++.h>
using namespace std;

const int N=1e5;
const int L=20;

int n,q;
int h[N],p[N][L];
long long sum[N];
vector<pair<int,int>> g[N];

void dfs(int v,int par=-1){
    for (auto x: g[v]){
        int to=x.first,c=x.second;
        if (to==par) continue;
        p[to][0]=v;
        sum[to]=sum[v]+c;
        h[to]=h[v]+1;
        dfs(to,v);
    }
}

void up(int &v,int len){
    for (int i=L-1; i>=0; i--){
        if ((1<<i)<=len){
            v=p[v][i];
            len-=(1<<i);
        }
    }
}

int lca(int v,int u){
    up(v,h[v]-h[u]);
    up(u,h[u]-h[v]);
    if (v==u) return v;
    for (int i=L-1; i>=0; i--){
        if (p[v][i]!=p[u][i]){
            v=p[v][i];
            u=p[u][i];
        }
    }
    return p[v][0];
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
        }
    }
    cin >> q;
    while(q--){
        int v,u;
        cin >> v >> u;
        v--; u--;
        cout << sum[v]+sum[u]-2LL*sum[lca(v,u)] << '\n';
    }
    return 0;
}
