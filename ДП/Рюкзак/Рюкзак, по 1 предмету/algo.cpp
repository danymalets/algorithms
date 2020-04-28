#include <bits/stdc++.h>
using namespace std;

const int MAXN=1e3;
const int MAXW=1e5;

int d[MAXN][MAXW],n,W,w,v;

int main()
{
    scanf("%d%d",&W,&n);
    for (int i=1; i<=n; i++){
        scanf("%d%d",&w,&v);
        for (int j=0; j<w; j++){
            d[i][j]=d[i-1][j];
        }
        for (int j=w; j<=W; j++){
            d[i][j]=max(d[i][j-w]+v,d[i-1][j]);
        }
    }
    printf("%d",d[n][W]);
    return 0;
}
