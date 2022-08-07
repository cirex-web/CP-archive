// Switch on the sky and the stars glow for you
// Go see the world 'cause it's all so brand new
// Don't close your eyes 'cause your future's ready to shine
// It's just a matter of time, before we learn how to fly
// Welcome to the rhythm of the night
// There's something in the air you can't deny

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

/*


*/

int main() {
    fast;
    int N,M; cin>>N>>M;
    map<int,int> freq;
    freq[N] = 0; //just so the last bit gets added (TODO:)
    FR(i,M){
        int player; cin>>player;player--;
        freq[player]++;
    }

    vi prefix;
    map<int,int> cnt; //for each prefix how many are there
    int prevVal = 0;
    for(auto [n,v]:freq){
        prefix.push_back(prevVal);
        cnt[prevVal]=n; //everything until this n

        prevVal+=v;
    }
    int Q; cin>>Q;
    FR(q,Q){
        int x; cin>>x;
        auto ptr = std::upper_bound(prefix.begin(), prefix.end(),x);
        if(ptr==prefix.begin()){
            cout<<0<<endl;
        }else{
            ptr--;
            cout<<cnt[*ptr]<<endl;
        }
    }

    return 0;
}

/*
 *
 *
5 6
2 2 3 3 3 5
10
0
1
2
3
4
5
6
7
8
9
 */