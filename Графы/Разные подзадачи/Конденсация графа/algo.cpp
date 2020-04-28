#include <bits/stdc++.h>
using namespace std;

const int N=1e5;

bool used[N];
int n,m,x,y,v,t_color;
int color[N];
vector<int> topsort;
vector<int> g[N],gr[N];

void dfs1(int v){
    used[v]=true;
    for (int i=0; i<g[v].size(); i++){
        int to=g[v][i];
        if (!used[to]) dfs1(to);
    }
    topsort.push_back(v);
}

void dfs2(int v){
    color[v]=t_color;
    for (int i=0; i<gr[v].size(); i++){
        int to=gr[v][i];
        if (!color[to]) dfs2(to);
    }
}

int main(){
    scanf("%d%d",&n,&m);
    for (int i=0; i<m; i++){
        scanf("%d%d",&x,&y);
        g[x-1].push_back(y-1);
        gr[y-1].push_back(x-1);
    }
    for (int i=0; i<n; i++){
        if (!used[i]) dfs1(i);
    }
    for (int i=0; i<n; i++){
        v=topsort[n-i-1];
        if (!color[v]){
            t_color++;
            dfs2(v);
        }
    }
    printf("%d\n",t_color);
    for (int i=0; i<n; i++){
        printf("%d ",color[i]);
    }
    return 0;
}
