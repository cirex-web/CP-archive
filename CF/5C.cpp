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
Read the problem carefully lol (especially if there's a new definition that you've never seen before

*/

/*Code Improvements



*/
// TAG: 
/*


*/

int main() {
    fast;
    string s; cin>>s;
    int N = sz(s);
    vi prefix(N+1,0);
    FR(i,N){
        prefix[i+1] = prefix[i]+(s[i]==')'?-1:1);
    }
    vi nxt(N+1,-1);
    map<int,int> pos;
    ROF(i,N,0){
        int pref = prefix[i];
        if(pos.count(pref)&&prefix[i]<prefix[i+1]){
            nxt[i] = pos[pref];
        }else{

            pos[pref] = i;
        }
    }
    map<int,int> valid;
    FR(i,N){
        if(nxt[i]!=-1){
            int len = nxt[i]-i;
            valid[len]++;
//            cerr<<i<<" "<<nxt[i]<<endl;
        }
    }
    if(sz(valid)){
        auto [len,freq] = *valid.rbegin();
        cout<<len<<" "<<freq<<endl;
    }else{
        cout<<"0 1"<<endl;
    }


    return 0;
}
