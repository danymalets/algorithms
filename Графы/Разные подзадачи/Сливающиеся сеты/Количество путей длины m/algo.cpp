#include<bits/stdc++.h>
using namespace std;

const int N=1e5;

int n,m;
int h[N];
vector<int> g[N];
multiset<int> s[N];
long long ans;

void dfs(int v,int p=-1){
    int mx=-1;
    for (auto to: g[v]){
        if (to==p) continue;
        h[to]=h[v]+1;
        dfs(to,v);
        if (mx==-1||s[to]>s[mx]) mx=to;
    }
    if (mx!=-1)swap(s[v],s[mx]);
    s[v].insert(h[v]);
    ans+=s[v].count(h[v]+m);
    for (auto to: g[v]){
        if (to==p||to==mx) continue;
        for (auto x: s[to]){
            ans+=s[v].count(2*h[v]+m-x);
        }
        for (auto x: s[to]){
            s[v].insert(x);
        }
    }
}

int main(){
    scanf("%d%d",&n,&m);
    for (int i=0; i<n-1; i++){
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

/*
7 3
1 2
1 3
2 4
2 5
3 6
3 7

*/








