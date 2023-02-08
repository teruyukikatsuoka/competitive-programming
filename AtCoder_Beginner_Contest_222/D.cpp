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
using vll = vector<long long>;
using vvll = vector<vector<long long>>;
using pll = pair<long long, long long>;
//---------------------------------------------------------------
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
const int dx[4] = {1, 0, -1, 0};
const int dy[4] = {0, 1, 0, -1};
//---------------------------------------------------------------
struct Edge {
    ll to;
    ll w;
    Edge(ll to, ll w) : to(to), w(w) {}
};
using Graph = vector<vector<Edge>>;
//↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓

const int mod = 998244353;
struct mint {
int64_t x;
mint(int64_t x=0):x((x%mod+mod)%mod){}
mint operator-() const { return mint(-x);}
mint& operator+=(const mint a) {if ((x += a.x) >= mod) x -= mod;return *this;}
mint& operator-=(const mint a) {if ((x += mod-a.x) >= mod) x -= mod;return *this;}
mint& operator*=(const mint a) { (x *= a.x) %= mod; return *this;}
mint operator+(const mint a) const { return mint(*this) += a;}
mint operator-(const mint a) const { return mint(*this) -= a;}
mint operator*(const mint a) const { return mint(*this) *= a;}
mint pow(int64_t t) const {if (!t) return 1;mint a = pow(t>>1);a *= a;if (t&1) a *= *this;return a;}
mint inv() const { return pow(mod-2);}
mint& operator/=(const mint a) { return *this *= a.inv();}
mint operator/(const mint a) {return mint(*this) /= a;}
};
istream& operator>>(istream& is, mint& a) { return is >> a.x;}
ostream& operator<<(ostream& os, const mint& a) { return os << a.x;}

int main() {
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

    ll n;
    cin>>n;
    vec<ll> a(n);
    vec<ll> b(n);

    rep(i,n){
        cin>>a[i];
    }

    rep(i,n) cin>>b[i];

    vec<vec<mint>> dp(n, vec<mint>(3005, 0));

    srep(i, a[0], b[0]){
        dp[0][i] = 1;
    }

    srep(i,a[0], 3000){
        dp[0][i+1] += dp[0][i];
    }

    srep(i,0,n-2){
        srep(j,a[i+1], b[i+1]){
            dp[i+1][j] = dp[i][j];
        }

        srep(j, a[i+1], 3000){
            dp[i+1][j+1] += dp[i+1][j];
        }
    }
    
    cout<<dp[n-1][b[n-1]]<<endl;
       
}