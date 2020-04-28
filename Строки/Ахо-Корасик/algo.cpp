#include <bits/stdc++.h>
using namespace std;

const int MSL=1e6;
const int K=26;

struct vertex{
    bool flag;
    char pch;
    int p,lnk;
    int next[K],go[K];
} t[MSL+1];

int sz=1;

void init(){
    t[0].lnk=t[0].p=-1;
    memset(t[0].next,-1,sizeof(t[0].next));
    memset(t[0].go,-1,sizeof(t[0].go));
}

void add(string s){
    int v=0;
    for (int i=0; i<s.length(); i++){
        char c=s[i]-'a';
        if (t[v].next[c]==-1){
            memset(t[sz].next,-1,sizeof(t[sz].next));
            memset(t[sz].go,-1,sizeof(t[sz].go));
            t[sz].lnk=-1;
            t[sz].p=v;
            t[sz].pch=c;
            t[v].next[c]=sz++;
        }
        v=t[v].next[c];
    }
    t[v].flag=true;
}

int go(int v,int c);

int get_link(int v){
    if (t[v].lnk==-1){
        if (v==0||t[v].p==0){
            t[v].lnk=0;
        }
        else{
            t[v].lnk=go(get_link(t[v].p),t[v].pch);
        }
    }
    return t[v].lnk;
}

int go(int v,int c){
    if (t[v].go[c]==-1){
        if (t[v].next[c]!=-1){
            t[v].go[c]=t[v].next[c];
        }
        else{
            if (v==0)
                t[v].go[c]=0;
            else{
                t[v].go[c]=go(get_link(v),c);
            }
        }
    }
    return t[v].go[c];
}

int main()
{
    init();
    add("abcd");
    add("bc");
    add("cd");
    cout << get_link(2);
    return 0;
}
