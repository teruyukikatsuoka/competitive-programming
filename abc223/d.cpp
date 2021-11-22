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

    ll n,m;
    cin>>n>>m;
    
    vec<vll> g(n+1);
    vll indeg(n+1,0);

    rep(i,m){
        ll a,b;
        cin>>a>>b;
        g[a].push_back(b);
        indeg[b]++;
    }

    priority_queue<ll, vector<ll>,greater<ll>> q;

    srep(i,1,n){
        if(indeg[i]==0)q.push(i);
    }

    queue<ll> ans;

    while(!q.empty()){
        ll x = q.top();
        q.pop();
        ans.push(x);

        for(auto v : g[x]){
            --indeg[v];
            if(indeg[v] == 0)q.push(v);
        }
    }

    if((ll)ans.size() == n){
        while(!ans.empty()){
            cout<<ans.front()<<" ";
            ans.pop();
        }
    }else{
        cout<< -1 <<endl;
    }



}
