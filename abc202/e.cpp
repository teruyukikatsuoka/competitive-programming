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
//---------------------------------------------------------------

//↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓

ll n;ll q;
vec<vll> child, lis;
vll in, out, depth;
ll t;

void dfs(ll u){
    in[u] = t++;
    lis[depth[u]].push_back(in[u]);
    for(auto c : child[u]){
        depth[c] = depth[u] + 1;
        dfs(c);
    }

    out[u] = t++;
}

int main() {
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

    cin>>n;
    child = lis = vec<vll>(n);
    in  = out = depth = vll(n);
    t = 0;
    for(ll i = 1; i <= n - 1; i++){
        ll p;
        cin>>p;
        child[p-1].push_back(i);
    }

    dfs(0);

    cin>>q;
    while(q--){
        ll u,d;
        cin>>u>>d;
        u--;
        auto& v = lis[d];
        cout<<lower_bound(v.begin(), v.end(), out[u])
             - lower_bound(v.begin(), v.end(), in[u])<<endl;
    }

}