#include <bits/stdc++.h>
using namespace std;
#define FOR(i,a,b) for(int i = (a); i<(b); i++)
#define FR(i,a) FOR(i,0,a)

#define vi vector<int>
#define vvi vector<vi>
#define vd vector<double>
#define vvd vector<vd>
#define sz(a) (int(a.size()))

#define ll long long
#define fast ios::sync_with_stdio(0); cin.tie(0)

/*
1
3
0.5
0.5
0.5

*/
int main(){
    fast;
    int T; cin>>T;
    FR(t,T){
        int N; cin>>N;
        vd probs(N); FR(i,N)cin>>probs[i];
        vd dp(1<<N,-1);
        FR(mask,sz(dp)){
            vi activePlayers;
            double allWhite = 1,allBlack = 1;
            FR(i,N){
                if(mask&(1<<i)){
                    activePlayers.push_back(i);
                    allWhite*=probs[i];
                    allBlack*=1-probs[i];
                }
            }

            if(sz(activePlayers)<=2)dp[mask] = 0; //TODO: right?
            else{
                dp[mask]=1; //at least the current game
                double someoneOutChance = 0;
                for(int player:activePlayers){
                    double playerWhite = probs[player];
                    double eliminatedChance = allWhite/playerWhite*(1-playerWhite)+allBlack/(1-playerWhite)*playerWhite;
                    // cerr<<allWhite<<endl;
                    someoneOutChance+=eliminatedChance;
                    dp[mask]+=eliminatedChance*dp[mask-(1<<player)];
                }
                dp[mask]/=someoneOutChance;
                // cerr<<someoneOutChance<<endl;

            }
            // cout<<bitset<8>(mask)<<" "<<dp[mask]<<endl;

        }
        cout<<setprecision(29)<<dp[sz(dp)-1]<<endl;
    }
    return 0;
}