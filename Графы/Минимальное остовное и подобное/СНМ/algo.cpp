#include<bits/stdc++.h>
using namespace std;

const int N=1e5;

int n,m,x,y;
int parent[N],size[N];
vector<int> ans;
vector<int> g[N];

void init(int n){
    for (int i=0; i<n; i++){
        parent[i]=i;
        size[i]=1;
    }
}

int find_set(int v){
    if (v==parent[v]) return v;
    return parent[v]=find_set(parent[v]);
}

void union_sets(int a,int b){
    a=find_set(a);
    b=find_set(b);
    if (a!=b){
        if (size[a]>size[b]) swap(a,b);
        size[b]+=size[a];
        size[a]=0;
        parent[a]=b;
    }
}

int main(){
    scanf("%d%d",&n,&m);
    init(n);
    for (int i=0; i<m; i++){
        scanf("%d%d",&x,&y);
        x--; y--;
        union_sets(x,y);
    }
    for (int i=0; i<n; i++){
        if (size[i]>0) ans.push_back(size[i]);
    }
    printf("%d\n",ans.size());
    for (int i=0; i<ans.size(); i++){
        printf("%d ",ans[i]);
    }
    return 0;
}
