#include<bits/stdc++.h>
using namespace std;

const int MOD=1e9+7;
const int N=(1<<17);

int n,m;
vector<int> x(N),y(N),z;

vector<int> naive_mult(const vector<int>& x, const vector<int>& y) {
    int n=x.size();
    vector<int> z(2*n);
    for (int i=0; i<n; i++){
        for (int j=0; j<n; j++){
            z[i+j]+=1LL*x[i]*y[j]%MOD;
        }
    }
    return z;
}

vector<int> mult_karatsuba(const vector<int>& x,const vector<int>& y){
    int n=x.size();
    if (n<=16){
        return naive_mult(x,y);
    }
    vector<int> z(2*n);
    int k=n/2;
    vector<int> a{x.begin()+k,x.end()},
                b{x.begin(),x.begin()+k},
                c{y.begin()+k,y.end()},
                d{y.begin(),y.begin()+k};
    vector<int> p1=mult_karatsuba(a,c),
                p2=mult_karatsuba(b,d);
    vector<int> s1(k),
                s2(k);
    for (int i=0; i<k; i++){
        s1[i]=(a[i]+b[i])%MOD;
        s2[i]=(c[i]+d[i])%MOD;
    }
    vector<int> p3=mult_karatsuba(s1,s2);
    for (int i=0; i<n; i++){
        p3[i]-=(p1[i]+p2[i])%MOD;
        if (p3[i]<0) p3[i]+=MOD;
    }
    for (int i=0; i<n; i++){
        z[i]=p2[i];
    }
    for (int i=n; i<2*n; i++){
        z[i]=p1[i-n];
    }
    for (int i=k; i<k+n; i++){
        z[i]=(z[i]+p3[i-k])%MOD;
    }
    return z;
}

int main(){
    cin >> n;
    for (int i=0; i<n; i++){
        cin >> x[i];
    }
    cin >> m;
    for (int i=0; i<m; i++){
        cin >> y[i];
    }
    z=mult_karatsuba(x,y);
    cout << n+m-1 << endl;
    for (int i=0; i<n+m-1; i++){
        cout << z[i] << ' ';
    }
    return 0;
}

/*

2
1 2
2
3 4

*/
