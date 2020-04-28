#include <bits/stdc++.h>
using namespace std;

const int N=1e5;
const int L=20;

int n,classes,h=1;
string s;
int p[N],c[N],cn[N];

bool cmp0(int i,int j){
    return s[i]<s[j];
}

bool cmp1(int i,int j){
    if (c[i]==c[j]) return c[(i+h)%n]<c[(j+h)%n];
    return c[i]<c[j];
}

void init(){
    for (int i=0; i<n; i++){
        p[i]=i;
    }
    sort(p,p+n,cmp0);
    c[p[0]]=0;
    for (int i=1; i<n; i++){
        if (s[p[i]]!=s[p[i-1]]) classes++;
        c[p[i]]=classes;
    }
    /*
    for (int i=0; i<n; i++){
        cout << p[i] << ' ';
    }
    cout << ", ";
    for (int i=0; i<n; i++){
        cout << c[i] << ' ';
    }
    cout << endl;
    */
    while(h<n){
        sort(p,p+n,cmp1);
        classes=0;
        cn[p[0]]=0;
        for (int i=1; i<n; i++){
            if (c[p[i]]!=c[p[i-1]]||c[(p[i]+h)%n]!=c[(p[i-1]+h)%n]) classes++;
            cn[p[i]]=classes;
        }
        for (int i=0; i<n; i++){
            c[i]=cn[i];
        }
        /*
        for (int i=0; i<n; i++){
            cout << p[i] << ' ';
        }
        cout << ", ";
        for (int i=0; i<n; i++){
            cout << c[i] << ' ';
        }
        cout << endl;
        */
        h*=2;
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin >> s;
    n=s.length();
    init();
    for (int i=0; i<n; i++){
        cout << p[i] << ' ';
    }
    return 0;
}
