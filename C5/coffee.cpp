#include <bits/stdc++.h>

using namespace std;
#define FOR(i,a,b) for(int i = (a); i<(b); i++)
#define FR(i,a) FOR(i,0,a)
#define vi vector<int>
#define vvi vector<vi>
#define ll long long
#define vl vector<ll>
#define vvl vector<vl>

#define pb(a) push_back(a)
#define all(a) a.begin(),a.end()
#define fast ios::sync_with_stdio(0);cin.tie(0)
#define sz(a) (int(a.size()))

int main(){
    int T; cin>>T;
    FR(t,T){
        int N,M,P; cin>>N>>M>>P;
        // vvi dist(N,vi(N,INT_MAX));
        vvl dp(N,vl(N,LLONG_MAX));
        FR(i,N)dp[i][i] = 0;
        FR(i,M){
            int a,b,t; cin>>a>>b>>t;a--;b--;
            dp[a][b] = t;
            dp[b][a] = t;
        }
        FR(k,N)FR(i,N)FR(j,N){
            if(dp[i][k]==LLONG_MAX||dp[k][j]==LLONG_MAX)continue;
            dp[i][j] = min(dp[i][j],dp[i][k]+dp[k][j]);
        }
        FR(p,P){
            int h,s,w; cin>>h>>s>>w;h--;s--;w--;
            if(dp[h][s]==LLONG_MAX||dp[s][w]==LLONG_MAX){
                cout<<-1<<endl;
            }else{
                cout<<dp[h][s]+dp[s][w]<<endl;
            }
        }
    }
    return 0;
}