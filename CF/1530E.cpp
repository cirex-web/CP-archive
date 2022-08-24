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

int main() {
    fast;
    int T; cin>>T;
    FR(t,T){
        string s; cin>>s; sort(all(s));
        map<char,int> freq;
        for(char c: s)freq[c]++;

        char start = '\0';
//        cerr<<start<<endl;
        for(auto [c,v]:freq){
            if(v==1){
                start = c;
                swap(s[0],s[s.find(c)]);
                sort(s.begin()+1,s.end());
                break;
            }
        }
        if(start||sz(freq)==1){
            cout<<s<<endl;
            continue;
        }


        auto [c1,v1] = *freq.begin();
        auto [c2,v2] = *next(freq.begin());

        if(v1<=sz(s)-v1+2){
            //aabababa...
            s.erase(remove(all(s),c1),s.end());
            string res(2,c1);v1-=2;
            int i = 0;
//            cerr<<s<<endl;
            while(1){
                if(res.back()!=c1&&v1){
                    res+=c1;
                    v1--;
                }else{
                    if(i==sz(s))break;
                    res+=s[i++];
                }
            }
            cout<<res<<endl;
        }else{
            if(sz(freq)==2){
                rotate(s.begin(),s.begin()+v1-1,s.end());
                cout<<s<<endl;

            }else{
                auto [c3,v3] = *next(next(freq.begin()));
                s.erase(s.begin()+s.find(c2));
                s.erase(s.begin()+s.find(c3));
                s.erase(std::remove(s.begin(), s.end(),c1),s.end());
//                cerr<<s<<endl;
                cout<<string()+c1+c2+string(v1-1,c1)+c3+s<<endl;
            }
        }


    }

    return 0;
}
// bbccc
// bbcccddd