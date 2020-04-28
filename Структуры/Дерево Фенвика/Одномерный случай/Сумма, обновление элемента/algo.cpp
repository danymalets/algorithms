#include<bits/stdc++.h>
using namespace std;

const int N=1e5;

int n,q;
int a[N];
long long t[N];

void add(int pos,int val){
    while(pos<n){
        t[pos]+=val;
        pos=pos|(pos+1);
    }
}

void update(int pos,int val){
    add(pos,val-a[pos]);
    a[pos]=val;
}

void build(){
    for (int i=0; i<n; i++){
        add(i,a[i]);
    }
}

long long pget(int r){
    long long res=0;
    while(r>=0){
        res+=t[r];
        r=(r&(r+1))-1;
    }
    return res;
}

long long get(int l,int r){
    return pget(r)-pget(l-1);
}

int main(){
    scanf("%d",&n);
    for (int i=0; i<n; i++){
        scanf("%d",&a[i]);
    }
    build();
    scanf("%d",&q);
    while(q--){
        int type;
        scanf("%d",&type);
        if (type==1){
            int pos,val;
            scanf("%d%d",&pos,&val);
            pos--;
            update(pos,val);
        }
        else{
            int l,r;
            scanf("%d%d",&l,&r);
            l--; r--;
            printf("%I64d\n",get(l,r));
        }
    }
    return 0;
}
