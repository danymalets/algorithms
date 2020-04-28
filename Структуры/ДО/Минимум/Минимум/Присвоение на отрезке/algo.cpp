#include<bits/stdc++.h>
using namespace std;

const int INF=2e9;
const int N=1e5;

struct data{
    int mx,val;
};

int n,q,type,l,r,val;
int a[N];
data t[4*N];

void build(int v,int tl,int tr){
    if (tl==tr) t[v].mx=a[tl];
    else{
        int tm=(tl+tr)/2;
        build(v*2,tl,tm);
        build(v*2+1,tm+1,tr);
        t[v].mx=min(t[v*2].mx,t[v*2+1].mx);
        t[v].val=-1;
    }
}

void push(int v){
    if (t[v].val!=-1){
        t[v*2].mx=t[v*2].val=t[v*2+1].mx=t[v*2+1].val=t[v].val;
        t[v].val=-1;
    }
}

long long get(int v,int tl,int tr,int l,int r){
    if (l>r) return INF;
    if (tl==l&&r==tr) return t[v].mx;
    push(v);
    int tm=(tl+tr)/2;
    return min(get(v*2,tl,tm,l,min(tm,r)),get(v*2+1,tm+1,tr,max(tm+1,l),r));
}

void update(int v,int tl,int tr,int l,int r,int val){
    if (l>r) return;
    if (l==tl&&r==tr){
        t[v].mx=t[v].val=val;
    }
    else{
        push(v);
        int tm=(tl+tr)/2;
        update(v*2,tl,tm,l,min(tm,r),val);
        update(v*2+1,tm+1,tr,max(tm+1,l),r,val);
        t[v].mx=min(t[v*2].mx,t[v*2+1].mx);
    }
}

int main(){
    scanf("%d",&n);
    for (int i=0; i<n; i++){
        scanf("%d",&a[i]);
    }
    build(1,0,n-1);
    scanf("%d",&q);
    while(q--){
        scanf("%d",&type);
        if (type==1){
            scanf("%d%d",&l,&r);
            printf("%d\n",get(1,0,n-1,l-1,r-1));
        }
        else {
            scanf("%d%d%d",&l,&r,&val);
            update(1,0,n-1,l-1,r-1,val);
        }
    }
    return 0;
}
