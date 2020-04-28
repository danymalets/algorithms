#include <bits/stdc++.h>
using namespace std;

const int N=1e5;

struct edge{
    int x,y,c;
};

bool cmp(edge a,edge b){
    return a.c<b.c;
}

int n,m,x,y,c;
int parent[N],set_size[N];
long long cost;
vector<edge> g;
vector<pair<int,int>> ans;

int find_set(int v){
    if (v==parent[v]) return v;
    return parent[v]=find_set(parent[v]);
}

void union_sets(int a,int b){
    a=find_set(a);
    b=find_set(b);
    if (a!=b){
        if (set_size[a]>set_size[b]) swap(a,b);
        set_size[b]+=set_size[a];
        parent[a]=b;
    }
}

int main(){
    cin >> n >> m;
    for (int i=0; i<n; i++){
        parent[i]=i;
        set_size[i]=1;
    }
    for (int i=0; i<m; i++){
        cin >> x >> y >> c;
        x--; y--;
        g.push_back({x,y,c});
    }
    sort(g.begin(),g.end(),cmp);
    for (int i=0; i<m; i++){
        if (find_set(g[i].x)!=find_set(g[i].y)){
            union_sets(g[i].x,g[i].y);
            cost+=g[i].c;
            ans.push_back(make_pair(g[i].x,g[i].y));
        }
    }
    if (ans.size()!=n-1) cout << -1;
    else{
        cout << cost << endl;
        for (int i=0; i<n-1; i++){
            cout << ans[i].first+1 << ' ' << ans[i].second+1 << endl;
        }
    }
    return 0;
}
