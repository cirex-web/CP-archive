#include <bits/stdc++.h>
using namespace std;
#define FOR(i,a,b) for(int i = (a); i<(b); i++)
#define FR(i,a) FOR(i,0,a)

#define vi vector<int>
#define vvi vector<vi>
#define vvvi vector<vvi>

#define vl vector<ll>
#define vvl vector<vl>
#define vvvl vector<vvl>
#define vd vector<double>
#define vvd vector<vd>
#define sz(a) (int(a.size()))
#define all(a) a.begin(), a.end()
#define ll long long
#define fast ios::sync_with_stdio(0); cin.tie(0)

/*

1
1
720 780 20


1
3
700 800 100
700 800 200
700 800 300

1
11
1 2 1000000
1 2 1000000
1 2 1000000
1 2 1000000
1 2 1000000
1 2 1000000
1 2 1000000
1 2 1000000
1 2 1000000
1 2 1000000
1 2 1000000
*/
struct ev{
    int start,end,amt;
};
struct task{
    int amt; int end;
};

int main(){
    fast;
    int T; cin>>T;
    FR(t,T){
        int N; cin>>N; vector<ev> evs;
        FR(i,N){
            int s,e,amt; cin>>s>>e>>amt;
            evs.push_back({s,e,amt});
        }
        sort(all(evs),[&](ev a, ev b){
            return a.start<b.start;
        });

        auto cmp = [&](task a, task b){
            if(a.end!=b.end)return a.end<b.end;
            return a.amt>b.amt;
        };
        auto test = [&](double rate){
            // cerr<<"____"<<endl;
            multiset<task,decltype(cmp)> tasks(cmp);
            double t = 0; int i = 0;
            while(1){
                while(i<N&&evs[i].start<=t){
                    tasks.insert({evs[i].amt,evs[i].end});
                    i++;
                }
                if(sz(tasks)){
                    auto curTask = *tasks.begin();
                    t+=double(curTask.amt)/rate;
                    // cerr<<sz(tasks)<<" "<<t<<" "<<rate<<endl;
                    if(t>=curTask.end+1e-9)return false; //oops ran out of time
                    tasks.erase(tasks.begin());
                }else{
                    if(i==N)return true;
                    t = evs[i].start;
                }
                // cerr<<t<<endl;
            }
        };
        double l = 0, r = 1e12;
        FR(_,3000){
            double mid = (l+r)/2;
            // cerr<<mid<<" "<<test(mid)<<endl;
            if(test(mid)){
                r = mid;
            }else{
                l = mid;
            }
        }
        cout<<setprecision(20)<<fixed<<l<<endl;
    }
    return 0;
}