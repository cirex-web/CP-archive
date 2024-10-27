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

const int N = 10000;
const int C = 100;
int children[N][C];
void bfs(string cur,int node,vs& ans){
    int childrenNum = 0;
//    cout<<cur<<endl;
    FR(c,C){
        if(children[node][c]!=-1){
            childrenNum++;
        }
    }
    if(childrenNum==0){
        ans.pb(cur);
        return;
    }
    if(childrenNum>1){
        ans.pb(cur);
        cur = "";
    }
    FR(c,C){
        if(children[node][c]!=-1){
            bfs(cur+char('$'+c),children[node][c],ans);
        }
    }

}
std::vector<std::string> SuffixTree(std::string text){ //with $?
//    cout<<('Z'-'$')<<endl;
    FR(i,N)FR(c,C)children[i][c] = -1;
    int n = 1;
    FR(i,sz(text)){
        string curStr = text.substr(i);
        int curNode = 0;
        for(char c:curStr){
//            cout<<curNode<<endl;

            if(children[curNode][c-'$']==-1){
                children[curNode][c-'$'] = n++;
            }
            curNode = children[curNode][c-'$'];
        }
    }
    vs ans;
    bfs("",0,ans);
    return ans;

}
std::string BurrowsWheelerTransform(std::string s){
    vs rotations;
    FR(i,sz(s)){
        rotations.pb(s);
        s += s[0];
        s = s.substr(1);

    }
    sort(all(rotations));
    string res;
    FR(i,sz(rotations))res.pb(rotations[i][sz(s)-1]);
    return res;
}
std::vector<int> SuffixArray(std::string Text){
    vector<pair<string,int>> aaaaaaaaaaaa;
    FR(i,sz(Text)){
        aaaaaaaaaaaa.emplace_back(Text.substr(i),i);
    }
    sort(all(aaaaaaaaaaaa));
    vi ans;
    for(auto [_,i]: aaaaaaaaaaaa)ans.pb(i);
    return ans;
}
std::string InverseBurrowsWheelerTransform(std::string lastCol){
    string firstCol = lastCol;
//    cout<<lastCol;
    sort(all(firstCol));
    char curChar = '$';
    string res = "";
    int freq = 1;
    while(true){
        int cnt = 0;
        FR(i,sz(lastCol)){
            cnt+=lastCol[i]==curChar;
            if(cnt==freq){
                char nxtChar = firstCol[i];
                int nxtFreq = 0;
                FRE(j,i){
                    nxtFreq+=nxtChar==firstCol[j];
                }
                freq = nxtFreq;
                curChar = nxtChar;
                res+=nxtChar;
                break;
            }
        }
        if(curChar=='$')break;
//        assert(cnt==freq);

    }
    return res;
}
int main() {
    fast;
    vs ans = SuffixTree("ATAAATG$");
    for(auto s: ans)cout<<s<<endl;

    return 0;
}
/*
THINGS TO CHECK BEFORE SUBMITTING:
 Corner cases? n=0,1?
 Possible chance for overflow?
*/
