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

vector<char> split(string& s){
    stringstream ss(s);
    char word;
    vector<char> split;
    while(ss>>word)split.pb(word);
    return split;
}
// X is the horizontal axis
vvd parseGrid(map<char,int>& convertorY,map<char,int>& convertorX){
    int N = sz(convertorY), M = sz(convertorX);
    vvd res(N,vd(M,-1));
    vi nxt;
    FR(i,M){
        char READ(c);
        assert(convertorX.count(c));
        nxt.pb(convertorX[c]);
    }
    FR(i,N){
        char READ(cur);
        assert(convertorY.count(cur));
        int startI = convertorY[cur];
        FR(j,M){

            cin>>res[startI][nxt[j]];
        }

    }
    return res;
}
string solve(vvd& transitionProb, vvd& emitProb, vi& emitted, map<int,char>& intToState){
    int numStates = sz(transitionProb), numSigma = sz(emitProb[0]);
    vvd dp(sz(emitted),vd(numStates,-1));
    vvi backtrack(sz(emitted),vi(numStates,-1));
    FR(i,sz(emitted)){
        FR(state,numStates){
            if(i==0){
                dp[i][state] = emitProb[state][emitted[i]];
            }else{
                FR(prevState,numStates){
                    double newScore = dp[i-1][prevState]*transitionProb[prevState][state]*emitProb[state][emitted[i]];
                    if(dp[i][state]<newScore){
                        dp[i][state] = newScore;
                        backtrack[i][state] = prevState;
                    }
                }
            }
        }
    }


    int bestState = 0;
    FR(state,numStates){
        if(dp[sz(emitted)-1][state]>dp[sz(emitted)-1][bestState])bestState = state;
        cout<<dp[sz(emitted)-1][state]<<" "<<state<<endl;
    }
    int curState = bestState;
    int pos = sz(emitted)-1;
    string ans;
    while(curState!=-1){
        ans+=intToState[curState];
        curState = backtrack[pos--][curState];
    }
    reverse(all(ans));
    return ans;
}
int main() {
    fast;
    string placeholder;
    string READ(emitted);
    set<char> distinct; for(char e: emitted)distinct.insert(e);
    cin>>placeholder;

    string line;
    map<char,int> sigmaMap;
    getline(cin,line);
    getline(cin,line);
    vector<char> sigmas = split(line);
    FR(i,sz(sigmas)){
        sigmaMap[sigmas[i]] = i;
    }

    cin>>placeholder;
    getline(cin,line); // ig this reads the newline
    getline(cin,line);

    auto states = split(line);
    int M = sz(states);
    map<char,int> stateMap;
    map<int,char> intToStateMap;
    FR(i,M){
        stateMap[states[i]]=i;
        intToStateMap[i] = states[i];
    }

    cin>>placeholder;

    vvd stateTransition = parseGrid(stateMap,stateMap);
    cin>>placeholder;
    vvd emitProb = parseGrid(stateMap,sigmaMap);

    vi emittedVec;
    for(char c: emitted)emittedVec.pb(sigmaMap[c]);
    // actual solve
    string ans = solve(stateTransition,emitProb,emittedVec,intToStateMap);
    cout<<ans<<endl;

    return 0;
}
/*
THINGS TO CHECK BEFORE SUBMITTING:
 Corner cases? n=0,1?
 Possible chance for overflow?
*/
