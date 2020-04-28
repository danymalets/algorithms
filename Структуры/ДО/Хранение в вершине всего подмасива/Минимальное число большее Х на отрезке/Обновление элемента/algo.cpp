#include<bits/stdc++.h>
using namespace std;

const int INF=2e9;
const int N=1e5;

int n,q,type,l,r,x,pos,val,ans;
int a[N];
multiset<int> t[4*N];

void union_sets(multiset<int> &s,multiset<int> &s1,multiset<int> &s2){
    s=s1;
    for (multiset<int>::iterator it=s2.begin(); it!=s2.end(); it++){
        s.insert(*it);
    }
}

void build(int a[],int v,int tl,int tr){
    if (tl==tr) t[v].insert(a[tl]);
    else{
        int tm=(tl+tr)/2;
        build(a,v*2,tl,tm);
        build(a,v*2+1,tm+1,tr);
        union_sets(t[v],t[v*2],t[v*2+1]);
    }
}

int get(int v,int tl,int tr,int l,int r,int x){
    if (l>r) return INF;
    if (l==tl&&r==tr){
        multiset<int>::iterator pos=t[v].upper_bound(x);
        if (pos==t[v].end()) return INF;
        return *pos;
    }
    int tm=(tl+tr)/2;
    return min(get(v*2,tl,tm,l,min(tm,r),x),get(v*2+1,tm+1,tr,max(tm+1,l),r,x));
}

void update(int v,int tl,int tr,int pos,int val){
    t[v].erase(t[v].find(a[pos]));
    t[v].insert(val);
    if (tl==tr) a[pos]=val;
    else{
        int tm=(tl+tr)/2;
        if (pos<=tm) update(v*2,tl,tm,pos,val);
        else update(v*2+1,tm+1,tr,pos,val);
    }
}

int main(){
    scanf("%d",&n);
    for (int i=0; i<n; i++){
        scanf("%d",&a[i]);
    }
    build(a,1,0,n-1);
    scanf("%d",&q);
    while(q--){
        scanf("%d",&type);
        if (type==1){
            scanf("%d%d%d",&l,&r,&x);
            ans=get(1,0,n-1,l-1,r-1,x);
            printf("%d\n",(ans==INF) ? -1 : ans);
        }
        else{
            scanf("%d%d",&pos,&val);
            update(1,0,n-1,pos-1,val);
        }
    }
    return 0;
}
