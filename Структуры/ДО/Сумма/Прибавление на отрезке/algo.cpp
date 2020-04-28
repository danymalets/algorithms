#include<bits/stdc++.h>
using namespace std;

const int N=1e5;

struct data{
    long long sum,add;
};

int n,q,type,l,r,add;
int a[N];
data t[4*N];

void build(int v,int tl,int tr){
    if (tl==tr) t[v].sum=a[tl];
    else{
        int tm=(tl+tr)/2;
        build(v*2,tl,tm);
        build(v*2+1,tm+1,tr);
        t[v].sum=t[v*2].sum+t[v*2+1].sum;
    }
}

void push(int v,int tl,int tr){
    t[v*2].add+=t[v].add;
    t[v*2+1].add+=t[v].add;
    int tm=(tl+tr)/2;
    t[v*2].sum+=t[v].add*(tm-tl+1);
    t[v*2+1].sum+=t[v].add*(tr-(tm+1)+1);
    t[v].add=0;
}

long long get(int v,int tl,int tr,int l,int r){
    if (l>r) return 0;
    if (l==tl&&r==tr) return t[v].sum;
    push(v,tl,tr);
    int tm=(tl+tr)/2;
    return get(v*2,tl,tm,l,min(tm,r))+get(v*2+1,tm+1,tr,max(tm+1,l),r);
}

void update(int v,int tl,int tr,int l,int r,int add){
    if (l>r) return;
    if (l==tl&&r==tr){
        t[v].add+=add;
        t[v].sum+=add*(tr-tl+1);
    }
    else{
        push(v,tl,tr);
        int tm=(tl+tr)/2;
        update(v*2,tl,tm,l,min(tm,r),add);
        update(v*2+1,tm+1,tr,max(tm+1,l),r,add);
        t[v].sum=t[v*2].sum+t[v*2+1].sum;
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
        else {
            scanf("%d%d%d",&l,&r,&add);
            update(1,0,n-1,l-1,r-1,add);
        }
    }
    return 0;
}
