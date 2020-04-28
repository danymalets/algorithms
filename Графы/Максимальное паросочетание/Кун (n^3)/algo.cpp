#include<bits/stdc++.h>
using namespace std;

const int N=100;

bool used[N];
int n,m,couples;
int matching[N];
vector<int> g[N];

bool findway(int v){
    used[v]=true;
    for (int i=0; i<g[v].size(); i++){
        int to=g[v][i];
        if (used[to]) continue;
        if (matching[to]==-1||findway(matching[to])){
            matching[v]=to;
            matching[to]=v;
            return true;
        }
    }
    return false;
}

int main(){
    freopen("input.txt","rt",stdin);
    memset(matching,-1,sizeof(matching));
    scanf("%d%d",&n,&m);
    while(m--){
        int x,y;
        scanf("%d%d",&x,&y);
        x--; y--;
        g[x].push_back(y);
        g[y].push_back(x);
    }
    for (int v=0; v<n; v++){
        if (matching[v]==-1){
            memset(used,false,sizeof(used));
            couples+=findway(v);
        }
    }
    printf("%d\n",couples);
    for (int v=0; v<n; v++){
        if (matching[v]>v) printf("%d %d\n",v+1,matching[v]+1);
    }
    return 0;
}













