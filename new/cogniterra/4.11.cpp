//<editor-fold desc="Template">
/*
お前はもう死んでいる

俯いたこのおでこトントン叩いたのは
きみなのかな？ 違うのかな？
目を開けたいのに まだ怖いんだ
夕焼けってなんだかさみしい
お願い 待って
もうすぐもっともっと呼ぶから
俯いたこのおでこトントン叩いたのは
きみなのかな？ 違うのかな？
目を開けたいのに まだ怖いんだ
夕焼けってなんだかさみしい
お願い 待って
もうすぐもっともっと呼ぶから
あたりまえみたいな言葉なんてやめてよ
だってほしいの ほんとの気持ちだけ
まだまだこどもだって言うんでしょ
わかってるの 変わりたいの だけどね
そっとそっと教えて
新しい世界の鍵回して
背中を抱きしめたい なんてね
ちょっと幼いって知ってるもん
*/

#include <bits/stdc++.h>

using namespace std;

template<class ...Args>
auto &read(Args &...args) { return (cin >> ... >> args); }

#define READ(...) __VA_ARGS__; read(__VA_ARGS__)
#define mp(a, b)(make_pair(a,b))
#define pb(a) push_back(a)
#define FORE(i, a, b) for (int i = (a); i <= (b); ++i)
#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define ROF(i, a, b) for (int i = (a); i >= (b); --i)
#define RF(i, a) ROF(i,a,0)
#define FR(i, a) FOR(i,0,a)
#define FRE(i, a) FORE(i,0,a)

#define fast ios::sync_with_stdio(0);cin.tie(0)
#define sz(x) ((int)(x.size()))
#define f first
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define CASE(t) "Case #"<<(t)<<": "

using ll = long long;
using ull = unsigned long long;
using vi = vector<int>;
using vl = vector<ll>;
using vd = vector<double>;
using vvi = vector<vi>;
using vvd = vector<vd>;
using vvl = vector<vl>;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
using pdd = pair<double, double>;

using vs = vector<string>;
using vb = vector<bool>;
using vvb = vector<vb>;
using vvs = vector<vs>;
using vpii = vector<pii>;
using vvpii = vector<vpii>;
using vvvi = vector<vvi>; //are you sure about this?
using vvvl = vector<vvl>; //are you sure about this?



//ll MOD = 1000000007;


template<typename T>
void setmax(T &a, T b) { if (b > a) a = b; }

template<typename T>
void setmin(T &a, T b) { if (b < a) a = b; }
//</editor-fold>
//<editor-fold desc="Notes">
/*Insights


*/

/*Debugging


*/

/*Code Improvements



*/
// TAG: 
/*


*/
//</editor-fold>

#define endl '\n'

std::tuple<int, std::string, std::string>
LocalAlignment(int match_reward, int mismatch_penalty, int indel_penalty,
               std::string s, std::string t){
    int N = sz(s),M = sz(t);
    vvi dp(N+1,vi(M+1));
    pii bestSol = {0,0};
    FRE(i,N)FRE(j,M){
        if(i&&j)setmax(dp[i][j],dp[i-1][j-1]+(s[i-1]==t[j-1]?match_reward:-mismatch_penalty));
        if(i)setmax(dp[i][j],dp[i-1][j]-indel_penalty);
        if(j)setmax(dp[i][j],dp[i][j-1]-indel_penalty);
        if(dp[i][j]>dp[bestSol.first][bestSol.second]){
           bestSol = {i,j};
        }
//        cout<<dp[i][j]<<" \n"[j==M];
    }
    int i = bestSol.first, j = bestSol.second;
    string a,b;
    while(true){
        if(i&&j&&dp[i][j] == dp[i-1][j-1]+(s[i-1]==t[j-1]?match_reward:-mismatch_penalty)){
            a+=s[i-1];
            b+=t[j-1];
            i--;j--;
        }else if(j&&dp[i][j] == dp[i][j-1]-indel_penalty){
            a+='-';
            b+=t[j-1];
            j--;
        }else if(i&&dp[i][j]==dp[i-1][j] - indel_penalty){
            a+=s[i-1];
            b+='-';
            i--;
        }else{
            assert(dp[i][j]==0);
            break;
        }
    }
    reverse(all(a));
    reverse(all(b));
//    cout<<dp[bestSol.first][bestSol.second]<<endl;
//    cout<<a<<" "<<b<<endl;
    return {dp[bestSol.first][bestSol.second],a,b};


}

array<int,3> backtrack[200][200][3];
void setMax(int& original, int newVal, int i, int j, int k, array<int,3> prevLoc){
    if(newVal>original){
        original = newVal;
        backtrack[i][j][k] = prevLoc;
    }
}
std::tuple<int, std::string, std::string>
AffineAlignment(int match_reward, int mismatch_penalty,
                int gap_opening_penalty, int gap_extension_penalty,
                std::string s, std::string t){
    int N = sz(s), M = sz(t);
    vvvi dp(N+1,vvi(M+1,vi(3,-1e5))); //dp[i][j][k] - best score w/ first i chars of s, first j chars of t, and k = 0 if last move was no gap, 1 if gap is in second string, 2 if gap in first string
    dp[0][0][0] = 0; //we start from no gap and no chars processed on any string
    // 9
    FRE(i,N)FRE(j,M){
            int matchScore = ((s[i-1]==t[j-1])?match_reward:-mismatch_penalty);
            if(i&&j)setMax(dp[i][j][0],dp[i-1][j-1][0]+matchScore,
                           i,j,0,{i-1,j-1,0});
            if(i&&j)setMax(dp[i][j][0],dp[i-1][j-1][1]+matchScore,
                           i,j,0,{i-1,j-1,1});
            if(i&&j)setMax(dp[i][j][0],dp[i-1][j-1][2]+matchScore,
                           i,j,0,{i-1,j-1,2});

            // gap at second string (like we insert only first string char)
            if(i)setMax(dp[i][j][1],dp[i-1][j][0]-gap_opening_penalty,
                        i,j,1,{i-1,j,0});
            if(i)setMax(dp[i][j][1],dp[i-1][j][1]-gap_extension_penalty,
                        i,j,1,{i-1,j,1});
            if(i)setMax(dp[i][j][1],dp[i-1][j][2]-gap_opening_penalty,
                        i,j,1,{i-1,j,2}); //case where you switch gaps. this counts as new gap

            // we are using a char from the second string, creating a gap in the first string
            if(j)setMax(dp[i][j][2],dp[i][j-1][0]-gap_opening_penalty,
                        i,j,2,{i,j-1,0});
            if(j)setMax(dp[i][j][2],dp[i][j-1][1]-gap_opening_penalty,
                        i,j,2,{i,j-1,1});
            if(j)setMax(dp[i][j][2],dp[i][j-1][2]-gap_extension_penalty,
                        i,j,2,{i,j-1,2});
    }
    string a,b;
    int i = N, j = M, k = max(mp(dp[N][M][0],0),max(mp(dp[N][M][1],1),mp(dp[N][M][2],2))).second; //we don't really care about whether or not we ended on an indel, so let's just take the optimal one
    while(i||j){
        array<int,3>& previousLoc = backtrack[i][j][k];
        char newA = '-',newB = '-';
        int nI = previousLoc[0],nJ = previousLoc[1],nK = previousLoc[2];
//        cout<<i<<" "<<j<<" "<<k<<endl;
        if(nI==i-1){
            newA = s[i-1];
        }
        if(nJ==j-1)newB = t[j-1]; // we basically took this character for this transition
        i = nI,j = nJ,k = nK;
        a+=newA;
        b+=newB;
    }
//    cout<<i<<" "<<j<<" "<<k<<endl;
//
//    cout<<a<<" "<<b<<endl;
    reverse(all(a)); reverse(all(b));

    return {max(dp[N][M][0],dp[N][M][1]),a,b};


}
/*
THINGS TO CHECK BEFORE SUBMITTING:
 Corner cases? n=0,1?
 Possible chance for overflow?
*/
