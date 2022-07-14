#include <bits/stdc++.h>

using namespace std;
#define FOR(i,a,b) for(int i = (a); i<(b); i++)
#define FR(i,a) FOR(i,0,a)
#define sz(a) ((int)a.size())
#define ROF(i,a,b) for(int i = (a); i>=(b);i--)
#define all(a) a.begin(),a.end()
#define pb(a) push_back(a)
using vi = vector<int>;
using ll = long long;
using vvi = vector<vi>;

struct ev{
    bool query; int person; int amt = -1;
};
struct BIT{
    vi ar;
    BIT(int N){
        ar.resize(N+1,0);
    }
    void upd(int i, int amt){
        i++;
        while(i<sz(ar)){
            ar[i]+=amt;
            i+=i&-i;
        }
    }
    int sum(int i){
        i++; int res = 0;
        while(i){
            res+=ar[i]; i-=i&-i;
        }
        return res;
    }
};
int main(){
    int T;cin>>T;
    FR(t,T){
        int Q;cin>>Q;
        map<string,int> peopleToInt;
        peopleToInt["ROOT"] = 0;
        vvi g(1); //contains the root thus far
        vector<ev> evs;
        FR(q,Q){
            string query;cin>>query;
            if(query[0]=='A'){
                string A,B; cin>>A>>B;
                peopleToInt[B] = sz(g);
                g.push_back(vi());
                g[peopleToInt[A]].push_back(peopleToInt[B]);

            }else if(query[0]=='S'){
                string person; int amt; cin>>person>>amt;
                evs.push_back({0,peopleToInt[person],amt});
            }else{
                //query
                string person;cin>>person;
                evs.push_back({1,peopleToInt[person]});
            }
            
        }
        int N = sz(g); //number of nodes (yes, including that extra ROOT)
        BIT bit(N);
        vi s(N,-1),e(N,-1);
        int timer = 0;
        function<void(int)> dfs = [&](int a){
            s[a]=timer++;
            for(int b: g[a]){
                dfs(b);
            }
            e[a] = timer-1; //get same value as child thing, not the next one
        };
        cout<<"COMPANY "<<t+1<<endl;
        dfs(0);
        for(auto ev: evs){
            if(ev.query){
                int l = s[ev.person], r = e[ev.person];
                cout<<bit.sum(r)-bit.sum(l-1)<<endl;
            }else{
                //add amt
                int loc = s[ev.person];
                bit.upd(loc,ev.amt);
            }
        }
    }
    
    
    
    return 0;
}