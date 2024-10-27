
#include <bits/stdc++.h>
#include <array>
using namespace std;

#define fast ios::sync_with_stdio(0);cin.tie(0)
template<class ...Args>
auto &read(Args &...args) { return (cin >> ... >> args); }

#define READ(...) __VA_ARGS__; read(__VA_ARGS__)
using vi = vector<int>;
using vvi = vector<vi>;
#define FOR(i,a,b) for(int i = (a); i<(b); i++)
#define FORE(i,a,b) for(int i = (a); i<=(b); ++i)
#define ROF(i,a,b) for(int i = (a); i>=(b); i--)
#define FR(i,a) FOR(i,0,a)
#define FRE(i,a) FR(i,a+1)
#define setmax(a,b) a = max((a),(b))


int dp[2001][4001];
int main() {
    fast;
    int READ(N,M,C);
    vector<array<int,3>> cows(N);
    for(auto & [p,m,c] : cows){
        cin>>p>>m>>c;
    }
    sort(cows.begin(),cows.end(),[](array<int,3>& a, array<int,3>& b){
        return a[2]<b[2];
    });
    dp[0][0] = 0;
//    int ans = 0;
    FORE(i,1,N){
        auto [p,m,c] = cows[i-1];

        FRE(cost,M+C){
//            if(cost)setmax(dp[i][cost],dp[i][cost-1]); //important line I think
            setmax(dp[i][cost],dp[i-1][cost]);
            if(cost>C){
                //only money left
                if(cost+m<=M+C)setmax(dp[i][cost+m],dp[i-1][cost]+p);
            }else{
                int cones = min(C-cost,m*c);
                int money = m-(cones/c);
                if(cost+cones+money<=M+C)setmax(dp[i][cost+cones+money],dp[i-1][cost]+p);
            }
//            cerr<<cost<<" "<<dp[i][cost]<<endl;
        }
    }
    cout<<dp[N][M+C]<<endl;
    return 0;
}
/*
THINGS TO CHECK BEFORE SUBMITTING:
 Corner cases? n=0,1?
 Possible chance for overflow?
*/
