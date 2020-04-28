#include <bits/stdc++.h>
using namespace std;

const int N=1e5;

int n;
int a[N],t[N];
long long ans;

void add(int pos,int val){
    for (int i=pos; i<n; i=(i|(i+1))){
        t[i]+=val;
    }
}

int get(int l,int r){
    int res=0;
    for (int i=r; i>=0; i=(i&(i+1))-1){
        res+=t[i];
    }
    for (int i=l-1; i>=0; i=(i&(i+1))-1){
        res-=t[i];
    }
    return res;
}

int main(){
    cin >> n;
    for (int i=0; i<n; i++){
        cin >> a[i];
        a[i]--;
        ans+=get(a[i]+1,n-1);
        add(a[i],1);
    }
    cout << ans;
    return 0;
}
