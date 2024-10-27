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

struct DSU{
    vi par, size;
    DSU(int x){
        par.resize(x);
        size.resize(x,1);
        FR(i,x)par[i] = i;
    }
    int getPar(int a){
        return par[a]==a?a:(par[a] = getPar(par[a]));
    }
    void merge(int a, int b){
        assert(in(a,sz(par))&&in(b,sz(par)));
        a = getPar(a);b = getPar(b);
//        if(size[a]<size[b])swap(a,b);
        if(a==b)return;
        par[b] = a;
        size[a]+=size[b];
    }
    int getSize(int a){
        assert(in(a,sz(par)));
        return size[getPar(a)];
    }
};
int main() {
    fast;
    int READ(N);
    vector<pair<int,int>> nums;
    FR(i,N){
        int READ(n);
        nums.pb(mp(n,i));
    }
    sort(all(nums));
    DSU d = N; //omg look at this spicy implicit conversion!!!
    vb vis(N);
    ll ans = 0;
    ROF(i,N-1,0){
        auto [n,j] = nums[i];
        if(j<N-1&&vis[j+1])d.merge(j,j+1);
        if(j>0&&vis[j-1])d.merge(j,j-1);
        setmax(ans,ll(n)*d.getSize(j)); //max spread with that post of size n
//        cout<<n<<" "<<d.getSize(j)<<endl;
        vis[j] = true;
    }
    cout<<ans<<endl;
    return 0;
}
/*
THINGS TO CHECK BEFORE SUBMITTING:
 Corner cases? n=0,1?
 Possible chance for overflow?
*/
