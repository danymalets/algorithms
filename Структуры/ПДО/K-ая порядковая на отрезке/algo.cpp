#include<bits/stdc++.h>
using namespace std;

const int N=1e5;
const int SZ=2*N+20*N;

int n,q;
int a[N],p[N];
pair<int,int> b[N];

int sz;
vector<int> linkv(1,0);
int t[SZ],L[SZ],R[SZ];

void build(int v,int tl,int tr){
    if (tl==tr){
    }
    else{
        int tm=(tl+tr)/2;
        L[v]=sz++; R[v]=sz++;
        build(L[v],tl,tm);
        build(R[v],tm+1,tr);
    }
}

void update(int v,int pv,int tl,int tr,int pos){
    if (tl==tr){
        t[v]=1;
    }
    else{
        int tm=(tl+tr)/2;
        if (pos<=tm){
            L[v]=sz++; R[v]=R[pv];
            update(L[v],L[pv],tl,tm,pos);
        }
        else{
            L[v]=L[pv]; R[v]=sz++;
            update(R[v],R[pv],tm+1,tr,pos);
        }
        t[v]=t[L[v]]+t[R[v]];
    }
}

int get(int v,int pv,int tl,int tr,int k){
    if (tl==tr){
        return b[tl].first;
    }
    else{
        int tm=(tl+tr)/2;
        if (k<=t[L[v]]-t[L[pv]]) return get(L[v],L[pv],tl,tm,k);
        else return get(R[v],R[pv],tm+1,tr,k-(t[L[v]]-t[L[pv]]));
    }
}

int main(){
    scanf("%d%d",&n,&q);
    for (int i=0; i<n; i++){
        scanf("%d",&a[i]);
        b[i].first=a[i];
        b[i].second=i;
    }
    sort(b,b+n);
    for (int i=0; i<n; i++){
        p[b[i].second]=i;
    }
    build(sz++,0,n-1);
    for (int i=0; i<n; i++){
        linkv.push_back(sz++);
        update(linkv[linkv.size()-1],linkv[linkv.size()-2],0,n-1,p[i]);
    }
    while(q--){
        int l,r,k;
        scanf("%d%d%d",&l,&r,&k);
        printf("%d\n",get(linkv[r],linkv[l-1],0,n-1,k));
    }
    return 0;
}



