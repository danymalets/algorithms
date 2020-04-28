#include<bits/stdc++.h>
using namespace std;

const int INF=1e9;
const int N=1e5;
const int Q=1e5;
const int SZ=2*N+20*Q;

int n,q,sz;
int a[N];
vector<int> linkv(1,0);
int t[SZ],L[SZ],R[SZ];

void build(int v,int tl,int tr){
    if (tl==tr){
        t[v]=a[tl];
    }
    else{
        int tm=(tl+tr)/2;
        L[v]=sz++; R[v]=sz++;
        build(L[v],tl,tm);
        build(R[v],tm+1,tr);
        t[v]=min(t[L[v]],t[R[v]]);
    }
}

void update(int v,int pv,int tl,int tr,int pos,int val){
    if (tl==tr){
        t[v]=val;
    }
    else{
        int tm=(tl+tr)/2;
        if (pos<=tm){
            L[v]=sz++; R[v]=R[pv];
            update(L[v],L[pv],tl,tm,pos,val);
        }
        else{
            L[v]=L[pv]; R[v]=sz++;
            update(R[v],R[pv],tm+1,tr,pos,val);
        }
        t[v]=min(t[L[v]],t[R[v]]);
    }
}

int get(int v,int tl,int tr,int l,int r){
    if (l>r){
        return INF;
    }
    if (l==tl&&r==tr){
        return t[v];
    }
    int tm=(tl+tr)/2;
    return min(get(L[v],tl,tm,l,min(r,tm)),get(R[v],tm+1,tr,max(l,tm+1),r));
}

int main(){
    scanf("%d",&n);
    for (int i=0; i<n; i++){
        scanf("%d",&a[i]);
    }
    build(sz++,0,n-1);
    scanf("%d",&q);
    while(q--){
        int type;
        scanf("%d",&type);
        if (type==1){
            int version,l,r;
            scanf("%d%d%d",&version,&l,&r);
            l--; r--;
            printf("%d\n",get(linkv[version],0,n-1,l,r));
        }
        else{
            int version,pos,val;
            scanf("%d%d%d",&version,&pos,&val);
            pos--;
            linkv.push_back(sz);
            update(sz++,linkv[version],0,n-1,pos,val);
        }
    }
    return 0;
}


/*
4
1 2 3 4
100
1 0 2 3
2 0 3 1
1 1 2 3
1 0 2 3

2
1
2

*/



