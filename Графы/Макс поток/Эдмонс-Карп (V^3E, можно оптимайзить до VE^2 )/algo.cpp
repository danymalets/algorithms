#include <iostream>
#include <queue>
using namespace std;

const int INF = 2e9;
const int N = 1e3;
const int M = 1e4;

bool used[N];
int n, m, source, target;
int u[M], v[M], from[N];
int capacity[N][N], flow[N][N];
queue<int> q;

bool find_way(int source, int sink){
    memset(used,false,sizeof(used));
    q.push(source);
    used[source] = true;
    while(!q.empty()){
        int v=q.front(); q.pop();
        for (int to = 0; to < n; to++){
            if (!used[to] && capacity[v][to] - flow[v][to] > 0){
                from[to] = v;
                used[to] = true;
                if (to == sink){
                    while(!q.empty()) q.pop();
                    return true;
                }
                q.push(to);
            }
        }
    }
    return false;
}

int find_max_flow(int source, int target){
    int maxflow = 0;
    while(find_way(source, target)){
        int delta = INF;
        for (int v = from[target], to = target; v >= 0; to = v, v = from[v]){
            delta = min(delta, capacity[v][to] - flow[v][to]);
        }
        for (int v = from[target], to = target; v >= 0; to = v, v = from[v]){
            flow[v][to] += delta;
            flow[to][v] -= delta;
        }
        maxflow += delta;
    }
    return maxflow;
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    //freopen("input.txt", "rt", stdin);
    //freopen("output.txt", "wt", stdout);
    cin >> n >> m >> source >> target;
    source--; target--;
    from[source] = -1;
    for (int i = 0; i < m; i++){
        int w;
        cin >> u[i] >> v[i] >> w;
        u[i]--; v[i]--;
        capacity[u[i]][v[i]] += w;
    }

    cout << find_max_flow(source, target) << '\n';
    for (int i = 0; i < m; i++){
        cout << max(0, flow[u[i]][v[i]]) << '\n';
    }
    return 0;
}













