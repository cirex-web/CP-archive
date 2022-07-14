#include <bits/stdc++.h>

using namespace std;
#define FOR(i,a,b) for(int i = (a); i<(b); i++)
#define FR(i,a) FOR(i,0,a)
#define sz(a) ((int)a.size())
#define ROF(i,a,b) for(int i = (a); i>=(b);i--)
#define all(a) a.begin(),a.end()
using vi = vector<int>;
using ll = long long;

int main(){
    int N; cin>>N;
    vi fac(13,1);
    FOR(i,1,sz(fac)){
        fac[i]=fac[i-1]*i;
    }
    FR(i,N){
        string s;cin>>s;

        map<char,int> freq;
        for(char c:s)freq[c]++;
        int ans = fac[sz(s)];
        for(auto [k,v] :freq){
            ans/=fac[v];
        }
        cout<<ans<<endl;
    }
    
    return 0;
}