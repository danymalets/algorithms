#include<bits/stdc++.h>
using namespace std;

const int N=1e5;

int n,q,type,l,r,pos,val;
int a[N];
long long t[4*N];

void build(int v,int tl,int tr){
    if (tl==tr) t[v]=a[tl];
    else{
        int tm=(tl+tr)/2;
        build(v*2,tl,tm);
        build(v*2+1,tm+1,tr);
        t[v]=t[v*2]+t[v*2+1];
    }
}

long long get(int v,int tl,int tr,int l,int r){
    if (l>r) return 0;
    if (l==tl&&r==tr) return t[v];
    int tm=(tl+tr)/2;
    return get(v*2,tl,tm,l,min(tm,r))+get(v*2+1,tm+1,tr,max(tm+1,l),r);
}

void update(int v,int tl,int tr,int pos,int new_val){
    if (tl==tr) t[v]=val;
    else{
        int tm=(tl+tr)/2;
        if (pos<=tm) update(v*2,tl,tm,pos,new_val);
        else update(v*2+1,tm+1,tr,pos,new_val);
        t[v]=t[v*2]+t[v*2+1];
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
            printf("%I64d\n",get(1,0,n-1,l-1,r-1));
        }
        else{
            scanf("%d%d",&pos,&val);
            update(1,0,n-1,pos-1,val);
        }
    }
    return 0;
}
