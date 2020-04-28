#include<bits/stdc++.h>
using namespace std;

const int N=1e5;

int n,q,type,k,pos,val;
int a[N],t[4*N];

void build(int v,int tl,int tr){
    if (tl==tr){
        if (a[tl]==0) t[v]=1;
    }
    else{
        int tm=(tl+tr)/2;
        build(v*2,tl,tm);
        build(v*2+1,tm+1,tr);
        t[v]=t[v*2]+t[v*2+1];
    }
}

int get(int v,int tl,int tr,int k){
    if (k>t[v]) return -2;
    if (tl==tr) return tl;
    int tm=(tl+tr)/2;
    if (k<=t[v*2]) return get(v*2,tl,tm,k);
    return get(v*2+1,tm+1,tr,k-t[v*2]);
}

void update(int v,int tl,int tr,int pos,int val){
    if (tl==tr){
        if (val==0) t[v]=1;
        else t[v]=0;
    }
    else{
        int tm=(tl+tr)/2;
        if (pos<=tm) update(v*2,tl,tm,pos,val);
        else update(v*2+1,tm+1,tr,pos,val);
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
        if (type==1) {
            scanf("%d",&k);
            printf("%d\n",get(1,0,n-1,k)+1);
        }
        else {
            scanf("%d%d",&pos,&val);
            update(1,0,n-1,pos-1,val);
        }
    }
    return 0;
}
