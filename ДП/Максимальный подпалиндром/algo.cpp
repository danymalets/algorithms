#include <bits/stdc++.h>
using namespace std;

const int N=1e3;

int n;
int dp[N][N];
string s;

int main()
{
    ios_base::sync_with_stdio(0);
    cin >> n >> s;
    for (int i=0; i<n; i++){
        dp[i][i]=1;
    }
    for (int len=2; len<=n; len++){
        for (int i=0; i<n-len+1; i++){
            int j=i+len-1;
            if (s[i]==s[j]){
                dp[i][j]=dp[i+1][j-1]+2;
            } else{
                dp[i][j]=max(dp[i+1][j],dp[i][j-1]);
            }
        }
    }
    cout << dp[0][n-1];
    return 0;
}
