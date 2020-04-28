#include<bits/stdc++.h>
using namespace std;

const int INF=2e9;
const int N=1000;

int n,m,q;
int a[N][N];
int t[4*N][4*N];

void build_y(int xv,int xtl,int xtr,int yv,int ytl,int ytr){
    if (ytl+1==ytr){
        if (xtl+1==xtr){
            t[xv][yv]=a[xtl][ytl];
        }
        else{
            t[xv][yv]=max(t[xv*2][yv],t[xv*2+1][yv]);
        }
    }
    else{
        int ytm=(ytl+ytr)/2;
        build_y(xv,xtl,xtr,yv*2,ytl,ytm);
        build_y(xv,xtl,xtr,yv*2+1,ytm,ytr);
        t[xv][yv]=max(t[xv][yv*2],t[xv][yv*2+1]);
    }
}

void build_x(int xv,int xtl,int xtr,int yv,int ytl,int ytr){
    if (xtl+1==xtr){

    }
    else{
        int xtm=(xtl+xtr)/2;
        build_x(xv*2,xtl,xtm,yv,ytl,ytr);
        build_x(xv*2+1,xtm,xtr,yv,ytl,ytr);
    }
    build_y(xv,xtl,xtr,yv,ytl,ytr);
}

void build(){
    build_x(1,0,n,1,0,m);
}

int get_y(int xv,int xtl,int xtr,int yv,int ytl,int ytr,int xl,int xr,int yl,int yr){
    //cout << "!! " << yv << ' ' << ytl << ' ' << ytr << ' ' << yl << ' ' << yr << endl;
    if (yl>=yr) return -INF;
    if (yl==ytl&&yr==ytr){
        return t[xv][yv];
    }
    else{
        int ytm=(ytl+ytr)/2;
        return max(get_y(xv,xtl,xtr,yv*2,ytl,ytm,xl,xr,yl,min(yr,ytm)),
                   get_y(xv,xtl,xtr,yv*2+1,ytm,ytr,xl,xr,max(yl,ytm),yr));
    }
}

int get_x(int xv,int xtl,int xtr,int yv,int ytl,int ytr,int xl,int xr,int yl,int yr){
    //cout << "?? " << xv << ' ' << xtl << ' ' << xtr << ' '<< xl << ' ' << xr << endl;
    if (xl>=xr) return -INF;
    if (xl==xtl&&xr==xtr){
        return get_y(xv,xtl,xtr,yv,ytl,ytr,xl,xr,yl,yr);
    }
    else{
        int xtm=(xtl+xtr)/2;
        return max(get_x(xv*2,xtl,xtm,yv,ytl,ytr,xl,min(xr,xtm),yl,yr),
                   get_x(xv*2+1,xtm,xtr,yv,ytl,ytr,max(xl,xtm),xr,yl,yr));
    }
}

int get(int x1,int y1,int x2,int y2){
    return get_x(1,0,n,1,0,m,x1,x2,y1,y2);
}

void update_y(int xv,int xtl,int xtr,int yv,int ytl,int ytr,int x,int y,int val){
    if (ytl+1==ytr){
        if (xtl+1==xtr){
            t[xv][yv]=val;
        }
        else{
            t[xv][yv]=max(t[xv*2][yv],t[xv*2+1][yv]);
        }
    }
    else{
        int ytm=(ytl+ytr)/2;
        if (y<ytm) update_y(xv,xtl,xtr,yv*2,ytl,ytm,x,y,val);
        else update_y(xv,xtl,xtr,yv*2+1,ytm,ytr,x,y,val);
        t[xv][yv]=max(t[xv][yv*2],t[xv][yv*2+1]);
    }
}

void update_x(int xv,int xtl,int xtr,int yv,int ytl,int ytr,int x,int y,int val){
    if (xtl+1==xtr){

    }
    else{
        int xtm=(xtl+xtr)/2;
        if (x<xtm) update_x(xv*2,xtl,xtm,yv,ytl,ytr,x,y,val);
        else update_x(xv*2+1,xtm,xtr,yv,ytl,ytr,x,y,val);
    }
    update_y(xv,xtl,xtr,yv,ytl,ytr,x,y,val);
}

void update(int x,int y,int val){
    update_x(1,0,n,1,0,m,x,y,val);
}

int main(){
    ios_base::sync_with_stdio(0);
    //freopen("out.txt","w",stdout);
    cin >> n >> m >> q;
    for (int i=0; i<n; i++){
        for (int j=0; j<m; j++){
            cin >> a[i][j];
        }
    }
    build();
    while(q--){
        char type;
        cin >> type;
        if (type=='?'){
            int x1,y1,x2,y2;
            cin >> x1 >> x2 >> y1 >> y2;
            x1--; y1--;
            cout << get(x1,y1,x2,y2) << '\n';
        }
        else{
            int x,y,val;
            cin >> x >> y >> val;
            x--; y--;
            update(x,y,val);
        }
    }
    return 0;
}
