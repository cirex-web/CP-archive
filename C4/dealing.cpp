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

#define ll long long
#define fast ios::sync_with_stdio(0); cin.tie(0)

/*



*/
int main(){
    fast;
    int T; cin>>T;
    FR(t,T){
        int N,K; cin>>N>>K;
        vi perm;vvi slots(K);
        FR(i,N){
            slots[i%K].push_back(i);
        }
        for(auto slot: slots){
            reverse(slot.begin(),slot.end());
            for(int n:slot){
                perm.push_back(n);
                
            }
        }
        // FR(i,N)cerr<<perm[i]<<" \n"[i==N-1];
        vector<bool> vis(N,0);
        ll ans = 1;
        FR(i,N){
            if(vis[i])continue;
            int cur = i;ll cycle = 0;
            while(!vis[cur]){
                vis[cur] = 1;
                cur = perm[cur]; 
                cycle++;
            }
            
            ans=ans/__gcd(ans,cycle)*cycle;
        }
        cout<<ans<<endl;
    }
    return 0;
}