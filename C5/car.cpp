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

int main(){
    int T; cin>>T;
    FR(t,T){
        string s; cin>>s;
        if(s.find("CAR")!=string::npos){
            if(s=="CAR"){
                cout<<"Arup"<<endl;
            }else{
                cout<<"Travis"<<endl;
            }
        }else{
            cout<<"Unknown"<<endl;
        }
    }
    return 0;
}
//TPACRE