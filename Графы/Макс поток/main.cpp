#include <iostream>
using namespace std;

const int INF = 1e9;
const int V = 602;

int cntv;
int cost[V][V], capacity[V][V];
int dist[V], potential[V], pr[V];
bool used[V];

bool find_way(int source, int target) {
    fill(used, used + cntv, false);
    fill(dist, dist + cntv, INF);
    dist[source] = 0;
    while (true) {
        int v = -1;
        for (int u = 0; u < cntv; u++)
            if (!used[u] && (v == -1 || dist[u] < dist[v])) v = u;
        if (v == -1 || dist[v] == INF)
            break;
        used[v] = true;
        for (int u = 0; u < cntv; u++) {
            int w = cost[v][u] + potential[v] - potential[u];
            if (capacity[v][u] && dist[u] > dist[v] + w) {
                dist[u] = dist[v] + w;
                pr[u] = v;
            }
        }
    }

    return dist[target] < INF;
}

int mincost_maxflow(int source, int target) {
    int ans = 0;
    while (find_way(source, target)) {
        memcpy(potential, dist, sizeof(dist));
        int delta = INF;
        for (int v = target; v != source; v = pr[v])
            delta = min(delta, capacity[pr[v]][v]);
        for (int v = target; v != source; v = pr[v]) {
            capacity[pr[v]][v] -= delta;
            capacity[v][pr[v]] += delta;
            ans += cost[pr[v]][v] * delta;
        }
    }
    return ans;
}

void add_edge(int u, int v, int _cap, int _cost){
    capacity[u][v] = _cap;
    cost[u][v] = _cost;
    capacity[v][u] = 0;
    cost[v][u] = -_cost;
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    //freopen("input.txt", "rt", stdin);
    //freopen("output.txt", "wt", stdout);
    int n, m, s, t;
    cin >> n >> m;
    s = 0;
    t = 1 + n + m;
    for (int i = 0; i < n; i++){
        int w;
        cin >> w;
        add_edge(s, 1 + i, w, 0);
    }
    for (int i = 0; i < m; i++){
        int w;
        cin >> w;
        add_edge(1 + n + i, t, w, 0);
    }
    for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j++){
            int c;
            cin >> c;
            add_edge(1 + i, 1 + n + j, INF, c);
        }
    }
    cntv = n + m + 2;
    cout << mincost_maxflow(s, t);
    return 0;
}
