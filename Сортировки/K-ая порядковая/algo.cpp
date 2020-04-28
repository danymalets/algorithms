#include<bits/stdc++.h>
using namespace std;

const int N=1e6;

int n,k;
int a[N];

int my_rand(int x){
    return (rand()*(RAND_MAX+1)+rand())%x;
}

int find_kth(int l,int r,int k){
    while(true){
        int mid=a[l+my_rand(r-l+1)],x=l,y=l;
        for (int z=l; z<r; z++){
            if (a[z]<mid){
                int t=a[z];
                a[z]=a[y];
                a[y]=a[x];
                a[x]=t;
                x++; y++;
            }
            else if (a[z]==mid){
                swap(a[y],a[z]);
                y++;
            }
        }
        if (k<x) r=x;
        else if (k>=y) l=y;
        else return a[x];
    }
}

int main(){
    //scanf("%d%d",&n,&k);
    n=1e6;
    k=1;
    k--;
    for (int i=0; i<n; i++){
        //scanf("%d",&a[i]);
        a[i]=5;
    }
    cout << find_kth(0,n-1,k);

    return 0;
}
