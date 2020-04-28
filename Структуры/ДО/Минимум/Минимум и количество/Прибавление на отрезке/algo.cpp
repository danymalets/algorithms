#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;

#define fast_io ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0)
#define erase_unique(x) (x).erase(unique(all(x)),(x).end())
#define sp(x) setprecision(x) << fixed
#define all(x) (x).begin(),(x).end()
#define dcl(x,y) (x%y?x/y+1:x/y)
#define cube(x) ((x)*(x)*(x))
#define sqr(x) ((x)*(x))
#define bg1 cout << '!'
#define bg2 cout << '?'
#define ln cout << '\n'
#define pb push_back
#define mp make_pair
#define endl '\n'
#define file_all file_in,file_out
#define file_in freopen("input.txt","rt",stdin)
#define file_out freopen("output.txt","wt",stdout)

const ll LLINF=8e18;
const int MOD=998244353;
const int INF=2e9;
const int N=1e6;

int q,n;
ll ans;
vector<int> g[N];
int t[4*N];
pair<int,int> mn[4*N];

pair<int,int> combine(pair<int,int> a,pair<int,int> b){
    if (a.first==b.first) return mp(a.first,a.second+b.second);
    return min(a,b);
}

void build(int v,int tl,int tr){
    if (tl==tr){
        t[v]=0;
        mn[v]=mp(0,1);
    }
    else{
        int tm=(tl+tr)/2;
        build(v*2,tl,tm);
        build(v*2+1,tm+1,tr);
        t[v]=0;
        mn[v]=combine(mn[v*2],mn[v*2+1]);
    }
}

void push(int v){
    t[v*2]+=t[v];
    mn[v*2].first+=t[v];
    t[v*2+1]+=t[v];
    mn[v*2+1].first+=t[v];
    t[v]=0;
}

void add(int v,int tl,int tr,int l,int r,int val){
    if (l>r){
        return;
    }
    if (l==tl&&r==tr){
        t[v]+=val;
        mn[v].first+=val;
    }
    else{
        int tm=(tl+tr)/2;
        push(v);
        add(v*2,tl,tm,l,min(r,tm),val);
        add(v*2+1,tm+1,tr,max(tm+1,l),r,val);
        mn[v]=combine(mn[v*2],mn[v*2+1]);
    }
}

pair<int,int> getmin(int v,int tl,int tr,int l,int r){
    if (l>r){
        return mp(INF,INF);
    }
    if (l==tl&&r==tr){
        return mn[v];
    }
    int tm=(tl+tr)/2;
    push(v);
    return combine(getmin(v*2,tl,tm,l,min(r,tm)),
                   getmin(v*2+1,tm+1,tr,max(tm+1,l),r));
}

int main(){
    fast_io;
    cin >> q;
    while(q--){
        cin >> n;
        build(1,0,n-1);
        for (int i=0; i<n-1; i++){
            int x,y;
            cin >> x >> y;
            x--; y--;
            if (x<y) swap(x,y);
            g[x].pb(y);
        }
        ans=0;
        for (int i=0; i<n; i++){
            add(1,0,n-1,0,i-1,1);
            for (auto j: g[i]){
                add(1,0,n-1,0,j,-1);
            }
            auto x=getmin(1,0,n-1,0,i);
            if (x.first==0) ans+=x.second;
        }
        cout << ans << endl;
        for (int i=0; i<n; i++){
            g[i].clear();
        }
    }
    return 0;
}

