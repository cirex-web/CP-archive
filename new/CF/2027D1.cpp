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
void setmax(T &a, T b) { if (b > a) a = b; }

template<typename T>
bool setmin(T &a, T b) { bool newSet = b<a; if (newSet) a = b; return newSet;}
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
    int READ(T);
    while(T--){
        int READ(N,M);
        vl A(N); FR(i,N)cin>>A[i]; // oshi no ko my love
        vl B(M); FR(i,M)cin>>B[i];
        vl prefixSum(N+1); FR(i,N)prefixSum[i+1]=prefixSum[i]+A[i];
        vvl dp(N+1,vl(M,LLONG_MAX));
        vvl cnt(N+1,vl(M,0));

        dp[0][0] = 0;
        cnt[0][0] = 1;
        FRE(n,N)FR(k,M){
//            cout<<n<<" "<<k<<" "<<dp[n][k]<<endl;
            if(dp[n][k]==LLONG_MAX)continue;
            if(k<M-1){
                if(setmin(dp[n][k+1],dp[n][k]))cnt[n][k+1] = 0;
                if(dp[n][k]==dp[n][k+1])cnt[n][k+1]+=cnt[n][k];
                cnt[n][k+1]%=MOD;
            }
            if(n<N){
//                // take as much as possible with canTake
//                ll canTake = B[k];
//                int l = n+1, r = N;
//                while(l<=r){
//                    int m = (l+r)/2;
//                    if(prefixSum[m]-prefixSum[n]>canTake)r = m-1;
//                    else l = m+1;
//                }
//                // r is the most you can take
//                cout<<n<<"! "<<k<<" "<<r<<endl;
                FORE(r,n+1,N){
                    if(prefixSum[r]-prefixSum[n]>B[k])break;
                    if(r>n){
    //                    cout<<">"<<r<<" "<<k<<" "<<dp[n][k]+(M-k-1)<<" "<<dp[r][k]<<endl;
                        if(setmin(dp[r][k],dp[n][k]+(M-k-1))){
                            cnt[r][k] = 0;
                        }
                        if(dp[r][k]==dp[n][k]+(M-k-1))cnt[r][k]+=cnt[n][k];
                        cnt[r][k]%=MOD;
                    }
                }

            }
        }
        if(dp[N][M-1]==LLONG_MAX)cout<<-1<<endl;
        else{
            cout<<dp[N][M-1]<<" "<<cnt[N][M-1]<<endl;
        }

    }
    return 0;
}
/*
THINGS TO CHECK BEFORE SUBMITTING:
 Corner cases? n=0,1?
 Possible chance for overflow?
*/
