#include <bits/stdc++.h>
using namespace std;

const int N=1e6;
const int L=26;

int next[N+1][L],sz=1,q,type;
bool flag[N+1];
string s;

void add(string s){
    int v=0;
    for (int i=0; i<s.length(); i++){
        char c=s[i]-'a';
        if (next[v][c]==0){
            next[v][c]=sz; sz++;
        }
        v=next[v][c];
    }
    flag[v]=1;
}

void del(string s){
    int v=0;
    for (int i=0; i<s.length(); i++){
        char c=s[i]-'a';
        if (next[v][c]==0) return;
        v=next[v][c];
    }
    flag[v]=0;
}

bool get(string s){
    int v=0;
    for (int i=0; i<s.length(); i++){
        char c=s[i]-'a';
        if (next[v][c]==0) return 0;
        v=next[v][c];
    }
    return flag[v];
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin >> q;
    while(q--){
        cin >> type;
        getline(cin,s);
        s.erase(0,1);
        if (type==1) add(s);
        else if (type==2) del(s);
        else cout << (get(s) ? "Yes\n" : "No\n");
    }
    return 0;
}
