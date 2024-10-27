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


vd iterate(vd& theta,vvd& Y){
    vvd Z(sz(Y),vd(sz(Y[0]),0));
    assert(sz(theta)==sz(Y[0]));
//    cout<<"Z:"<<endl;
    FR(i,sz(Y)){
        double sum = 0;
        FR(j,sz(Y[i]))sum+=Y[i][j]*theta[j];
        FR(j,sz(Y[i])){
            Z[i][j] = Y[i][j]*theta[j]/sum;
//            cout<<setw(10)<<Z[i][j]<<" \n"[j==sz(Y[i])-1];
        }
    }
    vd res(sz(theta),0);
    FR(i,sz(Y))FR(j,sz(Y[0]))res[j]+=Z[i][j];
    double sum = 0; FR(i,sz(res))sum+=res[i];
    cout<<"Theta: ";
    FR(i,sz(res)){
        res[i]/=sum;
        cout<<res[i]<<" \n"[i==sz(res)-1];
    }
//    cout<<endl;
    return res;


}
int main() {
    fast;
    vvd Y = {{1,1,1},{1,0,0},{1,1,1},{1,1,1},{0,1,0},{1,1,0},{1,1,1},{0,1,1},{0,1,1},{1,0,1}};
//    vvd Y = {{1,1,1},{1,0,0},{1,0,1},{1,1,1},{1,1,0},{0,1,0},{1,1,1},{0,0,1},{0,1,1},{1,0,1}};
    vd T = {.1/3,.1/3,.1/3};
    FR(i,200){
        T = iterate(T,Y);
    }
    return 0;
}
/*
THINGS TO CHECK BEFORE SUBMITTING:
 Corner cases? n=0,1?
 Possible chance for overflow?

 1 1 1 1
2 1 0 0
3 1 1 1
4 1 1 1
5 0 1 0
6 1 1 0
7 1 1 1
8 0 1 1
9 0 1 1
10 1 0 1

 1 1 1 1
2 1 0 0
3 1 0 1
4 1 1 1
5 1 1 0
6 0 1 0
7 1 1 1
8 0 0 1
9 0 1 1
10 1 0 1
*/
