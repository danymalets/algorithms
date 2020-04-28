#include <bits/stdc++.h>
using namespace std;

const int N=1e5;

int n;
int sz[N];
long long dp[N];
vector<int> g[N];
long long ans;

void dfs(int v,int p=-1){
    sz[v]=1;
    for (auto to: g[v]){
        if (to==p) continue;
        dfs(to,v);
        ans+=1LL*dp[v]*sz[to]+1LL*(dp[to]+sz[to])*(sz[v]-1);
        dp[v]+=dp[to]+sz[to];
        sz[v]+=sz[to];
    }
    ans+=dp[v];
}

int main(){
    scanf("%d",&n);
    for (int i=1; i<n; i++){
        int x,y;
        scanf("%d%d",&x,&y);
        x--; y--;
        g[x].push_back(y);
        g[y].push_back(x);
    }
    dfs(0);
    printf("%I64d",ans);
    return 0;
}
