#include<bits/stdc++.h>
using namespace std;

const int N=1e5;

int n,q;
int a[N],t[N];

void addp(int pos,int val){
    for (int i=pos; i<n; i=(i|(i+1))){
        t[i]+=val;
    }
}

void add(int l,int r,int val){
    addp(l,val);
    addp(r+1,-val);
}

void build(){
    for (int i=0; i<n; i++){
        add(i,i,a[i]);
    }
}

int get(int pos){
    int res=0;
    for (int i=pos; i>=0; i=(i&(i+1))-1){
        res+=t[i];
    }
    return res;
}

int main(){
    cin >> n >> q;
    for (int i=0; i<n; i++){
        cin >> a[i];
    }
    build();
    while(q--){
        char type;
        cin >> type;
        if (type=='+'){
            int l,r,val;
            cin >> l >> r >> val;
            l--; r--;
            add(l,r,val);
        }
        else{
            int pos;
            cin >> pos;
            pos--;
            cout << get(pos) << endl;
        }
    }
    return 0;
}
