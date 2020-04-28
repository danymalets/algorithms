#include<bits/stdc++.h>
using namespace std;

const int MOD=1e9+7;

int n,k,m;

vector<vector<int>> mtrx_mult(vector<vector<int>> a,vector<vector<int>> b){
    int n=a.size();
    vector<vector<int>> res(n,vector<int>(n));
    for (int i=0; i<n; i++){
        for (int j=0; j<n; j++){
            for (int k=0; k<n; k++){
                res[i][j]=(0LL+res[i][j]+1LL*a[i][k]*b[k][j])%MOD;
            }
        }
    }
    return res;
}

vector<vector<int>> mtrx_binpow(vector<vector<int>> a,int n){
    if (n==1) return a;
    if (n%2==1) return mtrx_mult(mtrx_binpow(a,n-1),a);
    vector<vector<int>> t;
    t=mtrx_binpow(a,n/2);
    return mtrx_mult(t,t);
}

int main(){
    scanf("%d%d%d",&n,&k,&m);
    vector<vector<int>> a(m,vector<int>(m));
    for (int i=0; i<m; i++){
        for (int j=i; j<=i+k; j++){
            a[i][(j+3*m)%m]++;
        }
    }
    for (int i=0; i<m; i++){
        for (int j=0; j<m; j++){
            cout << a[i][j] << ' ';
        }
        cout << endl;
    }
    cout << endl;
    a=mtrx_binpow(a,n);
    for (int i=0; i<m; i++){
        for (int j=0; j<m; j++){
            cout << a[i][j] << ' ';
        }
        cout << endl;
    }
    return 0;
}
