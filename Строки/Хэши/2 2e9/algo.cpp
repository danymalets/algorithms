#include <bits/stdc++.h>
using namespace std;

const int N=1e5;
const int P=29;
const int MOD1=2e9+11;
const int MOD2=2e9+33;

int n;
string s;
int powp1[N],powp2[N];
int hash1[N],hash2[N];

void init(string &s){
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
    s="aaaxyzxyz";
    init(s);
    cout << isequal(3,5,6,8) << isequal(2,4,5,7);
    return 0;
}
