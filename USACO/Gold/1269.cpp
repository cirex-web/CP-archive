

#include <bits/stdc++.h>

using ll = long long;
#define FOR(i,a,b) for(int i = (a); i<(b); i++)
#define FR(i,a) FOR(i,0,a)
#define ROF(i,a,b) for(int i = (a); i>=(b); i--)
#define sz(a) (int(a.size()))
using namespace std;
std::string random_string( size_t length )
{
    auto randchar = []() -> char
    {
        const char charset[] =
                "abcdefghijklmnopqrstuvwxyz";
        const size_t max_index = (sizeof(charset) - 1);
        return charset[ rand() % max_index ];
    };
    std::string str(length,0);
    std::generate_n( str.begin(), length, randchar );
    return str;
}
void bash(int N){
    cout<<200<<" "<<1000<<" "<<N<<endl;
    FR(i,N){
        cout<<char('a'+(i%26))<<" "<<random_string(10)<<endl;
    }
}
int main() {
    ios::sync_with_stdio(0);cin.tie(0);
//    bash(1000);
    ll L,R,N; cin>>L>>R>>N;
    vector<pair<char,string>> ops;
    FR(i,N){
        char c; string s; cin>>c>>s;
        ops.push_back({c,s});
    }
    vector<vector<pair<ll,int>>> children(26,vector<pair<ll,int>>(1,{1,N}));

    ROF(i,N-1,0){
        auto [c,s] = ops[i];
        ll cnt = 0;
        for(char stringChar: s){
            cnt+=children[stringChar-'a'].back().first;
            cnt = min(cnt,(ll)1e18);
        }

        children[c-'a'].push_back({cnt,i});

    }
    vector<vector<int>> freqBeforeT = {vector<int>(26,0)};
    int firstA = N;
    FR(i,N){
        vector<int> newFreq = freqBeforeT.back();
        newFreq[ops[i].first-'a']++;
        if(ops[i].first=='a'&&firstA==N)firstA = i;
        freqBeforeT.push_back(newFreq);
    }
    struct cachedVal{
        ll start,end;
        string s;
    };
    map<char,map<int,cachedVal>> dp;

    function<string(char, int,ll,ll,bool)> fetch = [&](char c, int t, ll l, ll r,bool useCache = true){
//        cerr<<c<<" "<<l<<" "<<r<<endl;
        if(useCache&&dp[c].count(t)){
            auto [s,e,str] = dp[c][t];
//            cerr<<s<<" "<<e<<" "<<str<<l<<" "<<r<<endl;
            if(l<s&&r>=s){
                dp[c][t].start = l;
                return dp[c][t].s = fetch(c,t,l,s-1,false)+str;
            }
            if(l<=e&&r>e){
                dp[c][t].end = r;
                dp[c][t].s +=fetch(c,t,r,e+1,false);
                return dp[c][t].s;
            }
            if(l>=s&&r<=e){
                return dp[c][t].s.substr(l-s,r-l+1);
            }
        }
        assert(l<=r);
        if(t==N){
            assert(l==r);
            return string(1,c);
        }
        ll startI = 0;
        string res;
        for(char child:ops[t].second){
            auto [subChildren,childT] = children[child-'a'][sz(children[child-'a'])-1-freqBeforeT[t+1][child-'a']]; //t+1 out of bounds?
//            cerr<<subChildren<<" "<<childT<<endl;
            if(startI + subChildren - 1 >= l && startI <= r){
//                cerr << startI << " " << subChildren << endl;
                res+=fetch(child, childT, max(0LL, l - startI), min(r - startI, subChildren - 1),true);
            }
            startI+=subChildren;

        }
        dp[c][t] = {l,r,res};
        return res;

    };
//    cerr<<L<<" "<<R<<endl;
    string ans = fetch('a',firstA,L-1,R-1,true);
//    assert(sz(ans)==R-L+1);
    cout<<ans<<endl;
    return 0;
}
/*
 *
 *
1 1 4
a ab
b ba
b ba
b ba
 */
//test if no As
/*
THINGS TO CHECK BEFORE SUBMITTING:
Corner cases? n=0,1?
Possible chance for overflow?
*/
