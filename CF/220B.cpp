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
#include <unordered_map>
#define endl '\n'

struct segTree{
    vector<unordered_map<int,int>> ar;
    vi res;
    segTree(int N){
        ar.resize(4*N);
        res.resize(4*N);
    }
    unordered_map<int,int> merge(unordered_map<int,int>& a, unordered_map<int,int>& b){
        if(sz(a)<sz(b))swap(a,b);
        unordered_map<int,int> combinedMap = a;
        for(auto [v,f]:b)combinedMap[v]+=f;
        return combinedMap;
    }
    void build(int i, int l, int r){
        if(l==r){
            int n;cin>>n;
            ar[i][n]++;
        }else{
            int m = (l+r)/2;
            build(2*i,l,m);
            build(2*i+1,m+1,r);
            ar[i] = merge(ar[2*i],ar[2*i+1]);
        }
        for(auto [k,f]:ar[i]){
            if(k==f)res[i]++;
        }

    }
    unordered_map<int,int> get(int i, int tl, int tr, int l, int r){
        if(r<tl||tr<l)return {};
        if(l<=tl&&tr<=r)return ar[i];
        int tm = (tl+tr)/2;
        auto m1 = get(2*i,tl,tm,l,r);
        auto m2 = get(2*i+1,tm+1,tr,l,r);
        return merge(m1,m2);
    }

};
int main() {
    fast;
    int READ(N,Q);
    segTree tree(N);
    tree.build(1,1,N);
    FR(q,Q){
        int READ(l,r);
        auto res = tree.get(1,1,N,l,r);
        int ans = 0;
        for(auto [k,v]:res){
            ans+=k==v;
        }
        cout<<ans<<endl;
    }
    return 0;
}
/*
THINGS TO CHECK BEFORE SUBMITTING:
 Corner cases? n=0,1?
 Possible chance for overflow?
*/
