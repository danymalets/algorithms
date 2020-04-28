#include <bits/stdc++.h>
using namespace std;

const int N=1e5;
const int L=20;

int a[N],st[L][N],logs[N],pow2[L],n,q,l,r;

void build(int a[],int n){
    int t_pow=2;
    pow2[0]=1;
    for (int i=2; i<n; i++){
        logs[i]=logs[i-1];
        if (i==t_pow){
            logs[i]++;
            t_pow*=2;
            pow2[logs[i]]=i;
        }
    }
    for (int i=0; i<n; i++){
        st[0][i]=a[i];
    }
    for (int t=1,t_pow=1; t_pow<n; t++,t_pow*=2){
        for (int i=0; i+t_pow<n; i++){
            st[t][i]=min(st[t-1][i],st[t-1][i+t_pow]);
        }
    }
}

int get(int l,int r){
    int t=logs[r-l];
    return min(st[t][l-1],st[t][r-pow2[t]]);
}

int main(){
    scanf("%d",&n);
    for (int i=0; i<n; i++){
        scanf("%d",&a[i]);
    }
    build(a,n);
    scanf("%d",&q);
    while(q--){
        scanf("%d%d",&l,&r);
        printf("%d\n",get(l,r));
    }
    return 0;
}
