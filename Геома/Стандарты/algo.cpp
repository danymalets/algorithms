#include<bits/stdc++.h>
using namespace std;

int point_in_line(int x1,int y1,int x2,int y2,int x3,int y3){ // left 1,in 0,right -1
    long long res=1LL*(y3-y2)*(x2-x1)-1LL*(y2-y1)*(x3-x2);
    if (res>0) return 1;
    if (res<0) return -1;
    return 0;
}

int main(){
    cout << point_in_line(0,0,-2,-2,-4,-1);
    return 0;
}
