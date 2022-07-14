#include <bits/stdc++.h>

#define FOR(i,a,b) for(int i = (a); i<(b); i++)
#define FR(i,a) FOR(i,0,a)
using namespace std;

#define fast ios::sync_with_stdio(0); cin.tie(0)
#define ll long long
#define vl vector<ll>
#define vi vector<int>
#define sz(a) ((int)a.size())
int main(){
    fast;
    int T; cin>>T;
    FR(t,T){
        int N; cin>>N;
        vl a(N),b(N),prefix(N+1);
        FR(i,N)cin>>a[i];
        FR(i,N)cin>>b[i];
        FR(i,N){
            prefix[i+1] = prefix[i]+(b[i]-a[i]);
        }
        map<int,int> freq;
        ll ans = 0;
        FR(i,sz(prefix)){
            ans+=freq[prefix[i]]++;
            
        }
        cout<<ans<<endl;
    }
}