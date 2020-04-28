#include <bits/stdc++.h>
using namespace std;

const int N=1e5;

int n,p;
int t[4*N];
long long ans;

int get(int v,int tl,int tr,int l,int r){
    if (l>r) return 0;
    if (l==tl&&r==tr){
        return t[v];
    }
    int tm=(tl+tr)/2;
    return get(v*2,tl,tm,l,min(r,tm))+get(v*2+1,tm+1,tr,max(tm+1,tl),r);
}

void update(int v,int tl,int tr,int pos){
    if (tl==tr){
        t[v]=1;
    }
    else{
        int tm=(tl+tr)/2;
        if (pos<=tm) update(v*2,tl,tm,pos);
        else update(v*2+1,tm+1,tr,pos);
        t[v]=t[v*2]+t[v*2+1];
    }
}

int main(){
    scanf("%d",&n);
    for (int i=0; i<n; i++){
        scanf("%d",&p);
        p--;
        ans+=get(1,0,n-1,p+1,n-1);
        update(1,0,n-1,p);
    }
    printf("%I64d",ans);
    return 0;
}
