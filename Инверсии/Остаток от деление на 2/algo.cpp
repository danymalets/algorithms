#include<bits/stdc++.h>
using namespace std;

const int N=1e5;

int n,ans;
int a[N],t[N];

int main(){
    scanf("%d",&n);
    for (int i=0; i<n; i++){
        scanf("%d",&a[i]);
        a[i]--;
    }
    for (int i=0; i<n; i++){
        while (a[i]!=i){
            swap(a[a[i]],a[i]);
            ans++;
        }
    }
    ans%=2;
    printf("%d",ans);
    return 0;
}
