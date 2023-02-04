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
struct UnionFind {
    vector<int> par; // par[i]:iの親の番号　(例) par[3] = 2 : 3の親が2

    UnionFind(int N) {
        par = vector<int>(N,-1);
    }

    int root(int x) { // データxが属する木の根を再帰で得る：root(x) = {xの木の根}
        if (par[x]<0) return x;
        return par[x] = root(par[x]);
    }

    bool unite(int x, int y) { // xとyの木を併合
        x = root(x); //xの根をrx
        y = root(y); //yの根をry
        if (x == y) return false; //xとyの根が同じ(=同じ木にある)時はそのま
        if(par[x]>par[y]) swap(x,y);
        par[x]+=par[y];
        par[y] = x;
        return true; //xとyの根が同じでない(=同じ木にない)時：xの根rxをyの根ryにつける
    }

    bool same(int x, int y) { // 2つのデータx, yが属する木が同じならtrueを返す
        int rx = root(x);
        int ry = root(y);
        return rx == ry;
    }

    int size(int x){
        return -par[root(x)];
    }
};



int main() {
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

    ll n,m;cin>>n>>m;

    vec<vll> g(n);

    rep(i,m){
        ll a,b;
        cin>>a>>b;
        a--;b--;
        g[a].push_back(b);
    }

    UnionFind uf(n);

    ll sum = 0;
    vll ans = {0};
    
    for(ll i = n-1; i>=1; i--){
        sum++;
        for(auto v: g[i]){
            if(!uf.same(i,v)){uf.unite(i,v);sum--;}
        }
        ans.push_back(sum);
    }

    reverse(all(ans));

    for(auto x: ans){
        cout<<x<<endl;
    }

    return 0;

}
