#include<bits/stdc++.h>
using namespace std;

const int N=1e5;

int n,m;
bool deleted[N];
int sz[N];
vector<int> g[N];
long long ans;

int get_size(int v,int p=-1){
    sz[v]=1;
    for (auto to: g[v]){
        if (to==p||deleted[to]) continue;
        sz[v]+=get_size(to,v);
    }
    return sz[v];
}

int find_centroid(int v,int size_tree,int p=-1){
    for (auto to: g[v]){
        if (to==p||deleted[to]) continue;
        if (sz[to]*2>size_tree) return find_centroid(to,size_tree,v);
    }
    return v;
}

void solve(int v){
    v=find_centroid(v,get_size(v));


    deleted[v]=true;

    for (auto to: g[v]){
        if (deleted[to]) continue;
        solve(to);
    }

    for (auto to: g[v]){
        if (deleted[to]) continue;
        solve(to);
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
    solve(0);
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








