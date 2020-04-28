#include <bits/stdc++.h>
using namespace std;

const int N=1e5;

struct askdata{
    int l,r,num;
};

bool cmp1(askdata a,askdata b){
    return a.l<b.l;
}
bool cmp2(askdata a,askdata b){
    return a.r<b.r;
}

int n,q,sq,L,R=-1;
int a[N],v[N],t[N];
askdata ask[N];
long long result,ans[N];

void add(int pos,int val){
    for (int i=pos; i<n; i=(i|(i+1))){
        t[i]+=val;
    }
}

int getp(int pos){
    int res=0;
    for (int i=pos; i>=0; i=(i&(i+1))-1){
        res+=t[i];
    }
    return res;
}

int get(int l,int r){
    return getp(r)-getp(l-1);
}

void add_left(int val){
   // cout << "?? + l " << val << endl;
    result+=get(0,val-1);
    add(val,1);
}

void add_right(int val){
   // cout << "?? + r " << val << endl;
    result+=get(val+1,n-1);
    add(val,1);
}

void del_left(int val){
    //cout << "?? - l " << val << endl;
    result-=get(0,val-1);
    add(val,-1);
}

void del_right(int val){
    //cout << "?? - r " << val << endl;
    result-=get(val+1,n);
    add(val,-1);
}

int main(){
    //freopen("input.txt","r",stdin);
    cin >> n >> q;
    sq=sqrt(q);
    for (int i=0; i<n; i++){
        cin >> a[i];
        v[i]=a[i];
    }
    sort(v,v+n);
    for (int i=0; i<n; i++){
        a[i]=lower_bound(v,v+n,a[i])-v;
    }
    for (int i=0; i<q; i++){
        cin >> ask[i].l >> ask[i].r;
        ask[i].l--; ask[i].r--;
        ask[i].num=i;
    }
    sort(ask,ask+q,cmp1);
    for (int i=0; i<q; i+=sq){
        sort(ask+i,ask+min(q,i+sq),cmp2);
    }
    for (int i=0; i<q; i++){
        while(L>ask[i].l){
            L--;
            add_left(a[L]);
        }
        while(R<ask[i].r){
            R++;
            add_right(a[R]);
        }
        while(L<ask[i].l){
            del_left(a[L]);
            L++;
        }
        while(R>ask[i].r){
            del_right(a[R]);
            R--;
        }
        ans[ask[i].num]=result;
    }
    for (int i=0; i<q; i++){
        cout << ans[i] << '\n';
    }
    return 0;
}
