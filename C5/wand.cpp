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

struct BIT{
    vi ar;
    BIT(int N){
        ar.resize(N+1,0);
    }
    void upd(int i, int mask){
        assert(i+1<sz(ar));
        for(i++;i<sz(ar);i+=i&-i)ar[i]^=mask;
    }
    int get(int i){
        int res = 0;
        for(i++;i;i-=i&-i)res^=ar[i];
        // cerr<<bitset<8>(res)<<endl;
        return res;
    }
};
int main(){
    int T; cin>>T;
    FR(t,T){
        int N,Q,K; cin>>N>>Q>>K;
        vvi g(N);
        BIT bit(2*N);
        FR(i,N-1){
            int par; cin>>par;
            g[par].push_back(i+1);
        }
        int timer = 0;
        vi s(N),e(N);
        function<void(int)> dfs = [&](int a){
            s[a]=timer++;
            for(int b: g[a]){
                dfs(b);
            }
            e[a]=timer++;
        };
        dfs(0);
        // cerr<<e[0]<<endl;
        FR(q,Q){
            int type; cin>>type;
            if(type==1){
                int w;string spell; cin>>w>>spell;
                int mask = 0;
                FR(i,K){
                    if(spell[i]=='Y')mask+=(1<<i); //backwards but whatever
                }
                bit.upd(s[w],mask);bit.upd(e[w],mask);
                // cerr<<"upd "<<s[w]<<" "<<e[w]<<endl;
            }else{
                int w; cin>>w;
                int mask = bit.get(s[w]);
                FR(i,K){
                    if(mask&(1<<i)){
                        cout<<"U";
                    }else{
                        cout<<"D";
                    }
                }
                // cerr<<" "<<s[w]<<endl;
                cout<<endl;
            }
        }
    }
    return 0;
}