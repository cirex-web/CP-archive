#include <bits/stdc++.h>
using namespace std;
#define FOR(i,a,b) for(int i = (a); i<(b); i++)
#define FORE(i,a,b) for(int i = (a); i<=(b); i++)

#define FR(i,a) FOR(i,0,a)
#define FRE(i,a) FR(i,a+1)

#define vi vector<int>
#define vvi vector<vi>
#define vb vector<bool>
#define vvb vector<vb>
#define vb vector<bool>
#define vvb vector<vb>
#define sz(a) (int(a.size()))
#define all(a) a.begin(),a.end()
#define vl vector<ll>
#define vvl vector<vl>
using ll = long long;
int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int T; cin>>T;
    FR(t,T){
        ll N,L; cin>>N>>L;
        vl ar(N),difs(N-1);
        FR(i,N)cin>>ar[i];
        sort(all(ar));
        FOR(i,1,N){
            difs[i-1] = ar[i]-ar[i-1]-1;
            // cerr<<difs[i]<<endl;
        }
        sort(all(difs));reverse(all(difs));
        ll ans = 0;
        
        for(int i = 0;i<sz(difs);i++){
            while(i+1<sz(difs)&&difs[i+1]==difs[i]){
                // cerr<<i<<endl;
                i++;
            }
            // cerr<<i<<endl;
            ans = max(ans,(i+1)*difs[i]);
        }
        cout<<ans<<endl;


    }
    return 0;
}