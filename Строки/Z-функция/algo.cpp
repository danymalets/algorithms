#include <bits/stdc++.h>
using namespace std;

vector<int> z_func(string s){
    int n=s.length();
    vector<int> z(n);
    for (int i=1,l=0,r=0; i<n; i++){
        if (i<=r) z[i]=min(z[i-l],r-i+1);
        while (i+z[i]<n&&s[i+z[i]]==s[z[i]]) z[i]++;
        if (i+z[i]-1>r) l=i,r=i+z[i]-1;
    }
    return z;
}

int z_find(string subs,string s,int pos=0){
    int m=subs.length();
    s=subs+'#'+s.substr(pos,s.length()-pos);
    int n=s.length();
    vector<int> z(n);
    for (int i=1,l=0,r=0; i<n; i++){
        if (i<=r) z[i]=min(z[i-l],r-i+1);
        while (i+z[i]<n&&s[i+z[i]]==s[z[i]]) z[i]++;
        if (i+z[i]-1>r) l=i,r=i+z[i]-1;
        if (z[i]==m) return i-m+pos-1;
    }
    return -1;
}

int main()
{
    cout << z_find("ABC","abcdABCefg") << '\n';
    cout << z_find("ABC","aABCabABCcd",5) << '\n';
    return 0;
}
