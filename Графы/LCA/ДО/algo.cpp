#include<bits/stdc++.h>
using namespace std;

const int INF=2e9;
const int N=1e5;

int n,q,x,y;
int high[N],first[N];
vector<int> lst;
vector< pair<int,int> > tree;
vector<int> graph[N];

void dfs(int v,int from){
    first[v]=lst.size();
    lst.push_back(v);
    for (int i=0; i<graph[v].size(); i++){
        int to=graph[v][i];
        if (to!=from){
            high[to]=high[v]+1;
            dfs(to,v);
            lst.push_back(v);
        }
    }
}

void build(int v,int tl,int tr){
    if (tl==tr){
        tree[v]=make_pair(high[lst[tl]],lst[tl]);
    }
    else{
        int tm=(tl+tr)/2;
        build(v*2,tl,tm);
        build(v*2+1,tm+1,tr);
        tree[v]=min(tree[v*2],tree[v*2+1]);
    }
}

pair<int,int> get(int v,int tl,int tr,int l,int r){
    if (l>r) return make_pair(INF,INF);
    if (l==tl&&r==tr) return tree[v];
    int tm=(tl+tr)/2;
    return min(get(v*2,tl,tm,l,min(tm,r)),get(v*2+1,tm+1,tr,max(tm+1,l),r));
}

int main()
{
    scanf("%d",&n);
    for (int i=0; i<n-1; i++){
        scanf("%d%d",&x,&y);
        x--; y--;
        graph[x].push_back(y);
        graph[y].push_back(x);
    }
    dfs(0,-1);
    tree.resize(4*lst.size());
    build(1,0,lst.size()-1);
    scanf("%d",&q);
    while(q--){
        scanf("%d%d",&x,&y);
        x--; y--;
        x=first[x];
        y=first[y];
        if (x>y) swap(x,y);
        printf("%d\n",get(1,0,lst.size()-1,x,y).second+1);
    }
    return 0;
}


