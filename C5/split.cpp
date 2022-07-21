#include <bits/stdc++.h>

using namespace std;
#define FOR(i,a,b) for(int i = (a); i<(b); i++)
#define FR(i,a) FOR(i,0,a)
#define vi vector<int>
#define vvi vector<vi>
#define ll long long
#define vl vector<ll>
#define vll vector<vl>

#define pb(a) push_back(a)
#define all(a) a.begin(),a.end()
#define fast ios::sync_with_stdio(0);cin.tie(0)
#define sz(a) (int(a.size()))

int main(){
    int T; cin>>T;
    vi fac(1e4+3,1);
    FOR(n,2,sz(fac)){
        if(fac[n]==1){
            for(int j = n*2; j<sz(fac);j+=n){
                fac[j] = n;
            }
        }
    }
    FR(t,T){
        int K,N; cin>>K>>N;
        vi dp(N+1,0);
        FOR(i,K,sz(dp)){
            dp[i]++;
            
        }
    }
    return 0;
}