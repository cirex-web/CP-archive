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
    vvd A = {{1,4},{2,6},{3,7},{4,5},{5,4},{4,3},{2,2},{5,1},{7,4},{8,2}};
    vvd B = {{0,2},{1,4},{2,5},{3,4},{5,3},{2,2},{3,1},{5,0},{6,2},{7,1}};
    pair<double,double> centroidA = {0,0};
    pair<double,double> centroidB = {0,0};
    int N = sz(A);
    FR(i,N){
        centroidA.f+=A[i][0];
        centroidA.s+=A[i][1];
        centroidB.f+=B[i][0];
        centroidB.s+=B[i][1];
    }
    centroidA.f/=N;
    centroidA.s/=N;
    centroidB.f/=N;
    centroidB.s/=N;
    cout<<centroidA.f<<" "<<centroidA.s<<endl;
    cout<<centroidB.f<<" "<<centroidB.s<<endl;
    FR(i,N){
        A[i][0]+=centroidB.f-centroidA.f;
        A[i][1]+=centroidB.s-centroidA.s;

    }
    double sum = 0;
    FR(i,N){
        sum+=(B[i][0]-A[i][0])*(B[i][0]-A[i][0])+(B[i][1]-A[i][1])*(B[i][1]-A[i][1]);
    }
    sum=sqrt(sum/N);
    cout<<sum<<endl;
    return 0;
}


/*
THINGS TO CHECK BEFORE SUBMITTING:
 Corner cases? n=0,1?
 Possible chance for overflow?
*/
