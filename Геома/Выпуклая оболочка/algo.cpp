#include<bits/stdc++.h>
using namespace std;

const int N=1e5;

struct point{
    int x,y;
};

int n;
point a[N];

bool cmp(point a,point b){
    if (a.x==b.x) return a.y<b.y;
    return a.x<b.x;
}

long long where(point a,point b,point c){
    return 1LL*(c.y-b.y)*(b.x-a.x)-1LL*(b.y-a.y)*(c.x-b.x);
}

int S(vector<point> v){
    int res=0;
    v.push_back(v[0]);
    for (int i=0; i<v.size()-1; i++){
        res+=(v[i].x-v[i+1].x)*(v[i].y+v[i+1].y);
    }
    return res;
}

int gets(int l,int r){
    vector<point> s1,s2;
    for (int i=l; i<=r; i++){
        while(s1.size()>1&&where(s1[s1.size()-2],s1[s1.size()-1],a[i])<0LL){
            s1.pop_back();
        }
        s1.push_back(a[i]);
    }
    for (int i=l; i<=r; i++){
        while(s2.size()>1&&where(s2[s2.size()-2],s2[s2.size()-1],a[i])>0LL){
            s2.pop_back();
        }
        s2.push_back(a[i]);
    }
    for (int i=s2.size()-2; i>0; i--){
        s1.push_back(s2[i]);
    }
    return S(s1);
}

int main(){
    scanf("%d",&n);
    for (int i=0; i<n; i++){
        scanf("%d%d",&a[i].x,&a[i].y);
    }
    sort(a,a+n,cmp);
    cout << gets(0,n-1);
    return 0;
}

/*
8
3 6
1 5
5 5
1 3
6 3
1 1
5 1
3 0


*/


