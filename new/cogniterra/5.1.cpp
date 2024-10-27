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
    vi rawNums;
    int n;
    while(cin>>n)rawNums.pb(n);
    int N = (int)sqrt(sz(rawNums));
    vd age(2*N-1);
    vi size(2*N-1,1);
    vvd D(2*N-1,vd(2*N-1,-1));
    FR(i,N)FR(j,N){
        D[i][j] = rawNums[N*i+j];
    }
    set<int> vis;
    vector<pair<pair<int,int>,double>> edges;
    FOR(newNode,N,sz(D)){
        pair<double,pair<int,int>> minDist = {INT_MAX,{-1,-1}};
        // new node that we're attaching
        FR(i,newNode)FR(j,newNode){
            if(i==j||vis.count(i)||vis.count(j))continue;
            setmin(minDist,{D[i][j],{i,j}});
        }
        auto [i,j] = minDist.s; // two nodes that we're merging
//        cout<<i<<" "<<j<<endl;
        age[newNode] = minDist.f/2;
        edges.push_back({{newNode,i},age[newNode]-age[i]});
        edges.push_back({{newNode,j},age[newNode]-age[j]});
        size[newNode] = size[i]+size[j];
        FR(prevNode,newNode){
            double dist = double(size[i]*D[prevNode][i]+size[j]*D[prevNode][j])/(size[i]+size[j]);
            D[prevNode][newNode] = dist;
            D[newNode][prevNode] = dist;

        }
        vis.insert(i);
        vis.insert(j);

    }

    for(auto [edge,dist]:edges){
        cout<<fixed<<setprecision(5)<<edge.f<<" "<<edge.s<<" "<<dist<<endl;
    }

    return 0;
}
/*
THINGS TO CHECK BEFORE SUBMITTING:
 Corner cases? n=0,1?
 Possible chance for overflow?
*/
