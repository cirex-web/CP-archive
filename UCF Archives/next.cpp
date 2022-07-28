#include <bits/stdc++.h>

using namespace std;
#define FOR(i,a,b) for(int i = (a); i<(b); i++)
#define FR(i,a) FOR(i,0,a)
#define sz(a) ((int)a.size())
#define ROF(i,a,b) for(int i = (a); i>=(b);i--)
#define all(a) a.begin(),a.end()
using vi = vector<int>;
using ll = long long;
using pii = pair<int,int>;
using pdd = pair<double,double>;


int main(){
    int T;cin>>T;
    FR(t,T){
        string s; cin>>s;
        ROF(i,2,0){
            if(s[i]=='Z')s[i]='A';
            else {
                s[i] = s[i]+1;
                break;
            }
        }
        cout<<s<<endl;
    }
    
    return 0;
}