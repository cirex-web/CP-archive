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
    int READ(T);
    while(T--){
        int READ(N);
        vl ar(N); FR(i,N)cin>>ar[i];
        vl pref(N+1);FR(i,N)pref[i+1] = pref[i]+ar[i];
        ll lb = 1, ub = 1e9*N; //a number of all time
        while(lb<=ub){
            ll mid = (lb+ub)/2;
            multiset<ll> window;

            vl dp(N+1,INT_MAX);
            dp[0] = 0; //min score (of blocked stuff) from [0..i-1] if we block off ar[i-1] (aka the ith el)
            window.insert(0);
            int j = 0;
            // you start from
//            cout<<mid<<endl;
            FORE(i,1,N){
                while(pref[i-1]-pref[j]>mid){
                    window.erase(window.find(dp[j++]));
                }
                assert(j<i); //so we can block out anything from a[j-1] (the jth el)
                dp[i] = ar[i-1]+*(window.begin());
                window.insert(dp[i]);
//                cout<<dp[i]<<" \n"[i==N];
            }
            while(pref[N]-pref[j]>mid){ //just update windowww again
                window.erase(window.find(dp[j++]));
            }
            if(*window.begin()<=mid){
                //good
                ub = mid-1;
            }else{
                lb = mid+1;
            }

        }
        cout<<lb<<endl;
    }
    return 0;
}
/*
THINGS TO CHECK BEFORE SUBMITTING:
 Corner cases? n=0,1?
 Possible chance for overflow?
7
  1 4 5 3 3 2
0 1 4 5 7 8 7

sldiing window set
*/
