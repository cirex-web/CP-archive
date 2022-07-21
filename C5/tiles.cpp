#include <bits/stdc++.h>

using namespace std;
#define FOR(i,a,b) for(int i = (a); i<(b); i++)
#define FR(i,a) FOR(i,0,a)
#define ROF(i,a,b) for(int i = (a); i>=(b); i--)
#define vi vector<int>
#define vvi vector<vi>
#define ll long long
#define vl vector<ll>
#define vll vector<vl>

#define pb(a) push_back(a)
#define all(a) a.begin(),a.end()
#define fast ios::sync_with_stdio(0);cin.tie(0)
#define sz(a) (int(a.size()))
int main(){
    int T; cin>>T;
    FR(_,T){
        string s,t; cin>>s>>t;
        map<int,int> index;
        FR(i,sz(s)){
            index[s[i]] = i;
        }
        int ans = 0;
        FR(i,sz(t)){
            int j = index[t[i]];
            // cerr<<i<<" "<<j<<endl;
            if(j>i){
                ROF(pos,j-1,i){
                    index[s[pos]]++;//shift stuff
                    s[pos+1] = s[pos];
                    // cerr<<"move "<<s[pos]<<endl;
                }
                s[i] = t[i];
                ans+=j-i;
                cerr<<s<<endl;
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}