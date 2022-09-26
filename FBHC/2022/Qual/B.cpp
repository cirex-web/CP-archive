// no comment

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
#define CASE(t) "Case #"<<(t)<<": "
int dx[4] = {1,0,-1,0};
int dy[4]= {0,1,0,-1};
bool vis[3001][3001];
int main() {
    fast;
    int T; cin>>T;
    FR(t,T){
        int READ(R,C);
        vs g(R); FR(r,R)cin>>g[r];
        auto get = [&](int r, int c){
            if(!in(r,R)||!in(c,C))return '#';
            return g[r][c];
        };
        queue<pii> q;
        vector<pii> originals;
        FR(r,R)FR(c,C){
            if(g[r][c]!='#'){
                if(g[r][c]=='^')originals.emplace_back(r,c);
                int good = 0;
                FR(i,4){
                    good+=get(r+dx[i],c+dy[i])!='#';
                }
                if(good<=1){
                    q.push({r,c});
                }else{
                    g[r][c]='^';
                }
            }
        }
        while(sz(q)){
            auto [r1,c1] = q.front();q.pop();

            vector<pii> friends;
            FR(i,4){
                int r2 = r1+dx[i],c2 = c1+dy[i];
                if(get(r2,c2)=='^'){
                    friends.push_back({r2,c2});
                }
            }
            if(sz(friends)<=1)g[r1][c1] = '.'; //sad tree
            if(sz(friends)==1){
                auto [r2,c2] = friends[0];
                if(!vis[r2][c2]){

                    q.push({r2,c2});
                    vis[r2][c2] = true;
                }
            }
        }
        for(auto [r,c]:originals){
            if(g[r][c]!='^'){
                cout<<CASE(t+1)<<"Impossible"<<endl;
                goto nxt;
            }
        }
        cout<<CASE(t+1)<<"Possible"<<endl;
        FR(r,R){
            FR(c,C){
                cout<<g[r][c];
            }
            cout<<endl;
        }
        nxt:;
    }

    return 0;
}
/*
THINGS TO CHECK BEFORE SUBMITTING:
 Corner cases? n=0,1?
 Possible chance for overflow?
*/
