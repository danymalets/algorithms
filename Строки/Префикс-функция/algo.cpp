#include <bits/stdc++.h>
using namespace std;

vector<int> p_func(string s){
    int n=s.length();
    vector<int> p(n);
    for (int i=1; i<n; i++){
        int j=p[i-1];
        while(j>0&&s[i]!=s[j]){
            j=p[j-1];
        }
        p[i]=(s[i]==s[j]) ? j+1 : j;
    }
    return p;
}

int p_find(string subs,string s,int pos=0){
    int m=subs.length();
    s=subs+'#'+s.substr(pos,s.length()-pos);
    int n=s.length();
    vector<int> p(n);
    for (int i=1; i<n; i++){
        int j=p[i-1];
        while(j>0&&s[i]!=s[j]){
            j=p[j-1];
        }
        p[i]=(s[i]==s[j]) ? j+1 : j;
        if (p[i]==m) return i-2*m+pos;
    }
    return  -1;
}

int main()
{
    cout << p_find("ABC","abcdABCefg") << '\n';
    cout << p_find("ABC","aABCabABCcd",5) << '\n';
    return 0;
}
