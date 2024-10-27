#include <bits/stdc++.h>
using namespace std;
template<class T> using V = vector<T>;
using ll = long long;
#define FOR(i,a,b) for(int i = (a); i<(b); i++)
#define FR(i,a) FOR(i,0,a)
#define FORE(i,a,b) for(int i = (a); i<=(b);i++)
#define FRE(i,a) FORE(i,0,a)
#define ROF(i,a,b) for(int i = (a); i>=b;i--)
#define mp make_pair
#define sz(a) ((int)a.size())
bool inside(int i, pair<int,int>& rng){
    return i>=rng.first&&i<=rng.second;
}
int main(){
    cin.tie(0); ios::sync_with_stdio(0);
    int N; cin>>N;
    V<ll> ar(N); FR(i,N)cin>>ar[i];
    V<ll> prefixes(N+1);
    FR(i,N)prefixes[i+1]+=prefixes[i]+ar[i];

    V<pair<ll,pair<int,int>>> allSums;
    FR(l,N)FOR(r,l,N){
        allSums.push_back(mp(prefixes[r+1]-prefixes[l],mp(l,r)));
    }
    sort(allSums.begin(),allSums.end());
    FR(i,N){
        ll ans = LLONG_MAX;
        FR(j,sz(allSums)){
            auto [sum,rng] = allSums[j];
            if(inside(i,rng)){
                if(j&&!inside(i,allSums[j-1].second))ans = min(ans,sum-allSums[j-1].first);
                if(j<sz(allSums)-1&&!inside(i,allSums[j+1].second))ans = min(ans,allSums[j+1].first-sum);
            }
        }
        cout<<ans<<endl;
    }


//    FR(i,N){
////        V<ll> sumsInRange;
//
////        FRE(j,i){
////            FOR(k,i,N){
////                ll s = prefixes[k+1]-prefixes[j];
////                sumsInRange.push_back(s);
////                allSums.erase(allSums.find(s));
////            }
////        }
////        ll ans = LLONG_MAX;
////        for(ll sum:sumsInRange){
////            //try to find something as close to sum as possible
////            auto ptr = allSums.lower_bound(sum);
////            if(ptr!=allSums.end())ans = min(ans,*ptr-sum);
////            if(ptr!=allSums.begin()){
////                ptr--;
////                ans = min(ans,sum-*ptr);
////            }
////
////        }
////        cout<<ans<<endl;
////        for(ll sum:sumsInRange)allSums.insert(sum); //add them back lol
//    }
    return 0;
}