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
struct segTree{
    vl tree;
    segTree(int N){
        tree.resize(4*N,INT_MAX);
    }
    ll getMin(int nodeI, int tL, int tR, int l, int r){
//        cout<<tL<<" "<<tR<<" "<<l<<" "<<r<<endl;
        if(r<l)return INT_MAX;
        if(l==tL&&r==tR)return tree[nodeI];
        int tM = (tR+tL)/2;
        assert(l>=tL&&r<=tR);
        return min(getMin(nodeI*2,tL,tM,l,min(r,tM)),getMin(nodeI*2+1,tM+1,tR,max(tM+1,l),r));

    }
    void update(int v, int tl, int tr, int i, ll val){
        if(tl==tr){
            tree[v] = min(tree[v],val);
            return;
        }
        assert(tl<tr);
        int tm = (tl+tr)/2;
        if(i<=tm){
            // left branch
            update(2*v,tl,tm,i,val);
        }else{
            update(2*v+1,tm+1,tr,i,val);
        }
        tree[v] = min(tree[2*v],tree[2*v+1]);

    }
};

int main() {
    fast;
    int READ(T);
    while(T--){
        int READ(N);
        vi scores(N); FR(i,N)cin>>scores[i];
        vi jump(N); FR(i,N){cin>>jump[i];jump[i]--;}
        vl prefixSum(N); FR(i,N){
            prefixSum[i]+=i>0?(prefixSum[i-1]+scores[i]):scores[i];
        }
        segTree bestJump(N);
        ll ans = 0;

        FR(i,N) {
            ll minDeduction = i>0?bestJump.getMin(1,0,N-1,i,N-1):0;
            if(minDeduction==INT_MAX)break; // can't reach here or anything past here
            setmax(ans,prefixSum[i]-minDeduction);
            int rangeI = jump[i];
            ll val = minDeduction+scores[i]; // basically dp[i] + score
            bestJump.update(1,0,N-1,rangeI,val);
        }
        cout<<ans<<endl;

    }
    return 0;
}
/*
THINGS TO CHECK BEFORE SUBMITTING:
 Corner cases? n=0,1?
 Possible chance for overflow?
*/
