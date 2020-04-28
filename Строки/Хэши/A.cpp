#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;

#define fast_io ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0)
#define erase_unique(x) (x).erase(unique(all(x)),(x).end())
#define sp(x) setprecision(x) << fixed
#define all(x) (x).begin(),(x).end()
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
const int MOD=2e9;
const int INF=2e9;
const int N=1e6;
const int P=29;

string s,t;
int fir0,fir1,cnt0,cnt1;
int ans;

int MOD1,MOD2;
int powp1[N],powp2[N];
int hash1[N],hash2[N];

int myrand(){
    return (int)1e9+rand()*(RAND_MAX+1)+rand();
}

bool isprime(int x){
    int t=sqrt(x);
    for (int i=2; i<=t; i++){
        if (x%i==0) return false;
    }
    return true;
}

void init(string &s){
    MOD1=myrand();
    while(!isprime(MOD1)) MOD1++;
    MOD2=myrand();
    while(!isprime(MOD2)||MOD2==MOD1) MOD2++;
    powp1[0]=1;
    powp2[0]=1;
    hash1[0]=s[0]-'a';
    hash2[0]=s[0]-'a';
    for (int i=1; i<s.length(); i++){
        powp1[i]=1LL*powp1[i-1]*P%MOD1;
        powp2[i]=1LL*powp2[i-1]*P%MOD2;
        hash1[i]=(0LL+hash1[i-1]+1LL*powp1[i]*(s[i]-'a'))%MOD1;
        hash2[i]=(0LL+hash2[i-1]+1LL*powp2[i]*(s[i]-'a'))%MOD2;
    }
}

int gethash1(int l,int r){
    return (0LL+hash1[r]-(l>0 ? hash1[l-1] : 0)+MOD1)%MOD1;
}

int gethash2(int l,int r){
    return (0LL+hash2[r]-(l>0 ? hash2[l-1] : 0)+MOD2)%MOD2;
}

bool isequal(int l1,int r1,int l2,int r2){
    if (r2-l2!=r1-l1) return false;
    return (1LL*gethash1(l1,r1)*powp1[l2]%MOD1==1LL*gethash1(l2,r2)*powp1[l1]%MOD1&&
            1LL*gethash2(l1,r1)*powp2[l2]%MOD2==1LL*gethash2(l2,r2)*powp2[l1]%MOD2);
}

int main()
{
    fast_io;
    srand(time(0));
    cin >> s >> t;
    init(t);
    for (int i=s.length()-1; i>=0; i--){
        if (s[i]=='0'){
            cnt0++;
            fir0=i;
        }
        else{
            cnt1++;
            fir1=i;
        }
    }
    if (cnt0<cnt1){
        for (int i=0; i<s.length(); i++){
            if (s[i]=='0') s[i]='1'; else s[i]='0';
        }
        swap(fir0,fir1);
        swap(cnt0,cnt1);
    }
    for (int x=1; x*cnt0<t.length(); x++){
        if ((t.length()-x*cnt0)%cnt1>0) continue;
        int y=(t.length()-x*cnt0)/cnt1;
        //cout << "! " << x << ' ' << y << endl;
        bool ok=true;
        for (int i=0,t=0; i<s.length(); i++){
            if (s[i]=='0'){
                if (!isequal(t,t+x-1,fir0*y,fir0*y+x-1)) ok=false;
                t+=x;
            }
            else{
                if (!isequal(t,t+y-1,fir1*x,fir1*x+y-1)) ok=false;
                t+=y;
            }
        }
        if (ok&&!isequal(fir0*y,fir0*y+x-1,fir1*x,fir1*x+y-1)) ans++;
    }
    cout << ans;
    return 0;
}




































