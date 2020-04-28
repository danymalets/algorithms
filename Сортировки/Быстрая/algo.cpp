#include<bits/stdc++.h>
using namespace std;

const int N=1e5;

int n;
int a[N];

void quicksort(int *a,int l,int r){
    if (r<=l) return;
    int i=l,j=r;
    int x=a[l+rand()%(r-l+1)];
    do{
        while(a[i]<x) i++;
        while(a[j]>x) j--;
        if (i<=j){
            swap(a[i],a[j]);
            i++; j--;
        }
    }while(i<=j);
    quicksort(a,l,j);
    quicksort(a,i,r);
}

int main(){
    scanf("%d",&n);
    for (int i=0; i<n; i++){
        scanf("%d",&a[i]);
    }
    quicksort(a,0,n-1);
    for (int i=0; i<n; i++){
        printf("%d ",a[i]);
    }
    return 0;
}
