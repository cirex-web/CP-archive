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

vi dfs(vvi& g, int i){
    int N = sz(g);
    vi dist(N,-1);
    dist[i] = 0;
    function<void(int,int)> dfs = [&](int a, int p){
        for(int b: g[a]){
            if(b==p)continue;
            dist[b] = dist[a]+1;
            dfs(b,a);
        }
    };
    dfs(i,-1);
    return dist;
}
long long minTurns(long long n, long long k, long long ahfacInit, long long tienInit, vector<pair<int, int>> &edges) {
    if(n==2)return 1;
    vvi g(n);
    for(auto [a,b]: edges){
        g[a].pb(b);
        g[b].pb(a);
    }
    vi tienDist = dfs(g,tienInit), botDist = dfs(g,ahfacInit);
    int mxDist = 0;

    FR(i,n){
        if(botDist[i]<tienDist[i]&&tienDist[i]>mxDist){

            mxDist = tienDist[i]; //TODO: what if multiple?
            ahfacInit = i;
        }
    }
    ll ans = mxDist-1;
    botDist = dfs(g,ahfacInit);

    ahfacInit = max_element(all(botDist))-botDist.begin(); //teleported onto diameter
//    cerr<<ahfacInit<<endl;
    assert(botDist[ahfacInit]>=2);
    if(!k){
        return ans+1; // one step and it's over
    }
    ans += botDist[ahfacInit]-2; //dist to get to one node next to bot
//    cerr<<ans<<endl;
    botDist = dfs(g,ahfacInit);
    int diameter = *max_element(all(botDist)); //# of steps needed to traverse diameter
//    cerr<<ahfacInit<<" "<<diameter<<endl;
    ans+=ll(k-1)*(diameter-2)+1;
    return ans;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int t; cin >> t;
    while (t--) {
        long long n, k, ahfacInit, tienInit;
        cin >> n >> k >> ahfacInit >> tienInit;
        vector<pair<int, int>> edges;
        for (int i = 0; i < n - 1; i++) {
            int u, v; cin >> u >> v;
            edges.push_back({u, v});
        }
        cout << minTurns(n, k, ahfacInit, tienInit, edges) << "\n";
    }
}
/*
THINGS TO CHECK BEFORE SUBMITTING:
 Corner cases? n=0,1?
 Possible chance for overflow?
*/
/*
1
3 5
1 0
1 0
0 2


1
6 2
1 3
3 0
0 1
0 2
3 4
 2 5



 1
 4 2
 0 3
 3 0
 0 1
 0 2
 */