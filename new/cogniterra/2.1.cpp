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
//#define in(r, R) (r>=0&&r<R)
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
void normalize(vvd& matrix){
    FR(i,sz(matrix[0])){
        double sum = 0;
        FR(r,sz(matrix))sum+=matrix[r][i];
        FR(r,sz(matrix))matrix[r][i]/=sum;
    }
}

map<char,int> nucleotideMap = {{'A',0},{'C',1},{'G',2},{'T',3}};
char nucleotides[] = {'A','C','G','T'};
vvd generateProfile(vs& strings){
    int K = sz(strings[0]);
    int N = sz(strings);
//    cout<<K<<endl;
    vvd newProfile(4,vd(K,0));
    FR(i,N){
        string motif = strings[i];
        FR(j,sz(motif)){
            newProfile[nucleotideMap[motif[j]]][j]++;
        }
    }
    normalize(newProfile);

    return newProfile;
}
int score(vvd& profile, vs& motifs){
    int mismatches = 0;
    FR(charI,sz(motifs[0])){
        map<char,int> cnt;
        int mostFreq = 0;
        for(auto motif: motifs)setmax(mostFreq,++cnt[motif[charI]]);
        mismatches+=sz(motifs)-mostFreq;
    }
    return mismatches;
}

std::string ProfileMostProbableKmer(std::string& text, int k,
                                    std::vector<std::vector<double>> profile){
    double bestScore = -1;
    string ans;
    FR(i,sz(text)-k+1){
        string cur = text.substr(i,k);
        double score = 1;
        FR(j,sz(cur)){
            score*=profile[nucleotideMap[cur[j]]][j];
        }
        if(score>bestScore){
            ans = cur;
            bestScore = score;
        }
    }
    return ans;

}
vs getMotifsFromProfile(vs& dna, vvd& profile,int K){
    vs motifs;
    for(string& cur: dna){
        motifs.pb(ProfileMostProbableKmer(cur,K,profile));
    }
    return motifs;
}
pair<int,std::vector<std::string>> RandomizedMotifSearchHelper(std::vector<std::string> dna,
                                               int k, int N){
    vs motifs;
    FR(i,N){
        motifs.pb(dna[i].substr(random()%(sz(dna[i])-k+1),k));
//        cout<<motifs[sz(motifs)-1]<<endl;
    }
    vvd profile = generateProfile(motifs);
//    cout<<sz(profile)<<" "<<sz(profile[0])<<endl;
    int bestScore = score(profile,motifs);
    while(true){
        motifs = getMotifsFromProfile(dna,profile,k);
        profile = generateProfile(motifs);
        int newScore = score(profile,motifs);
        if(newScore>=bestScore)break;
        bestScore = newScore;
    }
    return {bestScore,motifs};
}
std::vector<std::string> RandomizedMotifSearch(std::vector<std::string> dna,
                                                     int k, int N){
    pair<int,vs> res = {INT_MAX,{}};
    FR(i,1000){
        setmin(res, RandomizedMotifSearchHelper(dna,k,N));
    }
//    for(auto st:res.s)cout<<st<<endl;
    return res.s;
}

std::vector<int> MinimumSkew(const std::string& Genome){
    vi ans = {0};
    int curMin = 0;
    int i = 1;
    int pref = 0;
    for(char c:Genome){
        if(c=='G')pref++;
        if(c=='C')pref--;
        if(pref<=curMin){
            if(pref<curMin)ans.clear();
            ans.pb(i);
        }
        i++;
    }
    return ans;
}
std::vector <std::string> FindClumps(std::string genome,int k, int L, int t){
    map<string,int> window;
    set<string> ans;
    FR(i,L-k+1){
        string cur = genome.substr(i,k);
        if(++window[cur]==t)ans.insert(cur);
    }
    FOR(l,0,sz(genome)-L){
        window[genome.substr(l,k)]--;
        string nxt = genome.substr(l+L+1-k,k);
        if(++window[nxt]==t)ans.insert(nxt);
//        cout<<l<<" "<<l+L+1-k<<endl;
    }
    vs ansV; for(const string& str:ans)ansV.pb(str);
    return ansV;
}
int scoreMotifs(vs& motifs){
    auto profile = generateProfile(motifs);
    return score(profile,motifs);
}
pair<int,vs> GibbsSamplerHelper(std::vector<std::string>& dna,
                                      int k, int t, int N){
    vs motifs;
    FR(i,sz(dna))motifs.pb(dna[i].substr(random()%(sz(dna[i])-k+1),k));
//    motifs = {"AACGGCCA","AAGTGCCA","TAGTACCG","AAGTTTCA","ACGTGCAA"}; //
    vs bestMotifs = motifs;
    int bestScore = scoreMotifs(motifs);
//    cout<<bestScore<<endl;
    FR(i,N){
        int removeI = random()%sz(dna);
        motifs.erase(motifs.begin()+removeI);
        vvd tempProfile = generateProfile(motifs);
//        cout<<removeI<<endl;
        // generate probabilities
        vd probs(sz(dna[0])-k+1,1.0/10240);
        FR(j,sz(dna[removeI])-k+1){
            string cur = dna[removeI].substr(j,k);
            assert(sz(cur)==k);
            double score = 1;
            FR(charI,sz(cur)){
                score*=tempProfile[nucleotideMap[cur[charI]]][charI];
            }
            probs[j]+=score;
//            cout<<cur<<" "<<score<<endl;
        }

        //normalize probabilities
        double sum = 0; FR(j,sz(probs))sum+=probs[j];
        FR(j,sz(probs))probs[j]/=sum; //why would i seg fault?

        //get next motif
        double randN = (double)rand()/RAND_MAX;
//        cout<<randN<<endl;
        int nextMotifI = 0;
        sum = 0;
        while(nextMotifI<sz(probs)-1&&sum+probs[nextMotifI]<randN){
//            cout<<probs[nextMotifI]<<endl;
            sum+=probs[nextMotifI];
//            cout<<sum<<endl;
            nextMotifI++;
        }
        assert(sum<=1);

        //insert motif back in
        motifs.insert(motifs.begin()+removeI,dna[removeI].substr(nextMotifI,k));
        int newScore = scoreMotifs(motifs);

        if(bestScore>newScore){
            bestScore = newScore;
            bestMotifs = motifs;
        }
//        for(string st:motifs)cout<<st<<" ";
//        cout<<endl;

    }
    return {bestScore,bestMotifs};

}
std::vector<std::string> GibbsSampler(std::vector<std::string> dna,
                                      int k, int t, int N){
    pair<int,vs> ans = {INT_MAX,{}};
    FR(i,20){
        setmin(ans, GibbsSamplerHelper(dna,k,t,3000));
    }
//    for(string st:ans.s)cout<<st<<endl;
//    cout<<ans.f<<endl;
    return ans.s;
}
int main() {
    fast;
    srand(100);
    vs test = {"AACGGCCA","AAGTGCCA","TAGTACCG","AAGTTTCA","ACGTGCAA"};
    cout<<scoreMotifs(test)<<endl;
//    GibbsSampler({"TTACCTTAAC","GATGTCTGTC","CCGGCGTTAG","CACTAACGAG","CGTCAGAGGT"},4,5,100);
    GibbsSampler({"CGCCCCTCTCGGGGGTGTTCAGTAAACGGCCA","GGGCGAGGTATGTGTAAGTGCCAAGGTGCCAG","TAGTACCGAGACCGAAAGAAGTATACAGGCGT","TAGATCAAGTTTCAGGTGCACGTCGGTGAACC","AATCCACCAGCTCCACGTGCAATGTTGGCCTA"},8,5,300);
//    FindClumps("ACGTACGT",1,5,2);
    return 0;
}
/*
THINGS TO CHECK BEFORE SUBMITTING:
 Corner cases? n=0,1?
 Possible chance for overflow?
*/
