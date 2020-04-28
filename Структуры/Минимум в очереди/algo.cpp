#include <bits/stdc++.h>
using namespace std;

struct minqueue{
    stack<pair<int,int> > s1,s2;
    int back_val;

    int size(){
        return s1.size()+s2.size();
    }

    bool empty(){
        return !size();
    }

    void push(int val){
        back_val=val;
        int mn=(s1.empty()) ? val : min(val,s1.top().second);
        s1.push(make_pair(val,mn));
    }

    void perenos(){
        if (s2.empty()){
            int mn;
            while (!s1.empty()){
                mn=(s2.empty()) ? s1.top().first : min(s1.top().first,s2.top().second);
                s2.push(make_pair(s1.top().first,mn));
                s1.pop();
            }
        }
    }

    int back(){
        return back_val;
    }

    int front(){
        perenos();
        return s2.top().first;
    }

    void pop(){
        perenos();
        s2.pop();
    }

    int get_min(){
        if (s1.empty()) return s2.top().second;
        if (s2.empty()) return s1.top().second;
        return min(s1.top().second,s2.top().second);
    }
};

int q,type,val;
minqueue qu;

int main(){
    scanf("%d",&q);
    while(q--){
        scanf("%d",&type);
        if (type==1) {
            scanf("%d",&val);
            qu.push(val);
        }
        else if (type==2){
            qu.pop();
        }
        else {
            printf("%d\n",qu.get_min());
        }
    }
    return 0;
}
