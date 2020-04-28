#include <bits/stdc++.h>
using namespace std;

const int INF=2e9;
const int N=1e5;

int a[N],n,q,l,r,x,ans;
vector<int> t[4*N];

void build(int v,int tl,int tr){
    if (tl==tr) t[v].push_back(a[tl]);
    else{
        int tm=(tl+tr)/2;
        build(v*2,tl,tm);
        build(v*2+1,tm+1,tr);
        merge(t[v*2].begin(),t[v*2].end(),t[v*2+1].begin(),t[v*2+1].end(),back_inserter(t[v]));
    }
}

int get(int v,int tl,int tr,int l,int r,int x){
    if (l>r) return INF;
    if (l==tl&&r==tr){
        int pos=upper_bound(t[v].begin(),t[v].end(),x)-t[v].begin();
        if (pos==t[v].size()) return INF;
        return t[v][pos];
    }
    int tm=(tl+tr)/2;
    return min(get(v*2,tl,tm,l,min(tm,r),x),get(v*2+1,tm+1,tr,max(tm+1,l),r,x));
}

int main(){
    scanf("%d",&n);
    for (int i=0; i<n; i++){
        scanf("%d",&a[i]);
    }
    build(1,0,n-1);
    scanf("%d",&q);
    while(q--){
        scanf("%d%d%d",&l,&r,&x);
        ans=get(1,0,n-1,l-1,r-1,x);
        printf("%d\n",(ans==INF) ? -1 : ans);
    }
    return 0;
}
