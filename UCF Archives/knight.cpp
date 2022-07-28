#include <bits/stdc++.h>

using namespace std;
#define FOR(i,a,b) for(int i = (a); i<(b); i++)
#define FR(i,a) FOR(i,0,a)
#define sz(a) ((int)a.size())
#define ROF(i,a,b) for(int i = (a); i>=(b);i--)
#define all(a) a.begin(),a.end()
using vi = vector<int>;
using ll = long long;

struct knight{
    int death,years,q;
};
struct ev{
    int t,i;
    bool add;
};
int main(){
    int T; cin>>T;
    FR(t,T){
        int N; cin>>N;
        vector<knight> ks;
        vector<ev> evs;
        FR(i,N){
            int start,death,qual,years;
            cin>>start>>death>>qual>>years;
            evs.push_back({start,i,1});
            evs.push_back({death,i,0}); //dead at that year; not eligible
            ks.push_back({death,years,qual});   

        }
        sort(all(evs),[](ev a, ev b){
            if(a.t!=b.t)return a.t<b.t;
            return a.i<b.i; //can't have same i if same t 
        });
        
        auto cmp = [&](int i, int j){
            return ks[i].q>ks[j].q; //check?
        };
        set<int, decltype(cmp)> window(cmp);
        int cur_time = evs[0].t;
        int i = 0;
        while(1){
            while(i<sz(evs)&&evs[i].t<=cur_time){
                int id = evs[i].i;
                if(evs[i].add){
                    window.insert(id);
                }else if(window.find(id)!=window.end()){
                    //right?
                    window.erase(window.find(id));
                }
                i++;
            }
            if(!sz(window))break;

            int nxt = *window.begin();
            window.erase(window.begin());
            int prev_time = cur_time;
            cur_time = min(cur_time+ks[nxt].years,ks[nxt].death);
            assert(ks[nxt].death>prev_time);
            cout<<nxt+1<<" "<<prev_time<<" "<<cur_time<<endl;

        }

    }
    
    return 0;
}