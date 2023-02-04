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

ll a,b,k;
ll dp[65][65];
void comb(){
    for(ll i = 0; i < 61; i++){
        dp[i][0] = dp[i][i] = 1;
        for(ll j = 1; j <= i; j++){
            dp[i+1][j] = dp[i][j-1] + dp[i][j];
        }
    }
}


int main() {
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

    cin>>a>>b>>k;

    comb();

    ll s = a+b;
    string ans = "";
    while(s--){
        if(a > 0 && dp[a+b-1][b] >= k){
            ans += "a";
            a--;
        }else{
            ans+="b";
            k -= dp[a+b-1][b];
            b--;
        }
    }

    cout<<ans<<endl;
}