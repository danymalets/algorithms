#include <bits/stdc++.h>
using namespace std;

const int N=1e5;

int n;
int a[N];

long long inversions(int *a,int l,int r){
    if (l==r) return 0;
    int m=(l+r)/2;
    long long res=inversions(a,l,m)+inversions(a,m+1,r);
    int i=l,j=m+1,k=0;
    int temp[r-l+1];
    while(i<=m&&j<=r){
        if (a[i]<a[j]){
            temp[k]=a[i];
            i++;
            res+=j-(m+1);
        }
        else{
            temp[k]=a[j];
            j++;
        }
        k++;
    }
    while(i<=m){
        temp[k]=a[i];
        i++; k++;
        res+=j-(m+1);
    }
    while(j<=r){
        temp[k]=a[j];
        j++; k++;
    }
    for (int i=l; i<=r; i++){
        a[i]=temp[i-l];
    }
    return res;
}

int main(){
    scanf("%d",&n);
    for (int i=0; i<n; i++){
        scanf("%d",&a[i]);
    }
    printf("%I64d",inversions(a,0,n-1));
    return 0;
}
