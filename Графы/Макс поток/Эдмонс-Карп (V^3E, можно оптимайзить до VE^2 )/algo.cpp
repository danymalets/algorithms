#include<bits/stdc++.h>
using namespace std;

const int INF=8e18;
const int N=100;

bool used[N];
int n,m,source,sink,sz;
int from[N];
int capacity[N][N],flow[N][N];
queue<int> q;

bool find_way(int source,int sink){
    memset(used,false,sizeof(used));
    q.push(source);
    used[source]=true;
    while(!q.empty()){
        int v=q.front(); q.pop();
        for (int to=0; to<n; to++){
            if (!used[to]&&capacity[v][to]-flow[v][to]>0){
                from[to]=v;
                used[to]=true;
                if (to==sink){
                    while(!q.empty()) q.pop();
                    return true;
                }
                q.push(to);
            }
        }
    }
    return false;
}

long long find_max_flow(int source,int sinnk){
    long long maxflow=0;
    while(find_way(source,sink)){
        int delta=INF;
        for (int v=from[sink],to=sink; v>=0; to=v,v=from[v]){
            delta=min(delta,capacity[v][to]-flow[v][to]);
        }
        for (int v=from[sink],to=sink; v>=0; to=v,v=from[v]){
            flow[v][to]+=delta;
            flow[to][v]-=delta;
        }
        maxflow+=delta;
    }
    return maxflow;
}

int main(){
    freopen("input.txt","rt",stdin);
    scanf("%d%d%d%d",&n,&m,&source,&sink);
    source--; sink--;
    from[source]=-1;
    while(m--){
        int x,y,c;
        scanf("%d%d%d",&x,&y,&c);
        x--; y--;
        capacity[x][y]+=c;
    }

    printf("%I64d\n",find_max_flow(source,sink));
    for (int v=0; v<n; v++){
        for (int to=0; to<n; to++){
            if (flow[v][to]>0) sz++;
        }
    }
    printf("%d\n",sz);
    for (int v=0; v<n; v++){
        for (int to=0; to<n; to++){
            if (flow[v][to]>0) printf("%d %d %d\n",v+1,to+1,flow[v][to]);
        }
    }
    return 0;
}













