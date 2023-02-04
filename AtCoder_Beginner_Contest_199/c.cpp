//---------------------------------------------------------------
#include <bits/stdc++.h>
using namespace std;
#include <cstdlib>
#include <cmath>
#include <math.h>
#include <sstream>
#include <numeric>
#include <cassert>
//---------------------------------------------------------------
#define rep(i, n) for (long long i = 0; i < (long long)(n); i++)
#define rrep(i, n) for (long long i = 1; i <= (long long)(n); i++)
#define srep(i, s, n) for (long long i = (s); i <= (long long)(n); i++)
#define drep(i,n) for(long long i = (n)-1; i >= 0; --i)
#define SIZE 100005
#define INF 1e18
#define all(x) x.begin(),x.end()
#define fi first
#define se second
#define vec vector
using pint = pair<int,int>;
using ll = long long;
using vll = vector<ll>;
using vvll = vector<vector<ll>>;
//---------------------------------------------------------------
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
const int dx[4] = {1, 0, -1, 0};
const int dy[4] = {0, 1, 0, -1};
const double pi = acos(-1);
//---------------------------------------------------------------

//↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓


int main() {
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

    ll r,x,y;
    cin>>r>>x>>y;
    double ren = sqrt(x*x+y*y);
    if(r*r == x*x + y*y){cout<<1<<endl; return 0;}
    if(r*r> x*x + y*y) {cout<<2<<endl; return 0;}
    ll ans = ren/r+0.9999999999999;
    cout<<ans<<endl;
    return 0;
}