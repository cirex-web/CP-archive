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



ll MOD = 1000000007;


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
std::string LongestCommonSubsequence(std::string s, std::string t){
    int N = sz(s), M = sz(t);
    vvi dp(N+1,vi(M+1,0));

    FORE(i,1,N){
        FORE(j,1,M){
            dp[i][j] = max(dp[i][j-1],max(dp[i-1][j],dp[i-1][j-1]+(s[i-1]==t[j-1])));

        }
    }
    int i = N,j = M;
    string ans;
    while(i!=0&&j!=0){ // if you land here it's just diag
        if(dp[i][j]==dp[i-1][j-1]+(s[i-1]==t[j-1])){
            if(s[i-1]==t[j-1])ans+=s[i-1];
            i--;j--;
        }else if(dp[i][j]==dp[i-1][j])i--;
        else{
            assert(dp[i][j]==dp[i][j-1]);
            j--;
        }
    }
    reverse(all(ans));
    return ans;
}

std::tuple<int, std::string, std::string> GlobalAlignment(int match_reward, int mismatch_penalty, int indel_penalty,
                std::string s, std::string t){
    int N = sz(s), M = sz(t);
    vvi dp(N+1,vi(M+1,INT_MIN));
    FORE(i,0,N)FORE(j,0,M){
        if(i&&j)setmax(dp[i][j],dp[i-1][j-1]+(s[i-1]==t[j-1]?match_reward:-mismatch_penalty));
        if(i)setmax(dp[i][j],dp[i-1][j]-indel_penalty);
        if(j)setmax(dp[i][j],dp[i][j-1]-indel_penalty);
        if(!i&&!j)dp[i][j] = 0;
    }
    string resA,resB;
    int i = N, j = M;
    while(!(i==0&&j==0)){
//        cout<<i<<" "<<j<<endl;
        if(i&&j&&dp[i][j]==dp[i-1][j-1]+(s[i-1]==t[j-1]?match_reward:-mismatch_penalty)){
            //valid path goes through here
            resA+=s[i-1];resB+=t[j-1];
            i--;j--;
        }else if(i&&dp[i][j]==dp[i-1][j]-indel_penalty){
            resA+=s[i-1];
            resB+='-';
            i--;
        }else{

            assert(j!=0&&dp[i][j]==dp[i][j-1]-indel_penalty);
            resA+='-';
            resB+=t[j-1];
            j--;
        }
    }
    reverse(all(resA)); reverse(all(resB));
    return {dp[N][M],resA,resB};
}
int main() {
    fast;
//    cout<<LongestCommonSubsequence("GACT","ATG")<<endl;
    auto res = GlobalAlignment(1,1,2,"GAGA","GAT");
//    cout<<res[1]<<endl;
    return 0;
}
/*
THINGS TO CHECK BEFORE SUBMITTING:
 Corner cases? n=0,1?
 Possible chance for overflow?
*/
