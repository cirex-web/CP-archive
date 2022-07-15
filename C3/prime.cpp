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
int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    vi factor(1000001,1); 
    FOR(i,2,sz(factor)){
        if(factor[i]==1){
            for(int j = i; j<sz(factor);j+=i){
                factor[j] = i;
            }
        }
    }
    int T; cin>>T;
    FR(t,T){
        int N,Q;cin>>N>>Q;
        vector<set<int>> primes(N);map<int,int> ptoi;
        FR(i,N){
            int a; cin>>a;
            while(a!=1){
                int prime = factor[a];
                // cerr<<prime<<endl;
                if(!ptoi.count(prime))ptoi[prime] = sz(ptoi);
                a/=prime;
                primes[i].insert(prime);
            }
        }
        vvi prefix(N+1,vi(sz(ptoi)));
        FR(i,N){
            prefix[i+1] = prefix[i];
            for(int prime:primes[i]){
                // cerr<<prime<<"-"<<ptoi[prime]<<" ";
                prefix[i+1][ptoi[prime]]++;
            }
            // cerr<<endl;
        }
        FR(q,Q){
            int L,R; cin>>L>>R;
            int ans = 0;
            FR(i,sz(ptoi)){
                
                if(prefix[R][i]-prefix[L-1][i]>0)ans++;
            }
            cout<<ans<<endl;
        }
    }
    return 0;
}