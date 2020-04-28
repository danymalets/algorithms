#include <bits/stdc++.h>
using namespace std;

const int N=1e5;

bool used[N],is[N];
int tin[N],up[N];
int n,m,x,y,timer,ans;
vector<int> g[N];

void dfs(int x,int par=-1){
    tin[x]=up[x]=timer++;
    used[x]=true;
    int ch=0;
    for (int i=0; i<g[x].size(); i++){
        int to=g[x][i];
        if (used[to]&&to!=par){
            up[x]=min(up[x],tin[to]);
        }
        else if (!used[to]){
            ch++;
            dfs(to,x);
            up[x]=min(up[x],up[to]);
            if (up[to]>=tin[x]) is[x]=true;
        }
    }
    if (par==-1)
        if (ch>1) is[x]=true;
        else is[x]=false;
}


int main(){
    scanf("%d%d",&n,&m);
    while(m--){
        scanf("%d%d",&x,&y);
        x--; y--;
        g[x].push_back(y);
        g[y].push_back(x);
    }
    for (int i=0; i<n; i++){
        if (!used[i]) dfs(i);
    }
    for (int i=0; i<n; i++){
        if (is[i]) ans++;
    } printf("%d\n",ans);
    for (int i=0; i<n; i++){
        if (is[i]) printf("%d\n",i+1);
    }
    return 0;
}
