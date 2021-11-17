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

vll A[100];
vll B[100];

int main() {
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

    ll N,K,P;
    cin>>N>>K>>P;

    vll a(100);
    rep(i,N){
        cin>>a[i];
    }

    

    for(ll i = 0; i < (1<<N/2); i++){
        ll cnt = 0, sum = 0;
        for(ll j = 0; j < N/2; j++){
            if((i & (1<<j)) != 0){ //if(i & (1<<j) != 0)にするとバグるので気を付けましょう
                sum += a[j];
                cnt += 1;
            }
        }

        A[cnt].push_back(sum);
        
    }


    for(ll i = 0; i < (1<<(N - N/2)); i++){
        ll cnt = 0, sum = 0;
        for(ll j = 0; j < (N - N/2); j++){
            if((i & (1<<j)) != 0){
                sum += a[N/2 + j];
                cnt += 1;
            }
        }

        B[cnt].push_back(sum);
        
    }

    srep(i,0,N){
        sort(all(A[i]));
        sort(all(B[i]));
    }

    ll ans = 0;

    srep(i,0,K){
        for(ll j = 0; j < (ll)A[i].size(); j++){
            int iter = lower_bound(all(B[K-i]), P - A[i][j] +1) - B[K-i].begin();
            ans += (ll)iter;
        }
    }

    cout<<ans<<endl;
}
