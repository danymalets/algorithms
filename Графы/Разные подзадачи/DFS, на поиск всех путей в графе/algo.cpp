#include <bits/stdc++.h>
using namespace std;


const int MAXN=1e5;


bool b[MAXN];
int n,m,x,y,start,k,r[MAXN],vay[MAXN];
vector<int> g[MAXN];


void write(int vay[],int k){
    for (int i=0; i<k; i++){
        printf("%d ",vay[i]+1);
    }
    printf("\n");
}

void dfs(int x){
    b[x]=1;
    vay[k]=x; k++;
    write(vay,k);
    for (int i=0; i<g[x].size(); i++){
        y=g[x][i];
        if (!b[y]){
            dfs(y);
        }
    }
    k--;
    b[x]=0;
}


int main(){
    scanf("%d%d",&n,&m);
    for (int i=0; i<m; i++){
        scanf("%d%d",&x,&y);
        x--; y--;
        g[x].push_back(y);
        g[y].push_back(x);
    }

    for (int i=0; i<n; i++){
        dfs(i);
    }
    return 0;
}
