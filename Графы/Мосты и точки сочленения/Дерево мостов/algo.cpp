#include <bits/stdc++.h>
using namespace std;

const int N=1e5;
const int M=1e6;

bool used[N];
int tin[N],fup[N];
int n,nn=1,m,timer,ans;
vector<pair<int,bool>> g[N];
vector<int> g0[N];

void dfs1(int v,int p=-1){
    tin[v]=fup[v]=timer++;
    used[v]=true;
    for (int i=0; i<g[v].size(); i++){
        int to=g[v][i].first;
        if (to==p) continue;
        if (used[to]){
            fup[v]=min(fup[v],tin[to]);
        }
        else{
            dfs1(to,v);
            fup[v]=min(fup[v],fup[to]);
            if (fup[to]>tin[v]) g[v][i].second=true;
        }
    }
}

void dfs2(int v,int c,int p=-1){
    used[v]=true;
    for (int i=0; i<g[v].size(); i++){
        int to=g[v][i].first,b=g[v][i].second;
        if (used[to]) continue;
        if (b){
            int tn=nn;
            g0[c].push_back(tn);
            g0[tn].push_back(c);
            nn++;
            dfs2(to,tn,v);
        }
        else{
            dfs2(to,c,v);
        }
    }
}

int main(){
    scanf("%d%d",&n,&m);
    for (int i=0; i<m; i++){
        int x,y;
        cin >> x >> y;
        x--; y--;
        g[x].push_back(make_pair(y,0));
        g[y].push_back(make_pair(x,0));
    }
    dfs1(0);
    fill(used,used+n,false);
    dfs2(0,0);
    printf("%d\n",nn);
    for (int v=0; v<nn; v++){
        for (auto to: g0[v]){
            if (v<to) cout << v+1 << ' ' << to+1 << endl;
        }
    }
    return 0;
}


/*
9
11
1 2
2 3
1 3
4 6
6 7
7 4
5 8
5 9
8 9
2 4
3 5
*/
