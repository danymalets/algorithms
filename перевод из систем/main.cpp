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

typedef long long ll;
typedef long double ld;

#define fast_io ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0)
#define erase_unique(x) (x).erase(unique(all(x)),(x).end())
#define sp(x) setprecision(x) << fixed
#define all(x) (x).begin(),(x).end()
#define dcl(x,y) (x%y?x/y+1:x/y)
#define cube(x) ((x)*(x)*(x))
#define sqr(x) ((x)*(x))
#define bg1 cout << '!'
#define bg2 cout << '?'
#define ln cout << '\n'
#define pb push_back
#define mp make_pair
#define endl '\n'
#define file_all file_in,file_out
#define file_in freopen("input.txt","rt",stdin)
#define file_out freopen("output.txt","wt",stdout)

const ll LLINF = 8e18;
const int MOD = 1e9+7;
const int INF = 2e9;
const int N = 2e5;

long long to10(vector<int> v, int k) {
    long long res = 0;
    for (int i = (int)v.size() - 1; i >= 0; i--) {
        res *= k;
        res += v[i];
    }
    return res;
}

vector<int> from10(long long a, int k) {
    vector<int> res;
    while (a > 0) {
        res.push_back(a % k);
        a /= k;
    }
    return res;
}

string vtos(vector<int> v) {
    string s;
    for (int i = (int)v.size() - 1; i >= 0; i--) {
        if (v[i] < 10) s += v[i] + '0';
        else s += v[i] + 'A' - 10;
    }
    return s;
}

vector<int> stov(string s) {
    vector<int> v;
    for (int i = (int)s.length() - 1; i >= 0; i--) {
        if (isdigit(s[i])) v.push_back(s[i] - '0');
        else v.push_back(s[i] - 'A' + 10);
    }
    return v;
}

string convert(string s, int k, int n){
    return vtos(from10(to10(stov(s), k), n));
}

int main(){
    fast_io;
    string s;
    cin >> s;
    cout << convert(s, 5, 14);
    cerr << sp(2) << "\nTime execute: " << clock() / (double)CLOCKS_PER_SEC << " sec" << endl;
    return 0;
}

