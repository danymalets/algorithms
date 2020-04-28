#include<bits/stdc++.h>
using namespace std;

const int N=1e5;

int n,q,type,pos,l,r,add;
int a[N],t[4*N];

void build(int v,int tl,int tr){
    if (tl==tr) t[v]=a[tl];
    else{
        int tm=(tl+tr)/2;
        build(v*2,tl,tm);
        build(v*2+1,tm+1,tr);
    }
}

int get(int v,int tl,int tr,int pos){
    if (tl==tr) return t[v];
    int tm=(tl+tr)/2;
    if (pos<=tm) return t[v]+get(v*2,tl,tm,pos);
    else return t[v]+get(v*2+1,tm+1,tr,pos);
}

void update(int v,int tl,int tr,int l,int r,int add){
    if (r<l) return;
    if (l==tl&&r==tr) t[v]+=add;
    else{
        int tm=(tl+tr)/2;
        update(v*2,tl,tm,l,min(tm,r),add);
        update(v*2+1,tm+1,tr,max(tm+1,l),r,add);
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
            scanf("%d",&pos);
            printf("%d\n",get(1,0,n-1,pos-1));
        }
        else {
            scanf("%d%d%d",&l,&r,&add);
            update(1,0,n-1,l-1,r-1,add);
        }
    }
    return 0;
}
