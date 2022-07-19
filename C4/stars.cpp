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


1
AAEEFFEDDCCBBA 12
0 5 4 7 10 11 12 13
0 0 20 30 40 10 1 10
0 1 0 20 20 20 20 20
0 20 1 0 20 20 20 20
0 20 20 4 0 20 20 20
0 20 20 20 2 0 2 20
0 20 20 20 20 3 0 20
0 20 20 20 20 20 20 0

1
AAA 1
0 5 1 7 10 11 12 13
0 0 20 30 40 10 1 10
0 1 0 20 20 20 20 20
0 20 1 0 20 20 20 20
0 20 20 4 0 20 20 20
0 20 20 20 2 0 2 20
0 20 20 20 20 3 0 20
0 20 20 20 20 20 20 0


be careful about out of bounds stuff
*/
const int NOTES = 8;
int main(){
    fast;
    int T;cin>>T;
    FR(t,T){
        string music; int K; cin>>music>>K;
        music = " "+music; //idk
        int N = sz(music);
        vvi dist(NOTES,vi(NOTES,-1));
        FR(i,NOTES)FR(j,NOTES)cin>>dist[i][j];
        vvvl dp(N,vvl(NOTES,vl(N,LLONG_MAX)));
        dp[0][0][0] = 0; //we start from 1
        ll ans = LLONG_MAX;
        FOR(i,1,N){
            FOR(note,1,NOTES){ //not including empty cuz that's bad
                bool match = (note-1)==music[i]-'A';
                FR(k,N){ //get all the notes! (even more than K maybe)
                    FR(prevNote,NOTES){
                        if(dp[i-1][prevNote][k-match]!=LLONG_MAX){
                            if(k-match<0)continue;
                            dp[i][note][k] = min(dp[i][note][k],dp[i-1][prevNote][k-match]+dist[prevNote][note]);
                        }
                    }
                    // cerr<<i<<" "<<char('A'+note-1)<<" "<<k<<" "<<dp[i][note][k]<<endl;
                    if(i==N-1&&k>=K)ans = min(ans,dp[i][note][k]);
                }
            }
        }
        assert(dp[N-1][0][K]==LLONG_MAX);

        cout<<ans<<endl;

    }
    return 0;
}