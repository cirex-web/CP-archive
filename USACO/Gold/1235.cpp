//<editor-fold desc="Template">
/*
[Verse 1]
When the days are cold and the cards all fold
And the saints we see are all made of gold
When your dreams all fail and the ones we hail
Are the worst of all, and the blood's run stale

[Pre-Chorus]
I wanna hide the truth, I wanna shelter you
But with the beast inside, there's nowhere we can hide
No matter what we breed, we still are made of greed
This is my kingdom come, this is my kingdom come
[Chorus]
When you feel my heat, look into my eyes
It's where my demons hide, it's where my demons hide
Don't get too close; it's dark inside
It's where my demons hide, it's where my demons hide

[Verse 2]
At the curtain's call it's the last of all
When the lights fade out, all the sinners crawl
So they dug your grave and the masquerade
Will come calling out at the mess you've made

[Pre-Chorus]
Don't wanna let you down, but I am hell-bound
Though this is all for you, don't wanna hide the truth
No matter what we breed, we still are made of greed
This is my kingdom come, this is my kingdom come

[Chorus]
When you feel my heat, look into my eyes
It's where my demons hide, it's where my demons hide
Don't get too close; it's dark inside
It's where my demons hide, it's where my demons hide

[Bridge]
They say it's what you make, I say it's up to fate
It's woven in my soul, I need to let you go
Your eyes, they shine so bright, I wanna save that light
I can't escape this now, unless you show me how
[Chorus]
When you feel my heat, look into my eyes
It's where my demons hide, it's where my demons hide
Don't get too close; it's dark inside
It's where my demons hide, it's where my demons hide
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

struct childData{
    int val;
    int imbalance;
    int i;
};
struct segData{
    int pos,room,imbalance,i;
};
int main() {
    fast;
    int T,B; cin>>T>>B;
    FR(t,T){
        int N; cin>>N;
        vvi g(N);
        FR(i,N-1){
            int par;cin>>par;
            g[par-1].pb(i+1);
        }
        vi l(N),r(N);
        FR(i,N){
            cin>>l[i]>>r[i];
        }
        function<pii(int)> dfs = [&](int a){
            if(!sz(g[a]))return mp(-1,0); //optimal value, min imbalance # value

            int mxImb = 0;
            vector<childData> children;
            for(int b: g[a]){
                auto [val,imbalance] = dfs(b);
                setmax(mxImb,imbalance);
                children.push_back({val,imbalance,b});
            }
            segData leftMostRight = {INT_MAX,0,-1,-1},rightMostLeft = {INT_MIN,0,-1};
            for(auto data: children){
                int room = mxImb-data.imbalance;
                int left = max(l[data.i],data.val-room);
                int right = min(r[data.i],data.val+room);
                int rightRoom = r[data.i]-right;
                int leftRoom = left-l[data.i];
                if(leftMostRight.pos>right||(leftMostRight.pos==right&&leftMostRight.room>rightRoom)){
                    leftMostRight = {right,rightRoom,data.val-left+data.imbalance,data.i};
                }
                if(rightMostLeft.pos<left||(rightMostLeft.pos==left&&rightMostLeft.room>leftRoom)){
                    rightMostLeft = {left,leftRoom,right-data.val+data.imbalance,data.i};
                }
            }
            auto f = [&](int pos){

            };
            int lo = l[a], hi = r[a];
            while(lo<=hi){

            }

        };

    }
    return 0;
}
/*
THINGS TO CHECK BEFORE SUBMITTING:
 Corner cases? n=0,1?
 Possible chance for overflow?
*/
