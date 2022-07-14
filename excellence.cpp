#include <bits/stdc++.h>

#define FOR(i,a,b) for(int i = (a); i<(b); i++)
#define FR(i,a) FOR(i,0,a)
using namespace std;

#define fast ios::sync_with_stdio(0); cin.tie(0)
#define ll long long
int main(){
    fast;
    int T; cin>>T;
    FR(t,T){
        int N; cin>>N;
        vector<int> ar(N); FR(i,N)cin>>ar[i];
        sort(ar.begin(),ar.end());
        int ans = INT_MAX;
        FR(i,N/2){
            ans = min(ans,ar[i]+ar[N-i-1]);
        }
        cout<<ans<<endl;
    }
}