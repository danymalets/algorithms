#include <bits/stdc++.h>
using namespace std;

const int N=1e5;

int n;
int a[N];

void mergesort(int *a,int l,int r){
    if (l==r) return;
    int m=(l+r)/2;
    mergesort(a,l,m);
    mergesort(a,m+1,r);
    int i=l,j=m+1,k=0;
    int temp[r-l+1];
    while(i<=m&&j<=r){
        if (a[i]<a[j]){
            temp[k]=a[i];
            i++;
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
    }
    while(j<=r){
        temp[k]=a[j];
        j++; k++;
    }
    for (int i=l; i<=r; i++){
        a[i]=temp[i-l];
    }
}

int main(){
    scanf("%d",&n);
    for (int i=0; i<n; i++){
        scanf("%d",&a[i]);
    }
    mergesort(a,0,n-1);
    for (int i=0; i<n; i++){
        printf("%d ",a[i]);
    }
    return 0;
}
