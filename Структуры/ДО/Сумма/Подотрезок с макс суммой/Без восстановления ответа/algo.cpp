#include<bits/stdc++.h>
using namespace std;

const int N=1e5;

struct data{
    long long sum,pref,suff,ans;
};

int n,q,type,l,r,pos,val;
int a[N];
data t[4*N];

data make_data(int val){
    data res;
    res.sum=val;
    res.ans=res.pref=res.suff=max(0,val);
    return res;
}

data combine(data a,data b){
    data res;
    res.sum=a.sum+b.sum;
    res.pref=max(a.pref,a.sum+b.pref);
    res.suff=max(b.suff,b.sum+a.suff);
    res.ans=max(a.suff+b.pref,max(a.ans,b.ans));
    return res;
}

void build(int v,int tl,int tr){
    if (tl==tr) t[v]=make_data(a[tl]);
    else{
        int tm=(tl+tr)/2;
        build(v*2,tl,tm);
        build(v*2+1,tm+1,tr);
        t[v]=combine(t[v*2],t[v*2+1]);
    }
}

data get(int v,int tl,int tr,int l,int r){
    if (l==tl&&r==tr) return t[v];
    int tm=(tl+tr)/2;
    if (r<=tm) return get(v*2,tl,tm,l,r);
    if (l>tm) return get(v*2+1,tm+1,tr,l,r);
    return combine(get(v*2,tl,tm,l,tm),get(v*2+1,tm+1,tr,tm+1,r));
}

void update(int v,int tl,int tr,int pos,int val){
    if (tl==tr) t[v]=make_data(val);
    else{
        int tm=(tl+tr)/2;
        if (pos<=tm) update(v*2,tl,tm,pos,val);
        else update(v*2+1,tm+1,tr,pos,val);
        t[v]=combine(t[v*2],t[v*2+1]);
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
            scanf("%d%d",&l,&r);
            printf("%I64d\n",get(1,0,n-1,l-1,r-1).ans);
        }
        else{
            scanf("%d%d",&pos,&val);
            update(1,0,n-1,pos-1,val);
        }
    }
    return 0;
}
