#include<bits/stdc++.h>
using namespace std;

const int MOD=1e9+7;

long long n;
vector<vector<int>> ans;

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

vector<vector<int>> mtrx_binpow(vector<vector<int>> a,long long n){
    if (n==1) return a;
    if (n%2==1) return mtrx_mult(mtrx_binpow(a,n-1),a);
    vector<vector<int>> t;
    t=mtrx_binpow(a,n/2);
    return mtrx_mult(t,t);
}

int main(){

    return 0;
}
