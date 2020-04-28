#include<bits/stdc++.h>
using namespace std;

const long long LLINF=4e18;
const int N=1e5;

bool used[N];
int n,m,x,y,c,s,t;
int p[N];
long long dp[N];
stack<int> ans;
vector< pair<int,int> > g[N];

int main(){
    scanf("%d%d%d%d",&n,&m,&s,&t);
    s--; t--;
    for (int i=0; i<m; i++){
        scanf("%d%d%d",&x,&y,&c);
        x--; y--;
        g[x].push_back(make_pair(y,c));
        g[y].push_back(make_pair(x,c));
    }
    for (int i=0; i<n; i++){
        dp[i]=LLINF;
    }
    dp[s]=0;
    for (int i=0; i<n; i++){
        int v=-1;
        for (int j=0; j<n; j++){
            if (!used[j]&&(v==-1||dp[j]<dp[v])){
                v=j;
            }
        }
        if (dp[v]==LLINF) break;
        for (int j=0; j<g[v].size(); j++){
            int to=g[v][j].first,len=g[v][j].second;
            if (dp[v]+len<dp[to]){
                dp[to]=dp[v]+len;
                p[to]=v;
            }
        }
        used[v]=true;
    }
    p[s]=-1;
    for (int i=t; i!=-1; i=p[i]){
        ans.push(i);
    }
    if (dp[t]==LLINF){
        printf("-1");
    }
    else{
        printf("%I64d %d\n",dp[t],ans.size());
        while(!ans.empty()){
            printf("%d ",ans.top()+1); ans.pop();
        }
    }
    return 0;
}
