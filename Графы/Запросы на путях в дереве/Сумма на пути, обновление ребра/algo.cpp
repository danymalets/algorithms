#include<bits/stdc++.h>
using namespace std;

const int N=1e5;
const int L=20;

int n,q,timer;
int h[N],sz[N],tin[N],lst[N],sump[N];
int p[N][L];
long long sum[N];
long long t[4*N];
vector<pair<int,int>> g[N];

    int lst0[5]={0,1,2,3,4};
    int sum0[5]={0,1,2,3,4};



void dfs(int v,int par=-1){
    sz[v]=1;
    lst[timer]=v;
    tin[v]=timer++;
    for (auto x: g[v]){
        int to=x.first,c=x.second;
        if (to==par) continue;
        sump[to]=c;
        p[to][0]=v;
        sum[to]=sum[v]+c;
        h[to]=h[v]+1;
        dfs(to,v);
        sz[v]+=sz[to];
    }
}

void build(int v=1,int tl=0,int tr=n-1){
    if (tl==tr){
        t[v]=sum[lst[tl]];
    }
    else{
        int tm=(tl+tr)/2;
        build(v*2,tl,tm);
        build(v*2+1,tm+1,tr);
    }
}

int get(int pos,int v=1,int tl=0,int tr=n-1){
    if (tl==tr){
        return t[v];
    }
    int tm=(tl+tr)/2;
    if (pos<=tm) return t[v]+get(pos,v*2,tl,tm);
    else return t[v]+get(pos,v*2+1,tm+1,tr);
}

void update(int l,int r,int val,int v=1,int tl=0,int tr=n-1){
    if (l>r) return;
    if (l==tl&&r==tr){
        t[v]+=val;
    }
    else{
        int tm=(tl+tr)/2;
        update(l,min(tm,r),val,v*2,tl,tm);
        update(max(tm+1,l),r,val,v*2+1,tm+1,tr);
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
    build();
    for (int i=1; i<L; i++){
        for (int v=0; v<n; v++){
            p[v][i]=p[p[v][i-1]][i-1];
        }
    }

    cin >> q;
    while(q--){
        int type;
        cin >> type;
        if (type==1){
            int v,u;
            cin >> v >> u;
            v--; u--;
            cout << get(tin[v])+get(tin[u])-2LL*get(tin[lca(v,u)]) << '\n';
        }
        else{
            int v,u,c;
            cin >> v >> u >> c;
            v--; u--;
            if (h[u]>h[v]) v=u;
            update(tin[v],tin[v]+sz[v]-1,c-sump[v]);
            sump[v]=c;
        }
    }
    return 0;
}

/*
7
1 6 1
1 3 6
6 4 2
6 2 4
3 7 4
3 5 3
100
1 7 5
2 3 5 1
1 7 5
*/



