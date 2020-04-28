#include <bits/stdc++.h>
using namespace std;

const int N=1e5;
const int M=1e6;

bool used[N],is[M];
int tin[N],up[N];
int n,m,x,y,timer,ans;
vector<pair<int,int> > g[N];

void dfs(int v,int numpar=-1){
    tin[v]=up[v]=timer++;
    used[v]=true;
    int ch=0;
    for (int i=0; i<g[v].size(); i++){
        int to=g[v][i].first,num=g[v][i].second;
        if (used[to]&&num!=numpar){
            up[v]=min(up[v],tin[to]);
        }
        else if (!used[to]){
            ch++;
            dfs(to,num);
            up[v]=min(up[v],up[to]);
            if (up[to]>tin[v]) is[num]=true;
        }
    }
}


int main(){
    scanf("%d%d",&n,&m);
    for (int i=0; i<m; i++){
        scanf("%d%d",&x,&y);
        x--; y--;
        g[x].push_back(make_pair(y,i));
        g[y].push_back(make_pair(x,i));
    }
    for (int i=0; i<n; i++){
        if (!used[i]) dfs(i);
    }
    for (int i=0; i<m; i++){
        if (is[i]) ans++;
    }
    printf("%d\n",ans);
    for (int i=0; i<m; i++){
        if (is[i]) printf("%d\n",i+1);
    }
    return 0;
}
