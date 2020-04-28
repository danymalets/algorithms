#include <bits/stdc++.h>
using namespace std;

const int MX=100;
const int SUM=100;
const int N=100;

int n,sum,mx;
int dp[SUM][N];

int get(int k,int sum,int mx){
    //cout << k << ' ' << sum << ' ' << mx << endl;
    if (k==0){
        if (sum==0) return 1;
        return 0;
    }
    int ans=0;
    for (int i=0; i<=min(sum,mx); i++){
        ans+=get(k-1,sum-i,mx);
    }
    return ans;
}

int main()
{
    //cout << get(2,2,0);
    scanf("%d%d",&n,&sum);
    for (int i=0; i<=sum; i++){
        for (int j=0; j<=n; j++){
            dp[i][j]=1;
        }
    }

    for (int i=0; i<=sum; i++){
        for (int j=0; j<=n; j++){
            cout << get(j,i,9) << ' ';
        }
        cout << endl;
    }
    return 0;
}
