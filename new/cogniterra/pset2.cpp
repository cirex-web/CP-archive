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


/*
 *
TACATCCTG
GGACAGCGT
GACTTTGGC
AACAGTGAC
ATCC
GACA
ACTT
CAGT
 */

void normalize(vvd& matrix){
    FR(i,sz(matrix[0])){
        double sum = 0;
        FR(r,sz(matrix))sum+=matrix[r][i];
        FR(r,sz(matrix))matrix[r][i]/=sum;
    }
}
int main() {
    fast;
    int N = 4,K = 4,M=9; // K is length of k-mer (motifs), M is length of each read, N is # of reads
    vs reads,motifs;
    map<char,int> nucleotideToInt= {{'A',0},{'C',1},{'T',2},{'G',3}};
    FR(i,N){
        string s; cin>>s;reads.pb(s);
    }
    FR(i,N){
        string READ(motif);
        motifs.pb(motif);
    }
    vvd profile(4,vd(K,0.5)); //pseudo-counts
    FR(i,K){
        FR(j,N){
            profile[nucleotideToInt[motifs[j][i]]][i]++;
        }
    }

    normalize(profile);

    FR(row,4)FR(i,K)cout<<profile[row][i]<<" \n"[i==K-1];
    vvd hiddenMatrix(N,vd(M-K+1));
    vvd newProfile(4,vd(K,0));
    FR(i,N){
        string read = reads[i];
        double bestScore = 0;
        string nextMotif;
        FR(startI,M-K+1){
            string kMer = read.substr(startI,K);
            double score = 1;
            FR(j,K){
                score*=profile[nucleotideToInt[kMer[j]]][j];
            }
            hiddenMatrix[i][startI]=score;
            if(score>bestScore){
                nextMotif = kMer;
                bestScore = score;
            }
            FR(j,K){
                // add k-mers to the new profile, but weighted
                newProfile[nucleotideToInt[kMer[j]]][j]+=score;
            }
        }
        motifs[i] = nextMotif;
    }
    FR(i,N)cout<<motifs[i]<<"\n";
    FR(i,sz(hiddenMatrix))FR(j, sz(hiddenMatrix[i]))cout<<hiddenMatrix[i][j]<<" \n"[j==sz(hiddenMatrix[i])-1];
    normalize(newProfile);
    FR(i,sz(newProfile))FR(j,sz(newProfile))cout<<newProfile[i][j]<<" \n"[j==sz(newProfile)-1];
/*
Input:
TACATCCTG
GGACAGCGT
GACTTTGGC
AACAGTGAC
ATCC
GACA
ACTT
CAGT


Output:
0.416667 0.416667 0.0833333 0.25
0.25 0.25 0.416667 0.25
0.0833333 0.25 0.25 0.416667
0.25 0.0833333 0.25 0.0833333
ATCC
GACA
GACT
AACA
0.0036169 0.0036169 0.00651042 0.0108507 0.0036169 0.00130208
0.000434028 0.0108507 0.00072338 0.00651042 0.00120563 0.00651042
0.0180845 0.0108507 0.00651042 0.000434028 0.000434028 0.000434028
0.0180845 0.00072338 0.0108507 0.00072338 0.00390625 0.000144676
0.368541 0.587006 0.0444529 0.287234
0.24962 0.215426 0.522416 0.196049
0.0683891 0.174392 0.207447 0.473024
0.31345 0.0231763 0.225684 0.043693
 */

    return 0;
}
/*
THINGS TO CHECK BEFORE SUBMITTING:
 Corner cases? n=0,1?
 Possible chance for overflow?
*/
