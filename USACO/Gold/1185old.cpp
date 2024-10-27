#include <bits/stdc++.h>
using namespace std;

const int MOD = 1e9+7;

#define FOR(i,a,b) for(int i = (a); i<(b); i++)
#define FORE(i,a,b) FOR(i,a,b+1)
#define FR(i,a) FOR(i,0,a)
#define FRE(i,a) FR(i,a+1)

#define pb(a) push_back(a)
#define all(a) a.begin(),a.end()
using ll = long long;
using vi = vector<int>;
using vvi = vector<vi>;
using vl = vector<ll>;
using vvl = vector<vl>;

const int MH = 1001;
int main(){
    int N; cin>>N;
    vl ar(N); FR(i,N)cin>>ar[i];
    int offset = *min_element(all(ar));
    if(N%2==0)offset = 0;
    ll ans = 0;
    while(offset>=0){
        vvl dp(N+1,vl(MH,0)); dp[0][0] = 1;
        FR(i,N){
            FR(h1,MH){
                if(!dp[i][h1])continue;
                FORE(h2,h1,ar[i]-offset){
                    dp[i+1][h2-h1] += dp[i][h1];
                    dp[i+1][h2-h1]%=MOD;
                }
            }
        }
        ans+=dp[N][0];ans%=MOD;
        // cerr<<dp[N][0]<<endl;
        offset--;
    }
    cout<<ans<<endl;


    return 0;
}
