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


int main() {
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

    ll n,x;cin>>n>>x;
    vec<bool> seen(n, false);
    x--;
    seen[x] = true;
    ll ans = 1;
    queue<ll> q;

    q.push(x);

    vll a(n);
    rep(i,n){
        ll aa;
        cin>>aa;
        aa--;
        a[i] = aa;
    }

    while(!q.empty()){
        ll c = q.front();
        q.pop();
        if(seen[a[c]] == false){
            seen[a[c]] = true;
            q.push(a[c]);
            ans++;
        }
    }

    cout<<ans<<endl;
    return 0;


}
