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
//#define in(r, R) (r>=0&&r<R)
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

const int N = 500;
int dp[N][N][N];
array<int, 3> backtrack[N][N][N];


array<string,3> genSequence(int i, int j, int k,string& s1, string& s2, string& s3){
//    cout<<i<<" "<<j<<" "<<k<<endl;

    if(!i&&!j&&!k)return {"","",""};
    auto [pI,pJ,pK] = backtrack[i][j][k];
    auto [pS1,pS2,pS3] = genSequence(pI,pJ,pK,s1,s2,s3);
    char n1 = '-',n2 = '-', n3 = '-';
    if(i-pI)n1 = s1[i-1];
    if(j-pJ)n2 = s2[j-1];
    if(k-pK)n3 = s3[k-1];
    pS1+=n1;
    pS2+=n2;
    pS3+=n3;
    return {pS1,pS2,pS3};
}
std::tuple<int, std::string, std::string, std::string> MultipleAlignment(std::string s1, std::string s2, std::string s3){
    int N1 = sz(s1),N2 = sz(s2), N3 = sz(s3);

    FRE(i2,N1)FRE(j2,N2)FRE(k2,N3){
        FRE(d1,1)FRE(d2,1)FRE(d3,1){
            if(!d1&&!d2&&!d3)continue;
            int i1 = i2-d1,j1 = j2-d2,k1 = k2-d3;
            if(i1<0||j1<0||k1<0)continue;
            int val = dp[i1][j1][k1]+(d1+d2+d3==3&&s1[i1]==s2[j1]&&s2[j1]==s3[k1]);
            if(val>=dp[i2][j2][k2]){ //annoying 0 case is very bad
                dp[i2][j2][k2] = val;
                backtrack[i2][j2][k2] = {i1,j1,k1};
            }
        }
    }
    auto [ans1,ans2,ans3] = genSequence(N1,N2,N3,s1,s2,s3);
    return {dp[N1][N2][N3],ans1,ans2,ans3};

}
int main() {
//    LocalAlignment(24,1,2,"GGGGGAGAGGGG","GGGGGGGG");
//    auto res = AffineAlignment(1,3,2,1,"AA","A");
//    cout<<res<<endl;
//CCCCT
    auto [ans,a,b,c] = MultipleAlignment("AAAAT","CCCCT","T");
    cout<<ans<<endl<<a<<endl<<b<<endl<<c<<endl;
    return 0;
}
/*
THINGS TO CHECK BEFORE SUBMITTING:
 Corner cases? n=0,1?
 Possible chance for overflow?
*/
