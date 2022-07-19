#include <bits/stdc++.h>
using namespace std;
#define FOR(i,a,b) for(int i = (a); i<(b); i++)
#define FR(i,a) FOR(i,0,a)

#define vi vector<int>
#define vvi vector<vi>
#define vvvi vector<vvi>

#define vl vector<ll>
#define vvl vector<vl>
#define vvvl vector<vvl>
#define vd vector<double>
#define vvd vector<vd>
#define sz(a) (int(a.size()))

#define ll long long
#define fast ios::sync_with_stdio(0); cin.tie(0)

/*



*/

ll MOD = 1;
void add(ll& a, ll b){
    a+=b;a%=MOD;
}
void mul(ll&a, ll b){
    a*=b;a%=MOD;
}
int main(){
    fast;
    int T; cin>>T;
    FR(t,T){
        int W,L; cin>>W>>L>>MOD;
        vvvl dp(W,vvl(L,vl(3,0))); 
        auto get = [&](int r, int c, int skipColor)->ll{
            if(r<0||c<0)return 1; 
            ll res = 0;
            FR(color,3){
                if(color==skipColor)continue;
                add(res,dp[r][c][color]);
            }
            return res;
        };
        FR(r,sz(dp)){
            FR(c,sz(dp[0])){
                FR(color,3){
                    dp[r][c][color] = get(r-1,c,color)*get(r,c-1,color)%MOD;
                }
            }
        }
        ll ans = 0;
        FR(color,3)add(ans,dp[W-1][L-1][color]);
        cout<<ans<<endl;
    }
    return 0;
}