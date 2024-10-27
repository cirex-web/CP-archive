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


typedef std::vector<std::vector<int>> DistMatrix;
typedef std::tuple<int, int, double> WeightedEdge;

vector<WeightedEdge> helper(vvd& D, vi & iMap, int nextNode){

    assert(sz(D)==sz(iMap));
    int N = sz(D);
    if(N==2){
        return {{iMap[1],iMap[0],D[0][1]}};
    }
    vd dist(N);
    FR(i,N){
        FR(j,N)dist[i]+=D[i][j];
    }
    pair<double,pair<int,int>> minEdge = {INT_MAX,{-1,-1}};
    vector<WeightedEdge> newEdges;
    FR(i,N){
        FR(j,N){
            if(i==j)continue;
            setmin(minEdge,{(N-2)*D[i][j]-dist[i]-dist[j],{i,j}});
        }
    }
    auto [i,j] = minEdge.s; // i and j are neighbors
    double delta = ((dist[i]-D[i][j])-(dist[j]-D[i][j]))/(N-2); //TODO: ???
    newEdges.push_back({nextNode,iMap[i],(D[i][j]+delta)/2});
    newEdges.push_back({nextNode,iMap[j],(D[i][j]-delta)/2});
    vvd newMatrix(N-1,vd(N-1));
    vi newIMap(N-1,-1);
    map<int,int> reIndex;
    FR(node,N){
        if(node==i||node==j)continue;
        int newNodeI = sz(reIndex);
        reIndex[node] = newNodeI;
        newIMap[newNodeI] = iMap[node];
    }
    newIMap[N-2] = nextNode;
    FR(row,N)FR(col,N){
            if(row==i||row==j||col==i||col==j)continue;
            newMatrix[reIndex[row]][reIndex[col]] = D[row][col];
        }
//    cout<<i<<endl;
    FR(node,N){
        if(node==i||node==j)continue;
        newMatrix[reIndex[node]][N-2] = newMatrix[N-2][reIndex[node]] = (D[node][i]+D[node][j]-D[i][j])/2;
//        cout<<iMap[node]<<" "<<D[node][i]<<" "<<distI<<endl;

    }
    auto res = helper(newMatrix,newIMap,nextNode+1);
    res.insert(res.end(),all(newEdges));
    return res;
}
// Insert your NeighborJoining function here, along with any subroutines you need
std::vector<WeightedEdge> NeighborJoining(DistMatrix D){
    vi iMap(sz(D));
    FR(i,sz(iMap))iMap[i] = i;
    vvd sameMatrix(sz(D),vd(sz(D)));
    FR(i,sz(D))FR(j,sz(D))sameMatrix[i][j] = D[i][j];
    return helper(sameMatrix,iMap,sz(D));
}


template<class TupType, size_t... I>
void print(const TupType& _tup, std::index_sequence<I...>)
{
    std::cout << "(";
    (..., (std::cout << (I == 0? "" : ", ") << std::get<I>(_tup)));
    std::cout << ")\n";
}

template<class... T>
void print (const std::tuple<T...>& _tup)
{
    print(_tup, std::make_index_sequence<sizeof...(T)>());
}
int main() {
    int READ(N);
    vvi D(N,vi(N));
    FR(i,N)FR(j,N)cin>>D[i][j];
    auto ans = NeighborJoining(D);
    for(auto edge:ans){
        print(edge);
    }
    fast;

    return 0;
}
/*
THINGS TO CHECK BEFORE SUBMITTING:
 Corner cases? n=0,1?
 Possible chance for overflow?
*/
