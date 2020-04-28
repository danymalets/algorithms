#include<bits/stdc++.h>
using namespace std;

const int N=1e5;

int n,q,l,r,x,ans;
int a[N];
vector<int> t[4*N],L[4*N],R[4*N];

void my_merge(int v,int v1,int v2){
    int sz=t[v1].size()+t[v2].size();
    t[v].resize(sz);
    L[v].resize(sz);
    R[v].resize(sz);
    int i=0,j=0,k=0;
    while(i<t[v1].size()&&j<t[v2].size()){
        L[v][k]=i;
        R[v][k]=j;
        if (t[v1][i]<t[v2][j]) t[v][k++]=t[v1][i++];
        else t[v][k++]=t[v2][j++];
    }
    while(i<t[v1].size()){
        L[v][k]=i;
        R[v][k]=j;
        t[v][k++]=t[v1][i++];
    }
    while(j<t[v2].size()){
        L[v][k]=i;
        R[v][k]=j;
        t[v][k++]=t[v2][j++];
    }
}

void build(int v,int tl,int tr){
    if (tl==tr)t[v].push_back(a[tl]);
    else{
        int tm=(tl+tr)/2;
        build(v*2,tl,tm);
        build(v*2+1,tm+1,tr);
        my_merge(v,v*2,v*2+1);
    }
}

int get(int v,int tl,int tr,int l,int r,int pos){
    if (l>r||pos==t[v].size()) return 0;
    cout << "! " << v << ' ' << pos << endl;
    if (l==tl&&r==tr){
        return t[v].size()-pos;
    }
    int tm=(tl+tr)/2;
    return get(v*2,tl,tm,l,min(tm,r),L[v][pos])+get(v*2+1,tm+1,tr,max(tm+1,l),r,R[v][pos]);
}

int main(){
    scanf("%d",&n);
    for (int i=0; i<n; i++){
        scanf("%d",&a[i]);
    }
    build(1,0,n-1);
    /*
    for (int i=1; i<=7; i++){
        cout << '!' << i << endl;
        for (int j=0; j<t[i].size(); j++){
            cout << t[i][j] << ' ';
        } cout << endl;
        for (int j=0; j<L[i].size(); j++){
            cout << L[i][j] << ' ';
        } cout << endl;
        for (int j=0; j<R[i].size(); j++){
            cout << R[i][j] << ' ';
        } cout << endl;
        cout << endl;
    }
    */
    scanf("%d",&q);
    while(q--){
        scanf("%d%d%d",&l,&r,&x);
        l--; r--;
        int pos=lower_bound(t[1].begin(),t[1].end(),x)-t[1].begin();
        printf("%d\n",get(1,0,n-1,l,r,pos));
    }
    return 0;
}
