#include <bits/stdc++.h>

using namespace std;
#define FOR(i,a,b) for(int i = (a); i<(b); i++)
#define FR(i,a) FOR(i,0,a)
#define vi vector<int>
#define vvi vector<vi>
#define ll long long
#define vl vector<ll>
#define vll vector<vl>

#define pb(a) push_back(a)
#define all(a) a.begin(),a.end()
#define fast ios::sync_with_stdio(0);cin.tie(0)
#define sz(a) (int(a.size()))

/*

3 2 1 7
2 3

1
999999999 0 1 1000000000

10 0 1 10

5 1 1 7
1

7 2 1 11
1 2
*/
int main(){
    int T; cin>>T;
    FR(t,T){
        ll N,M,C,R; cin>>N>>M>>C>>R;
        vector<ll> ranges;
        ll prev = 0;
        vl loc(M); FR(i,M)cin>>loc[i]; sort(all(loc));
        FR(i,M){
            if(loc[i]-prev>0)ranges.push_back(loc[i]-prev);
            prev = loc[i]+C;
        }
        if(R-prev>0)ranges.push_back(R-prev);
        // sort(all)
        auto test = [&](double gap){
            ll fit = 0;
            for(auto w:ranges){
                fit+=(w-gap)/(C+gap);
            }
            // cerr<<gap<<" "<<fit<<endl;
            return fit>=N;
        };
        auto exactFit = [&](){
            ll cars = 0;
            for(auto w:ranges){
                // cerr<<(w-gap)/(C+gap)<<endl;
                cars+=w/C;
                if(w/C*C==w)cars--; //can't fit this
                // cerr<<w<<" "<<cars<<endl;
            }
            return cars<N;
        };
        double l = 0, r = 1e12;
        FR(i,2000){
            double mid = (l+r)/2;
            if(test(mid)){
                l = mid;
            }else{
                r = mid;
            }
        }
        if(exactFit()){ //test with width 0 (can you actually fit these)
            cout<<"Impossible"<<endl;
        }else{
            cout<<setprecision(30)<<l<<endl;
        }
        // if(M==0){
        //     assert(fabs(l-double(R-C*N)/(N+1))<=1e6);
        // }
        
    }
    return 0;
}