#include <bits/stdc++.h>
using namespace std;


const int MAXN=1e4;
const long long INF=1e18;


bool b[MAXN];
int n,m,x,y,start,ves,minv;
long long g[MAXN][MAXN];





int main(){


    scanf("%d%d",&n,&m);

    for (int i=0; i<n; i++){
        for (int j=0; j<n; j++){
            g[i][j]=INF;
        }
    }

    for (int i=0; i<n; i++){
        g[i][i]=0;
    }

    for (int i=0; i<m; i++){
        scanf("%d%d%d",&x,&y,&ves);
        x--; y--;
        g[x][y]=ves;
        g[y][x]=ves;
    }

    for (int k=0; k<n; k++){
        for (int i=0; i<n; i++){
            for (int j=0; j<n; j++){
                if(g[i][k]!=INF&&g[j][k]!=INF)
                    g[i][j]=min(g[i][j],g[i][k]+g[j][k]);
            }
        }
    }

    for (int i=0; i<n; i++){
        for (int j=0; j<n; j++){
            if (g[i][j]==INF) printf("INF ");
            else printf("%lld ",g[i][j]);
        }
        printf("\n");
    }

    return 0;
}

