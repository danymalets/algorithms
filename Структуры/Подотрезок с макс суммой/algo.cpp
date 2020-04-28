#include <bits/stdc++.h>
using namespace std;

const int N=1e5;

int n,l,r;
long long maxsum,lmin;
int a[N];
long long p[N];

int main(){
    scanf("%d",&n);
    for (int i=0; i<n; i++){
        scanf("%d",&a[i]);
        p[i]=a[i];
        if (i>0) p[i]+=p[i-1];
        if (p[i]<p[lmin]) lmin=i;
        if ()
    }
    return 0;
}
