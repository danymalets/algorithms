#include <bits/stdc++.h>
using namespace std;

const int N=1e5;
const int L=17;

int n,classes,i,h=1;
string s;
int p[N+1],c[L+1][N+1];
long long ans;

bool cmp0(int x,int y){
    return s[x]<s[y];
}

bool cmp1(int x,int y){
    if (c[i-1][x]==c[i-1][y]) return c[i-1][(x+h)%n]<c[i-1][(y+h)%n];
    return c[i-1][x]<c[i-1][y];
}

int lcp(int x,int y){
    int res=0;
    for (int i=L; i>=0; i--){
        if (c[i][x+res]==c[i][y+res]){
            res+=(1<<i);
        }
    }
    return res;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin >> s;
    s+=' ';
    n=s.length();
    for (int j=0; j<n; j++){
        p[j]=j;
    }
    sort(p,p+n,cmp0);
    c[0][p[0]]=0;
    for (int j=1; j<n; j++){
        if (s[p[j]]!=s[p[j-1]]) classes++;
        c[0][p[j]]=classes;
    }
    for (i=1; i<=L; i++){
        sort(p,p+n,cmp1);
        classes=0;
        c[i][p[0]]=0;
        for (int j=1; j<n; j++){
            if (c[i-1][p[j]]!=c[i-1][p[j-1]]||c[i-1][(p[j]+h)%n]!=c[i-1][(p[j-1]+h)%n]) classes++;
            c[i][p[j]]=classes;
        }
        h*=2;
    }
    for (int i=1; i<n; i++){
        ans+=n-p[i]-1-lcp(p[i],p[i-1]);
    }
    cout << ans;
    return 0;
}
