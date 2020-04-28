#include<bits/stdc++.h>
using namespace std;

const int N=1e5;

struct data{
    int num,l,r;
};

bool cmp(data a,data b){
    return a.r<b.r;
}

int n,q;
int a[N],p[N],w[N],t[N],ans[N];
data ask[N];
vector<int> v;

void add(int pos,int val){
    for (int i=pos; i<n; i=(i|(i+1))){
        t[i]+=val;
    }
}

int getp(int r){
    int res=0;
    for (int i=r; i>=0; i=(i&(i+1))-1){
        res+=t[i];
    }
    return res;
}

int get(int l,int r){
    return getp(r)-getp(l-1);
}

int main(){
    cin >> n >> q;
    for (int i=0; i<n; i++){
        cin >> a[i];
        v.push_back(a[i]);
    }
    sort(v.begin(),v.end());
    v.erase(unique(v.begin(),v.end()),v.end());
    fill(p,p+n,-1);
    for (int i=0; i<q; i++){
        ask[i].num=i;
        cin >> ask[i].l >> ask[i].r;
        ask[i].l--; ask[i].r--;
    }
    sort(ask,ask+q,cmp);
    int j=0;
    for (int i=0; i<n; i++){
        int tmp=lower_bound(v.begin(),v.end(),a[i])-v.begin();
        w[i]=p[tmp];
        p[tmp]=i;
        add(i,1);
        if (w[i]!=-1) add(w[i],-1);
        while(ask[j].r==i){
            ans[ask[j].num]=get(ask[j].l,ask[j].r);
            j++;
        }
    }
    for (int i=0; i<q; i++){
        cout << ans[i] << '\n';
    }
    return 0;
}
