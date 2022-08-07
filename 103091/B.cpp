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
const int MAX_N = 11;
bool U[MAX_N][MAX_N],D[MAX_N][MAX_N],L[MAX_N][MAX_N],R[MAX_N][MAX_N];
bool chk(int x,int y){
    //bottom left corner
    if(x<0||y<0||x>=MAX_N-1||y>=MAX_N-1)return false;
    return U[x][y]&&R[x][y]&&
            L[x+1][y]&&U[x+1][y]&&
            D[x][y+1]&&R[x][y+1]&&
            L[x+1][y+1]&&D[x+1][y+1];
}
int wins[2];
int main() {
    fast;
    int N; cin>>N;
    int player = 0;

    FR(i,2*N*(N-1)){
        cout<<(player==0?'A':'B');
        int READ(x1,y1,x2,y2);x1--;y1--;x2--;y2--;

        if(y1<y2||x1>x2){
            swap(x1,x2);
            swap(y1,y2);
        }
        if(x1!=x2){
            R[x1][y1] = true;
            L[x2][y2] = true;
            int taken = chk(x1,y1-1)+chk(x1,y1);
            if(taken){
                wins[player]+=taken;
            }else{
                player^=1;
            }
        }else{
            D[x1][y1] = true;
            U[x2][y2] = true;
            int taken = chk(x1-1,y2)+chk(x1,y2);
            if(taken){
                wins[player]+=taken;
            }else{
                player^=1;
            }
        }

    }
    cout<<endl;
    cout<<wins[0]<<" "<<wins[1]<<endl;

    return 0;
}
//ABABABABABABABBBABBABBBB
//ABABABABABABABBBABBABBBB