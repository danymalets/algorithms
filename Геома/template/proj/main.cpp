#include <iostream>
#include <stdio.h>
#include <vector>
#include <stack>
#include <queue>
#include <deque>
#include <map>
#include <set>
#include <bitset>
#include <cmath>
#include <cstdlib>
#include <algorithm>
#include <math.h>
#include <random>
#include <string>
#include <iomanip>
using namespace std;

//#define double long

// geoma

const long double EXP=0;

struct point{
    long double x,y;
};

struct line{
    long double A,B,C;
};

struct segment{
    point A,B;
};

struct circle{
    point O;
    long double r;
};

long double distance(point p1,point p2){
    return sqrt((p1.x-p2.x)*(p1.x-p2.x)+(p1.y-p2.y)*(p1.y-p2.y));
}

line line_by_points(point p1,point p2){
    return {p1.y-p2.y,p2.x-p1.x,p1.x*p2.y-p2.x*p1.y};
}

point segment_center(segment s){
    return {(s.A.x+s.B.x)/2,(s.A.y+s.B.y)/2};
}

line perpendicular_line(line l,point p){
    return {-l.B,l.A,l.B*p.x-l.A*p.y};
}

point intersection_of_lines(line l1,line l2){
    return {(l2.B*l1.C-l1.B*l2.C)/(l2.A*l1.B-l1.A*l2.B),(l2.A*l1.C-l1.A*l2.C)/(l2.B*l1.A-l1.B*l2.A)};
}

int points(point p1,point p2,point p3){
    long double res=(p2.x-p1.x)*(p3.y-p2.y)-(p3.x-p2.x)*(p2.y-p1.y);
    if (abs(res)<=EXP) return 0;
    else if (res>0) return 1;
    else return -1;
}

circle circle_by_points(point p1,point p2,point p3){
    line l1,l2;
    l1=line_by_points(p1,p2);
    l2=line_by_points(p2,p3);
    l1=perpendicular_line(l1,segment_center({p1,p2}));
    l2=perpendicular_line(l2,segment_center({p2,p3}));
    point p=intersection_of_lines(l1,l2);
    return {p,distance(p,p1)};
}

//geoma

int main(){
    cout << setprecision(2) << fixed << a;
    point p1,p2,p3;
    cin >> p1.x >> p1.y >> p2.x >> p2.y >> p3.x >> p3.y;
    circle c=circle_by_points(p1,p2,p3);
    cout << setprecision(2) << fixed << c.O.x << ' ' << c.O.y << ' ' << c.r;
        cerr << setprecision(2) << fixed << "\nTime execute: " << clock() / (double)CLOCKS_PER_SEC << " sec" << endl;
    return 0;
}
