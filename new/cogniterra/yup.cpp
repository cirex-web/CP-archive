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
#define s second
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define in(r, R) (r>=0&&r<R)
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
bool setmax(T &a, T b) { if (b > a) {a = b;return true;} return false; }

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

int main() {
    fast;
    string exon1 = "TGATTTAT",exon2 = "CGGTT";
    int K = 2;
    string kMer = exon1+exon2; //the kmer but extended to include both full adjacent exons (exon 1 and exon 2)

    // start and end indices of the initial seed (ATCG in this case)
    int startK = sz(exon1)-K;
    int endK = sz(exon1)+K-1;
    cout<<"Exon 1 + Exon 2: "<<kMer<<endl;
    cout<<"Seed: "<<kMer.substr(startK,endK-startK+1)<<endl<<endl;

    vs reads = {"TGATTTATCGGTT","AAATGATTTATCGGTTAAA","ATTTATCGGTT","TGATTTATCGG","ATCGT","GATATCGT","TTATCGA","AAATG","ATCGTGATTTATCG","ATCG"}; // could span longer than the above two exons, but could also be shorter, like TTATCGG
    for(auto read: reads){

        cout<<"Input: "<<read<<endl;
        int N = sz(kMer), M = sz(read);
        vvi dp(N+1,vi(M+1,INT_MIN)); // N+1 x M+1 dp matrix
        map<pair<int,int>,pair<int,int>> backtrackMap;
        int indel = 2, mismatch = 2,match = 1;
        int ans = INT_MIN;
        pii endVal = {-1,-1};
        FRE(i,N){
            FRE(j,M){
                if(i==0)dp[i][j] = 0; //if the start of the read matches exons before exon 1 (so dp[0][*] = 0 for all *)
                if(i-1<startK&&j==0)dp[i][j] = 0; // if read doesn't span the entirety of exon 1 (we basically start aligning read later)
                pii backtrack = {-1,-1};
                if(i-1>=startK&&i-1<=endK){ //start and end of seed
                    // we require a match to take place here
                    if(i&&j&&kMer[i-1]==read[j-1]&&dp[i-1][j-1]!=INT_MIN){
                        if(setmax(dp[i][j],dp[i-1][j-1]+match)){
                            backtrack = {i-1,j-1};
                        }
                    }
                }else{
                    // do your standard thing
                    if(i&&dp[i-1][j]!=INT_MIN){
                        if(setmax(dp[i][j],dp[i-1][j]-indel))backtrack = {i-1,j};
                    }
                    if(j&&dp[i][j-1]!=INT_MIN){
                        if(setmax(dp[i][j],dp[i][j-1]-indel)){
                            backtrack = {i,j-1};
                        }
                    }
                    if(i&&j&&dp[i-1][j-1]!=INT_MIN){
                        if(setmax(dp[i][j],dp[i-1][j-1]+(kMer[i-1]==read[j-1]?match:-mismatch))){
                            backtrack = {i-1,j-1};
                        }
                    }
                }
                if(backtrack.f!=-1){
                    backtrackMap[{i,j}] = backtrack;
                }
                if(i==N){
                    if(setmax(ans,dp[i][j]))endVal={i,j}; // if latter half of the read overextends exon 2
                }
                if(i-1>=endK&&j==M){
                    if(setmax(ans,dp[i][j]))endVal={i,j}; //if read doesn't span entirety of exon 2
                }
            }
        }
        int i = endVal.f, j = endVal.s;
        if(ans==INT_MIN)cout<<"seed not found in read"<<endl;
        else{
            cout<<"Best score: "<<ans<<endl;
            assert(i!=-1);
            string a,b;

            if(N-i!=0)a+=string(N-i,'*');
            if(M-j!=0)b+=string(M-j,'*');
            while(true){
                if(!backtrackMap.count({i,j}))break;
                auto [nI,nJ] = backtrackMap[{i,j}];
                a+=nI==i?'-':kMer[i-1];
                b+=nJ==j?'-':read[j-1];
                i = nI,j=nJ;
            }
            FR(k,max(i,j)){
                a+=k<i?'*':' ';
                b+=k<j?'*':' ';
            }
            reverse(all(a));
            reverse(all(b));
            cout<<a<<endl;
            cout<<b<<endl;
        }
        cout<<endl;
    }


    return 0;
}
/*
THINGS TO CHECK BEFORE SUBMITTING:
 Corner cases? n=0,1?
 Possible chance for overflow?
*/
