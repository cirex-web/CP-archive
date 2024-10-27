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
map<char,int> nucleotideMap = {{'A',0},{'C',1},{'G',2},{'T',3}};
char intToNucleotide[4] = {'A','C','G','T'};
// [node #][char]
int dp[300][4];
int backtrack[300][4][2];//left is smaller node (gives desired character based on current character. 0 is left, 1 is right)

void process(int node, vvi& g,int i, vs& leaves){
    if(sz(g[node])){
        assert(sz(g[node])==2);
        int leftNode = g[node][0], rightNode = g[node][1];
        if(leftNode>rightNode)swap(leftNode,rightNode);
        process(g[node][0],g,i,leaves);
        process(g[node][1],g,i,leaves);
        FR(curChar,4){
            pair<int,int> bestLeft = {INT_MAX,-1},bestRight = {INT_MAX,-1};
            FR(leftChar,4){
                if(dp[leftNode][leftChar]==INT_MAX)continue;
                int score = dp[leftNode][leftChar]+(leftChar!=curChar);
                setmin(bestLeft,{score,leftChar});

            }
            FR(rightChar,4){
                if(dp[rightNode][rightChar]==INT_MAX)continue;
                int score = dp[rightNode][rightChar]+(curChar!=rightChar);
                setmin(bestRight,{score,rightChar});
            }
            assert(bestLeft.second!=-1&&bestRight.second!=-1);
            dp[node][curChar] = bestLeft.first+bestRight.first;
            backtrack[node][curChar][0] = bestLeft.second;
            backtrack[node][curChar][1] = bestRight.second;

        }
    }else{
        assert(node>=0&&node<(sz(g)+1)/2); // aka it's a leaf node
        FR(j,4)dp[node][j] = INT_MAX;
        dp[node][nucleotideMap[leaves[node][i]]] = 0;
    }

}
int fillInAns(int curNode, vs& leaves, int bestChar,vvi& g){
    int minScore = INT_MAX;
    if(bestChar==-1){ //just for the root node
        FR(i,4){
            int curScore = dp[curNode][i];
            if(curScore<minScore){
                minScore = curScore;
                bestChar = i;
            }
        }

    }
    leaves[curNode]+=intToNucleotide[bestChar];
    if(sz(g[curNode])){
        assert(sz(g[curNode])==2);
        int leftNode = g[curNode][0], rightNode = g[curNode][1];
        if(leftNode>rightNode)swap(leftNode,rightNode);
        fillInAns(leftNode,leaves,backtrack[curNode][bestChar][0],g);
        fillInAns(rightNode,leaves,backtrack[curNode][bestChar][1],g);
    }
    return minScore;
}
std::tuple<int, std::vector<std::string>>
SmallParsimony(std::vector<std::string> leaves_labels,
               std::vector<std::pair<int, int>> edge_list){
    int N = 2*sz(leaves_labels)-1;
    vvi g(N);
    vi deg(N);
    for(auto [a,b]:edge_list){
        assert(a>b);
        g[a].pb(b);
        deg[b]++;
    }
    int root = -1;
    FR(i,N){
        if(deg[i]==0){
            root = i;
            break;
        }
    }
    vs ans(N);
    int minScore = 0;
    FR(i,sz(leaves_labels[0])){
        memset(dp,0,sizeof(dp));
        memset(backtrack,0,sizeof(backtrack));
        // current index that we're processing
        process(root,g,i,leaves_labels);
        minScore+=fillInAns(root,ans,-1,g);
    }

    return {minScore,ans};
}
int main() {
    fast;
    auto [score,ans] = SmallParsimony({"AT","AT"},{{2,0},{2,1}});
    cout<<score<<endl;
    FR(i,sz(ans))cout<<ans[i]<<" \n"[i==sz(ans)-1];
    return 0;
}
/*
THINGS TO CHECK BEFORE SUBMITTING:
 Corner cases? n=0,1?
 Possible chance for overflow?
*/
