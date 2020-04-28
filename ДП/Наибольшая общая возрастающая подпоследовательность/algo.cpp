#include <bits/stdc++.h>
using namespace std;

const int N=3e3+1;

int n,m,dp[N][N];
vector<int> a,b;

int main(){
    scanf("%d%d",&n,&m);
    a.resize(n+1);
    b.resize(m+1);
    for (int i=1; i<=n; i++){
        scanf("%d",&a[i]);
    }
    for (int i=1; i<=m; i++){
        scanf("%d",&b[i]);
    }
    for (int i=1; i<=n; i++){
        int best=0;
        for (int j=1; j<=m; j++){
            dp[i][j]=dp[i-1][j];
            if (a[i]==b[j]&&dp[i-1][j]<best+1) dp[i][j]=best+1;
            if (a[i]>b[j]&&dp[i-1][j]>best) best=dp[i-1][j];
        }
    }
    int mx=0;
    for (int j=1; j<=m; j++){
        mx=max(dp[n][j],mx);
    }
    printf("%d",mx);
    return 0;
}
