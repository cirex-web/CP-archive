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
cycles are fun (especially when the order of what each thing gets is rearranged - you naturally form cycles - good for dp


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
bool acceptable[19][19]; //acceptable[a][b] - whether cow a can get gift b
int main() {
    fast;
    int N; cin>>N;

    FR(cow,N){
        bool ok = true;
        FR(j,N){
            int READ(gift); gift--;
            acceptable[cow][gift] = ok;
            if(gift==cow)ok = false;
        }
    }
    vvvl dp(1<<N,vvl(N+1,vl(2,0))); //dp[cows][cow thief][a recent thief (0 if no thief involved)]
    dp[0][N][0] = 1;
    FOR(cows,1,sz(dp)){
        vi numAcceptableGifts(N);
        FR(i,N){
            if(!(cows&(1<<i)))continue;
            FR(j,N){
                if(!(cows&(1<<j)))continue;
                if(acceptable[i][j])numAcceptableGifts[i]++;
            }
        }
        FR(thiefCow,N){
            if(cows&(1<<thiefCow))continue; //TODO: absurd case... But will it affect the ans?
            FR(cow,N){
                if(!(cows&(1<<cow)))continue;
                for(int isThiefRecent:{0, 1}){

                    //the thiefCow took the gift for cow.
                    if(isThiefRecent && !acceptable[thiefCow][cow])continue; //nevermind... the thief won't take this cow's gift

                    if(acceptable[cow][thiefCow])dp[cows][thiefCow][isThiefRecent]+= dp[cows ^ (1 << cow)][N][0]; //take the gift for the thief cow - order is restored
                    if(numAcceptableGifts[cow]-acceptable[cow][thiefCow]>0)dp[cows][thiefCow][isThiefRecent]+=dp[cows ^ (1 << cow)][thiefCow][0]; //the thief's restriction prevails! (But the restriction no longer applies)

//                    cerr<<cow<<" "<<bitset<4>(cows)<<" "<<thiefCow<<" "<<isThiefRecent<<" "<<dp[cows][thiefCow][isThiefRecent]<<endl;
                }

            }
        }
        //no steal N case.
        int randCow = __builtin_ctz(cows);

        dp[cows][N][0]+=dp[cows^(1<<randCow)][N][0];//cow responsibly takes her own gift

        dp[cows][N][0]+=dp[cows^(1<<randCow)][randCow][1]; //thievery
//        cerr<<bitset<4>(cows)<<" "<<dp[cows][N][0]<<endl;
        //TODO: you can't just directly scale it right???
    }
    int Q; cin>>Q;
    while(Q--){
        string READ(cowsString);
        int cows1 = 0,cows2 = 0;
        FR(i,N){
            if(cowsString[i]=='H')cows1+=(1<<i);
            else cows2+=(1<<i);
        }
        cout<<dp[cows1][N][0]*dp[cows2][N][0]<<endl;
    }
    return 0;
}
/*
THINGS TO CHECK BEFORE SUBMITTING:
 Corner cases? n=0,1?
 Possible chance for overflow?

4
2 3 4 1
3 4 1 2
4 1 2 3
1 2 3 4
6
GGGG
GGHH

4
 2 1 3 4
 1 2 3 4
 4 3 2 1
 3 4 2 1
 3
 GGGH
 GHGH
 GGGH
*/
