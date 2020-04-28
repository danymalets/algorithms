#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;

#define fast_io ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0)
#define erase_unique(x) (x).erase(unique(all(x)),(x).end())
#define sp(x) setprecision(x) << fixed
#define all(x) (x).begin(),(x).end()
#define dcl(x,y) (x%y?x/y+1:x/y)
#define cube(x) ((x)*(x)*(x))
#define sqr(x) ((x)*(x))
#define bg1 cout << '!'
#define bg2 cout << '?'
#define ln cout << '\n'
#define pb push_back
#define mp make_pair
#define endl '\n'
#define file_all file_in,file_out
#define file_in freopen("input.txt","rt",stdin)
#define file_out freopen("output.txt","wt",stdout)

const ll LLINF=8e18;
const int MOD=998244353;
const int INF=2e9;
const int N=40000;
const int SN=200;

int n,q;
int a[N];
int tadd[SN],tupd[SN],mn[SN];
ll sum[SN];

void build(){
    for (int i=0; i<SN; i++){
        tupd[i]=-1;
        mn[i]=INF;
        for (int j=SN*i; j<min(n,SN*(i+1)); j++){
            mn[i]=min(mn[i],a[j]);
            sum[i]+=a[j];
        }
    }
}

int get(int pos){
    int num=pos/SN;
    if (tupd[num]==-1){
        return a[pos]+tadd[num];
    }
    else{
        return tupd[num]+tadd[num];
    }
}

void push(int num){
    if (tupd[num]!=-1){
        for (int i=num*SN; i<min(n,SN*(num+1)); i++){
            a[i]=tupd[num];
        }
    }
    for (int i=num*SN; i<min(n,SN*(num+1)); i++){
        a[i]+=tadd[num];
    }
    tupd[num]=-1;
    tadd[num]=0;
}

void per(int num){
    mn[num]=INF;
    sum[num]=0;
    for (int i=num*SN; i<min(n,SN*(num+1)); i++){
        mn[num]=min(mn[num],a[i]);
        sum[num]+=a[i];
    }
}

void update(int l,int r,int val){
    int num1=l/SN,
        num2=r/SN;
    if (num1==num2){
        push(num1);
        for (int i=l; i<=r; i++){
            a[i]=val;
        }
        per(num1);
    }
    else{
        push(num1);
        for (int i=l; i<min(n,SN*(num1+1)); i++){
            a[i]=val;
        }
        per(num1);
        push(num2);
        for (int i=SN*num2; i<=r; i++){
            a[i]=val;
        }
        per(num2);
    }
    for (int i=num1+1; i<num2; i++){
        tadd[i]=0;
        tupd[i]=val;
        sum[i]=1LL*val*SN;
        mn[i]=val;
    }
}

void add(int l,int r,int val){
    int num1=l/SN,
        num2=r/SN;
    if (num1==num2){
        push(num1);
        for (int i=l; i<=r; i++){
            a[i]+=val;
        }
        per(num1);
    }
    else{
        push(num1);
        for (int i=l; i<min(n,SN*(num1+1)); i++){
            a[i]+=val;
        }
        per(num1);
        push(num2);
        for (int i=SN*num2; i<=r; i++){
            a[i]+=val;
        }
        per(num2);
    }
    for (int i=num1+1; i<num2; i++){
        tadd[i]+=val;
        sum[i]+=1LL*val*SN;
        mn[i]+=val;
    }
}

ll getsum(int l,int r){
    int num1=l/SN,
        num2=r/SN;
    ll res=0;
    if (num1==num2){
        push(num1);
        for (int i=l; i<=r; i++){
            res+=a[i];
        }
    }
    else{
        push(num1);
        for (int i=l; i<min(n,SN*(num1+1)); i++){
            res+=a[i];
        }
        push(num2);
        for (int i=SN*num2; i<=r; i++){
            res+=a[i];
        }
    }
    for (int i=num1+1; i<num2; i++){
        res+=sum[i];
    }
    return res;
}

int getmin(int l,int r){
    int num1=l/SN,
        num2=r/SN;
    int res=INF;
    if (num1==num2){
        push(num1);
        for (int i=l; i<=r; i++){
            res=min(res,a[i]);
        }
    }
    else{
        push(num1);
        for (int i=l; i<SN*(num1+1); i++){
            res=min(res,a[i]);
        }
        push(num2);
        for (int i=SN*num2; i<=r; i++){
            res=min(res,a[i]);
        }
    }
    for (int i=num1+1; i<num2; i++){
        res=min(res,mn[i]);
    }
    return res;
}

int main(){
    fast_io;
    cin >> n;
    for (int i=0; i<n; i++){
        cin >> a[i];
    }
    build();

    cin >> q;
    while(q--){
        string type;
        cin >> type;
        if (type=="get"){
            int pos;
            cin >> pos;
            pos--;
            cout << get(pos) << endl;
        }
        else if (type=="update"){
            int l,r,val;
            cin >> l >> r >> val;
            l--; r--;
            update(l,r,val);
        }
        else if (type=="add"){
            int l,r,val;
            cin >> l >> r >> val;
            l--; r--;
            add(l,r,val);
        }
        else if (type=="rsq"){
            int l,r;
            cin >> l >> r;
            l--; r--;
            cout << getsum(l,r) << endl;
        }
        else {
            int l,r;
            cin >> l >> r;
            l--; r--;
            cout << getmin(l,r) << endl;
        }
    }
    return 0;
}

/*
4 4
1 2 3 4
+ 3 2
? 3 4
t 1
? 1 4
*/



































