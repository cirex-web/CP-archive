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

2 2
00
00
*/
int UP=0,DOWN=1,LEFT=2,RIGHT=3;
struct pos{
    int r,c,speed,dir;
    int time;
};
// is the map/set the reason why MLE? (yes) (it's also pretty slow)
// if you have an add function (for bfs) try to initialize the queue with that method as well
bool vis[401][401][28][4];
int main() {
    fast;
    int R,C; cin>>R>>C;
    vs g(R); FR(r,R)cin>>g[r];

    queue<pos> q;
    int ans = -1;
    auto add = [&](int r, int c, int speed, int dir, int time){
        if(speed<0)return;
        assert(g[r][c]=='0');
        FR(i,speed){
            int sign = (dir==DOWN||dir==RIGHT)?1:-1;
            if(dir==DOWN||dir==UP){
                r+=sign;
            }else{
                c+=sign;
            }
            if(!in(r,R)||!in(c,C)||g[r][c]=='1')return;
        }
        if(!vis[r][c][speed][dir]){
//            cerr<<vis[a]<<endl;
            vis[r][c][speed][dir] = true;
            if(r==R-1&&c==C-1)ans = time;
            q.push({r,c,speed,dir,time});
        }
    };
    add(0,0,0,DOWN,0);
    while(sz(q)&&ans==-1){
        pos a = q.front();q.pop();
        a.time++;
        if(!a.speed){
            FR(i,4){
                if(i!=a.dir){
                    add(a.r,a.c,a.speed,i,a.time);
                }
            }
        }
        for(int speed: {a.speed-1,a.speed+1}){
            add(a.r,a.c,speed,a.dir,a.time);
        }
    }
    cout<<ans<<endl;

    return 0;
}
