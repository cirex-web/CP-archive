#include <bits/stdc++.h>

#define FOR(i,a,b) for(int i = (a); i<(b); i++)
#define FR(i,a) FOR(i,0,a)
using namespace std;

#define fast ios::sync_with_stdio(0); cin.tie(0)
#define ll long long
#define vl vector<ll>
#define vi vector<int>
#define vvi vector<vi>

#define sz(a) ((int)a.size())
#define all(a) a.begin(), a.end()
#define pb(a) push_back(a)

struct pt{
    int x,y,i;
}

int main(){
    fast;
    int T; cin>>T;
    FR(t,T){
        int N,R,W,H; cin>>N>>R>>W>>H;
        vector<pt> pts,og;
        map<int,int> dp;
        FR(i,N){
            int x,y; cin>>x>>y;
            pts.push_back({y,x,i}); //sort by y first
        }
        og = pts;
        sort(all(pts));
        set<int> considered;
        for(auto [y1,x1,i1]:pts){
            vector<pair<int,int>> remove;
            for(auto i2:considered){
                // cerr<<x1<<" "<<y1<<" "<<x2<<" "<<y2<<endl;
                // cerr<<fabs(double(y2-y1)/(x2-x1))<<endl;
                auto [x2,y2,_] = og[i2];
                if(x1==x2||fabs(double(y2-y1)/(x2-x1))>=R){
                    // cerr<<'f';
                    dp[i1]=max(dp[i1],dp[i2]+1);
                    // remove.push_back(i2); //kinda jank
                }
            }
            considered.insert({x1,y1});
            // for(auto [x,y]:remove)considered.erase(considered.find());
        }
        int ans = 0;
        for(auto [_,val]:dp){
            cerr<<_.first<<" "<<_.second<<" "<<val<<endl;
            ans = max(ans,val+1);
        }
        cout<<ans<<endl;
        
    }
    
}