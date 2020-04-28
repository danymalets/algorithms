#include <bits/stdc++.h>
using namespace std;

const int MAXN=1e5;

int a[MAXN],n;
vector<int> v;

int lenLIS(int a[],int l,int r){
    vector<int> ans;
    for (int i=l; i<=r; i++){
        int x=lower_bound(ans.begin(),ans.end(),a[i])-ans.begin();
        if (x==ans.size()) ans.push_back(a[i]);
        else ans[x]=a[i];
    }
    return ans.size();
}

void LIS(int a[],int l,int r,vector<int> &ans){
    ans.clear();
    for (int i=l; i<=r; i++){
        int x=lower_bound(ans.begin(),ans.end(),a[i])-ans.begin();
        if (x==ans.size()) ans.push_back(a[i]);
        else ans[x]=a[i];
    }
}

int lenLNDS(int a[],int l,int r){
    vector<int> ans;
    for (int i=l; i<=r; i++){
        int x=upper_bound(ans.begin(),ans.end(),a[i])-ans.begin();
        if (x==ans.size()) ans.push_back(a[i]);
        else ans[x]=a[i];
    }
    return ans.size();
}

void LNDS(int a[],int l,int r,vector<int> &ans){
    ans.clear();
    for (int i=l; i<=r; i++){
        int x=upper_bound(ans.begin(),ans.end(),a[i])-ans.begin();
        if (x==ans.size()) ans.push_back(a[i]);
        else ans[x]=a[i];
    }
}

int main()
{
    scanf("%d",&n);
    for (int i=0; i<n; i++){
        scanf("%d",&a[i]);
    }
    LIS(a,0,n-1,v);
    printf("%d\n",v.size());
    for (int i=0; i<v.size(); i++){
        printf("%d ",v[i]);
    }
    return 0;
}
