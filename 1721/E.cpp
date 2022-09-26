// ♬ I got my head out the sunroof ♬


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

/*Insights


*/

/*Debugging


*/

/*Code Improvements



*/
// TAG: 
/*


*/
int nxt[1000100][26];
int main() {
    fast;
    string s; cin>>s;
    int N = sz(s);
    int Q; cin>>Q;
    vi kmp(N,0);
    int k = 0;
    FOR(i,0,N){
        FR(curLetter,26){
            int pK = k;
            if(k&&s[k]!=curLetter)k = nxt[kmp[k-1]][curLetter];
            if(s[k]==curLetter)k++;
            if(curLetter==s[i]-'a')kmp[i] = k; //the actual string
            nxt[i][curLetter] = k;
            k = pK;
        }
        k = kmp[i];
    }

    FR(q,Q){
//        cerr<<q<<endl;
        string READ(cur);
        k = kmp.back();
        auto get = [&](int i){
            if(i<N)return s[i];
            else return cur[i-N];
        };
        FOR(i,N,N+sz(cur)){
//            cerr<<k<<endl;
            if(k&&k<=N){
                k = nxt[k-1][get(i)-'a'];
            }else{
                while(k>=N&&get(k)!=get(i))k = kmp[k-1];
                if(k)k = nxt[k-1][get(i)-'a'];
            }
            if(get(k)==get(i))kmp.pb(++k);
            else kmp.pb(0);
        }
        FOR(i,N,N+sz(cur))cout<<kmp[i]<<" ";
        cout<<endl;
        FR(i,sz(cur))kmp.pop_back();
    }
//    FR(i,N)cout<<kmp[i]<<" \n"[i==N-1];

    return 0;
}
/*
THINGS TO CHECK BEFORE SUBMITTING:
 Corner cases? n=0,1?
 Possible chance for overflow?
*/
