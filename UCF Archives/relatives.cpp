#include <bits/stdc++.h>

using namespace std;
#define FOR(i,a,b) for(int i = (a); i<(b); i++)
#define FR(i,a) FOR(i,0,a)
#define sz(a) ((int)a.size())
#define ROF(i,a,b) for(int i = (a); i>=(b);i--)
#define all(a) a.begin(),a.end()
#define pb(a) push_back(a)
using vi = vector<int>;
using ll = long long;
using vvi = vector<vi>;


int main(){
    int T;cin>>T;
    FR(t,T){
        int N;cin>>N;
        vector<vector<double>> dp(1<<N,vector<double>(N,INT_MAX)); //min cost traversing [bitmask] ending at [i]
        dp[1][0] = 0;
        vector<vector<double>> cost(N,vector<double>(N,-1));
        FR(i,N)FR(j,N){
            cin>>cost[i][j]; //why does converting to an int break??
        }
        FOR(mask,2,1<<N){
            FR(end1,N){
                if((mask&(1<<end1))==0)continue; //doesn't exist
                // cout<<(mask&(1<<end1))<<endl;
                int prev_mask = mask-(1<<end1);
                FR(end2,N){
                    if(prev_mask&(1<<end2)&&dp[prev_mask][end2]!=INT_MAX){
                        //has this thing 
                        dp[mask][end1] = min(dp[mask][end1],dp[prev_mask][end2]+cost[end2][end1]);

                    }

                }
            }
        }
        int full_mask = sz(dp)-1;
        assert(dp[full_mask][0]==INT_MAX); //legit can't end here
        double ans = INT_MAX;
        FOR(end,1,N){
            assert(dp[full_mask][end]!=INT_MAX);
            ans = min(ans,dp[full_mask][end]+cost[end][0]);
        }
        cout<<setprecision(2)<<fixed<<ans<<endl;
        
    }
    
    
    
    return 0;
}